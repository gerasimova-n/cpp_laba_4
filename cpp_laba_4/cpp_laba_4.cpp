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
    
    friend Rational operator+ (const Rational&, const Rational&);
    friend Rational operator- (const Rational&, const Rational&);
    friend Rational operator* (const Rational&, const Rational&);
    friend Rational operator/ (const Rational&, const Rational&);
    friend bool operator> (const Rational&, const Rational&);
    friend bool operator== (const Rational&, const Rational&);
    friend double rationalInDouble(const Rational&);
    
    friend ostream& operator<< (ostream&, const Rational&);
};

Rational operator+ (const Rational& left, const Rational& right) {
    int znam = NOK(left.znam, right.znam);
    int chis = left.chis * (znam / left.znam) + right.chis * (znam / right.znam);
    Rational result(chis, znam);
    return result;
}

Rational operator+ (const int left, const Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational + right;
    return result;
}

Rational operator+ (const Rational& left, const int right) {
    Rational rightRational = right;
    Rational result = left + rightRational;
    return result;
}

Rational operator- (const Rational& left, const Rational& right) {
    int znam = NOK(left.znam, right.znam);
    int chis = left.chis * (znam / left.znam) - right.chis * (znam / right.znam);
    Rational result(chis, znam);
    return result;
}

Rational operator- (const int left, const Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational - right;
    return result;
}

Rational operator- (const Rational& left, const int right) {
    Rational rightRational = right;
    Rational result = left - rightRational;
    return result;
}

Rational operator* (const Rational& left, const Rational& right) {
    int chis = left.chis * right.chis;
    int znam = left.znam * right.znam;
    Rational result(chis, znam);
    return result;
}

Rational operator* (const int left, const Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational * right;
    return result;
}

Rational operator* (const Rational& left, const int right) {
    Rational rightRational = right;
    Rational result = left * rightRational;
    return result;
}

Rational operator/ (const Rational& left, const Rational& right) {
    Rational nright(right.znam, right.chis);
    Rational result = left * nright;
    return result;
}

Rational operator/ (const int left, const Rational& right) {
    Rational leftRational = left;
    Rational result = leftRational / right;
    return result;
}

Rational operator/ (const Rational& left, const int right) {
    Rational rightRational = right;
    Rational result = left / rightRational;
    return result;
}

ostream& operator<< (ostream& out, const Rational& r) {
    out << r.chis << '/' << r.znam << endl;
    return out;
}

bool operator> (const Rational& left, const Rational& right) {
    int znam = NOK(left.znam, right.znam);
    int chisl = left.chis * (znam / left.znam);
    int chisr = right.chis * (znam / right.znam);
    return chisl > chisr;
}

bool operator> (const int left, const Rational& right) {
    Rational leftRational = left;
    bool result = leftRational > right;
    return result;
}

bool operator> (const Rational& left, const int right) {
    Rational rightRational = right;
    bool result = left > rightRational;
    return result;
}

bool operator< (const Rational& left, const Rational& right) {
    return !(left > right);
}

bool operator< (const int left, const Rational& right) {
    Rational leftRational = left;
    bool result = leftRational < right;
    return result;
}

bool operator< (const Rational& left, const int right) {
    Rational rightRational = right;
    bool result = left < rightRational;
    return result;
}

bool operator== (const Rational& left, const Rational& right) {
    return (left.chis == right.chis) && (left.znam == right.znam);
}

bool operator== (const int left, const Rational& right) {
    Rational leftRational = left;
    bool result = leftRational == right;
    return result;
}

bool operator== (const Rational& left, const int right) {
    Rational rightRational = right;
    bool result = left == rightRational;
    return result;
}

bool operator!= (const Rational& left, const Rational& right) {
    return !(left==right);
}

bool operator!= (const int left, const Rational& right) {
    Rational leftRational = left;
    bool result = leftRational != right;
    return result;
}

bool operator!= (const Rational& left, const int right) {
    Rational rightRational = right;
    bool result = left != rightRational;
    return result;
}

bool operator>= (const Rational& left, const Rational& right) {
    return (left>right)||(left==right);
}

bool operator>= (const int left, const Rational& right) {
    Rational leftRational = left;
    bool result = leftRational >= right;
    return result;
}

bool operator>= (const Rational& left, const int right) {
    Rational rightRational = right;
    bool result = left >= rightRational;
    return result;
}

bool operator<= (const Rational& left, const Rational& right) {
    return (left < right) || (left == right);
}

bool operator<= (const int left, const Rational& right) {
    Rational leftRational = left;
    bool result = leftRational <= right;
    return result;
}

bool operator<= (const Rational& left, const int right) {
    Rational rightRational = right;
    bool result = left <= rightRational;
    return result;
}

double rationalInDouble (const Rational& num) {
    return ((double)num.chis/(double)num.znam);
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
    
    bool res6 = num3 > num4;
    if (res6 == 1)
        cout << "2/3 > 3/5" << '\n' << endl;
    else
        cout << "2/3 < 3/5" << '\n' << endl;

    bool res7 = num3 == num4;
    if (res7 == 1)
        cout << "2/3 == 3/5" << '\n' << endl;
    else
        cout << "2/3 != 3/5" << '\n' << endl;

    cout << "Представим 2/3 как double: ";
    double res8 = rationalInDouble(num3);
    cout << res8 << endl;
}
