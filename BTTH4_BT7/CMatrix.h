#ifndef CMATRIX_H_INCLUDED
#define CMATRIX_H_INCLUDED
#include <vector>
#include <iostream>
class CMatrix {
private:
    int iRows;
    int iCols;
    std::vector<std::vector<double>> val;
public:
    CMatrix();
    CMatrix(int r, int c);

    int getiRows() const;
    int getiCols() const;

    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;
    CMatrix operator*(const CMatrix& other) const;
    std::vector<double> operator* (const std::vector<double>& v) const;

    friend std::ostream& operator<<(std::ostream& os, const CMatrix& m);
    friend std::istream& operator>>(std::istream& is, CMatrix& m);
};

#endif // CMATRIX_H_INCLUDED
