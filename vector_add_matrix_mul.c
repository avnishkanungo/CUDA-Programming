#include <stdio.h>

typedef struct {
    int squareFeet;
    int numberOfBedrooms;
    int numberOfBathrooms;
} House;

void vecAdd(float *a, float *b, float *c, int n) {
    for (int i = 0; i < 3; i++) {
        c[i] = a[i]+b[i];
    }
}

void addMatrix(float *a, float *b, float *c, int n, int l) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            *(c+i*l+j) = *(a+i*l+j) + *(b+i*l+j);
            // c[i*l+j] = a[i*l+j] + b[i*l+j];
            
        }
    }
}

void printMatrix(float *a, int n, int l) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            printf("%f ", *(a+i*l+j));
        }
        printf("\n");
    }
}

void printVec(float *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f\n", a[i]);
    }
}


void main() {
    printf("Hello, World!\n");
    int *x,y;
    y=15;
    printf("%d\n", y);
    x = &y;
    *x = 10;
    printf("%d\n", y);

    House someHouse = {960,2,1};

    printf("squareFeet: %d\n", someHouse.squareFeet);
    printf("numberOfBedrooms: %d\n", someHouse.numberOfBedrooms);
    printf("numberOfBathrooms: %d\n", someHouse.numberOfBathrooms);

    House *myHouse;
    myHouse = &someHouse;
    printf("squareFeet: %d\n", myHouse->squareFeet);
    printf("numberOfBedrooms: %d\n", myHouse->numberOfBedrooms);
    printf("numberOfBathrooms: %d\n", myHouse->numberOfBathrooms);

    char someString[] = "Hello, World!";
    printf("%c\n", someString[1]);
    char *pString = someString;
    printf("%c\n", *(pString+9));
    printf("%c\n", someString[1]);
    printf("%p\n",(void*)someString[1]);
    printf("%p\n",(void*)pString);

    int aNums[] = {1,2,3,4,5};
    // printf("%d\n", aNums);
    int *pNums = &aNums;
    
    pNums++;
    printf("%d\n", *pNums);

    printf("%p\n", (void*)pNums);

    float a[3] = {1,2,3};
    float b[3] = {4,5,6};
    float c[3];
    vecAdd(a,b,c,3);
    printf("%f\n", c[0]);
    printf("%f\n", c[1]);
    printf("%f\n", c[2]);
    printf("\n");
    printVec(c,3);

    float mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(mat,3,3);
    printf("\n");
    float mat2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    float mat3[3][3];
    addMatrix(mat,mat2,mat3,3,3);
    printMatrix(mat3,3,3);

}