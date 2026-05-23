#include "CVector.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
//Constructor mac dinh;
CVector::CVector() {
}
//Constructor khi co so chieu;
CVector::CVector(int n) {
    toado.resize(n, 0.0);
}
//Ham cho phep doc va sua;
double& CVector::operator[](int index) {
    if (index < 0 || index >= getChieu()) {
        cout << "Khong thuoc pham vi!";
        exit(1);
    }
    return toado[index];
}
//Ham chi cho doc (nhu doc tu const CVector& other = other[i]);
double CVector::operator[](int index) const{
    if (index < 0 || index >= getChieu()) {
        cout << "Khong thuoc pham vi!";
        exit(1);
    }
    return toado[index];
}
//Phep cong 2 vector;
CVector CVector::operator+(const CVector& other) const {
    //Khong cung so chieu thi stop;
    if (getChieu() != other.getChieu()) {
        return CVector();
    }
    CVector res(getChieu());
    for (int i = 0; i < getChieu(); i++) {
        res[i] = toado[i] + other[i];
    }
    return res;
}
//Phep tru 2 vector;
CVector CVector::operator-(const CVector& other) const {
    if (getChieu() != other.getChieu()) {
        return CVector();
    }
    CVector res(getChieu());
    for (int i = 0; i < getChieu(); i++) {
        res[i] = toado[i] - other[i];
    }
    return res;
}
//Phep nhan vector voi so thuc;
CVector CVector::operator*(double val) const {
    CVector res(getChieu());
    for (int i = 0; i < getChieu(); i++) {
        res[i] = toado[i] * val;
    }
    return res;
}
//Tich vo huong 2 vector;
double CVector::operator*(const CVector& other) const {
    if (getChieu() != other.getChieu()) {
        return 0;
    }
    double res = 0.0;
    for (int i = 0; i < getChieu(); i++) {
        res += toado[i] * other[i];
    }
    return res;
}
//Ham lay chieu cua vector;
int CVector::getChieu() const {
    return toado.size();
}
//Phep nhap (>>);
istream& operator>>(istream& is, CVector& other) {
    for (int i = 0; i < other.getChieu(); i++) {
        cout << "Nhap toa do " << i + 1 << ": ";
        is >> other[i];
    }
    return is;
}
//Phep xuat (<<);
ostream& operator<<(ostream& os, const CVector& other) {
    os << "(";
    for (int i = 0; i < other.getChieu(); i++) {
        os << other[i];
        if (i < other.getChieu() - 1) os << ", ";
    }
    os << ")";
    return os;
}
