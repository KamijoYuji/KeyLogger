#include<iostream>
#include <string>
using namespace std;


class StrD {
public:
    string beta;
    int num;
    StrD(string beta, int num) {
        this->beta = beta;
        this->num = num;
    }
    StrD() {
        beta = "0";
        num = 0;
    }
    void setStrD(string beta) { this->beta = beta;}
    string getStrD() { return beta;}
    void setPoint(int n) { num = n; }
    int getPoint() { return num; }
private:
    void reverse(string& a1) {
        int s = a1.size();
        for (int i = 0; i < s / 2; i++) {
            char a = a1[i];
            a1[i] = a1[s - 1 - i];
            a1[s - 1 - i] = a;
        }
    }
public:
    //1234.546 + 45.1 -> 3 1. +2 45.100
    StrD operator +(StrD other) {
        auto a1 = getStrD();
        auto a2 = other.getStrD();
        auto n = getPoint() > other.getPoint() ? getPoint() : other.getPoint();

        if (getPoint() > other.getPoint())
        {
            int c = getPoint() - other.getPoint();
            while (c) {
                a2 += '0';
                c--;
            }

        }
        else {
            int c = other.getPoint() - getPoint();
            while (c) {
                a1 += '0';
                c--;
            }
        }

        reverse(a1);
        reverse(a2);

        while (a1.size() != a2.size()) {
            if (a1.size() > a2.size())
                a2 += '0';
            else
                a1 += '0';
        }

        auto s = a1.size() > a2.size() ? a1.size() : a2.size();
        string b = "";
        bool flag = 0;
        for (int i = 0; i < a1.size(); i++) {
            b += (((a1[i] - (2 * '0') + a2[i] + flag) % 10) + '0');
            flag = b[i] != (a1[i] + a2[i] + flag - '0');
        }
        if (flag)
            b += '1';
        reverse(b);
        StrD a(b, n);
        return a;
    }

    friend ostream& operator <<(ostream& o, StrD a) {
        auto c = a.getStrD();
        string b;
        for (int i = 0; i < c.size() + 1; i++)
            b += '.';
        int s = b.size();
        bool flag = 0;
        int p = a.getPoint();
        for (int i = 0; i < s-1; i++) {
            flag = (i == (s - 1 - p)) + flag;
            b[(i+flag)] = c[i];
        }
        o << b;
        if (!a.getPoint())
            o << '0';
        return o;
    }
};

int main() {
    StrD b1("12345343490639823493465969234121049325908649", 13);
    StrD b2("124999773452346457352453569", 20);
    //1234534349063982349346596923412.1049325908649 + 1249997.73452346457352453569
    StrD c = b1 + b2;

    cout << c;
    cout << endl<< 1234534349063982349346596923412.1049325908649 + 1249997.73452346457352453569 << endl;
    cout << StrD("9", 0) + StrD("1", 0);
    return 0;
}
