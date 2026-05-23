#ifndef CDATE_H_INCLUDED
#define CDATE_H_INCLUDED
#include <iostream>
class CDate {
private:
    int iNgay;
    int iThang;
    int iNam;
    bool KiemTraNamNhuan() const;
    bool KiemTraHopLe() const;
    void ChuanHoa();
    int TinhNgayTuDau() const;
public:
    CDate (int ngay = 1, int thang = 1, int nam = 1);

    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);

    CDate operator+(int ngay) const;
    CDate operator-(int ngay) const;

    int operator-(const CDate& other) const;

    friend std::ostream& operator<<(std::ostream& os, const CDate& d);
    friend std::istream& operator>>(std::istream& is, CDate& d);
};

#endif // CDATE_H_INCLUDED
