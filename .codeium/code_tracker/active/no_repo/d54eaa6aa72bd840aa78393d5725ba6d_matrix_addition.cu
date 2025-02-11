
M/teamspace/studios/this_studio/MatrixAdditionAndAssignment/matrix_addition.cuÏ#include<stdio.h>
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

}0*$0ecbdd1c-c002-4afa-90d5-c50c51adf33c082 *$8d40c9ad-671b-4f52-9948-4654d897549508'2'* *$8d40c9ad-671b-4f52-9948-4654d897549508*R 2RV *$171088a0-cc15-4180-8d15-fa69cfd5ed3f08VY2Yb *$171088a0-cc15-4180-8d15-fa69cfd5ed3f08bc2cj *$171088a0-cc15-4180-8d15-fa69cfd5ed3f08jk kr 	r¯ 2¯Ó*$0b2039e8-6e26-4620-bfbb-a9439effecb408
Óì 
ìõ 
õ  
 ¥ 
¥¨ 
¨© 
©µ 2µ·*$9be76487-46cb-48a4-aca5-3c43e9bfb5cf08
·ã 
ãå åæ
æê êí
íû 
û 
ƒ ƒ„
„ˆ ˆ‹
‹™ 
™  
 ¸ ¸¹
¹Ó ÓÔ
Ô… …ˆ
ˆ­ 
­³ 
³á áâ
âå åæ
æ¹ ¹º
º½ ½¾
¾› ›
ž ž 
 ¨ 
¨¹ 
¹Â 
ÂÛ 
Ûé éë
ëñ 
ñú úŒ
Œ 
 
¥ 
¥¦ 
¦í í…	
…	§	 §	­	
­	Ô	 
Ô	Ý	 Ý	Þ	
Þ	ß	 ß	à	
à	â	 
â	ç	 
ç	ð	 ð	ñ	
ñ	ò	 ò	ó	
ó	õ	 
õ	¿
 
¿
Ä
 
Ä
à
 
à
† 
†‹ 
‹ •
•› › 
 ¬ 
¬Ï 2Tfile:///teamspace/studios/this_studio/MatrixAdditionAndAssignment/matrix_addition.cu