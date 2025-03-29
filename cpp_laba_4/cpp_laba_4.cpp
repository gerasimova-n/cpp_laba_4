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
    
    int getZnam() const { return znam; }
    int getChis() const { return chis; }
    friend Rational operator+ (const Rational&, const Rational&);
    friend Rational operator+ (int, const Rational&);
    friend Rational operator+ (const Rational&, int);
    friend Rational operator- (const Rational&, const Rational&);
    friend Rational operator- (int, const Rational&);
    friend Rational operator- (const Rational&, int);
    friend Rational operator* (const Rational&, const Rational&);
    friend Rational operator* (int, const Rational&);
    friend Rational operator* (const Rational&, int);
    friend Rational operator/ (const Rational&, const Rational&);
    friend Rational operator/ (int, const Rational&);
    friend Rational operator/ (const Rational&, int);
    
    friend ostream& operator<< (ostream&, Rational&);
};

Rational operator+ (const Rational& left, const Rational& right) {
    int znam = NOK(left.getZnam(), right.getZnam());
    int chis = left.getChis() * (znam / left.getZnam()) + right.getChis() * (znam / right.getZnam());
    Rational result(chis, znam);
    return result;
}

Rational operator+ (int left, Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational + right;
    return result;
}

Rational operator+ (Rational& left, int right) {
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

Rational operator- (int left, Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational - right;
    return result;
}

Rational operator- (Rational& left, int right) {
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

Rational operator* (int left, Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational * right;
    return result;
}

Rational operator* (Rational& left, int right) {
    Rational rightRational = right;
    Rational result = left * rightRational;
    return result;
}

Rational operator/ (Rational& left, Rational& right) {
    Rational nright(right.getZnam(), right.getChis());
    Rational result = left * nright;
    return result;
}

Rational operator/ (int left, Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational / right;
    return result;
}

Rational operator/ (Rational& left, int right) {
    Rational rightRational = right;
    Rational result = left / rightRational;
    return result;
}

ostream& operator<< (ostream& out, Rational& r) {
    out << r.getChis() << '/' << r.getZnam() << endl;
    return out;
}

bool operator> (Rational& left, Rational& right) {
    int znam = NOK(left.getZnam(), right.getZnam());
    int chisl = left.getChis() * (znam / left.getZnam());
    int chisr = right.getChis() * (znam / right.getZnam());
    return chisl > chisr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Вводим числа 3 и -9" << "\n" << "Результат: ";
    Rational num1(3, -9);
    cout << num1 << endl;

    cout << "Вводим число 3" << "\n" << "Результат: ";
    Rational num2 = 3; //испльзуется конструктор преобразования
    cout << num2 << endl;

    Rational num3(2, 3);
    Rational num4(3, 5);

    Rational res = num3 - num4;
    cout << "2/3 - 3/5 = " << res << endl;

    Rational res4 = num3 - 3;
    cout << "2/3 - 3 = " << res4 << endl;

    Rational res2 = num3 * num4;
    cout << "2/3 * 3/5 = " << res2 << endl;

    Rational res3 = num3 * 5;
    cout << "2/3 * 5 = " << res3 << endl;

    Rational res5 = num3 / num4;
    cout << "2/3 / 3/5 = " << res5 << endl;
    
    //переделать с выводом текстика, а не 0 и 1
    bool res6 = num3 > num4;
    cout << "2/3 > 3/5 = " << res6 << endl;
}
