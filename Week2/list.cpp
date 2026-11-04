#include <bits/stdc++.h>
using namespace std;

int main(){

    list<int> l;

    while(1){

        cout << "\n============= LIST =============\n";
        cout << "1. Them vao dau\n";
        cout << "2. Them vao cuoi\n";
        cout << "3. Xoa dau\n";
        cout << "4. Xoa cuoi\n";
        cout << "5. Duyet xuoi\n";
        cout << "6. Duyet nguoc\n";
        cout << "0. Thoat\n";

        int lc;
        cout << "Nhap lua chon: ";
        cin >> lc;

        if(lc == 1){

            int x;
            cout << "Nhap x: ";
            cin >> x;

            l.push_front(x);
        }

        else if(lc == 2){

            int x;
            cout << "Nhap x: ";
            cin >> x;

            l.push_back(x);
        }

        else if(lc == 3){

            if(!l.empty()){
                l.pop_front();
            }
        }

        else if(lc == 4){

            if(!l.empty()){
                l.pop_back();
            }
        }

        else if(lc == 5){

            cout << "Duyet xuoi: ";

            for(int x : l){
                cout << x << " ";
            }

            cout << endl;
        }

        else if(lc == 6){

            cout << "Duyet nguoc: ";

            for(auto it = l.rbegin(); it != l.rend(); it++){
                cout << *it << " ";
            }

            cout << endl;
        }

        else if(lc == 0){
            break;
        }
    }

    return 0;
}
