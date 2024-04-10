//// overload_date.cpp
//// compile with: /EHsc
//#include <iostream>
//using namespace std;
//
//class Date
//{
//    int mo, da, yr;
//public:
//    Date(int m, int d, int y)
//    {
//        mo = m; da = d; yr = y;
//    }
//    friend ostream& operator<<(ostream& os, const Date& dt);
//};
//
//ostream& operator<<(ostream& os, const Date& dt)
//{
//    os << dt.mo << '/' << dt.da << '/' << dt.yr;
//    return os;
//}
//
//int main()
//{
//    Date dt(5, 6, 92);
//    cout << dt;
//}


#include<iostream>
#include<cstring>
using namespace std;

// vasiot kod za klasite ovde

class StockRecord{
private:
    char id[12], kompanija[50];
    double nabavna_cena, momentalna_cena;
    int broj_akcii;
    //double prafit = 0;
public:
    StockRecord(char * id = "", char * kompanija = "", double nabavna_cena = 0,  int broj_akcii = 0, double momentalna_cena = 0)
    {
        strcpy(this->id, id);
        strcpy(this->kompanija, kompanija);
        this->nabavna_cena = nabavna_cena;
        this->momentalna_cena = momentalna_cena;
        this->broj_akcii = broj_akcii;
        //prafit += profit();
    }
    ~StockRecord(){}

    void setNewPrice(double c)
    {
        momentalna_cena = c;
    }
    double value()
    {
        return (double)broj_akcii * momentalna_cena;
    }
    double profit()const
    {
        return (double)broj_akcii * (momentalna_cena - nabavna_cena);
    }

    friend ostream& operator<<(ostream& os, const StockRecord& sr);

};

ostream& operator<<(ostream& os, const StockRecord& sr)
    {
        os<<sr.kompanija<<" "<<sr.broj_akcii<<" "<<sr.nabavna_cena<<" "<<sr.momentalna_cena<<" "<<sr.profit()<<endl;
        return os;
    }

class Client{
private:
    char ime_prezime[60];
    int ID;
    StockRecord * kompanii;
    int n;
public:
    Client(char *ime_prezime = 0, int ID = 0, StockRecord * kompanii = 0, int n = 0)
    {
        strcpy(this->ime_prezime, ime_prezime);
        this->ID = ID;
        this->n = n;
        this->kompanii = new StockRecord[n];
        for(int i=0; i<n; i++)
        {
            this->kompanii[i] = kompanii[i];
        }
    }
    Client(const Client &c)
    {
        strcpy(ime_prezime, c.ime_prezime);
        ID = c.ID;
        n = c.n;
        kompanii = new StockRecord[c.n];
        for(int i=0; i<n; i++)
        {
            kompanii[i] = c.kompanii[i];
        }
    }
    Client& operator=(const Client &c)
    {
        if(this!=&c)
        {
            strcpy(ime_prezime, c.ime_prezime);
            ID = c.ID;
            n = c.n;
            delete [] kompanii;
            kompanii = new StockRecord[c.n];
            for(int i=0; i<n; i++)
            {
                kompanii[i] = c.kompanii[i];
            }
        }
        return *this;
    }
    ~Client()
    {
        delete [] kompanii;
    }

    double totalValue() const
    {
        double total = 0;
        for(int i=0; i<n; i++)
        {
            total += kompanii[i].value();
        }
        return total;
    }

    Client& operator +=(const StockRecord &c)
    {
        StockRecord * temp = new StockRecord[n + 1];
        for(int i=0; i<n; i++)
        {
            temp[i] = kompanii[i];
        }
        temp[n++] = c;
        delete [] kompanii;
        kompanii = temp;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Client& c);

};

ostream& operator<<(ostream& os, const Client& c)
{
    os<<c.ID<<" "<<c.totalValue()<<endl;
    for(int i=0; i<c.n; i++)
    {
        cout<<c.kompanii[i];
    }
    return os;
}

// ne menuvaj vo main-ot

int main(){

    int test;
    cin >> test;

    if(test == 1){
    	double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
    	char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for(int i = 0; i < n; ++i){
        	cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    }
    else if(test == 3){
    	cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
        	StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
//            cout<<c;
//            cout<<"TEST"<<endl;
            c += sr;
            if(flag){
            	cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}
