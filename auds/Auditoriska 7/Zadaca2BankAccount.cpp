#include <iostream>
#include <cstring>

using namespace std;

class DebitAccount{
protected:
    char ime[100];
    long brSmetka;
    double saldo;
public:
    DebitAccount(char * ime = "", long brSmetka = 0, double saldo = 0)
    {
        strcpy(this->ime, ime);
        this->brSmetka = brSmetka;
        this->saldo = saldo;
    }

    void print()
    {
        cout << "Korisnik: " << ime << endl << "Broj na smetka: " << brSmetka << endl;
        cout << "Saldo: " << saldo <<endl;
    }

    void deposit(double kolku)
    {
        if(kolku >= 0)
        {
            saldo += kolku;
        }
        else{
            cout<< "Vnesete validna suma za deponiranje." <<endl;
        }
    }

    void withdraw(double kolku)
    {
        if(kolku < 0)
        {
            cout<< "Vnesete validna suma za povlekuvanje." <<endl;
            return;
        }
        if(kolku <= saldo)
        {
            saldo -= kolku;
        }
        else{
            cout<< "Nemate dovolno sredstva." <<endl;
        }
    }
};

class CreditAccount: public DebitAccount{
private:
    double minus;
    double limit;
    double kamata;
public:
    CreditAccount(char * ime = "", long brSmetka = 0, double saldo = 0,
    double limit = 1000, double minus = 0, double kamata = 0.05) : DebitAccount(ime, brSmetka, saldo)
    {
        this->minus = minus;
        this->limit = limit;
        this->kamata = kamata;
    }

    void print()
    {
        DebitAccount::print();
        cout<< "Limit: "<< limit <<endl<< "Minus: " << minus <<endl<< "Kamata: " << kamata <<endl;
    }

    void withdraw(double kolku)
    {
        if(kolku <= saldo)
        {
            DebitAccount::withdraw(kolku);
        }
        else if(kolku <= saldo + limit - minus){
            double zaem = kolku - saldo;
            minus += zaem * (1.0 + kamata);
            cout<<"Minus: "<<zaem<<endl;
            cout<<"Kamata: "<<zaem*kamata<<endl;
            deposit(zaem);
            DebitAccount::withdraw(kolku);
        }
        else{
            cout<<"Nemate dovolno sredstva."<<endl;
            this->print();
        }
    }

};

int main()
{
    DebitAccount deb("Deki", 12345, 100000);
    CreditAccount cred("Roki", 54321, 50000, 20000);

    deb.print();

    deb.deposit(50000);
    deb.withdraw(60000);
    deb.print();

    cred.print();
    cred.deposit(10000);
    cred.print();
    cred.withdraw(65000);
    cred.print();

    return 0;
}
