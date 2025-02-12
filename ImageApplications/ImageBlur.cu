#include <stdio.h>
#include <cuda_runtime.h>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>


__global__ void blurKernel(unsigned char *d_input, unsigned char *d_output, int width, int height) {
    int idx = threadIdx.x+blockDim.x*blockIdx.x;
    int idy = threadIdx.y+blockDim.y*blockIdx.y;
    if (idx < width && idy < height) {
        int greyScaleOffset = idy * width + idx;
        int rgbOffset = greyScaleOffset * 3;

        unsigned char r = d_input[rgbOffset];
        unsigned char g = d_input[rgbOffset + 1];
        unsigned char b = d_input[rgbOffset + 2];

        d_output[greyScaleOffset] = 0.21f * r + 0.72f * g + 0.07f * b;
        
    }
}

int main(){
    cv::Mat input = cv::imread("test.jpg");
    
    if (input.empty()) {
        printf("Error: Could not read input image\n");
        return -1;
    }

    int width = input.cols;
    int height = input.rows;
    
    // Allocate host memory for output
    cv::Mat output(height, width, CV_8UC1);

    // Allocate device memory
    unsigned char *d_input, *d_output;
    cudaMalloc(&d_input, width * height * 3 * sizeof(unsigned char));  // RGB input
    cudaMalloc(&d_output, width * height * sizeof(unsigned char));     // Grayscale output
    cudaCheckError();

    // Copy input image to device
    cudaMemcpy(d_input, input.data, width * height * 3 * sizeof(unsigned char), 
               cudaMemcpyHostToDevice);
    cudaCheckError();

    // Set up grid and block dimensions
    dim3 blockDim(16, 16);  // 256 threads per block
    dim3 gridDim((width + blockDim.x - 1) / blockDim.x, 
                 (height + blockDim.y - 1) / blockDim.y);

    // Launch kernel
    blurKernel<<<gridDim, blockDim>>>(d_input, d_output, width, height);
    cudaCheckError();

    // Copy result back to host
    cudaMemcpy(output.data, d_output, width * height * sizeof(unsigned char), 
               cudaMemcpyDeviceToHost);
    cudaCheckError();

    // Save output image
    cv::imwrite("output.jpg", output);

    // Clean up
    cudaFree(d_input);
    cudaFree(d_output);
    cudaCheckError();

    return 0;
}


