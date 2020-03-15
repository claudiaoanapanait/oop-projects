#include <iostream>
#include<math.h>
using namespace std;

class polinom {
private:
    double vect[1000000000];
    double length;
public:
    polinom(double len);
    polinom(polinom vect2[], double length);
    ~polinom();
    friend polinom operator + (polinom const &vect1, polinom const &vect2);
    friend polinom operator - (const polinom &vect1, const polinom &vect2);
    friend polinom operator * (const polinom &vect1, const polinom &vect2);
    friend double calculpct(const polinom &vect1, double x);
    void print(){
        cout<<"P=";
        cout<<vect[0];
        for(int i=1; i<=length-1; i++)
            cout<<" + "<<vect[i]<<"X la puterea "<<i;
    }
};
polinom::polinom(double len){
    int i;
    length=len;
    for (i=0; i<=len-1; i++)
        cin>>vect[i];
}
polinom::polinom(polinom vect2[], double length){
    int i;
    for(i=0; i<=vect2->length-1; i++)
        vect[i]=vect2->vect[i];
}
polinom::~polinom() {
    delete[] vect;
}
polinom operator + (polinom const &vect1, polinom const &vect2){
    polinom r(max(vect1.length, vect2.length));
    for(int i=0; i<=max(vect1.length, vect2.length)-1; i++)
        r.vect[i]=vect1.vect[i]+vect2.vect[i];
    return r;
}
polinom operator - (const polinom &vect1, const polinom &vect2){
    polinom r(max(vect1.length, vect2.length));
    for(int i=0; i<=max(vect1.length, vect2.length)-1; i++)
        r.vect[i]=vect1.vect[i]-vect2.vect[i];
    return r;
}
polinom operator * (const polinom &vect1, const polinom &vect2){
    polinom r(vect1.length*vect2.length);
    for(int i=0; i<=vect1.length-1; i++)
        for(int j=0; j<=vect2.length-1; j++){
            r.vect[i+j]=r.vect[i+j]+vect1.vect[i]*vect2.vect[j];
        }
    return r;
}
double calculpct(const polinom &vect1, double x) {
    double suma = 0;
    for (int i =vect1.length-1; i >= 0; i++)
        suma = suma + (pow(x, i)*vect1.vect[i]);
    return suma;
}
int max(double n, double m){
    if (n>=m)
        return n;
    else
        return m;
}
double n, m;
int main()
{   int x;
    cin>>n>>m>>x;
polinom vect1(n);
polinom vect2(m);
polinom vect3=vect1+vect2;
polinom vect4=vect1-vect2;
polinom vect5=vect1*vect2;
double suma=calculpct(vect1, x);
cout<<suma;
vect3.print();
vect4.print();
vect5.print();
return 0;
}
