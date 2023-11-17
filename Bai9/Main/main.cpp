#include "../Source/LinkList.h"
#include <iostream>

using namespace std;

int main()
{
    LinkList *Dlist = new LinkList;
    int lc;
    do
    {
        system("cls");
        cout << "---------------------------MENU---------------------------------\n";
        cout << "| 1. Nhap Danh Sach Sinh Vien.                                 |";
        cout << "\n| 2. Them Mot Sinh Vien Moi Vao Danh Sach.                     |";
        cout << "\n| 3. In Danh Sach Tat Ca Cac Sinh Vien.                        |";
        cout << "\n| 4. Hien Thi Danh Sach Theo Thu Tu Giam Dan Cua Tong Diem.    |";
        cout << "\n| 5. Hien Thi Danh Sach Sinh Vien Co Diem Trung Binh >=8.0.    |";
        cout << "\n| 6. In Danh Sach Sinh Vien Theo Lop.                          |";
        cout << "\n| 7. In Danh Sach Sinh Vien Theo Ma Sinh Vien.                 |";
        cout << "\n| 8. Xap Xep Theo Thu Tu Alphabet.                             |";
        cout << "\n| 9. Xoa Toan Bo Danh Sach Sinh Vien Co Diem Trung Binh <=5.0. |";
        cout << "\n| 10. Thoat!.                                                  |";
        cout << "\n----------------------------------------------------------------\n";
        cout << "\n. Chon chuc nang tu 1..9:";
        int n;
        cout << "\nNhap lua chon:";
        cin >> n;
        lc = n;
        cin.ignore();
        system("cls");
        switch (n)
        {
        case 1:
        {
            while (true)
            {
                sinhvien tmp;
                string k;
                cin >> tmp;
                if (tmp.getmsv() <= 0)
                {
                    break;
                }
                cout << "Nhap vi tri can them vao:";
                getline(cin, k);
                if (k == "")
                {
                    Dlist->insert(tmp, 0);
                }
                else
                {
                    Dlist->insert(tmp, stoi(k));
                }
            }
        }
        break;
        case 2:
        {
            sinhvien tmp;
            cin >> tmp;
            string k;
            cout << "Nhap Vi Tri Can Them Vao:";
            getline(cin, k);
            cin.ignore();
            if (k == "")
            {
                Dlist->insert(tmp, 0);
            }
            else
            {
                Dlist->insert(tmp, stoi(k));
            }
            break;
        }
        case 3:
        {
            cout << "Danh Sach Sinh Vien:\n";
            Dlist->in();
            break;
        }
        case 4:
        {
            Dlist->SapXepGiamDan();
            Dlist->in();
            break;
        }
        case 5:
        {
            Dlist->SinhVienXepLoaiGioi();
            break;
        }
        case 6:
        {
            Dlist->FindFromClassName();
            break;
        }
        case 7:
        {
            Dlist->FindFromId();
            break;
        }
        case 8:
        {
            Dlist->SapXepTheoAlphabet();
            Dlist->in();
            break;
        }
        case 9:
        {
            Dlist->XoaSinhVienDiemKem();
            break;
        }
        }
        system("pause");
    } while (lc != 10);

    return 0;
}


