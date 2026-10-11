/*
    Author: Ramelito N. Martinez
    Purpose: Mock Exam for EDPSE

*/

#include <iostream>
using namespace std;

void showDivider(){
    cout << "==============================";
}

void runApplication(){
    showDivider();
    showAuthor();
    showDivider();
    showMenu();
}

int main(){
    runApplication();
return 0;
}
