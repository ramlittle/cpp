#include <iostream>
#include <fstream>
using namespace std;

string convertToBinary(int decimalNumber){
    string binaryResult="";
    //determine maximum binValue to use
    int binValue=1;
    while(binValue<=decimalNumber){
        binValue*=2;
    }
    //converto to binary
    while(binValue!=0){
        if(decimalNumber >= binValue){
            binaryResult+="1";
            decimalNumber-=binValue;
        }else{
            binaryResult+="0";
            //remove created front zero
            if(binaryResult[0]=='0'){
                binaryResult="";
            }
        }
        binValue/=2;
    }
    return binaryResult;
}

int determineDecimalValueOfEachHexCharacter(char singleHexGiven){
    int decimalValue = 0;
    switch(singleHexGiven){
        case 'A': decimalValue=10; break;
        case 'B': decimalValue=11; break;
        case 'C': decimalValue=12; break;
        case 'D': decimalValue=13; break;
        case 'E': decimalValue=14; break;
        case 'F': decimalValue=15; break;
        default: decimalValue=singleHexGiven-'0'; // convert each character to single character integer
    }
    return decimalValue;
}

string convertHexToBinary(string hexGiven){
    //given : A2

    /*
        convert each splitted to binary
        while making sure each result will have 4 length
        concat each result to the string result
    */
    string completeBinaryResult = "";
    for(int i=0;i<hexGiven.length();i++){
        int eachDecimalValue = determineDecimalValueOfEachHexCharacter(hexGiven[i]);
        string binaryEquivalent=convertToBinary(eachDecimalValue);
        if(binaryEquivalent.length()< 4){
            int neededZeroes = 4-binaryEquivalent.length();
            string temp = binaryEquivalent;
            binaryEquivalent = "";
            for(int j=1;j<=neededZeroes;j++){
                binaryEquivalent+='0';
            }
            binaryEquivalent+=temp;
        }
        cout << binaryEquivalent << endl;
        completeBinaryResult+=binaryEquivalent;
    }
    return completeBinaryResult;
}

void writeToFile(string hexGiven, string result){
    //prepare file
    ofstream resultWriting;
    resultWriting.open("result.txt");

    if(!resultWriting.is_open()){
        cout << "failed to create saved result" << endl;
        return;
    }
    //process the file
    resultWriting << "HEX TO BINARY APP " << endl;
    resultWriting << "GIVEN IS " << hexGiven << endl;
    resultWriting << "RESULT: " << result << endl;

    //close the file
    cout << "result saved to result.txt";
    resultWriting.close();
}

int main(){
    string hex;
    cout << "provide Hex " << endl;
    cin >> hex;
    string result = convertHexToBinary(hex);
    cout << result << endl;
    writeToFile(hex,result);
return 0;
}
