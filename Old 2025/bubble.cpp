#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arrA = {1,8,5,10,7,2,3,4,6};

    for(int i=0;i<arrA.size();i++){
        for(int j=0;j<arrA.size()-i-1;j++){
            if(arrA[j]>=arrA[j+1]){
                int temp = arrA[j];
                arrA[j] = arrA[j+1];
                arrA[j+1] = temp;
            }
        }
    }
    //verify
    for(int i=0;i<arrA.size();i++){
        cout << arrA[i] << " ";
    }
return 0;
}
