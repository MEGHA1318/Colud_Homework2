#include <stdio.h>

void enterValue(int first[][10], int second[][10], int r1, int c1, int r2, int c2);

void mul_Matrix(int first[][10], int second[][10], int multResult[][10], int r1, int c1, int r2, int c2);

void Result(int mult[][10], int r1, int c2);

int main() {
    int first[10][10], second[10][10], mult[10][10], r1, c1, r2, c2;
    printf("Enter the rows and column for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the rows and column for the second matrix: ");
    scanf("%d %d", &r2, &c2);
    
    while (c1 != r2) {
        printf("Enter rows and columns again.\n");
        printf("Enter rows and columns for the first matrix: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and columns for the second matrix: ");
        scanf("%d%d", &r2, &c2);
    }
    
    
    enterValue(first, second, r1, c1, r2, c2);
    
    
    mul_Matrix(first, second, mult, r1, c1, r2, c2);
    // Function to display resultant matrix after multiplication.
    Result(mult, r1, c2);
    return 0;
}
void enterValue(int first[][10], int second[][10], int r1, int c1, int r2, int c2) {
    printf("\nEnter elements of matrix 1:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &first[i][j]);
        }
    }
    printf("\nEnter elements of matrix 2:\n");
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%d", &second[i][j]);
        }
    }
}
void mul_Matrix(int first[][10], int second[][10], int mult[][10], int r1, int c1, int r2, int c2) {
   
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            mult[i][j] = 0;
        } 
    }
   
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                mult[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}
void Result(int mult[][10], int r1, int c2) {
    printf("\nOutput Matrix:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("%d  ", mult[i][j]);
            if (j == c2 - 1)
                printf("\n");
        }
    }
}