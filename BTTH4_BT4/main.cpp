#include <iostream>
#include "CDate.h"
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    CDate ngaygui, ngayrut;
    double tiengoc, laisuatnam;
    cout << "Nhap ngay gui (dd/mm/yyyy): \n";
    cin >> ngaygui;
    cout << "Nhap ngay rut (dd/mm/yyyy): \n";
    cin >> ngayrut;
    cout << "Nhap so tien goc (VND): ";
    cin >> tiengoc;
    cout << "Nhap lai suat nam (%): ";
    cin >> laisuatnam;

    int songaygui = ngayrut - ngaygui;
    if (songaygui < 0) {
        cout << "Loi! Ngay rut phai sau ngay gui!";
        return 1;
    }

    double tienlai = tiengoc * (laisuatnam / 100.0) * (songaygui / 365.0);
    double tong = tiengoc + tienlai;

    cout << "Ngay gui tien: " << ngaygui << '\n';
    cout << "Ngay rut tien: " << ngayrut << '\n';
    cout << "Tong so ngay da gui : " << songaygui << '\n';
    cout << "Tien lai: " << fixed << setprecision(0) << tienlai << "VND" << '\n';
    cout << "Tong tien: " << fixed << setprecision(0) << tong << "VND" << '\n';

    cout << "Nhap so ngay cong them vao ngay rut tien: ";
    int n1;
    cin >> n1;
    cout <<  ngayrut << " cong them " << n1 << " = " << ngayrut + n1 << '\n';

    cout << "Nhap so ngay tru bot vao ngay rut tien: ";
    int n2;
    cin >> n2;
    cout << ngayrut << " tru bot " << n2 << " = " << ngayrut - n2;
}
