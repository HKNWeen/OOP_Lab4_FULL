#include <iostream>
#include "CVector.h"
using namespace std;

int main()
{
    int n1;
    cout << "Nhap so chieu cua vector v1: ";
    cin >> n1;
    CVector v1(n1);
    cout << "Nhap vector v1: \n";
    cin >> v1;
    cout << "Toa do vector v1: " << v1 << '\n';

    int n2;
    cout << "Nhap so chieu cua vector v2: ";
    cin >> n2;
    CVector v2(n2);
    cout << "Nhap vector v2: \n";
    cin >> v2;

    //Neu 2 vector cung so chieu thi in ket qua;
    if (v1.getChieu() == v2.getChieu()) {
        cout << "Toa do vector v2: " << v2 << '\n';
        cout << "v1 + v2 = " << v1 + v2 << '\n';
        cout << "v1 - v2 = " << v1 - v2 << '\n';
        cout << "Tich vo huong v1 * v2 = " << v1 * v2 << '\n';
    }
    else {
        cout << "Loi! v1 va v2 khong cung so chieu! \n";
    }

    cout << "Nhap so nhan vao cac vector: ";
    double val;
    cin >> val;
    cout << "v1 * " << val << " = " << v1 * val << '\n';
    cout << "v2 * " << val << " = " << v2 * val << '\n';
}
