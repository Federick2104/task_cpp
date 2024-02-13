#include <iostream>
#include <fstream>
using namespace std;


struct node {
    int data;
    node* next;
};

void print(node* l) {
    if (l == nullptr) {
        cout << "Empty list" << endl;
        return;
    }

    while (l != nullptr) {
        cout << l->data << " ";
        l = l->next;
    }
    cout << endl;
}

// Scrivere una funzione che data una lista in input
// calcola il massimo della lista
int maxIt(node* lst) {
    if (lst == nullptr) {
        cout << "Empty list" << endl;
        return 0;
    } else if (lst->next == nullptr)
        return lst->data;

    int max = lst->data;
    while (lst != nullptr) {
        if (lst->data > max)
            max = lst->data;
        lst = lst->next;
    }

    return max;
}

int maxRec(node* lst) {
    if (lst == nullptr) {
        cout << "Empty list" << endl;
        return 0;
    } else if (lst->next == nullptr) {
        return lst->data;
    }

    int max = maxRec(lst->next);
    if (max > lst->data)
        return max;
    else
        return lst->data;

}

// Scrivere una funzione che elimini tutti gli elementi di una lista
void deleteList(node* &lst) {
    if (lst == nullptr)
        return;
    while (lst != nullptr) {
        node* tmp = lst;
        lst = lst->next;
        delete tmp;
    }
}

void printRec(node* lst) {
    if (lst == nullptr)
        return;
    cout << lst->data << " ";
    printRec(lst->next);
}


void print_reverse(node* lst) {
    if (lst == nullptr)
        return;
    print_reverse(lst->next);
    cout << lst->data << " ";
}

void removeAtTheBeginning(node* &lst) {
    if (lst == nullptr) {
        cout << "Error: empty list" << endl;
        return;
    }
    node* new_list = lst->next;
    delete lst;
    lst = new_list;
}


// Scrivere una funzione che prende come parametro una lista e
// un elemento e rimuove tutti gli elementi uguali ad e
void rimuovi(node* &lst, int elem) {
    while (lst != nullptr && lst->data == elem)
        removeAtTheBeginning(lst);

    if (lst != nullptr) {
        node* cursor = lst;
        while (cursor != nullptr && cursor->next != nullptr) {
            if (cursor->next->data == elem) {
                node* tmp = cursor->next;
                cursor->next = cursor->next->next;
                delete tmp;
            }
            cursor = cursor->next;
        }
    }
}

void rimuoviRec(node* &lst, int elem) {
    if (lst == nullptr)
        return;
    else if (lst->data == elem) {
        removeAtTheBeginning(lst);
        rimuoviRec(lst, elem);
    } else
        rimuoviRec(lst->next, elem);
}


void sort(node* lst) {
    if (lst == nullptr) {
        return;
    }

    node* cursor = lst;
    while (cursor->next != nullptr) {
        if (cursor->data > cursor->next->data) {
            // swap
            int tmp = cursor->data;
            cursor->data = cursor->next->data;
            cursor->next->data = tmp;
            cursor = lst;
        } else {
            cursor = cursor->next;
        }
    }
}

void addAtTheBeginning(node* &lst, int x) {
    node* new_node = new node;
    new_node->data = x;
    new_node->next = lst;
    lst = new_node;
}

void addAtTheEnd(node* &lst, int x) {
    if (lst == nullptr) {
        addAtTheBeginning(lst, x);
        return;
    }

    node* new_node = new node;
    new_node->data = x;
    new_node->next = nullptr;

    node* cursor = lst;
    while (cursor->next != nullptr)
        cursor = cursor->next;
    cursor->next = new_node;
}

void removeAtTheEnd(node* &lst) {
    if (lst == nullptr) {
        cout << "Error: empty list" << endl;
        return;
    } else if (lst->next == nullptr) {
        removeAtTheBeginning(lst);
        return;
    }

    node* cursor = lst;
    while (cursor->next->next != nullptr)
        cursor = cursor->next;

    delete cursor->next;
    cursor->next = nullptr;
}

int lengthIt(node* lst) {
    if (lst == nullptr)
        return 0;
    int l = 0;
    while (lst != nullptr) {
        l++;
        lst = lst->next;
    }

    return l;
}

int lengthRec(node* lst) {
    if (lst == nullptr)
        return 0;
    else
        return 1 + lengthRec(lst->next);
}


int sumRec(node* lst) {
    if (lst == nullptr)
        return 0;
    else
        return lst->data + sumRec(lst->next);
}

bool equals(node* l1, node* l2) {
    if (l1 == nullptr && l2 == nullptr)
        return true;
    else if (l1 == nullptr && l2 != nullptr)
        return false;
        else if (l1 != nullptr && l2 == nullptr)
        return false;
    else if (l1->data != l2->data)
        return false;
    else
        return equals(l1->next, l2->next);
}

bool containsIt(node* lst, int elem) {
    if (lst == nullptr)
        return false;
    else {
        while (lst != nullptr) {
            if (lst->data == elem)
                return true;
            lst = lst->next;
        }

        return false;
    }
}

bool containsRec(node* lst, int elem) {
    if (lst == nullptr)
        return false;
    else if (lst->data == elem)
        return true;
    else
        return containsRec(lst->next, elem);
}

// Scrivere una funzione concat che concatena la lista l2 a l1
void concat(node* &l1, node* l2) {
    if (l1 == nullptr) {
        l1 = l2;
        return;
    }

    node* cursor = l1;
    while (cursor->next != nullptr)
        cursor = cursor->next;

    cursor->next = l2;
}

