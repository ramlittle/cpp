#include <iostream>
using namespace std;

void sortLowestToHighest(int givenArray[],int lengthOfArray){
    for(int i=1;i<lengthOfArray;i++){
        for(int j=0;j<lengthOfArray-i;j++){
            if(givenArray[j] > givenArray[j+1]){
                int temp = givenArray[j];
                givenArray[j]=givenArray[j+1];
                givenArray[j+1] = temp;
            }
        }
    }
}
int main(){
    int lengthOfArray = 10;
    int givenArray[lengthOfArray] = {5,4,10,8,7,13,3,2,1,78};

    cout <<"THIS IS THE ORIGINAL ARRAY"<<endl;
    for(int i=0;i<lengthOfArray;i++){
        cout << givenArray[i] << " ";
    }
    cout << endl;

    sortLowestToHighest(givenArray,lengthOfArray);

    cout << "THIS IS NOW THE SORTED VERSION"<<endl;
    for(int i=0;i<lengthOfArray;i++){
        cout << givenArray[i] << " ";
    }
    cout << endl;
return 0;
}
