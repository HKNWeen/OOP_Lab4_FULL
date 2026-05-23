#include <iostream>
#include "cSoPhuc.h"
using namespace std;

int main()
{
    cSoPhuc a, b;
    cout << "Nhap so phuc a: \n";
    cin >> a;
    cout << "Nhap so phuc b: \n";
    cin >> b;
    cout << "So phuc a = " << a << '\n';
    cout << "So phuc b = " << b << '\n';

    cout << "(" << a << ") + (" << b << ") = " << a + b << '\n';
    cout << "(" << a << ") - (" << b << ") = " << a - b << '\n';
    cout << "(" << a << ") * (" << b << ") = " << a * b << '\n';
    cout << "(" << a << ") / (" << b << ") = " << a / b << '\n';

    if (a == b) cout << "So phuc a va b bang nhau!" << '\n';
    else if (a != b) cout << "So phuc a va b khong bang nhau!" << '\n';
}
