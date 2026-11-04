#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

typedef struct Node* node;

// Tao node
node makeNode(int x){

    node tmp = new Node();

    tmp->data = x;
    tmp->prev = NULL;
    tmp->next = NULL;

    return tmp;
}

// Them vao dau
void insertFirst(node &a, int x){

    node tmp = makeNode(x);

    if(a == NULL){
        a = tmp;
    }
    else{
        tmp->next = a;
        a->prev = tmp;
        a = tmp;
    }
}

// Them vao cuoi
void insertLast(node &a, int x){

    node tmp = makeNode(x);

    if(a == NULL){
        a = tmp;
    }
    else{

        node p = a;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = tmp;
        tmp->prev = p;
    }
}

// Duyet xuoi
void inForward(node a){

    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }

    cout << endl;
}

// Tim node cuoi
node getLast(node a){

    if(a == NULL){
        return NULL;
    }

    node p = a;

    while(p->next != NULL){
        p = p->next;
    }

    return p;
}

// Duyet nguoc
void inBackward(node a){

    node p = getLast(a);

    while(p != NULL){
        cout << p->data << " ";
        p = p->prev;
    }

    cout << endl;
}

int main(){

    node head = NULL;

    while(1){

        cout << "\n====== DOUBLY LINKED LIST ======\n";
        cout << "1. Them vao dau\n";
        cout << "2. Them vao cuoi\n";
        cout << "3. Duyet xuoi\n";
        cout << "4. Duyet nguoc\n";
        cout << "0. Thoat\n";

        int lc;
        cout << "Nhap lua chon: ";
        cin >> lc;

        if(lc == 1){

            int x;
            cout << "Nhap x: ";
            cin >> x;

            insertFirst(head, x);
        }

        else if(lc == 2){

            int x;
            cout << "Nhap x: ";
            cin >> x;

            insertLast(head, x);
        }

        else if(lc == 3){

            cout << "Duyet xuoi: ";
            inForward(head);
        }

        else if(lc == 4){

            cout << "Duyet nguoc: ";
            inBackward(head);
        }

        else if(lc == 0){
            break;
        }
    }

    return 0;
}
