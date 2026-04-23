// type casting 
#include <iostream>
using namespace std;
int main(){
    // implicit 
    char grade='A';
    int value=grade;
    cout<<value<<endl;

    // explicit 
    double price =100.99;
    int newP= (int)price;
    cout<<newP;
    return 0;
}