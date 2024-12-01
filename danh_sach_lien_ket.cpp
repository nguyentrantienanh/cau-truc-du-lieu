#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

typedef struct Node* node;
// cap nhat mot node moi vao du lieu 
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;// co the su su nullptr thay Null
    return tmp;
}

//kiem tra rong
bool empty(node a){
    return a == NULL;
}


// danh sach co bao nhieu phan tu
int size(node a){
    int cnt = 0;
    while(a != NULL){// neu a khac null
        ++cnt;
        a = a->next; // gan dia chi cho node tiep theo cho node hien tai
        // cho node hien tai cho node tiep theo
    }
    return cnt;
}

//them 1 phan tu vao dau danh sach lien ket
void insertfirst(node &a, int x){
    node tmp = makeNode(x);
    if (a == NULL){
        a = tmp;
    }
    else{
        tmp->next = a;
        a = tmp;
    }
}

// them  1 phan tu cuoi danh sach lien ket 
void insertlast(node &a, int x){
    node tmp = makeNode(x);
    if (a == NULL){
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

// them 1 phan tu vao giua dslk
void insertmiddle(node &a, int x, int pos){
    int n = size(a);
    if (pos <= 0 || pos > n + 1){
        cout << "vi tri chen khong hop le! \n ";
    }
    if(n == 1){
        insertfirst(a, x); return;
    }
    else if (n == pos + 1){
        insertlast(a, x); return;
    }
    node p = a;
    for(int i = 1; i < pos - 1; i++){
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
    }

// xoa phan tu o dau
void deletefirst( node &a){
    if(a == NULL) return;
    a = a->next;
}

// xoa phan tu o cuoi 
void deletelast(node &a){
    if(a == NULL) return;
    node truoc = NULL, sau = a;
    while (sau->next != NULL){
        truoc = sau;
        sau = truoc->next;
    }
    if(truoc == NULL){
        a = NULL;
    }
    else{
        truoc->next =NULL;
    }
}

// xoa phan tu o giua
void deletemiddle(node &a, int pos){
    if( pos <= 0 || pos > size(a)) return; //  nghĩa là nếu pos nhở hơn 0 hoặc lớn hơn size a thì hàm sẽ kết thúc
    node truoc = NULL, sau = a;
    for(int i = 1; i < pos; i++){
        truoc = sau;
        sau = sau->next;
    }
    if( truoc == NULL){
        a = a->next;
    }
    else{
        truoc->next = sau->next;
    }
}

void in(node a){
    cout <<"-------------\n";
    while (a != NULL){
        cout << a->data << " ";
        a = a->next;
    }
    cout <<"-----------\n";
}

void sapxep(node &a){
   for (node p = a; p->next != NULL; p = p->next){
    node min = p;
    for (node q  = p->next; q != NULL; q = q->next){
        if(q->data < min->data){
            min = q;
        }
    }
    int tmp = min->data;
    min->data = p->data;
    p->data = tmp;
   }
    
}


int main(){
    node head = NULL;
    while(1){
        cout << "1. chen phan tu dau trong danh sanh\n";
        cout << "2. chen phan tu cuoi trong danh sach\n";
        cout << "3. chen phan tu giua trong danh sach\n";
        cout << "4. xoa phan tu dau trong danh sach \n";
        cout << "5. xoa phan tu cuoi trong danh sach\n";
        cout << "6. xoa phan tu giu trong danh sach\n";
        cout << "7. duyet danh sach lien ket\n";
        cout << "-------------------------------\n";
        cout << "nhap lua chon";
        int lc; cin >> lc;
        if(lc == 1){
            int x; cout <<"nhap gai tri can chen: "; cin >> x;
            insertfirst(head, x);
        }
        else if(lc == 2){
            int x; cout <<"nhap gai tri can chen: "; cin >> x;
            insertlast(head, x);
        }
        else if(lc == 3){
            int x; cout << "nhap gia tri can chen: "; cin >> x;
            int pos; cout << "nhap vi tri can chen: "; cin >> pos;
            insertmiddle(head, x, pos);
        }
        else if(lc == 4){
            deletefirst(head);
        }
        else if(lc == 5){
            deletelast(head);
        }
        else if(lc == 6){
            int pos; cout << "nhap vi tri can xoa: "; cin >> pos;
            deletemiddle(head, pos);
        }
        else if(lc == 7){
            in(head);
        }
    }
    return 0;
}