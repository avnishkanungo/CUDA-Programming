#include<stdio.h>
#include<cuda_runtime.h>

__global__ void matrixAdd(int* a, int* b, int* c, int w, int l) {
    int idx = blockIdx.x*blockDim.x + threadIdx.x;
    int idy = blockIdx.y*blockDim.y + threadIdx.y;
    if (idx<w && idy<l){
        c[idy*w+idx] = a[idy*w+idx] + b[idy*w+idx];
    };
}

int main() {
    const int w = 64;
    const int l = 64;
    size_t size = w * l * sizeof(int);

    int *h_a, *h_b, *h_c;
    int *d_a, *d_b, *d_c;

    h_a = (int*)malloc(size);
    h_b = (int*)malloc(size);
    h_c = (int*)malloc(size);

    for (int i = 0; i < w * l; i++) {
        h_a[i] = i;  // Random values for array a
        h_b[i] = i*2;  // Random values for array b
    }

    cudaMalloc((void**)&d_a,size);
    cudaMemcpy(d_a,h_a,size,cudaMemcpyHostToDevice);
    cudaMalloc((void**)&d_b,size);
    cudaMemcpy(d_b,h_b,size,cudaMemcpyHostToDevice);
    cudaMalloc((void**)&d_c,size);

    dim3 threadsInBlock(16,16);
    dim3 blocksInGrid(
        (w + threadsInBlock.x-1)/threadsInBlock.x,
        (l + threadsInBlock.x-1)/threadsInBlock.y
    );

    matrixAdd<<<blocksInGrid,threadsInBlock>>>(d_a,d_b,d_c,w,l);

    cudaDeviceSynchronize();

    cudaMemcpy(h_c,d_c,size,cudaMemcpyDeviceToHost);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    free(h_a);
    free(h_b);
    free(h_c);

    for(int i=0;i<10;i++){
        for(int j=0; j<10; j++){
            printf("%d+%d=%d\n",h_a[i*l+j],h_b[i*l+j],h_c[i*l+j]);
        }
        
    };

    return 0;

}