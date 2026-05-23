#include <iostream>
#include "CDaThuc.h"
using namespace std;

int main()
{
    CDaThuc dt1, dt2;
    cout << "Nhap da thuc 1: \n";
    cin >> dt1;

    cout << "Nhap da thuc 2: \n";
    cin >> dt2;

    cout << "Da thuc 1 (A): " << dt1 << '\n';
    cout << "Da thuc 2 (B): " << dt2 << '\n';

    cout << "Tong (A + B): " << dt1 + dt2 << '\n';
    cout << "Hieu (A - B): " << dt1 - dt2 << '\n';
    cout << "Tich (A * B): " << dt1 * dt2 << '\n';

    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Gia tri f(" << x << ") cua da thuc 1 = " << dt1.TinhGiaTri(x) << '\n';
    cout << "Gia tri f(" << x << ") cua da thuc 2 = " << dt2.TinhGiaTri(x) << '\n';
}
