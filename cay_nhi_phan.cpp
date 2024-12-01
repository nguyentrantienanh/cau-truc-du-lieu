#include<iostream>
using namespace std;

// khai báo cấu trúc 1 cái node
struct node
{
    int data; // dữ liệu của node ==> dữ liệu mà node sẽ lưu trữ 
    node *pLeft; // node bên trái của cây <=> cây con trái 
    node *pRight; // node bên phải cửa cây <=> cây con phải 
};
typedef struct node NODE;
typedef NODE* TREE;

// khởi tạo cây
void khoitaocay(TREE &t)
{
    t = NULL; // cây rỗng
}

// hàm thêm phần tử x vào cây nhị phân
void themnodevaocay(TREE &t, int x)
{
    // nếu cây rỗng 
    if (t == NULL )
    {
        NODE  *p = new NODE; // khởi tạo 1 cái node để thêm vào cây 
        p -> data = x; // thêm dữ liệu x vào data
        p -> pLeft = NULL;
        p -> pRight = NULL;
        t = p;// node p chính là code gốc <=> x chính là node gốc 
    }
    else // cây có tồn tại phần tử
    {
        // nếu phần tử thêm vào mà nhỏ hơn node gốc ==> thêm nó vào bên trái
        if (t -> data > x)
        {
            themnodevaocay(t->pLeft, x); // duyệt qua trái để thêm phần tử xx
        }
        else if (t->data < x)// nếu phần tử thêm vào mà lớn hơn node gốc ==> theem nó vào bên phải
        {
            themnodevaocay(t->pRight, x); // duyệt qua phải để thêm phần tử xx
        }
    }
}
// hàm xuất cây ngị phân theo nlr
void duyet_NLR(TREE t)
{
    //nếu cây còn phần tử thì tiếp tục duyệt 
    if (t != NULL)
    {
        cout << t-> data << " "; // xuất dữ liệu trong nodenode
        duyet_NLR(t->pLeft); // duyệt qua trái
        duyet_NLR(t->pRight);// duyệt qua phải
    }
}
// hàm xuất theo nhị phân theo nrl
void duyet_NRL(TREE t)
{
    //nếu cây còn phần tử thì tiếp tục duyệt 
    if (t != NULL)
    {
        cout << t-> data << " "; // xuất dữ liệu trong node
        duyet_NRL(t->pRight);// duyệt qua phải
        duyet_NRL(t->pLeft); // duyệt qua trái
         
    }
}
void TaoMang(int* arr, int n, int chosen){
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == chosen) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = chosen;
    }
}
// hàm nhập dữ liệu
void Menu(TREE &t)
{
    while (true)
     {
        cout<< "\n\n\t\t ====MENu=====";
        cout<< "\n1. Nhập dữ liệu \n";
        cout<< "\n2. xuat du lieu theo nlr";
        cout<< "\n3. xuất dữ liệu theo nrl";
        cout<< "\n0. ket thuc\n";
        cout<< "\n\n\t\t ============";
       
       
        int luachon;

        cout<< "\n Nhập lựa chọn:  ";
        cin >> luachon;
        if (luachon < 0 || luachon > 3)
        {
            cout << "\n Lựa chọn  không hợp lệ";
            system("pause");
        }
        else if (luachon ==1)
        {
            int n;
            cout << "\nTao so nut co trong cay: ";
            cin >> n;

            int* arr = new int[n];
            cout << "\nNhap cac nut cua cay: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }

            int chosen;
            cout << "\nNhap so de lam root: ";
            cin >> chosen;
            TaoMang(arr, n, chosen);

            for (int i = 0; i < n; i++) {
                themnodevaocay(t, arr[i]);
    }
        }
        else if (luachon == 2)
        { 
        cout << "\n\t\t DUYET CAY THEO NLR\n ";
        duyet_NLR(t);
        }
        else if (luachon == 3)
        {
        cout<< "\n\t\t DUYET CAY THEO NRL\n";
        duyet_NRL(t);
        }
        else
        { 
            break;
        }
     }
}


int main()
{
    TREE t;
    khoitaocay(t);
    Menu(t);
    system("pause");
    return 0;
}