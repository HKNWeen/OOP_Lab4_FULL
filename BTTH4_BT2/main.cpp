#include <iostream>
#include "cPhanSo.h"
using namespace std;

int main()
{
    cPhanSo a, b;
    cout << "Nhap phan so a: \n";
    cin >> a;
    cout << "Nhap phan so b: \n";
    cin >> b;

    cout << "Phan so a: " << a << '\n';
    cout << "Phan so b: " << b << '\n';

    //Tinh toan +, -, *, / giua 2 phan so;
    cout << "(" << a << ")" << " + " << "(" << b << ") = " << a + b << '\n';
    cout << "(" << a << ")" << " - " << "(" << b << ") = " << a - b << '\n';
    cout << "(" << a << ")" << " * " << "(" << b << ") = " << a * b << '\n';
    cout << "(" << a << ")" << " / " << "(" << b << ") = " << a / b << '\n';

    //So sanh 2 phan so;
    if (a == b) cout << a << " bang " << b;
    else if (a > b) cout << a << " lon hon " << b;
    else if (a < b) cout << a << " nho hon " << b;
}
