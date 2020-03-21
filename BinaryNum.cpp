#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This code transfor a decimal number into binary one
class BinaryNum{
    public:
        static void binaryNumber(unsigned int n){
            vector<int> res;
            int i;
            for(i=0; n>0; i++){
                res.push_back(n%2);
                n/=2;
            }
            //We apply reverse algorithm in order to have the correct number
            reverse(res.begin(), res.end());
            //We print the binary format number by number
            for(auto i:res){
                cout<<i;
            }
        }
};

int main(int argc, char const *argv[]){
    
    BinaryNum::binaryNumber(100);    

    return 0;
}
