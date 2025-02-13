#include<stdio.h>
#include<cuda_runtime.h>

__global__ void matMul(float* a, float* b, float* c, int a_rows, int a_cols, int b_cols){     //dont need to define b_rows as that will need to be same as a_cols for matrix mul to works
    int rows = threadIdx.y + blockDim.y * blockIdx.y;
    int cols = threadIdx.x + blockDim.x * blockIdx.x;

    if(rows<a_rows && cols<b_cols){
        float sum = 0.0f;
        for(int k=0;k<a_cols;k++){
            sum += a[rows*a_cols+k]*b[k*b_cols+cols];
        }
        c[rows*b_cols+cols] = sum;
    }

}


void initializeMatrix(float* d_a, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            d_a[i*cols+j] = rand()%10;
        }
    }
}

void printMatrix(float* d_a, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%f ", d_a[i*cols+j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    float *d_a, *d_b, *d_c;
    float *h_a, *h_b, *h_c;

    int a_rows,a_cols,b_rows,b_cols;

    printf("Enter the value for the rows and colums for d_a:");
    scanf("%d %d", &a_rows,&a_cols);

    printf("Enter the value for the rows and colums for d_b:");
    scanf("%d %d", &b_rows,&b_cols);

    if (a_cols != b_rows){
        printf("Error");
        return -1;
    }

    h_a = (float*)malloc(a_rows*a_cols*sizeof(float));
    h_b = (float*)malloc(b_rows*b_cols*sizeof(float));
    h_c = (float*)malloc(a_rows*b_cols*sizeof(float));

    initializeMatrix(h_a,a_rows,a_cols);
    initializeMatrix(h_b,b_rows,b_cols);

    cudaMalloc((void**)&d_a,a_rows*a_cols*sizeof(float));
    cudaMalloc((void**)&d_b,b_rows*b_cols*sizeof(float));
    cudaMalloc((void**)&d_c,a_rows*b_cols*sizeof(float));

    cudaMemcpy(d_a,h_a,a_rows*a_cols*sizeof(float),cudaMemcpyHostToDevice);
    cudaMemcpy(d_b,h_b,b_rows*b_cols*sizeof(float),cudaMemcpyHostToDevice);

    dim3 threadsInBlock(16,16);
    dim3 blocksInGrid((a_rows+threadsInBlock.x-1)/threadsInBlock.x,
                      (b_cols+threadsInBlock.y-1)/threadsInBlock.y);

    matMul<<<blocksInGrid,threadsInBlock>>>(d_a,d_b,d_c,a_rows,a_cols,b_cols);

    cudaMemcpy(h_c,d_c,a_rows*b_cols*sizeof(float),cudaMemcpyDeviceToHost);
    printMatrix(h_c,a_rows,b_cols);
}