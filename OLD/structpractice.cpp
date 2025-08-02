#include <iostream>
using namespace std;


struct PersonInfo{
    string name;
    int age;
};

int main(){
    int empCount =3;
    PersonInfo ICTEmployees[empCount];

    ICTEmployees[0].name = "Ram";
    ICTEmployees[0].age = 123;
    ICTEmployees[1].name = "Sam";
    ICTEmployees[1].age = 123;
    ICTEmployees[2].name = "Kam";
    ICTEmployees[2].age = 123;


    string headerCol1 = "EMPLOYEE NAME";
    string headerCol2 = "EMPLOYEE AGE";
    cout << headerCol1 << "\t" << headerCol2 << endl;

    for(int i=0;i<empCount;i++){
        cout << ICTEmployees[i].name << "\t" << ICTEmployees[i].age << endl;
    }
return 0;
}
