
#ifndef SINH_VIEN_H
#define SINH_VIEN_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class sinhvien
{
private:
    long long msv; // ma sinh vien
    string hodem;  // ho dem
    string ten;    // ten sinh vien
    float DiemTB;  // diem trung binh
    string tenlop; // ten lop
public:
    friend istream &operator>>(istream &input, sinhvien &a)
    {
        cout << "Nhap ma sinh vien:";
        input >> a.msv;
        input.ignore();
        if (a.msv <= 0)
        {
            return input;
        }
        cout << "Nhap ho dem:";
        getline(input, a.hodem);
        cout << "Nhap ten:";
        getline(input, a.ten);
        cout << "Nhap Diem Trung Binh:";
        input >> a.DiemTB;
        input.ignore();
        cout << "Nhap Ten Lop:";
        getline(input, a.tenlop);
        return input;
    }
    friend ostream &operator<<(ostream &output, sinhvien a)
    {
        output << a.msv << setw(20) << a.hodem << setw(20) << a.ten << setw(25) << a.DiemTB << setw(20) << a.tenlop << "\n";
        return output;
    }

    sinhvien operator=(const sinhvien &a)
    {
        if (this == &a)
        {
            return *this;
        }
        this->msv = a.msv;
        this->hodem = a.hodem;
        this->ten = a.ten;
        this->DiemTB = a.DiemTB;
        this->tenlop = a.tenlop;
        return *this;
    }

    long long getmsv()
    {
        return msv;
    }
    void setmsv(long long msv)
    {
        this->msv = msv;
    }
    string gethodem()
    {
        return hodem;
    }
    void sethodem(string hodem)
    {
        this->hodem = hodem;
    }

    string getten()
    {
        return ten;
    }
    void setten(string ten)
    {
        this->ten = ten;
    }

    float getDiemTB()
    {
        return DiemTB;
    }

    void setDiemTB(float DTB)
    {
        this->DiemTB = DTB;
    }

    string gettenlop()
    {
        return tenlop;
    }
    void settenlop(string tenlop)
    {
        this->tenlop = tenlop;
    }
};

#endif