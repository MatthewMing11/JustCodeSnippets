#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>

void child(int id){
    std::cout<<id<<std::endl;
}

int main(int argc, char* argv[]){
    std::vector<std::thread> threads;
    for (int i=0;i<10;i++){
        threads.push_back(std::thread(child,i));
        threads[i].join();
    }
}