#ifndef LINK_LIST_
#define LINK_LIST_

#include "NODE.h"
#include <iostream>
#include <iomanip>
#include "../Source/SinhVien.h"

using namespace std;

class LinkList
{
private:
    Node *head;

public:
    LinkList()
    {
        head = NULL;
    }
    ~LinkList()
    {
        head = NULL;
    }

    Node *gethead()
    {
        return head;
    }
    int sz();
    void in();
    void insert(sinhvien a, int k);
    void SinhVienXepLoaiGioi();
    void FindFromClassName();
    void FindFromId();
    void SapXepGiamDan();
    void SapXepTheoAlphabet();
    void XoaSinhVienDiemKem();
    Node *LastNode();
};

Node *LinkList::LastNode()
{
    Node *p = head;
    while (p != NULL && p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

void LinkList::SapXepTheoAlphabet()
{
    if (head != NULL)
    {
        for (Node *p = head; p->next != NULL; p = p->next)
        {
            Node *min = p;
            for (Node *q = p->next; q != NULL; q = q->next)
            {
                if (q->getsv().getten() < min->getsv().getten())
                {
                    min = q;
                }
            }
            sinhvien tmp = min->getsv();
            min->setsv(p->getsv());
            p->setsv(tmp);
        }
    }
}

void LinkList::SapXepGiamDan()
{
    if (head != NULL)
    {
        for (Node *p = head; p->next != NULL; p = p->next)
        {
            Node *max = p;
            for (Node *q = p->next; q != NULL; q = q->next)
            {
                if (q->getsv().getDiemTB() > max->getsv().getDiemTB())
                {
                    max = q;
                }
            }
            sinhvien tmp = max->getsv();
            max->setsv(p->getsv());
            p->setsv(tmp);
        }
    }
}

void LinkList::XoaSinhVienDiemKem()
{
    if (head == NULL)
    {
        cout << " Danh Sach Lien Ket Rong!\n";
        return;
    }
    else
    {
        Node *p = head;
        while (p != NULL)
        {
            if (p->sv.getDiemTB() <= 5)
            {
                Node *temp = p;      // luu de xoa
                if (p->prev == NULL) // neu la node dau
                {
                    head = p->next;
                    if (head != NULL) // gan lai cho prev cua node goc bang NULL
                    {
                        head->prev = NULL;
                    }
                    p = p->next; 
                }
                else if (p->next == NULL) // neu la node cuoi
                {
                    p->prev->next = NULL;
                    p = NULL;
                }
                else // neu la node giua
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    p = p->next; 
                }
                delete temp;
            }
            else // neu khong roi vao diem trung binh <=5
            {
                p = p->next; // thi cho p tien den dia chi nut tiep theo
            }
        }
        delete p;
    }
}

void LinkList::FindFromId()
{
    if (head == NULL)
    {
        cout << "Danh Sach Lien Ket Rong!\n";
        return;
    }
    else
    {
        long long id;
        cout << "Nhap Ten Id Can tim:";
        cin >> id;
        cin.ignore();
        Node *p = head;
        bool flag = false;
        while (p != NULL)
        {
            if (p->sv.getmsv() == id)
            {
                flag = true;
            }
            p = p->next;
        }
        if (!flag)
        {
            cout << "Khong tim thay sinh vien co id:" << id << "\n";
        }
        else
        {
            p = head;
            int cnt = 0;
            cout << "Ma Sinh Vien" << setw(20) << "Ho Dem Sinh Vien" << setw(20) << "Ten sinh vien" << setw(25) << "Diem Trung Binh" << setw(20) << "Ten Lop\n";
            while (p != NULL)
            {
                cnt++;
                if (p->sv.getmsv() == id)
                {
                    cout << p->sv;
                    cout << "Vi Tri:" << cnt << "\n";
                }
                p = p->next;
            }
        }
    }
}

void LinkList::FindFromClassName()
{
    if (head == NULL)
    {
        cout << "Danh Sach Lien Ket Rong!\n";
        return;
    }
    else
    {
        string Class_Name;
        cout << "Nhap Ten Class Can tim:";
        getline(cin, Class_Name);
        Node *p = head;
        bool flag = false;
        while (p != NULL)
        {
            if (p->sv.gettenlop() == Class_Name)
            {
                flag = true;
            }
            p = p->next;
        }
        if (!flag)
        {
            cout << "Khong tim thay sinh vien co lop:" << Class_Name << "\n";
        }
        else
        {
            p = head;
            cout << "Ma Sinh Vien" << setw(20) << "Ho Dem Sinh Vien" << setw(20) << "Ten sinh vien" << setw(25) << "Diem Trung Binh" << setw(20) << "Ten Lop\n";
            while (p != NULL)
            {
                if (p->sv.gettenlop() == Class_Name)
                {
                    cout << p->sv;
                }
                p = p->next;
            }
        }
    }
}

void LinkList::SinhVienXepLoaiGioi()
{
    if (head == NULL)
    {
        cout << "Danh Sach Lien Ket Rong!\n";
        return;
    }
    else
    {
        cout << "Danh Sach Sinh Vien Co Diem Xep Loai Gioi La:\n";
        Node *p = head;
        bool flag = false;
        while (p != NULL)
        {
            if (p->sv.getDiemTB() >= 8)
            {
                flag = true;
            }
            p = p->next;
        }
        if (!flag)
        {
            cout << "Khong co sinh vien nao co diem trung binh >=8\n";
        }
        else
        {
            cout << "Ma Sinh Vien" << setw(20) << "Ho Dem Sinh Vien" << setw(20) << "Ten sinh vien" << setw(25) << "Diem Trung Binh" << setw(20) << "Ten Lop\n";
            p=head;
            while (p != NULL)
            {
                if (p->sv.getDiemTB() >= 8)
                {
                    cout << p->sv;
                }
                p = p->next;
            }
        }
    }
}

void LinkList::insert(sinhvien a, int k)
{
    Node *tmp = new Node;
    tmp->sv = a;
    tmp->next = NULL;
    tmp->prev = NULL;
    if (k == 1)
    {
        if (head == NULL)
        {
            head = tmp;
        }
        else
        {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
    }
    else if (k >= sz() + 1 || k == 0)//k=0 tuong ưng voi nguoi nhap bo trong không nhập vị trí
    {
        if (head == NULL)
        {
            head = tmp;
        }
        else
        {
            Node *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = tmp;
            tmp->prev = p;
        }
    }
    else if (k > 1 || k <= sz())
    {
        if (head == NULL)
        {
            head = tmp;
        }
        else
        {
            Node *p = head;
            for (int i = 0; i < k - 1; i++)
            {
                p = p->next;
            }
            tmp->next = p;
            p->prev->next = tmp;
            tmp->prev = p->prev;
            p->prev = tmp;
        }
    }
}

int LinkList::sz()
{
    int cnt = 0;
    Node *p = head;
    while (p != NULL)
    {
        p = p->next;
        cnt++;
    }

    return cnt;
}

void LinkList::in()
{
    if (head == NULL)
    {
        cout << "Danh Sach Lien Ket Rong!\n";
    }
    else
    {
        cout << "Ma Sinh Vien" << setw(20) << "Ho Dem Sinh Vien" << setw(20) << "Ten sinh vien" << setw(25) << "Diem Trung Binh" << setw(20) << "Ten Lop\n";
        Node *p = head;
        while (p != NULL)
        {
            cout << p->sv;
            p = p->next;
        }
    }
}

#endif