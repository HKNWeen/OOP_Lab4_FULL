#ifndef CPHANSO_H_INCLUDED
#define CPHANSO_H_INCLUDED
#include <iostream>
class cPhanSo {
private:
    int iTu, iMau;
    int UCLN(int a, int b);
    void RutGon();
public:
    cPhanSo(int tu = 0, int mau = 1);

    friend cPhanSo operator+(const cPhanSo &a, const cPhanSo &b);
    friend cPhanSo operator-(const cPhanSo &a, const cPhanSo &b);
    friend cPhanSo operator*(const cPhanSo &a, const cPhanSo &b);
    friend cPhanSo operator/(const cPhanSo &a, const cPhanSo &b);

    friend bool operator==(const cPhanSo &a, const cPhanSo &b);
    friend bool operator<(const cPhanSo &a, const cPhanSo &b);
    friend bool operator>(const cPhanSo &a, const cPhanSo &b);
    friend std::ostream& operator<<(std::ostream& os, const cPhanSo &ps);
    friend std::istream& operator>>(std::istream& is, cPhanSo &ps);
};

#endif // CPHANSO_H_INCLUDED
