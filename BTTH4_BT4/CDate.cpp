#include "CDate.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Constructor;
CDate::CDate(int ngay, int thang, int nam) {
    iNgay = ngay;
    iThang = thang;
    iNam = nam;
    ChuanHoa();
}
//Ham kiem tra nam nhuan cua ngay thang nam;
bool CDate::KiemTraNamNhuan() const {
    return (iNam % 400 == 0 || (iNam % 4 == 0 && iNam % 100 != 0));
}
//Ham kiem tra tinh hop le cua ngay thang nam;
bool CDate::KiemTraHopLe() const {
    if (iNgay < 1 || iThang < 1 || iThang > 12 || iNam < 1) return false;
    int daysmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (KiemTraNamNhuan()) {
        daysmonth[2] = {29};
    }
    if (iNgay > daysmonth[iThang]) return false;
    return true;
}
//Ham tinh so ngay cua CDate ke tu 01/01/0001;
int CDate::TinhNgayTuDau() const{
    int days = 0;
    int years = iNam - 1;
    days = 365 * years + years / 4 - years / 100 + years / 400;
    int daysmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (KiemTraNamNhuan()) daysmonth[2] = 29;
    for (int i = 1; i < iThang; i++) {
        days += daysmonth[i];
    }
    days += iNgay;
    return days;
}
//Ham chuan hoa Ngay/Thang/Nam;
void CDate::ChuanHoa() {
    int daysmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (KiemTraNamNhuan()) daysmonth[2] = 29;
    //Truong hop ngay vuot qua so ngay trong thang;
    while (iNgay > daysmonth[iThang]) {
        //Cap nhat ngay cua thang 2 tuy theo nam;
        if (KiemTraNamNhuan()) daysmonth[2] = 29;
        else daysmonth[2] = 28;
        iNgay -= daysmonth[iThang];
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    //Truong hop ngay <= 0;
    while (iNgay < 1) {
        iThang--;
        if (iThang < 1) {
            iThang = 12;
            iNam--;
        }
        if (KiemTraNamNhuan()) daysmonth[2] = 29;
        else daysmonth[2] = 28;
        iNgay += daysmonth[iThang];

    }
}
//Phep xuat (<<);
ostream& operator<<(ostream& os, const CDate& d) {
    os << setfill('0') << setw(2) << d.iNgay << "/"
    << setfill('0') << setw(2) << d.iThang << "/"
    << setfill('0') << setw(4) << d.iNam;
    return os;
}
//Prefix (++t);
CDate& CDate::operator++() {
    ++iNgay;
    ChuanHoa();
    return *this;
}
//Postfix (t++);
CDate CDate::operator++(int) {
    CDate temp = *this;
    ++(*this);
    return temp;
}
//Prefix (--t);
CDate& CDate::operator--() {
    --iNgay;
    ChuanHoa();
    return *this;
}
//Postfix (t--);
CDate CDate::operator--(int) {
    CDate temp = *this;
    --(*this);
    return temp;
}
//Toan tu cong ngay tuy y vao Ngay/Thang/Nam;
CDate CDate::operator+(int ngay) const{
    return CDate(iNgay + ngay, iThang, iNam);
}
//Toan tu tru ngay tuy y vao Ngay/Thang/Nam;
CDate CDate::operator-(int ngay) const{
    return CDate(iNgay - ngay, iThang, iNam);
}
//Toan tu tru di 1 Ngay/Thang/Nam khac;
int CDate::operator-(const CDate& other) const{
    return TinhNgayTuDau() - other.TinhNgayTuDau();
}

//Phep nhap (>>);
istream& operator>>(istream& is, CDate& d) {
    do {
        cout << "Nhap ngay: ";
        is >> d.iNgay;
        cout << "Nhap thang: ";
        is >> d.iThang;
        cout << "Nhap nam: ";
        is >> d.iNam;
        if (!d.KiemTraHopLe()) {
            cout << "Ngay/Thang/Nam khong hop le! Vui long nhap lai! \n";
        }
    } while (!d.KiemTraHopLe());
    return is;
}
