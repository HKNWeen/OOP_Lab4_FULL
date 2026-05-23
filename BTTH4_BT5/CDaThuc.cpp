#include <iostream>
#include "CDaThuc.h"
#include <math.h>
using namespace std;
//Constructor mac dinh;
CDaThuc::CDaThuc() {
    bac = 0;
    //Khoi tao vector co 1 phan tu la so 0;
    heso.resize(1, 0.0);
}
//Constructor co bac;
CDaThuc::CDaThuc(int b) {
    bac = b;
    //Khoi tao vector co b + 1 phan tu la so 0;
    heso.resize(b + 1, 0.0);
}
void CDaThuc::ChuanHoa() {
    while (bac > 0 && heso[bac] == 0) {
        bac--;
        heso.pop_back();
    }
}
//Toan tu cong giua 2 da thuc;
CDaThuc CDaThuc::operator+(const CDaThuc& other) const{
    int n = max(bac, other.bac);
    CDaThuc res(n);
    for (int i = n; i >= 0; i--) {
        double val1 = (i > bac) ? 0 : heso[i];
        double val2 = (i > other.bac) ? 0 : other.heso[i];
        res.heso[i] = val1 + val2;
    }
    res.ChuanHoa();
    return res;
}
//Toan tu tru giua 2 da thuc;
CDaThuc CDaThuc::operator-(const CDaThuc& other) const {
    int n = max(bac, other.bac);
    CDaThuc res(n);
    for (int i = n; i >= 0; i--) {
        double val1 = (i > bac) ? 0 : heso[i];
        double val2 = (i > other.bac) ? 0 : other.heso[i];
        res.heso[i] = val1 - val2;
    }
    res.ChuanHoa();
    return res;
}
//Toan tu nhan giua 2 da thuc;
CDaThuc CDaThuc::operator*(const CDaThuc& other) const {
    int n = bac + other.bac;
    CDaThuc res(n);
    for (int i = bac; i >= 0; i--) {
        for (int j = other.bac; j >= 0; j--) {
            res.heso[i + j] += heso[i] * other.heso[j];
        }
    }
    res.ChuanHoa();
    return res;
}
//Ham tinh gia tri f(x) cua da thuc;
double CDaThuc::TinhGiaTri(double x) const{
    double res = 0;
    for (int i = bac; i >= 0; i--) {
        res = res + (heso[i] * pow(x, i));
    }
    return res;
}
//Phep nhap (>>);
istream& operator>>(istream& is, CDaThuc& dt) {
    do {
        cout << "Nhap bac cua da thuc (>= 0): ";
        is >> dt.bac;
    } while (dt.bac < 0);
    dt.heso.resize(dt.bac + 1);
    for (int i = dt.bac; i >= 0; i--) {
        cout << "Nhap he so cua x^" << i << " :";
        is >> dt.heso[i];
    }
    dt.ChuanHoa();
    return is;
}
//Phep xuat (<<);
ostream& operator<<(ostream& os, const CDaThuc& dt) {
    bool isfirst = true;
    for (int i = dt.bac; i >= 0; i--) {
        if (dt.heso[i] != 0) {
            if (!isfirst) {
                if (dt.heso[i] > 0) os << " + ";
                else os << " - ";
            }
            else {
                if (dt.heso[i] < 0) os << "-";
                isfirst = false;
            }
            double val = abs(dt.heso[i]);
            //Neu bac = 0 hoac gia tri khong bang 1 thi in gia tri;
            if (i == 0 || val != 1) os << val;
            if (i != 0){
                os << "x";
                if (i != 1) os << "^" << i;
            }
        }
    }
    if (isfirst) os << 0;
    return os;
}
