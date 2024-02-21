#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include <ctime>

#define MAX_THREADS 4

void matrixMult(int source1[][4], int source2[][4], int dest[][4], int i){
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            dest[i][j]+=source1[i][k]*source2[k][j];
        }
    }
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    const int size=4;
    int A[size][size]={};
    int B[size][size]={};
    int C1[size][size]={};
    int C2[size][size]={};

    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            A[i][j]=rand() % 100 + 1;
            B[i][j]=rand() % 100 + 1;
        }
    }
    int total;
    int sizeA=sizeof(A)/sizeof(A[0]);
    int sizeB=sizeof(B)/sizeof(B[0]);
    int sizeC=sizeof(A[0])/sizeof(int);
    for(int row=0;row<sizeA;row++){
        for(int col=0;col<sizeB;col++){
            total=0;
            for(int index=0;index<sizeC;index++){
                total+=A[row][index]*B[index][col];
            }
            std::cout<<total<<std::endl;
            C1[row][col]=total;
        }
    }
    std::cout<<"First Matrix"<<std::endl;
    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        std::cout<<A[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"Second Matrix"<<std::endl;
    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        std::cout<<B[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"C1 Matrix"<<std::endl;
    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        std::cout<<C1[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    std::thread threads[MAX_THREADS];
    for(int i=0;i<MAX_THREADS;i++){
        threads[i]=std::thread(matrixMult,std::ref(A),std::ref(B),std::ref(C2),i);
    }
    for(int i=0;i<MAX_THREADS;i++){
        threads[i].join();
    }
    std::cout<<"C2 Matrix"<<std::endl;
    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        std::cout<<C2[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}