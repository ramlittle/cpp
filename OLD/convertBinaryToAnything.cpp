#include <iostream>
using namespace std;

int convertBinaryToDecimal(string binaryGiven){
    int decimalResult = 0;
    int binaryValue = 1;
    //reverse the binary given
    for(int i=binaryGiven.length()-1;i>=0;i--){
        //add the binValue to decimaloutput if each element is equal to 1
        if(binaryGiven[i]=='1'){
            decimalResult += binaryValue;
        }
        binaryValue*=2;
    }
    return decimalResult;
}

string convertBinaryToOctal(string binaryGiven){

    //determine length of array to use
    int quotientResult = binaryGiven.length()/3;
    int modulosResult = binaryGiven.length()%3;
    int arrayLength = quotientResult+modulosResult;
    cout << "array length " << arrayLength << endl;
    string container[arrayLength];

    /*
        split the givenBinary into 3 elements by
        looping through the binaryGiven in reverse
        insert each binary character to each of the container element
        proceed to the next container element when the container element length reaches 3
    */

    int containerIndex = 0;

    for(int i=binaryGiven.length()-1;i>=0;i--){
        if(container[containerIndex].length() == 2){
            container[containerIndex]+=binaryGiven[i];
            containerIndex++;
        }else{
            container[containerIndex]+=binaryGiven[i];
        }
    }



    cout << "result: " << endl;
    //loop through each element
    for(int i=0;i<arrayLength;i++){
        //make sure each element length is 3, if not add zeroes infront
        if(container[i].length() != 3){
            int neededZeroes = 3-container[i].length();
            string completedBinary = container[i];
            for(int z=1;z<=neededZeroes;z++){
                completedBinary += "0";
            }
            container[i] = completedBinary;
            cout << " completed Binary is " << completedBinary << endl;
        }

        //then return each character in each container elment to its original position
        string fixedBinaryPosition = "";
        for(int j=container[i].length()-1;j>=0;j--){
            fixedBinaryPosition+=container[i][j];
        }
        container[i] = fixedBinaryPosition;
        cout << " index " << i << " value = " << container[i] << endl;
    }

    //finally in reverse, convert the splitted binary using the function convertToDecimal
    string octalResult="";
    for(int i=arrayLength-1;i>=0;i--){
        //then concatenate each result to one string output
        octalResult+=to_string(convertBinaryToDecimal(container[i]));
    }
    cout << "FINAL " << octalResult << endl;

    return octalResult;
}


int main(){
    string binaryGiven;

    while(binaryGiven!="0"){
        cout << "enter binary " << endl;
        getline(cin,binaryGiven);
        cout << "Result is :" << convertBinaryToOctal(binaryGiven) << endl;

    };


return 0;
}
