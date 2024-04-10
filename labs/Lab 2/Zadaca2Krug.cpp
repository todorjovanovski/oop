#include <iostream>
#include <cmath>
using namespace std;

class Krug {
private:
    float radius;
    const float pi = 3.14;
public:
    Krug(){}
    Krug(float r)
    {
        radius = r;
    }
    ~Krug(){}

    float plostina()
    {
        return radius*radius*pi;
    }
    float perimetar()
    {
        return 2*radius*pi;
    }
    bool ednakvi()
    {
        if(plostina() == perimetar())
        {
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
	float r;
	cin >> r;
	//instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura
	Krug k(r);

	cout << k.perimetar() << endl;
	cout << k.plostina() << endl;
	cout << k.ednakvi() <<endl;
    //instanciraj objekt od klasata Krug cij radius ne e definiran
	return 0;
}
