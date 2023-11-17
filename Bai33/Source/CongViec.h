#ifndef CONG_VIEC_
#define CONG_VIEC_

#include <iostream>
#include <string>

using namespace std;

class CongViec
{
private:
    string time_start;
    string ten_cong_viec;
    string noi_dung;
    string tinh_chat_cong_viec;
    bool check_Hoan_Thanh;

public:
    CongViec(string time_start = "", string ten_cong_viec = "", string noi_dung = "", string tinh_chat_cong_viec = "")
    {
        this->time_start = time_start;
        this->ten_cong_viec = ten_cong_viec;
        this->noi_dung = noi_dung;
        this->tinh_chat_cong_viec = tinh_chat_cong_viec;
        check_Hoan_Thanh = false;
    }

    bool getcheck_Hoan_thanh() const
    {
        return check_Hoan_Thanh;
    }

    void setcheck_Hoan_Thanh(bool check)
    {
        check_Hoan_Thanh = check;
    }

    string gettime_start() const
    {
        return time_start;
    }

    void settime_start(string time)
    {
        time_start = time;
    }

    string getten_cong_viec() const
    {
        return ten_cong_viec;
    }

    void setten_cong_viec(string cong_viec)
    {
        ten_cong_viec = cong_viec;
    }

    string gettinh_chat_cong_viec() const
    {
        return tinh_chat_cong_viec;
    }

    void settinh_chat_cong_viec(string tinh_chat)
    {
        tinh_chat_cong_viec = tinh_chat;
    }

    string getnoi_dung() const
    {
        return noi_dung;
    }

    void setnoi_dung(string noidung)
    {
        noi_dung = noidung;
    }

    friend istream &operator>>(istream &input, CongViec &a);
    friend ostream &operator<<(ostream &output, const CongViec &a);
};

istream &operator>>(istream &input, CongViec &a)
{
    cout << "Nhap Gio Bat Dau:";
    getline(input, a.time_start);
    cout << "Nhap Ten Cong Viec:";
    getline(input, a.ten_cong_viec);
    cout << "Nhap Noi Dung:";
    getline(input, a.noi_dung);
    cout << "Nhap Tinh Chat Cong Viec:";
    getline(input, a.tinh_chat_cong_viec);
    return input;
}

ostream &operator<<(ostream &output, const CongViec &a)
{
    output << a.time_start << " " << a.ten_cong_viec << " " << a.noi_dung << " " << a.tinh_chat_cong_viec << "\n";
    return output;
}

#endif