node* concat2(node* l1, node* l2) {
    node* result = nullptr;
    while (l1 != nullptr) {
        addAtTheEnd(result, l1->data);
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        addAtTheEnd(result, l2->data);
        l2 = l2->next;
    }

    return result;
}


int* contains(int* A[], int l, int e) {
    for (int i = 0; i < l; i++)
        if (*A[i] == e)
            return A[i];
    return nullptr;
}

int task7() {
    int* A[1000];
    bool first_allocated[1000];
    int n; 
    int cursor = 0;
    int allocated_vars = 0;

    do {
        cout << "Inserire un valore: " << endl;
        cin >> n;

        if (n >= 0) {
            int* previous = contains(A, cursor, n);

            if (previous == nullptr) {
                int* new_var = new int;
                *new_var = n;
                A[cursor] = new_var;
                first_allocated[cursor] = true;
                cursor++; 
                allocated_vars++;
            } else {
                A[cursor] = previous;
                first_allocated[cursor] = false;
                cursor++;
            }
        }

    } while (n >= 0);

    cout << "Allocate " << allocated_vars << " variabili" << endl;;

    for (int i = 0; i < cursor; i++)
        cout << *A[i] << " ";
    cout << endl; 

    for (int i = 0; i < cursor; i++)
        if (first_allocated[i]) {
            cout << "Deallocato " << A[i] << endl;
            delete A[i];
        }

    return 0;
}


/**
 * Scrivere una funzione rotate che prenda in input una lista di
 * numeri interi e esegua una rotaziine singola degli elementi.
 * La rotazione deve spostare l'ultimo elemento della lista nella posizione
 * in testa.
 * 
 * l -> 1 2 3 4 5
 * rotate(l) -> 5 1 2 3 4
 */ 
void rotate(node* &lst) {
    if (lst == nullptr || lst->next == nullptr)
        return;


    node* cursor = lst;
    while (cursor->next->next != nullptr)
        cursor = cursor->next;

    node* tmp = cursor->next;
    cursor->next = nullptr;
    tmp->next = lst;
    lst = tmp;
}

/**
 * scrivere una funzione sublist che prenda come parametri
 * una lista di interi e due indici start e end e restituisca
 * una nuova lista che rappresenta la sottolista fra i due
 * indici (inclusi)
 * 
 * l -> 1 2 3 4 5 6 7 8
 * sl = sublist(l, 2, 5);
 * sl -> 3 4 5 6 
 */

node* sublist(node* lst, int start, int end) {
    if (lst == nullptr 
        || start > end 
        || end > lengthIt(lst) 
        || start > lengthIt(lst)
        || start < 0) {
        cout << "Lista vuota oppure indici invalidi" << endl;
        return nullptr;
    }

    node* cursor = lst;
    int currentIndex = 0;

    while (cursor != nullptr && currentIndex < start) {
        currentIndex++;
        cursor = cursor->next;
    }
    
    node* sl = nullptr;

    while (cursor && currentIndex <= end) {
        addAtTheEnd(sl, cursor->data);
        cursor = cursor->next;
        currentIndex++;
    }
 
    return sl;

}

int lists() {
    node* list = nullptr;
    addAtTheEnd(list, 1);
    addAtTheEnd(list, 2);
    addAtTheEnd(list, 3);
    addAtTheEnd(list, 4);
    addAtTheEnd(list, 5);
    addAtTheEnd(list, 6);
    printRec(list);
    cout << endl;
    rotate(list);
    printRec(list);

    cout << endl;

    printRec(sublist(list, 2, 4));
    return 0;
}

// Leggere la sequenza di interi contenuta in dati.txt
// memorizzarlo in una lista e stampare infine la lista
int streams() {
    ifstream f1;
    f1.open("dati.txt");

    if (f1.fail()) {
        cout << "Impossibile aprire il file" << endl;
        return -1;
    }

    node* list = nullptr;
    int n;
    while (!f1.eof()) {
        f1 >> n;
        addAtTheEnd(list, n);
    }

    printRec(list);


    f1.close();
    return 0;
}


int countSubsequences(int a[], int len, int k) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int partial_sum = 0;
        for (int j = i; j < len; j++) {
            partial_sum += a[j];
            if (partial_sum == k) 
                count++;
        }
    }

    return count;
}


char* revert(char* str) {
    int l = strlen(str);
    char* result = new char[l + 1];

    for (int i = 0; i < l; i++)
        result[i] = str[l - i - 1];

    result[l] = '\0';
    return result;
}

void addAtTheEnd(node* &lst, int x) {
    if (lst == nullptr) {
        addAtTheBeginning(lst, x);
        return;
    }

    node* new_node = new node;
    new_node->data = x;
    new_node->next = nullptr;

    node* cursor = lst;
    while (cursor->next != nullptr)
        cursor = cursor->next;
    cursor->next = new_node;
}

node* f(node* lst) {
    if (lst == nullptr)
        return lst;

    node* result = nullptr;

    while (lst != nullptr) {
        if (lst->data > 0)
            addAtTheEnd(result, list->data)
        lst = lst->next;
    }

    return result;
}

int main() {
    char s[51];
    cin.getline(s, 51, '\n');

    if (cin.fail())
        return -1;

    char* r = revert(s);
    cout << r << endl;
    delete [] r;
    return 0;
}
