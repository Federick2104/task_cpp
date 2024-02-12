//
// Created by Federico Schianchi on 16/11/23.
//
#include <iostream>
#include <cstring>

using namespace std;

struct Contatto {
    char nome[32];
    char cognome[32];
    char telefono[16];
};

int main(){
    Contatto rubrica[101];
    int counter = 0;
    int op;
    bool failed;

    cout << "*** Rubrica ***" << endl;

    while (true){
        Contatto e{};
        bool a_used;

        cout << "    1 - Visualizza rubrica" << endl;
        cout << "    2 - Inserisci contatto" << endl;
        cout << "    3 - Cancella contatto" << endl;
        cout << "    4 - Esci" << endl;

        do {
            cin >> op;
            failed = cin.fail();
            if (failed)
                cin.clear();
            cin.ignore(5000, '\n');
        } while (failed);

        switch (op) {
            case 1: //Visualizza rubrica
                if(counter == 0 ){
                    cout << "Rubrica vuota!" << endl;
                }else {
                    for (int i = 0; i < counter; i++) {
                        cout << i+1 << "° Contatto | Nome: " << rubrica[i].nome << ", "
                         << "Cognome: " << rubrica[i].cognome << ", "
                         << "Telefono: " << rubrica[i].telefono << endl;
                    }
                }
                break;
            case 2: //Inserisci contatto
                if(counter == 100){
                    cout << "Lista piena! (MAX 100 contatti)" << endl;
                    break;
                }
                do {
                    cout << "Inserisci il nome del contatto da aggiungere: ";
                    cin.getline(e.nome, 32, '\n');
                    failed = cin.fail();
                    if (failed) {
                        cin.clear();
                        cin.ignore(5000, '\n');
                    } else {
                        a_used = false;
                        for (int i = 0; i < counter; i++) {
                            if (strcmp(rubrica[i].nome, e.nome) == 0){
                                cout << "Nome gia' esistente!" << endl;
                                a_used = true;
                            }
                        }
                    }
                } while (failed || a_used);

                do {
                    cout << "Inserisci il cognome del contatto da aggiungere: ";
                    cin >> e.cognome;
                    failed = cin.fail();
                    if (failed)
                        cin.clear();
                    cin.ignore(5000, '\n');
                } while (failed);

                do {
                    cout << "Inserisci il telefono del contatto da aggiungere: ";
                    cin >> e.telefono;
                    failed = cin.fail();
                    if (failed)
                        cin.clear();
                    cin.ignore(5000, '\n');
                } while (failed || strlen(e.telefono) > 13);

                cout << endl << "Contatto aggiunto!" << endl;

                rubrica[counter] = e;
                counter++;
                break;

            case 3: //Cancella contatto
                do {
                    cout << "Inserisci il nome del contatto da cancellare: ";
                    cin >> e.nome;
                    failed = cin.fail();
                    if (failed)
                        cin.clear();
                    cin.ignore(5000, '\n');
                } while (failed);
                do {
                    cout << "Inserisci il cognome del contatto da cancellare: ";
                    cin >> e.cognome;
                    failed = cin.fail();
                    if (failed)
                        cin.clear();
                    cin.ignore(5000, '\n');
                } while (failed);

                int error = 1;
                int i_toremove;
                for (int i = 0; i < counter; i++) {
                    //controllo se contatto esiste
                    if (strcmp(rubrica[i].nome, e.nome) == 0 && strcmp(rubrica[i].cognome, e.cognome) == 0) {
                        error = 0;
                        i_toremove = i;
                        break;
                    }
                }
                if (error == 0){ //cancello contatto e shifto rubrica per riempire lo spazio
                    for (int i = i_toremove; i < counter-1; i++) {
                        rubrica[i] = rubrica[i + 1];
                    }
                    counter--;
                    cout << "Contatto " << e.nome << " " << e.cognome << " cancellato!" << endl;
                } else {
                    cout << "Contatto non trovato!" << endl;
                }
        }
        //Chiudi il programma
        if (op == 4){
            cout << "Addio!";
            break;
        }

    }
    return 0;
}