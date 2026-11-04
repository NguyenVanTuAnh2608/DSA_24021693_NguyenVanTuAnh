#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

// Tao node
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Dem so phan tu
int Size(node a){
    int cnt = 0;
    while(a != NULL){
        a = a->next;
        cnt++;
    }
    return cnt;
}

// Them vao dau
void insertFirst(node &a, int x){
    node tmp = makeNode(x);

    if(a == NULL){
        a = tmp;
    }
    else{
        tmp->next = a;
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
    }
}

// Them vao vi tri k
void insertMiddle(node &a, int x, int k){
    int n = Size(a);

    if(k <= 0 || k > n + 1){
        cout << "Vi tri khong hop le\n";
        return;
    }

    if(k == 1){
        insertFirst(a, x);
        return;
    }

    if(k == n + 1){
        insertLast(a, x);
        return;
    }

    node p = a;

    for(int i = 1; i < k - 1; i++){
        p = p->next;
    }

    node tmp = makeNode(x);

    tmp->next = p->next;
    p->next = tmp;
}

// Xoa dau
void deleteFirst(node &a){
    if(a == NULL){
        return;
    }

    a = a->next;
}

// Xoa cuoi
void deleteLast(node &a){
    if(a == NULL){
        return;
    }

    node truoc = NULL;
    node sau = a;

    while(sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }

    if(truoc == NULL){
        a = NULL;
    }
    else{
        truoc->next = NULL;
    }
}

// Xoa tai vi tri k
void deleteMiddle(node &a, int k){
    if(k <= 0 || k > Size(a)){
        return;
    }

    node truoc = NULL;
    node sau = a;

    for(int i = 1; i < k; i++){
        truoc = sau;
        sau = sau->next;
    }

    if(truoc == NULL){
        a = a->next;
    }
    else{
        truoc->next = sau->next;
    }
}

// Duyet xuoi
void in(node a){
    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }

    cout << endl;
}

// Duyet nguoc
void inNguoc(node a){
    if(a == NULL){
        return;
    }

    inNguoc(a->next);
    cout << a->data << " ";
}

int main(){

    node head = NULL;

    while(1){

        cout << "\n========== LINKED LIST ==========\n";
        cout << "1. Chen vao dau\n";
        cout << "2. Chen vao cuoi\n";
        cout << "3. Chen vao vi tri\n";
        cout << "4. Xoa dau\n";
        cout << "5. Xoa cuoi\n";
        cout << "6. Xoa vi tri\n";
        cout << "7. Duyet xuoi\n";
        cout << "8. Duyet nguoc\n";
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
            int x, k;
            cout << "Nhap x: ";
            cin >> x;
            cout << "Nhap vi tri: ";
            cin >> k;
            insertMiddle(head, x, k);
        }

        else if(lc == 4){
            deleteFirst(head);
        }

        else if(lc == 5){
            deleteLast(head);
        }

        else if(lc == 6){
            int k;
            cout << "Nhap vi tri can xoa: ";
            cin >> k;
            deleteMiddle(head, k);
        }

        else if(lc == 7){
            cout << "Duyet xuoi: ";
            in(head);
        }

        else if(lc == 8){
            cout << "Duyet nguoc: ";
            inNguoc(head);
            cout << endl;
        }

        else if(lc == 0){
            break;
        }
    }

    return 0;
}
