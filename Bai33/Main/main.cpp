
#include "../Source/CayBST.h"
#include "../Source/CongViecTrongNgay.h"
#include "../Source/NodeBST.h"
#include <iostream>

using namespace std;

int main()
{
    CayBST *BST = new CayBST;
    int lc;
    do
    {
        system("cls");
        cout << "-------------------------MENU------------------------\n";
        cout << "| 1. Nhap Noi Dung Can Lam Theo Ngay,Theo Gio.      |";
        cout << "\n| 2. Xem Lich Cong Tac Theo Ngay.                   |";
        cout << "\n| 3. Duyet Tat Ca Danh Sach Cac Cong Viec.          |";
        cout << "\n| 4. xem lich cong tac theo tinh chat cong viec.    |";
        cout << "\n| 5. Nhap Cac Cong Viec Da Hoan Thanh.              |";
        cout << "\n| 6. In Cac Cong Viec Da Hoan Thanh.                |";
        cout << "\n| 7. xem Cac Cong Viec Chua Thuc Hien.              |";
        cout << "\n| 8. Xem Cac Cong Viec Tu Ngay a Den Ngay b.        |";
        cout << "\n| 9. Dieu Chinh Lich Cong Tac.                      |";
        cout << "\n| 10. Thoat!.                                       |";
        cout << "\n-----------------------------------------------------\n";
        cout << "\n. Chon chuc nang tu 1..10.";
        int n;
        cout << "\nNhap lua chon:";
        cin >> n;
        cin.ignore();
        lc = n;
        system("cls");
        switch (n)
        {
        case 1:
        {
            CongViecTrongNgay a;
            a.insert();
            //NodeBST *&headPtr = BST->getheadBST();
            BST->insertNodeBST(BST->getheadBST(), a);
            break;
        }
        case 2:
        {
            if (BST->is_empty())
            {
                cout << "Cay Rong!\n";
            }
            else
            {
                int ngay;
                cout << "Nhap Ngay can xem lich cong tac:";
                cin >> ngay;
                cin.ignore();
                BST->XemLichCongTacTheoNgayYeuCau(BST->getheadBST(), ngay);
            }
            break;
        }
        case 3:
        {
            if (BST->is_empty())
            {
                cout << "Cay Rong!\n";
            }
            else
            {
                BST->xuat(BST->getheadBST());
            }
            break;
        }
        case 4:
        {
            if (BST->is_empty())
            {
                cout << "Cay Rong!\n";
            }
            else
            {
                string tinhchat;
                cout << "Nhap tinh chat cong viec can tim kiem:";
                getline(cin, tinhchat);
                BST->XemLichCongTacTheoTinhChatYeuCau(BST->getheadBST(), tinhchat);
            }
            break;
        }
        case 5:
        {
            if (BST->is_empty())
            {
                cout << "Cay Rong!\n";
            }
            else
            {
                int ngay;
                string giobatdau, tencv;
                cout << "Nhap Ngay:";
                cin >> ngay;
                cin.ignore();
                cout << "Nhap Gio Bat Dau:";
                getline(cin, giobatdau);
                cout << "Nhap Ten Cong Viec:";
                getline(cin, tencv);
                BST->DanhDauCacCongViecDaHoanThanh(BST->getheadBST(), ngay, giobatdau, tencv);
            }
            break;
        }
        case 6:
        {
            if (BST->is_empty())
            {
                cout << "Cay Rong!\n";
            }
            else
            {
                BST->XemCacCongViecDaHoanhThanh(BST->getheadBST());
            }
            break;
        }
        case 7:
        {
            if (BST->is_empty())
            {
                cout << "Cay Rong!\n";
            }
            else
            {
                BST->XemCacCongViecChuaHoanhThanh(BST->getheadBST());
            }
            break;
        }
        case 8:
        {
            if (BST->is_empty())
            {
                cout << "Cay Rong!\n";
            }
            else
            {
                int a, b;
                cout << "Nhap Ngay a:";
                cin >> a;
                cin.ignore();
                cout << "Nhap Ngay b:";
                cin >> b;
                cin.ignore();
                BST->XemCacCongViecTuNgayaDenNgayb(BST->getheadBST(), a, b);
            }
            break;
        }
        case 9:
        {
            if (BST->is_empty())
            {
                cout << "Cay Rong!\n";
            }
            else
            {
                NodeBST *headPtr = BST->getheadBST();
                BST->DeleteCacCongViecDaHoanThanh(headPtr);
                BST->DieuChinhLichCongTac(headPtr, BST->getheadBST());
            }
            break;
        }
        }
        system("pause");
    } while (lc != 10);
    delete BST;
    return 0;
}