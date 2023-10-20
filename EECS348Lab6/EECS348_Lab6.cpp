#include<iostream>                        
#include <fstream>                        
#include <iomanip>

using namespace std;
static int maxsize = 100;

void printmatrix(int *m1, int size);
void addmatrix(int *m1, int *m2, int size);
void matrixproduct(int *m1, int *m2, int size);
void matrixdiff(int *m1, int *m2, int size);

//main function that does file reading and stores it into matricies
int main() {
    int size = 0;
    std::ifstream input("matrix_input.txt");
    input >> size;
    int m1[size][size];
    int m2[size][size];
    for (int i = 0; i < size; i++) {
        for (int j=0; j < size; j++){
            input >> m1[i][j];
            //std::cout<< m1[i][j]<<std::endl; (this was used to test)
        }
    }
    for (int k = 0; k < size; k++) {
        for (int l=0; l < size; l++){
            input >> m2[k][l];
            //std::cout<< m2[k][l]<<std::endl;
        }
    }

    std::cout << "Cole Bartley" << std::endl;
    std::cout << "Lab #6: Matrix manipulation\n" << std::endl;
    std::cout << "Maxtrix A:" << std::endl;
    printmatrix((int *)&m1, size);
    std::cout << "\nMatrix B:" << std::endl;
    printmatrix((int *)&m2, size);
    std::cout << "\nMatrix Sum (A + B)" << endl;
    addmatrix((int *)&m1,(int *)&m2 ,size);
    std::cout << "\nMatrix Product (A * B)" << endl;
    matrixproduct((int *)&m1,(int *)&m2 ,size);
    std::cout << "\nMatrix Difference (A - B)" << endl;
    matrixdiff((int *)&m1,(int *)&m2 ,size);
}
//function that prints out the matrices in a neat form
void printmatrix(int *m1, int size){
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            std::cout<< setw(4) << m1[i*size + j];
        }
        std::cout << std::endl;
    }
}
//function that adds the matrices together and orints them out
void addmatrix(int *m1, int *m2, int size){
    int m3[size][size];
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            m3[i][j] = m1[i*size + j] + m2[i*size + j];
        }
    }
    printmatrix((int *)&m3, size);
}

//function that multiplies the matricies together and prints them out
void matrixproduct(int *m1, int *m2, int size){
    int m3[size][size];
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            m3[i][j] = 0;
            for (int k=0; k < size; k++){
                m3[i][j] += m1[i*size + k] * m2[k*size + j];
            }
        }
    }
    printmatrix((int *)&m3, size);
}
//function that takes the difference between the matricies and prints them out
void matrixdiff(int *m1, int *m2, int size){
    int m3[size][size];
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            m3[i][j] = m1[i*size + j] - m2[i*size + j];
        }
    }
    printmatrix((int *)&m3, size);
}