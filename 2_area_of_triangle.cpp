#include <iostream>

using namespace std;
int main(){
    int num1, num2;
    cout << "Enter first integer: ";
    cin >> num1;
    cout << "Enter second integer: ";
    cin >> num2;

    float area = (num1 * num2) / 2 ;
    cout << "The area of the triangle is: " << area << endl;
}