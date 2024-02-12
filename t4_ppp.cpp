//
// Created by Federico Schianchi on 07/11/23.
//
#include <iostream>
#include <cstring>
#define MAX_L 101
using namespace std;

int main(){
    char a[MAX_L];
    char b[MAX_L];

    while (true){
        cout << "Inserire la prima parola: " ;
        cin.getline(a, MAX_L);
        if (a[0] == '$'){
            cout << "Addio!";
            break;
        }
        cout << "Inserire la seconda parola: ";
        cin.getline(b, MAX_L);
        if (b[0] == '$'){
            cout << "Addio!";
            break;
        }
        //uguali
        if (strcmp(a,b) == 0){
            cout << "Le due parole sono uguali." << endl << "Reverse: ";
            for (int i = strlen(a); i > 0 ;i--)
                cout << a[i-1];
            cout << endl << endl;

        } else if ( strstr(a,b) != a + strlen(a)  || strstr(b,a) != b + strlen(b) ){
            if (strlen(a) > strlen(b)){
                //prefisso
                int count_p1 = 0, count_s1 = 0;
                for(int i = 0; i < strlen(b); i++)
                    (a[i] == b[i]) ? count_p1++ : count_p1 += 0;
                if (count_p1 == strlen(b))
                    cout << "La parola " << b << " e' prefisso di " << a << endl << endl;

                //suffisso
                int len_b = strlen(b)-1;
                for(int i = strlen(a); i > 0; i--){
                    (a[i-1] == b[len_b]) ? count_s1++ : count_s1+=0;
                    len_b--;
                }
                if (count_s1 == strlen(b))
                    cout << "La parola " << b << " e' suffisso di " << a << endl << endl;
            }
            else{
                //prefisso
                int count_p2 = 0, count_s2 = 0;
                for(int i = 0; i < strlen(a); i++)
                    (a[i] == b[i]) ? count_p2++ : count_p2 += 0;
                if (count_p2 == strlen(a))
                    cout << "La parola " << a << " e' prefisso di " << b << endl << endl;

                //suffisso
                int len_a = strlen(a)-1;
                for(int i = strlen(b); i > 0; i--){
                    (b[i-1] == a[len_a]) ? count_s2++ : count_s2+=0;
                    len_a--;
                }
                if (count_s2 == strlen(a))
                    cout << "La parola " << a << " e' suffisso di " << b << endl << endl;
            }
        } else
            cout << endl << endl;
    }
return 0;
}