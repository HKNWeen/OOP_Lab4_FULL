#include "cSoPhuc.h"
#include <iostream>
#include <cmath> //fabs
using namespace std;
//Constructor;
cSoPhuc::cSoPhuc(double thuc, double ao) {
    iThuc = thuc;
    iAo = ao;
}
//Phep cong: (a + bi) + (c + di) = (a + c) + (b + d)i
cSoPhuc operator+(const cSoPhuc &a, const cSoPhuc &b) {
    return cSoPhuc(a.iThuc + b.iThuc, a.iAo + b.iAo);
}
//Phep tru:(a + bi) - (c + di) = (a - c) + (b - d)i;
cSoPhuc operator-(const cSoPhuc &a, const cSoPhuc &b) {
    return cSoPhuc(a.iThuc - b.iThuc, a.iAo - b.iAo);
}
//Phep nhan: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i;
cSoPhuc operator*(const cSoPhuc &a, const cSoPhuc &b) {
    return cSoPhuc(a.iThuc * b.iThuc - a.iAo * b.iAo, a.iThuc * b.iAo + a.iAo * b.iThuc);
}
//Phep chia: (a + bi) / (c + di) = [(ac + bd)/(cc + dd)] + [(bc - ad)/(cc + dd)]i;
cSoPhuc operator/(const cSoPhuc &a, const cSoPhuc &b) {
    double mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
    if (fabs(mau) < 1e-9) {
        cout << "Loi: chia cho 0!";
        return 0;
    }
    return cSoPhuc((a.iThuc * b.iThuc + a.iAo * b.iAo) / mau, (a.iAo * b.iThuc - a.iThuc * b.iAo) / mau);
}
//Phep so sanh (==);
bool operator==(const cSoPhuc &a, const cSoPhuc &b) {
    return (a.iThuc == b.iThuc && a.iAo == b.iAo);
}
//Phep so sanh (!=);
bool operator!=(const cSoPhuc &a, const cSoPhuc &b) {
    return !(a == b);
}
//Phep xuat (<<);
ostream& operator<<(ostream& os, const cSoPhuc &sp){
    if (sp.iThuc != 0) {
        os << sp.iThuc;
        if (sp.iAo > 0) os << " + " << sp.iAo << "i";
        else if (sp.iAo < 0) os << " - " << -sp.iAo << "i";
    }
    else {
        if (sp.iAo == 0) os << "0";
        else os << sp.iAo << "i";

    }
    return os;
}
//Phep nhap (>>);
istream& operator>>(istream& is, cSoPhuc &sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.iThuc;
    cout << "Nhap phan ao: ";
    is >> sp.iAo;
    return is;
}
