//
// Created by Federico Schianchi on 28/11/23.
//
#include <iostream>
#define max_l 1000

using namespace std;

int main(){

    int x = 0, all = 0, counter = 0;
    int* arrA[max_l] = {};
    int* memory[max_l] = {};

    while(true) {
        cout << "Inserire un numero: ";
        cin >> x;
        if (x <= 0)
            break;

        bool presente = false;
        for(int i = 0; i < counter; i++){
            if(*arrA[i] == x){
                arrA[counter] = arrA[i];
                counter++;
                presente = true;
                break;
            }
        }
        if(!presente){
            arrA[counter] = new int(x);
            memory[all] = arrA[counter];
            all++;
            counter++;
        }
    }

    //test: 4 5 4 4 3 2 2 4 6 7

    cout << "Allocate " << all << " variabili." << endl;

    for(int i = 0; i < counter; i++){
        cout << *arrA[i] << "  ";
    }

    //delete memeory allocata
    for (int i = 0; i < all; ++i) {
        delete memory[i];
    }

   return 0;
}