#include <iostream>
#include <vector>

// Inner product function
int inner_prod(std::vector<int> &x,std::vector<int> &y){
    int result=0;
    for(int i=0;i<x.size();i++){
        result+=x[i]*y[i];
    }
    return result;
}
// For 2D vectors
std::vector<double> gram_schmidt(std::vector<int> &v1, std::vector<int> &v2){
    std::vector<double> result;
    std::vector<double> projection;
    int i;
    for (i=0;i<v2.size();i++){
        projection.push_back(inner_prod(v2,v1)*1.0/inner_prod(v1,v1)*v1[i]);
    }
    for(i=0;i<v2.size();i++){
        result.push_back(v2[i]-projection[i]);
    }
    return result;
}

int main()
{
    int input;
    std::vector<int> u {1,0,-1};
    std::vector<int> v {0,4,6};
    std::vector<double> result;
    result=gram_schmidt(u,v);
    for(int i=0;i<u.size();i++){
        std::cout<<result[i]<< " ";
    }
    std::cout<<"\n";
}
