#include <iostream>
using namespace std;

struct MyObject{
    string name;
    int age;
};

void showDivider(){
    cout << "============================" << endl;
}
void showAppTitle(){
    cout << "Title: Practice Struct, Array Object, and Bubble Sort" << endl;
}
void showAuthor(){
    string author = "Ramelito Martinez";
    string purpose = "EDPSE Exam Practice";
    cout << "Author: " << author << endl;
    cout << "Purpose: " << purpose << endl;
}
void runApplication(){
    showDivider();
    showAppTitle();
    showAuthor();
    showDivider();
}
int main(){
    runApplication();
return 0;
}
