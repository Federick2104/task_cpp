//
// Created by Federico Schianchi on 22/11/23.
//
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void separa(char s[], char alpha[], char num[], int& a, int&n){
    for(int i = 0; i < strlen(s); i++ ){
        if(isalpha(s[i])){
            alpha[a] = s[i];
            a++;
        } else if(isdigit(s[i])){
            num[n] = s[i];
            n++;
        }else{
            continue;
        }
    }
}

int main(){
    char str[101];
    int a;
    int n;
    char SAlpha[101];
    char SNum[101];

    cout << "Inserisci una stringa (MAX 100 char): ";
    cin.getline(str, 101);

    separa(str, SAlpha, SNum, a, n);

    cout << "Caratteri alfabetici" << endl;
    for(int i = 0; i < a; i++){
        cout << SAlpha[i] << " ";
    }
    cout << endl;

    cout << "Caratteri numerici" << endl;
    for(int i = 0; i < n; i++){
        cout << SNum[i] << " ";
    }
    return 0;
}