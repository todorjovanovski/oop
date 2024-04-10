#include <iostream>
using namespace std;

class Agol {
private:
    int stepeni, minuti, sekundi;
public:
    Agol(){}
    ~Agol(){}
    void set_stepeni(int c)
    {
        stepeni = c;
    }
    void set_minuti(int m)
    {
        minuti = m;
    }
    void set_sekundi(int s)
    {
        sekundi = s;
    }

    int getSekundi()
    {
        return sekundi;
    }

    int to_sekundi()
    {
        return stepeni*3600+minuti*60+sekundi;
    }

};

bool proveri(int stepeni, int minuti, int sekundi)
{
    if(stepeni <= 360 && stepeni > 0 && minuti <= 60 && minuti > 0 && sekundi <= 60 && sekundi >= 0)
    {
        return true;
    }
    else{
        return false;
    }
}

bool changeOfSeconds(Agol a, int sec){
	return a.getSekundi()!=sec;
}

int main() {

    //da se instancira objekt od klasata Agol
    Agol a1;
    int deg, min, sec;
    cin >> deg >> min >> sec;

    if (proveri(deg, min, sec)) {

    	a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1,sec))
			cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;
    }
    else{
        cout<<"Nevalidni vrednosti za agol"<<endl;
    }

    return 0;
}
