#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include <chrono>

#define MAX_THREADS 4

const int size=4;
void matrixMult(int source1[][size], int source2[][size], int dest[][size], int i){
    for(int j=0;j<size;j++){
        for(int k=0;k<size;k++){
            dest[i][j]+=source1[i][k]*source2[k][j];
        }
    }
}

int main(int argc, char* argv[]){
    //borrowed timing execution code from https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    srand(time(NULL));
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
    auto t1 = high_resolution_clock::now();
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
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms\n";

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
    t1 = high_resolution_clock::now();
    std::thread threads[MAX_THREADS];
    for(int i=0;i<MAX_THREADS;i++){
        threads[i]=std::thread(matrixMult,std::ref(A),std::ref(B),std::ref(C2),i);
    }
    for(int i=0;i<MAX_THREADS;i++){
        threads[i].join();
    }
    t2 = high_resolution_clock::now();
    ms_int = duration_cast<milliseconds>(t2 - t1);
    ms_double = t2 - t1;
    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms\n";
    std::cout<<"C2 Matrix"<<std::endl;
    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        std::cout<<C2[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}