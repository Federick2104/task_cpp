//
// Created by Federico Schianchi on 11/10/23.
//

#include <iostream>
using namespace std;

int main (){
    char x, y, z;
    cout << "Inserire tre caratteri: " << endl;
    cin >> x >> y >> z;

/*
    (x > 96 && x < 123) ? ( ((x += 3) > 122) ? (x-=122)+=96 : x *=1 ) : x = 42;
    (y > 96 && y < 123) ? ( ((y += 3) > 122) ? (y-=122)+=96 : y *=1 ) : y = 42;
    (z > 96 && z < 123) ? ( ((z += 3) > 122) ? (z-=122)+=96 : z *=1 ) : z = 42;
*/

    if (x > 96 && x < 123) {
        x += 3;
        if (x > 122) {
            x -= 122;
            x += 96;
        } else {
            x *= 1;
        }
    } else x = 42;

    if (y > 96 && y < 123) {
        y += 3;
        if (y > 122) {
            y -= 122;
            y += 96;
        } else {
            y *= 1;
        }
    } else
        y = 42;

    if (z > 96 && z < 123) {
        z += 3;
        if (z > 122) {
            z -= 122;
            z += 96;
        } else {
            z *= 1;
        }
    } else
        z = 42;

    cout << "Cifrario di cesare: " << x << " " << y << " " << z << endl;

}


