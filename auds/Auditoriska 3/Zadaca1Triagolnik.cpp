#include <iostream>
#include <cmath>
using namespace std;

class Triagolnik{
private:
    int a, b, c;

public:
    Triagolnik(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
    ~Triagolnik(){}

    int perimetar()
    {
        return a+b+c;
    }

    float plostina()
    {
        float s = (a+b+c)/2.0;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }


};

int main()
{
    int a, b, c;
    cin>>a>>b>>c;

    Triagolnik t(a, b, c);

    cout<<"Plostina na triagolnikot: "<<t.plostina()<<endl;
    cout<<"Perimetar na triagolnikot: "<<t.perimetar();

    return 0;
}
