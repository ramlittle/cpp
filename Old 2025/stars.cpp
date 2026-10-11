#include <iostream>
using namespace std;
int main(){
    int limit = 10;
    for(int i=1;i<=limit;i++){
        for(int j=1;j<=limit;j++){
            if(i==1 || i == limit || j==1 || j==limit || (i==limit/2 && j==limit/2)){
                cout << "* ";
            }else{
                cout << "- ";
            }
        }
        cout << endl;
    }

return 0;
}
