#include <iostream>
#include "CMatrix.h"
using namespace std;

int main()
{
    CMatrix m1;
    cout << "Nhap ma tran m1: \n";
    cin >> m1;
    CMatrix m2;
    cout << "Nhap ma tran m2: \n";
    cin >> m2;

    cout << "Ma tran m1: \n" << m1;
    cout << "Ma tran m2: \n" << m2;
    if (m1.getiRows() == m2.getiRows() && m1.getiCols() == m2.getiCols()) {
        cout << "Tong hai ma tran (m1 + m2): \n";
        cout << m1 + m2;
        cout << "Hieu hai ma tran (m1 - m2): \n";
        cout << m1 - m2;
    }
    else {
        cout << "Loi! So cot hoac so dong cua m1 khong bang m2.\nKhong the tinh tong va hieu m1, m2!\n";
    }
    if (m1.getiCols() == m2.getiRows()) {
    cout << "Tich hai ma tran (m1 * m2): \n";
    cout << m1 * m2;
    }
    else {
        cout << "Loi! so cot m1 khong bang so dong m2.\nKhong the tinh tich m1, m2!\n";
    }
    cout << "Nhap vector de nhan voi cac ma tran: \n";
    cout << "Nhap kich thuoc: \n";
    int n;
    cin >> n;
    vector <double> v (n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap v[" << i << "]: ";
        cin >> v[i];
    }
    if (m1.getiCols() == v.size()) {
        vector<double> tich1 = m1 * v;
        cout << "Tich (m1 * v): \n";
        for (int i = 0; i < tich1.size(); i++) {
            cout << tich1[i] << '\n';
        }
    }
    else {
        cout << "Loi! so cot m1 khong bang so dong v.\nKhong the tinh tich m1!\n";
    }
    if (m2.getiCols() == v.size()) {
        vector<double> tich2 = m2 * v;
        cout << "Tich (m2 * v): \n";
        for (int i = 0; i < tich2.size(); i++) {
            cout << tich2[i] << '\n';
        }
    }
    else {
        cout << "Loi! so cot m2 khong bang so dong v.\nKhong the tinh tich m2 * v!\n";
    }
}
