#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int a, b, c, d;
    int x, y;
    cout << "Enter A, B, C of quadratic equation";
    cin >> a >> b >> c;
    d = (b*b) - (4*a*c);
    cout << "Discriminant is " << d;
    x = ((-b + sqrt(d))/ 2 * a);
    y = ((-b - sqrt(d))/ 2 * a);
    cout << "\nRoots are " << x << " and " << y;
    return 0;
    // The discriminant is calculated by (b^2) - (4*a*c).

}