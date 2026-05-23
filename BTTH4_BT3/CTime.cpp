#include <iostream>
#include "CTime.h"
#include <iomanip>
using namespace std;
//Constructor
CTime::CTime(int gio, int phut, int giay) {
    iGio = gio;
    iPhut = phut;
    iGiay = giay;
    ChuyenHoa();
}
// Chuan hoa thoi gian ve khoang hop le [00:00:00, 23:59:59];
void CTime::ChuyenHoa() {
    long long totalsec = iGio * 3600 + iPhut * 60 + iGiay;
    int daysec = 24 * 3600;
    if (totalsec < 0) {
        totalsec = daysec + (totalsec % daysec);
    }
    totalsec = totalsec % daysec;
    iGio = totalsec / 3600;
    iPhut = (totalsec % 3600) / 60;
    iGiay = totalsec % 60;
}
//Prefix ++ (++t);
CTime& CTime::operator++() {
    iGiay++;
    ChuyenHoa();
    return *this;
}
//Postfix ++ (t++);
CTime CTime::operator++(int) {
    CTime temp = *this;
    ++(*this);
    return temp;
}
//Prefix -- (--t);
CTime& CTime::operator--() {
    iGiay--;
    ChuyenHoa();
    return *this;
}
//Postfix -- (t--);
CTime CTime::operator--(int) {
    CTime temp = *this;
    --(*this);
    return temp;
}
//Ham cong them giay tuy y vao thoi gian;
CTime CTime::operator+(int giay) {
    return CTime(iGio, iPhut, iGiay + giay);
}
//Ham tru them giay tuy y vao thoi gian;
CTime CTime::operator-(int giay) {
    return CTime(iGio, iPhut, iGiay - giay);
}
// Phep xuat (<<);
 ostream& operator<<(ostream& os, const CTime& t) {
     os << setfill('0') << setw(2) << t.iGio << ":"
     << setfill('0') << setw(2) << t.iPhut << ":"
     << setfill('0') << setw(2) << t.iGiay;
     return os;
 }
// Phep nhap (>>);
 istream& operator>>(istream& is, CTime& t) {
     do {
        cout << "Nhap gio (0-23): "; is >> t.iGio;
        cout << "Nhap phut (0 - 59): "; is >> t.iPhut;
        cout << "Nhap giay (0 - 59): "; is >> t.iGiay;
        if (t.iGio < 0 || t.iGio > 23 || t.iPhut < 0 || t.iPhut > 59 || t.iGiay < 0 || t.iGiay > 59) {
            cout << "Du lieu khong hop le, vui long nhap lai!";
        }
     } while (t.iGio < 0 || t.iGio > 23 || t.iPhut < 0 || t.iPhut > 59 || t.iGiay < 0 || t.iGiay > 59);
     return is;
 }

