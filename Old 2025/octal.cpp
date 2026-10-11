#include <iostream>
using namespace std;

string convertDecimalToBinary(int givenDecimal){
    int bitValue = 1;
    string result = "";
    //12
    while(bitValue<=givenDecimal){
        bitValue*=2;
    }
    bitValue/=2;
    while(bitValue!=0){
        if(givenDecimal>=bitValue){
            result+='1';
            givenDecimal-=bitValue;
        }else{
            result+='0';
        }
        bitValue/=2;
    }
    return result;
}

bool isValidDecimal(string givenDecimal){
    for(int i=0;i<givenDecimal.length();i++){
        if(isalpha(givenDecimal[i])){
            return false;
        }
    }
    return true;
}

void runDecimalToBinaryConversion(){
    cout << "Enter your number " << endl;
    string decimal;
    cin >> decimal;
    while(!isValidDecimal(decimal)){
        cout << "That is not a valid number " << endl;
        cin >> decimal;
    }
    string binaryResult = convertDecimalToBinary(stoi(decimal));
    cout << "Binary Result: " << binaryResult << endl;
}

char getCharacterEquivalent(int givenDecimal){
    char result;
   switch(givenDecimal){
    case 10: result = 'A';break;
    case 11: result = 'B';break;
    case 12: result = 'C';break;
    case 13: result = 'D';break;
    case 14: result = 'E';break;
    case 15: result = 'F';break;
    default : result = givenDecimal + '0';
   }
   return result;
}
int convertBinaryToDecimal(string givenBinary){
    cout << "binary to convert " << givenBinary << endl;
    int result = 0;
    int bitValue = 1;
    for(int i=givenBinary.length()-1;i>=0;i--){
        if(givenBinary[i] == '1'){
            result+=bitValue;
        }
        bitValue*=2;
    }

    return result;
}
string convertBinaryToOctal(string givenBinary,int limit){
    string result = "";
    //int limit = 3;
    //get arraycontainer size
    int quotient= givenBinary.length()/limit;
    int modulo = givenBinary.length()%limit;
    int arraySize = quotient + modulo;
    string arrayContainer[arraySize];
    int arrayIndex = arraySize-1;
    //loop through givenBinary in reverse and insert each bit to the array Container so we can split them
    for(int i=givenBinary.length()-1;i>=0;i--){
        if(arrayContainer[arrayIndex].length()==limit){
            arrayIndex--;
            arrayContainer[arrayIndex]+=givenBinary[i];
        }else{
            arrayContainer[arrayIndex]+=givenBinary[i];
        }
    }

    //loop through container
    for(int i=0;i<arraySize;i++){
            cout << arrayContainer[i] << " length is " <<arrayContainer[i].length() << endl;
        //pad zeroes to indexes not reaching length limit
        if(arrayContainer[i].length()!=limit){
            int neededZeroes=limit - arrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                arrayContainer[i]+='0';
            }
        }

        //reverse the positions of the bits in each array index in the container
        string temp = "";
        for(int k=arrayContainer[i].length()-1;k>=0;k--){
            temp+=arrayContainer[i][k];
        }
        arrayContainer[i] = temp;

        //convert each binary to decimal
        int decimalValue = convertBinaryToDecimal(arrayContainer[i]);
        cout << "decimalValue " << decimalValue << endl;
        //get characterEquivalent
        char charValue = getCharacterEquivalent(decimalValue);
        cout << "characterValue " << charValue << endl;
        result+=charValue;
    }
    return result;
}
void runApplication(){
    string octalResult = convertBinaryToOctal("11111100",3);
    cout <<"octal Result : " << octalResult<<endl;

}
int main(){
    //runApplication();
    runDecimalToBinaryConversion();
    return 0;
}
