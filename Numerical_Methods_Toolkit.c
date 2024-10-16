#include<stdio.h> 
#include<math.h>
#include<stdlib.h>
#define n 3

float** createMat(int, int);
void displayMatrix(float**, int, int);
void addEntriestoMatrix(float*, float**);
float** invert(float**, int);
float** MatMul(float**, int, int, float**, int, int);
float** LinearRegression(float*, float*, int, int);

int main(){
    float** Mat = createMat(n,n);
    float* Entries = (float*)malloc(n*n*sizeof(float));
    // for(int i = 0; i < n*n; i++){
    //     float entry;
    //     scanf("%f", &entry);
    //     Entries[i] = entry;
    // }
    // addEntriestoMatrix(Entries, Mat);
    // //displayMatrix(Mat,n);
    // //printf("\n");
    // displayMatrix(invert(Mat,n), n, n);

    // float** Mat1 = createMat(2,3);
    // Mat1[0][0] = 4; Mat1[0][1] = 5; Mat1[0][2] = 7;
    // Mat1[1][0] = 2; Mat1[1][1] = 1; Mat1[1][2] = 0;

    // displayMatrix(Mat1, 2, 3);
    // printf("\n");
    // float** Mat2 = createMat(3,2);
    // Mat2[0][0] = 2; Mat2[0][1] = 3;
    // Mat2[1][0] = 8; Mat2[1][1] = 9;
    // Mat2[2][0] = 1; Mat2[2][1] = 1;
    // float** Mat3 = MatMul(Mat1, 2, 3, Mat2, 3, 2);
    // displayMatrix(Mat3, 2, 2);
    float f_i[15] = {1.0, 2.1, 3.2, 4.3, 5.0, 6.1, 7.2, 8.3, 9.4, 10.5, 11.6, 12.7, 13.8, 14.9, 15.5};
    float x_i[15] = {1.5, 2.3, 3.1, 3.9, 5.0, 5.7, 6.4, 7.3, 8.1, 9.0, 9.8, 10.5, 11.4, 12.2, 13.0};
    float** coeff = LinearRegression(f_i, x_i, 1, 15);
    displayMatrix(coeff, 2, 1);
}




float** createMat(int rows, int columns){
    float** Mat = (float**)malloc(columns*sizeof(float*));
    for(int i = 0; i < rows; i++){
        Mat[i] = (float*)calloc(rows, sizeof(float)); 
    }
    return Mat;
} 
void displayMatrix(float** Mat, int row, int column){
    for(int i = 0; i < row; i ++){
        for(int j = 0; j < column; j++){
            printf("%f ", Mat[i][j]);
        }
        printf("\n");
    }
}
void addEntriestoMatrix(float* Entry, float** Mat){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Mat[i][j] = Entry[i*n + j];
        }
    }
}
float** invert(float** Mat, int size){
    //printf("Hello0");
    //displayMatrix(Mat,n);
    //printf("\n");
    float** InvMat = createMat(n,n);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            InvMat[i][j] = (i == j) ? 1.0 : 0.0;  // Identity matrix
        }
    }
    //displayMatrix(InvMat,n);
    //printf("Hello0");
    for(int i = 0; i < size; i++){
        float pivot = Mat[i][i];
        //printf("Hello1");
        for(int j = 0; j < size; j++){
            Mat[i][j]/= pivot;
            InvMat[i][j]/= pivot;
        }
        for(int j = 0; j < size; j++){
            if(j == i){
                continue; //"i" IS the pivot
            }
            float Factor = Mat[j][i];
            //Now, we iterate over each row, find pivot, and then iterate over each row that DOES not have the pivot
            for(int k = 0; k < size; k++){
                Mat[j][k] -= Factor*Mat[i][k];
                InvMat[j][k] -= Factor*InvMat[i][k];
            }
        }
    }
     //displayMatrix(Mat,n);//for debugging alone
     //printf("\n");
     return InvMat;
    }

    float** MatMul(float** Mat1, int row1, int column1, float** Mat2, int row2, int column2){
        if(column1 != row2){
            fprintf(stderr, "Error: Cannot multiply \n");
            return NULL;               
        }
        float** output = createMat(row1, column2);
        for(int i = 0; i <row1; i++){
            for(int j = 0; j < column2; j++){
                for(int k = 0; k < column1; k++){
                    output[i][j]+= Mat1[i][k]*Mat2[k][j];
                }
            }
        }
        return output;
    }
    float** LinearRegression(float* f_i, float* x_i, int degree_input, int size){
        int degree = degree_input + 1;
        float* LHS = (float*)calloc((2*(degree - 1)), sizeof(float));
        for(int i = 0; i <= 2*(degree - 1); i++){
            for(int j = 0; j < size; j++){
                LHS[i] += pow(x_i[j],i);
            }
            printf("%f\n", LHS[i]);
        }
        printf("\n");
        float* RHS = (float*)calloc(degree, sizeof(float));
        for(int i = 0; i < degree; i++){
            for(int j = 0; j < size; j++){
                RHS[i] += f_i[j]*pow(x_i[j], i);
            }
            printf("%f\n", RHS[i]);
        }
        printf("\n");
        float** A = createMat(degree, degree);
        float** B = createMat(degree, 1);
        float** X = createMat(degree, 1);

        for(int i = 0; i < degree; i++){
            for(int j = 0; j < degree; j++){
               A[i][j] = LHS[i+j]; 
            }
        }

        for(int i = 0; i < degree; i++){
            B[i][0] = RHS[i];
        }
        displayMatrix(A,degree, degree);
        printf("\n");
        displayMatrix(B, degree, 1);
        printf("\n");
        //eqn to solve is AX = B
        X = MatMul(invert(A, degree), degree, degree, B, degree, 1);
        return X;
    }   