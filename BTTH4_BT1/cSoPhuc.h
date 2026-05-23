#ifndef CSOPHUC_H_INCLUDED
#define CSOPHUC_H_INCLUDED
#include <iostream>

class cSoPhuc {
private:
    double iThuc, iAo;
public:
    cSoPhuc(double thuc = 0.0, double ao = 0.0);

    /*Dung friend/non-member operator de ho tro phep toan giua so phuc va so thuc o ca hai ben.
    vi du: khong friend (la member cua class): cSoPhuc * 5.5 (duoc), 5.5 * cSoPhuc (khong);
    co friend (khong phai member cua class): cSoPhuc * 5.5 (duoc), 5.5 * cSoPhuc (duoc);
    */
    //Nap chong toan tu so hoc;
    friend cSoPhuc operator+(const cSoPhuc &a, const cSoPhuc &b);
    friend cSoPhuc operator-(const cSoPhuc &a, const cSoPhuc &b);
    friend cSoPhuc operator*(const cSoPhuc &a, const cSoPhuc &b);
    friend cSoPhuc operator/(const cSoPhuc &a, const cSoPhuc &b);

    //Nap chong toan tu so sanh;
    friend bool operator==(const cSoPhuc &a, const cSoPhuc &b);
    friend bool operator!=(const cSoPhuc &a, const cSoPhuc &b);

    //Nap chong toan tu nhap xuat;
    friend std::ostream& operator<<(std::ostream& os, const cSoPhuc& sp);
    friend std::istream& operator>>(std::istream& is, cSoPhuc& sp);
};

#endif // CSOPHUC_H_INCLUDED
