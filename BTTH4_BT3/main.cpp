#include <iostream>
#include "CTime.h"
using namespace std;

int main()
{
    CTime t;
    cin >> t;
    cout << "Thoi gian ban nhap: " << t << '\n';

    cout << "Thoi gian sau khi cong them 1 giay: ";
    t++;
    cout << t << '\n';

    cout << "Thoi gian sau khi tru bot 1 giay: ";
    t--;
    cout << t << '\n';

    int g1;
    cout << "Nhap so giay cong them vao thoi gian: ";
    cin >> g1;
    cout << t << " cong them " << g1 << " giay = " << t + g1 << '\n';

    int g2;
    cout << "Nhap so giay tru bot vao thoi gian: ";
    cin >> g2;
    cout << t << " tru bot " << g2 << " giay = " << t - g2 << '\n';
}
