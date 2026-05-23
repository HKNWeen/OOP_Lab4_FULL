#ifndef CDATHUC_H_INCLUDED
#define CDATHUC_H_INCLUDED
#include <iostream>
#include <vector>

class CDaThuc {
private:
    int bac;
    std::vector <double> heso;
    void ChuanHoa();
public:
    CDaThuc();
    CDaThuc(int b);

    CDaThuc operator+(const CDaThuc& other) const;
    CDaThuc operator-(const CDaThuc& other) const;
    CDaThuc operator*(const CDaThuc& other) const;
    double TinhGiaTri(double x) const;

    friend std::istream& operator>>(std::istream& is, CDaThuc& dt);
    friend std::ostream& operator<<(std::ostream& os, const CDaThuc& dt);
};

#endif // CDATHUC_H_INCLUDED
