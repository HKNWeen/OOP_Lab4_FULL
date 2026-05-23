#include <iostream>
#include "cPhanSo.h"
using namespace std;
//Constructor;
cPhanSo::cPhanSo(int tu, int mau) {
    iTu = tu;
    iMau = mau;
    RutGon();
}
//Ham tim uoc chung lon nhat cua mau va tu;
int cPhanSo::UCLN(int a, int b){
    if (b == 0) return a;
    int r = a % b;
    return UCLN(b, r);
}
//Ham toi gian phan so;
void cPhanSo::RutGon() {
    int g = UCLN(iTu, iMau);
    iTu /= g;
    iMau /= g;
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}
//Nap chong toan tu cong hai phan so;
cPhanSo operator+(const cPhanSo &a, const cPhanSo &b) {
    return cPhanSo(a.iTu * b.iMau + b.iTu * a.iMau, a.iMau * b.iMau);
}
//Nap chong toan tu tru hai phan so;
cPhanSo operator-(const cPhanSo &a, const cPhanSo &b) {
    return cPhanSo(a.iTu * b.iMau - b.iTu * a.iMau, a.iMau * b.iMau);
}
//Nap chong toan tu nhan hai phan so;
cPhanSo operator*(const cPhanSo &a, const cPhanSo &b) {
    return cPhanSo(a.iTu * b.iTu, a.iMau * b.iMau);
}
//Nap chong toan tu chia hai phan so;
cPhanSo operator/(const cPhanSo &a, const cPhanSo &b) {
    return cPhanSo(a.iTu * b.iMau, a.iMau * b.iTu);
}
//Phep so sanh (==);
bool operator==(const cPhanSo &a, const cPhanSo &b) {
    return (a.iTu * b.iMau == b.iTu * a.iMau);
}
//Phep so sanh (<);
bool operator<(const cPhanSo &a, const cPhanSo &b) {
    return (a.iTu * b.iMau < b.iTu * a.iMau);
}
//Phep so sanh (>);
bool operator>(const cPhanSo &a, const cPhanSo &b) {
    return (a.iTu * b.iMau > b.iTu * a.iMau);
}
//Phep xuat (<<);
ostream& operator<<(ostream& os, const cPhanSo &ps) {
    if (ps.iTu == 0) os << 0;
    else if (ps.iMau == 1) os << ps.iTu;
    else os << ps.iTu << "/" << ps.iMau;
    return os;
}
//Phep nhap (>>);
istream& operator>>(istream& is, cPhanSo &ps) {
    cout << "Nhap tu: ";
    is >> ps.iTu;
    cout << "Nhap mau: ";
    is >> ps.iMau;
    while (ps.iMau == 0) {
        cout << "Mau so phai khac 0, vui long nhap lai: ";
        is >> ps.iMau;
    }
    ps.RutGon();
    return is;
}


