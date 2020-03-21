#include <cstdlib>
#include <iostream>
using namespace std;

class BinaryNum{

    public:
        static int getNthFib(int n){
            if(n==2){return 1;}
            else if(n==1){return 0;}
            else{
                return getNthFib(n-1)+getNthFib(n-2);
            }
        }
};

int main(int argc, char const *argv[])
{
    cout<<BinaryNum::getNthFib(7);
    return 0;
}



