#include <iostream>
using namespace std;
//  bubble sort:Thuật toán sắp xếp nổi bọt
int main()
{
  int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    int arr[n];
    cout << "Nhap cac phan tu cua mang: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = n - 1; i > 0; i--) // vòng lặp i chạy (n - 1) đến 1
    {
        for (int j = 0; j < i; j++) // vòng lặp j chạy từ 0 đến i - 1
        {
            if (arr[j] > arr[j + 1]) // hàm đổi giá trị (vd: j = 6 và j + 1 = 5)
            {
                int kq = arr[j];  // kq = j là lưu kq = 6 
                arr[j] = arr[j + 1]; // j = j+1 là lưu j = 5
                arr[j + 1]= kq; // (kq = 6) giờ lấy j + 1 = kq thành j+1 = 6
            }  // tổng hàm xong ta có j = 5 và j + 1 = 6 đã đổi giá trị
        }

    }

    for(int i = 0; i < n;i++) 
    {
        cout<< arr[i] << " "; // hàm in ra kq
    }
    return 0;
}