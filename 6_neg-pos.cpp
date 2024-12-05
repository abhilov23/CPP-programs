#include <iostream>
using namespace std;

int main(){
    int n1;
    cout << "enter the number:";
    cin >> n1;
    if (n1 > 0){
        cout << n1 << "is positive";
    }
    else if (n1 < 0){
        cout << n1 << " is negative";
    }
}