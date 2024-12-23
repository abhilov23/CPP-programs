#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string str = "Abhilov";
    int j = 0;

    for (int i = 0; i < str.length(); i++)
    {
        j++;
    }
    cout << " " << j;
    return 0;
}