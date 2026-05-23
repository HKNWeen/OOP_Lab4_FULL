#ifndef CVECTOR_H_INCLUDED
#define CVECTOR_H_INCLUDED
#include <vector>
#include <iostream>

class CVector {
private:
    std::vector<double> toado;
public:
    CVector();
    CVector(int n);
    int getChieu() const;

    double& operator[](int index);
    double operator[](int index) const;
    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;
    CVector operator*(double val) const;
    double operator*(const CVector& other) const;

    friend std::ostream& operator<<(std::ostream& os, const CVector& other);
    friend std::istream& operator>>(std::istream& is, CVector& other);
};

#endif // CVECTOR_H_INCLUDED
