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
    friend Rational operator+ (Rational&, Rational&);
    friend Rational operator+ (int&, Rational&);
    friend Rational operator+ (Rational&, int&);
    friend Rational operator- (Rational&, Rational&);
    friend Rational operator- (int&, Rational&);
    friend Rational operator- (Rational&, int&);
    friend Rational operator* (Rational&, Rational&);
    friend Rational operator* (int&, Rational&);
    friend Rational operator* (Rational&, int&);
    friend Rational operator/ (Rational&, Rational&);
    friend Rational operator/ (int&, Rational&);
    friend Rational operator/ (Rational&, int&);
    
    friend ostream& operator<< (ostream&, Rational&);
};

Rational operator+ (Rational& left, Rational& right) {
    int znam = NOK(left.getZnam(), right.getZnam());
    int chis = left.getChis() * (znam / left.getZnam()) + right.getChis() * (znam / right.getZnam());
    Rational result(chis, znam);
    return result;
}

Rational operator+ (int& left, Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational + right;
    return result;
}

Rational operator+ (Rational& left, int& right) {
    Rational rightRational = right;
    Rational result = left + rightRational;
    return result;
}

Rational operator- (Rational& left, Rational& right) {
    int znam = NOK(left.getZnam(), right.getZnam());
    int chis = left.getChis() * (znam / left.getZnam()) - right.getChis() * (znam / right.getZnam());
    Rational result(chis, znam);
    return result;
}

Rational operator- (int& left, Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational - right;
    return result;
}

Rational operator- (Rational& left, int& right) {
    Rational rightRational = right;
    Rational result = left - rightRational;
    return result;
}

Rational operator* (Rational& left, Rational& right) {
    int chis = left.getChis() * right.getChis();
    int znam = left.getZnam() * right.getZnam();
    Rational result(chis, znam);
    return result;
}

Rational operator* (int& left, Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational * right;
    return result;
}

Rational operator* (Rational& left, int& right) {
    Rational rightRational = right;
    Rational result = left * rightRational;
    return result;
}

Rational operator/ (Rational& left, Rational& right) {
    Rational nright(right.getZnam(), right.getChis());
    Rational result = left * nright;
    return result;
}

Rational operator/ (int& left, Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational / right;
    return result;
}

Rational operator/ (Rational& left, int& right) {
    Rational rightRational = right;
    Rational result = left / rightRational;
    return result;
}

ostream& operator<< (ostream& out, Rational& r) {
    out << r.getChis() << '/' << r.getZnam() << endl;
    return out;
}

int main()
{
    int a = 9;
    Rational b(5, 3);
    Rational c(1, 4);
    Rational l = a / c;
    cout << l;
}
