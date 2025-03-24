#include <iostream>
using namespace std;

//нахождение НОД методом Евклида
int NOD(int a, int b) {
    if (b == 0)
        return a;
    return NOD(b, a % b);
}

//нахождение НОК
int NOK(int a, int b) {
    return a * b / NOD(a, b);
}

class Rational {
    int chis;
    int znam;

public:
    Rational(int c = 1, int z = 1) : chis(c), znam(z) {
        if ((znam < 0 && chis>0) || (znam < 0 && chis < 0)) {
            chis *= -1;
            znam *= -1;
        }
        int nod = abs(NOD(chis, znam));
        chis /= nod;
        znam /= nod;
    }
    
    int getZnam() { return znam; }
    int getChis() { return chis; }
    friend Rational operator+ (const Rational&, const Rational&);
    friend Rational operator- (const Rational&, const Rational&);
    friend Rational operator* (const Rational&, const Rational&);
    friend Rational operator/ (const Rational&, const Rational&);

    void print() {
        cout << getChis() << '/' << getZnam() << endl;
    }
};

Rational operator+ (Rational& left, Rational& right) {
    int znam = NOK(left.getZnam(), right.getZnam());
    int chis = left.getChis() * (znam / left.getZnam()) + right.getChis() * (znam / right.getZnam());
    Rational sum(chis, znam);
    return sum;
}

int main()
{
    Rational a;
    Rational b = 9;
    Rational c(3, 6);
    Rational l = b + c;
    l.print();
}
