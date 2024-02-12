//
// Created by Federico Schianchi on 19/10/23.
//
#include <iostream>
using namespace std;

int main() {
    int h;
    do {
        cout << "Inserire un valore intero (> 0): " << endl;
        cin >> h;
        if (h <= 0)
            cout << "Input errato." << endl;
    } while(h <= 0);

    for (int riga = 0; riga < 2*h-1; riga++) {
        for (int cln = 0; cln < h; cln++) {
            if (riga < h) {
                if (riga + cln < h-1)
                    cout << "   ";
                else
                    cout << " * ";
            } else {
                if (riga - cln <= h-1)
                    cout << " * ";
                else
                    cout << "   ";
            }
        }
        cout << endl;
    }
    return 0;
}
