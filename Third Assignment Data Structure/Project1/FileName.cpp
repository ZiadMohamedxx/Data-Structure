#include <iostream>
using namespace std;

void main() {
    int x = 4;
    int y = 14;
    int i = 2;
    int k = 30;
    int a;
    while (x == 4) {
        if (k > i) {
            for (a = k; a >= y; a -= 5) {
                cout << a << endl;
                cout << x + a << endl;
            }
            k -= a;
        }
        else if (k < i) {
            for (a = 1; a <= 2; a++) {
                cout << a << endl;
                k += a;
                i++;
            }
        }
        else {
            cout << i << endl;
            break;
        }
    }
   
}