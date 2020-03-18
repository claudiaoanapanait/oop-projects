#include <iostream>
#include<cmath>

using namespace std;

class polinom {
private:

    double *vect;
    int length;
public:
    polinom(int len, bool citire = true);

    polinom(polinom const &vect2);

    ~polinom();

    friend polinom operator+(polinom const &vect1, polinom const &vect2);

    friend polinom operator-(const polinom &vect1, const polinom &vect2);

    friend polinom operator*(const polinom &vect1, const polinom &vect2);

    friend double calculpct(const polinom &vect1, double x);

    void print(ostream &os) const {
        os << "P=";
        os << vect[0];
        for (int i = 1; i <= length - 1; i++)
            os << " + " << vect[i] << "X^" << i;
    }

    friend ostream &operator<<(ostream &os, const polinom &polinom);
};

polinom::polinom(int len, bool citire) {
    int i;
    length = len;
    vect = new double[len];
    if (citire)
        for (i = 0; i < len; i++)
            cin >> vect[i];
    else
        for (i = 0; i < len; i++)
            vect[i] = 0;
}

polinom::polinom(polinom const &vect2) {
    int i;
    length = vect2.length;
    vect = new double[length];
    for (i = 0; i < vect2.length; i++)
        vect[i] = vect2.vect[i];
}

polinom::~polinom() {
    delete[] vect;
}

polinom operator+(polinom const &vect1, polinom const &vect2) {
    polinom r(max(vect1.length, vect2.length), false);
    polinom const &p = vect1.length > vect2.length ? vect1 : vect2;
    for (int i = 0; i < min(vect1.length, vect2.length); i++)
        r.vect[i] = vect1.vect[i] + vect2.vect[i];
    for (int j = min(vect1.length, vect2.length); j < r.length; ++j)
        r.vect[j] = p.vect[j];
    return r;
}

polinom operator-(const polinom &vect1, const polinom &vect2) {

    polinom r(max(vect1.length, vect2.length), false);
    polinom const &p = vect1.length > vect2.length ? vect1 : vect2;

    for (int i = 0; i <= min(vect1.length, vect2.length) - 1; i++)
        r.vect[i] = vect1.vect[i] - vect2.vect[i];
    for (int j = min(vect1.length, vect2.length); j < r.length; ++j)
        r.vect[j] = p.vect[j];
    return r;
}

polinom operator*(const polinom &vect1, const polinom &vect2) {

    polinom r((vect1.length * vect2.length), false);

    for (int i = 0; i <= vect1.length - 1; i++)
        for (int j = 0; j <= vect2.length - 1; j++) {
            r.vect[i + j] = r.vect[i + j] + vect1.vect[i] * vect2.vect[j];
        }
    return r;
}

double calculpct(const polinom &vect1, double x) {

    double suma = 0;
    for (int i = vect1.length - 1; i >= 0; i--)
        suma = suma + (pow(x, i) * vect1.vect[i]);
    return suma;
}

ostream &operator<<(ostream &os, const polinom &polinom) {
    polinom.print(os);
    return os;
}


int main() {
    int m, n;
    int x;
    cin >> n >> m >> x;
    polinom vect1(n);
    polinom vect2(m);
    polinom vect3 = vect1 + vect2;
    polinom vect4 = vect1 - vect2;
    polinom vect5 = vect1 * vect2;
    double suma = calculpct(vect1, x);
    cout << "Suma=" << suma << endl;
    cout << vect3 << endl;
    cout << vect4 << endl;
    cout << vect5;
    return 0;
}
