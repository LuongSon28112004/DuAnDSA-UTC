
#ifndef CONG_VIEC_TRONG_NGAY_
#define CONG_VIEC_TRONG_NGAY_

#include <iostream>
#include <string>
#include <vector>
#include "../Source/LinkList.h"
#include "../Source/CongViec.h"

class CongViecTrongNgay
{
private:
    int ten_ngay;
    node head; // danh sach lien ket de luu cac cong viec trong mọt ngay
public:
    CongViecTrongNgay()
    {
        ten_ngay = 0;
        head = NULL;
    }

    CongViecTrongNgay operator=(const CongViecTrongNgay &a)
    {
        if (this == &a)
        {
            return *this;
        }
        this->ten_ngay = a.ten_ngay;
        this->head = a.head;
        return *this;
    }

    int getten_ngay() const
    {
        return ten_ngay;
    }

    void setten_ngay(int ngay)
    {
        ten_ngay = ngay;
    }

    node &gethead()
    {
        return head;
    }

    void sethead(node a)
    {
        head = a;
    }

    void insert()
    {
        cout << "Nhap Ten Ngay:";
        cin >> ten_ngay;
        cin.ignore();
        while (true)
        {
            CongViec a;
            cout << "Nhap Thong Tin Cong Viec:\n";
            cin >> a;
            insertLast(head, a);
            cout << "Ban Muon Nhap Tiep Cong Viec Trong Ngay Nay khong Dong y(1) or Thoat(0)\n";
            cout << "Nhap lua chon:\n";
            sapxep(head);
            int lc;
            cin >> lc;
            cin.ignore();
            if (lc!=1)
            {
                break;
            }
        }
    }
    void inDS()
    {
        cout << "cong viec trong ngay " << ten_ngay << ":\n";
        in(head);
    }
    void inDS_Theo_Tinh_Chat_Cong_Viec(string tinhchat)
    {
        cout << "cong viec trong ngay " << ten_ngay << ":\n";
        in_Theo_Tinh_Chat_Cong_Viec(head, tinhchat);
    }

    void inDS_Theo_Cong_Viec_Da_Hoan_Thanh()
    {
        cout << "cong viec trong ngay " << ten_ngay << ":\n";
        in_Theo_Cong_Viec_Da_Hoan_Thanh(head);
    }

    void inDS_Theo_Cong_Viec_Chua_Hoan_Thanh()
    {
        cout << "cong viec trong ngay " << ten_ngay << ":\n";
        in_Theo_Cong_Viec_Chua_Hoan_Thanh(head);
    }
};

#endif
