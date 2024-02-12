//
// Created by Federico Schianchi on 04/11/23.
//
#define  MAX_BIT 4
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int bit[MAX_BIT];
    int ope;
    int dec = 0;

    for (int i = 3; i > -1; i--) {
        while (bit[i] != 0 || bit[i] != 1) {
            cout << "Inserisci bit nella posizione " << i << ": ";
            cin >> bit[i];
            if (bit[i] == 0 || bit[i] == 1)
                break;
            else
                cout << "Errore!" << endl;
        }
    }
    cout << "Operazione:" << endl << "     0 - Stampa binario: " << endl
    << "     1 - Converti in decimale: " << endl << "     2 - Calcola opposto: " << endl;
    do{
        cin >> ope;
        if (ope < 0 || ope > 2)
            cout << "Errore!" << endl;
    }while (ope < 0 || ope > 2);

    switch (ope) {
        case 0:
            cout << "Numero binario: " << bit[3] << bit[2] << bit[1] << bit[0] << endl;
            break;
        case 1:
            for(int j = 2; j > -1; j--)
                (bit[j] == 1) ? dec += pow(2,j) : dec += 0;
            (bit[3] == 1) ? dec = pow(2,3)*-1 + dec : dec += 0;
            cout << "Numero decimale: " << dec;
            break;
        case 2:
            for(int j = 2; j > -1; j--)
                (bit[j] == 1) ? dec += pow(2,j) : dec += 0;
            (bit[3] == 1) ? dec = pow(2,3)*-1 + dec : dec += 0;
            dec *= -1;

            if (abs(dec) == 8) {  //Overflow
                cout << "Overflow!" << endl;
                break;
            } else if (dec > 0){  //caso > 0
                for(int i = 0; i < 4; i++){
                    bit[i] = dec%2;
                    dec = dec/2;
                }
            } else {    //caso < 0
                for(int i = 0; i < 4; i++){
                    bit[i] = dec%2;
                    dec = dec/2;
                }
                for (int i = 0; i < 4; i++)  //gestione del riporto
                    (bit[i] == 0) ? bit[i] = 1 : bit[i] = 0;
                if (bit[0] == 0) //caso in cui il bit 0 valga 0
                    bit[0] = 1;
                else {  //caso in cui il bit 0 valga 1
                    int r = 1;
                    for(int i = 0; i <= 3; i++){
                        int s = bit[i]+r;
                        if (s == 2){
                            bit[i] = 0;
                            r = 1;
                        } else{
                            bit[i] = s;
                            r = 0;
                        }
                    }
                }
            }
            cout << "Opposto: " << bit[3] << bit[2] << bit[1] << bit[0] <<  endl;
            break;
    }
    return 0;
}
