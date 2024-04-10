#include<iostream>
using namespace std;


class Vozilo{
protected:
    double mass;
    int height, width;
public:
    Vozilo(double mass = 0, int height = 0, int width = 0)
    {
        this->mass = mass;
        this->height = height;
        this->width = width;
    }

    virtual double getMass() = 0;

    virtual int getHeight() = 0;

    virtual int getWidth() = 0;

    virtual int vratiDnevnaCena() = 0;
};


class Avtomobil : public Vozilo{
private:
    int doors;
public:
    Avtomobil(double mass = 0, int height = 0, int width = 0,
    int doors = 0) : Vozilo(mass, height, width)
    {
        this->doors = doors;
    }

    double getMass()
    {
        return mass;
    }
    int getHeight()
    {
        return height;
    }
    int getWidth()
    {
        return width;
    }
    int getDoors()
    {
        return doors;
    }
    int vratiDnevnaCena()
    {
        if(doors < 5)
        {
            return 100;
        }
        else return 130;
    }
};


class Avtobus : public Vozilo{
private:
    int passengers;
public:
    Avtobus(double mass = 0, int height = 0, int width = 0,
    int passengers = 0) : Vozilo(mass, height, width)
    {
        this->passengers = passengers;
    }

    double getMass()
    {
        return mass;
    }
    int getHeight()
    {
        return height;
    }
    int getWidth()
    {
        return width;
    }
    int getPassengers()
    {
        return passengers;
    }
    int vratiDnevnaCena()
    {
        return 5*passengers;
    }
};


class Kamion : public Vozilo{
private:
    double weightLimit;
public:
    Kamion(double mass = 0, int height = 0, int width = 0,
    double weightLimit = 0) : Vozilo(mass, height, width)
    {
        this->weightLimit = weightLimit;
    }

    double getMass()
    {
        return mass;
    }
    int getHeight()
    {
        return height;
    }
    int getWidth()
    {
        return width;
    }
    double getWeightLimit()
    {
        return weightLimit;
    }
    int vratiDnevnaCena()
    {
        return (mass + weightLimit)*0.02;
    }
};


class ParkingPlac{
private:
    Vozilo **vozila;
    int n;
public:
    ParkingPlac(Vozilo ** vozila = 0, int n = 0)
    {
        this->n = n;
        this->vozila = new Vozilo*[n];
        for(int i=0; i<n; i++)
        {
            this->vozila[i] = vozila[i];
        }
    }
    ParkingPlac(const ParkingPlac &p)
    {
        this->n = p.n;
        this->vozila = new Vozilo*[p.n];
        for(int i=0; i<n; i++)
        {
            this->vozila[i] = p.vozila[i];
        }
    }
    ParkingPlac& operator=(const ParkingPlac &p)
    {
        if(this!=&p)
        {
            this->n = p.n;
            this->vozila = new Vozilo*[p.n];
            for(int i=0; i<n; i++)
            {
                this->vozila[i] = p.vozila[i];
            }
        }
        return * this;
    }
    ~ParkingPlac()
    {
        delete [] vozila;
    }

    ParkingPlac& operator+=(Vozilo * v)
    {
        Vozilo ** temp = new Vozilo*[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i] = vozila[i];
        }
        temp[n++] = v;
        delete [] vozila;
        vozila = temp;
        return * this;
    }

    float presmetajVkupnaMasa()
    {
        float sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += vozila[i]->getMass();
        }
        return sum;
    }
    int brojVozilaPoshirokiOd(int w)
    {
        int counter = 0;
        for(int i=0; i<n; i++)
        {
            if(vozila[i]->getHeight() > w)
            {
                counter++;
            }
        }
        return counter;
    }
    int pogolemaNosivostOd(Vozilo& v)
    {
        int counter = 0;
        for(int i=0; i<n; i++)
        {
            Kamion *castedKamion = dynamic_cast<Kamion *>(vozila[i]);
            if(castedKamion && castedKamion->getWeightLimit() > v.getMass())
            {
                counter++;
            }
        }
        return counter;
    }
    void pecati()
    {
        int countAvtomobil = 0, countAvtobus = 0, countKamion = 0;
        for(int i=0; i<n; i++)
        {
            Avtomobil *castedAvtomobil = dynamic_cast<Avtomobil *>(vozila[i]);
            Avtobus *castedAvtobus = dynamic_cast<Avtobus *>(vozila[i]);
            Kamion *castedKamion = dynamic_cast<Kamion *>(vozila[i]);
            if(castedAvtomobil)
            {
                countAvtomobil++;
            }
            else if(castedAvtobus)
            {
                countAvtobus++;
            }
            else if(castedKamion)
            {
                countKamion++;
            }
        }

        cout<< "Brojot na avtomobili e " <<countAvtomobil<<  ", brojot na avtobusi e ";
        cout<<countAvtobus<< " i brojot na kamioni e " <<countKamion<<"."<<endl;
    }
    int vratiDnevnaZarabotka()
    {
        int sum = 0;
        for(int i = 0; i<n; i++)
        {
            sum += vozila[i]->vratiDnevnaCena();
        }
        return sum;
    }
};



int main(){
    ParkingPlac p;

    int n;
    cin>>n;
    int shirina,visina, broj;
    float masa,nosivost;
    for (int i=0;i<n;i++){
        int type;
        cin>>type;
        if(type==1){
            cin>>masa>>shirina>>visina>>broj;
            Avtomobil *a=new Avtomobil(masa,shirina,visina,broj);
            p+=a;
        }
        if(type==2){
            cin>>masa>>shirina>>visina>>broj;
            p+=new Avtobus(masa,shirina,visina,broj);
        }
        if(type==3){
            cin>>masa>>shirina>>visina>>nosivost;
            p+=new Kamion(masa,shirina,visina,nosivost);
        }
    }

    p.pecati();

    cout<<"\nZarabotkata e "<<p.vratiDnevnaZarabotka()<<endl;
    cout<<"Vkupnata masa e "<<p.presmetajVkupnaMasa()<<endl;
    cout<<"Brojot poshiroki od 5 e "<<p.brojVozilaPoshirokiOd(5)<<endl;
    Avtomobil a(1200,4,3,5);
    cout<<"Brojot na kamioni so nosivost pogolema od avtomobilot e "<<p.pogolemaNosivostOd(a)<<endl;

    return 0;
}
