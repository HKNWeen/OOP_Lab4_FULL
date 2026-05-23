#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED
#include <iostream>
class CTime {
private:
    int iGio;
    int iPhut;
    int iGiay;
    void ChuyenHoa();
public:
    CTime(int gio = 0, int phut = 0, int giay = 0);

    //prefix (++t): thay doi gia tri goc va return gia tri goc;
    CTime& operator++();
    //postfix (t++): tao mot ban sao cua gia tri goc, thay doi gia tri goc, return ban sao;
    CTime operator++(int);
    CTime& operator--();
    CTime operator--(int);

    CTime operator+(int giay);
    CTime operator-(int giay);

    friend std::ostream& operator<<(std::ostream&, const CTime& t);
    friend std::istream& operator>>(std::istream&, CTime& t);
};

#endif // CTIME_H_INCLUDED
