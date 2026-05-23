#include <iostream>
#include <vector>
#include "CMatrix.h"
using namespace std;
//Constructor mac dinh;
CMatrix::CMatrix() {
    iRows = 0;
    iCols = 0;
}
//Constructor;
CMatrix::CMatrix(int r, int c) {
    iRows = r;
    iCols = c;
    val.assign(r, vector<double> (c, 0.0));
}
//Getter lay dong;
int CMatrix::getiRows() const {
    return iRows;
}
//Getter lay cot;
int CMatrix::getiCols() const {
    return iCols;
}
//Phep cong hai ma tran;
CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (iRows != other.iRows || iCols != other.iCols) return CMatrix();
    CMatrix res(iRows, iCols);
    for (int i = 0; i < iRows; i++) {
        for (int j = 0; j < iCols; j++) {
            res.val[i][j] = val[i][j] + other.val[i][j];
        }
    }
    return res;
}
//Phep tru hai ma tran;
CMatrix CMatrix::operator-(const CMatrix& other) const {
    if (iRows != other.iRows || iCols != other.iCols) return CMatrix();
    CMatrix res(iRows, iCols);
    for (int i = 0; i < iRows; i++) {
        for (int j = 0; j < iCols; j++) {
            res.val[i][j] = val[i][j] - other.val[i][j];
        }
    }
    return res;
}
//Phep nhan hai ma tran;
CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (iCols != other.iRows) return CMatrix();
    CMatrix res(iRows, other.iCols);
    for (int i = 0; i < iRows; i++) {
        for (int j = 0; j < other.iCols; j++) {
            for (int k = 0; k < iCols; k++) {
                res.val[i][j] += val[i][k] * other.val[k][j];
            }
        }
    }
    return res;
}
//Phep nhan ma tran voi vector;
vector<double> CMatrix::operator*(const vector<double>& v) const{
    if (iCols != v.size()) return vector<double> ();
    vector<double> res(iRows, 0.0);
    for (int i = 0; i < iRows; i++) {
        for (int j = 0; j < iCols; j++) {
            res[i] += val[i][j] * v[j];
        }
    }
    return res;
}
//Phep nhap (>>);
istream& operator>>(istream& is, CMatrix& m) {
    cout << "Nhap so dong: ";
    is >> m.iRows;
    cout << "Nhap so cot: ";
    is >> m.iCols;
    m.val.assign(m.iRows, vector<double> (m.iCols, 0.0));
    for (int i = 0; i < m.iRows; i++) {
        for (int j = 0; j < m.iCols; j++) {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            is >> m.val[i][j];
        }
    }
    return is;
}
//Phep xuat (<<);
ostream& operator<<(ostream& os, const CMatrix& m) {
    for (int i = 0; i < m.iRows; i++) {
        for (int j = 0; j < m.iCols; j++) {
            os << m.val[i][j] << " ";
        }
        os << '\n';
    }
    return os;
}
