#include <iostream>
#include <cstring>

using namespace std;

class NegativeValueException{
private:
    char text[100];
public:
    NegativeValueException(char * text = "")
    {
        strcpy(this->text, text);
    }
    void print()
    {
        cout<<text;
    }
};


class Discount{
public:
    static double euro;
    static double dollar;

    virtual double discountPrice() = 0;
    virtual double price() = 0;
    virtual void printRule() = 0;
};
double Discount::euro = 61.6;
double Discount::dollar = 55.2;


class Product{
protected:
    char name[100];
    double price;
public:
    Product(char * name = "", double price = 0)
    {
        strcpy(this->name, name);
        this->price = price;
    }

    double getPrice()
    {
        return price;
    }
    void print()
    {
        cout<<name<< " - "<<price<<endl;
    }
    void changePrice(double newPrice)
    {
        if(newPrice < 0)
        {
            throw NegativeValueException("Vnesena e negativna vrednost za cena.");
        }
        else
        {
            price = newPrice;
            print();
        }
    }
};


class Cosmetics: public Product, public Discount{
private:
    int weight;
public:
    Cosmetics(char * name = "", double price = 0, int weight = 0) : Product(name, price)
    {
        this->weight = weight;
    }

    double discountPrice()
    {
        if(getPrice()/dollar > 20)
        {
            return getPrice()*0.86;
        }
        else if(getPrice()/euro > 5)
        {
            return getPrice()*0.88;
        }
        else{
            return getPrice();
        }
    }
    double price()
    {
        return getPrice();
    }
    void printRule()
    {
        cout<<"Poskapi od 5 eur imaat 12%, a poskapi od 20 usd imaat 14%"<<endl;
    }
};


class FoodProduct : public Product, public Discount{
private:
    double calories;
public:
    FoodProduct(char * name = "", double price = 0, double calores = 0) : Product(name, price)
    {
        this->calories = calores;
    }

    double discountPrice()
    {
        return getPrice();
    }
    double price()
    {
        return getPrice();
    }
    void printRule()
    {
        cout<<"Za hrana nema popust."<<endl;
    }
};


class Drinks : public Product, public Discount{
private:
    char brand[100];
    bool isAlchoholic;
public:
    Drinks(char * name = "", double price = 0, char *brand = "", bool isAlchoholic = false) : Product(name, price)
    {
        strcpy(this->brand, brand);
        this->isAlchoholic = isAlchoholic;
    }

    double discountPrice()
    {
        if(isAlchoholic && getPrice()/euro > 20)
        {
            return getPrice() * 0.95;
        }
        else if(!isAlchoholic && strcmp(brand, "Coca-Cola") == 0)
        {
            return getPrice() * 0.9;
        }
        else{
            return getPrice();
        }
    }
    double price()
    {
        return getPrice();
    }
    void printRule()
    {
        cout<<"Site alkoholni pijaloci pogolemi od 20 eur imaat 5% popust, a Coca-Cola ima 10% popust."<<endl;
    }
};

double totalDiscount(Discount ** d, int n)
{
    double discount = 0;
    for(int i=0; i<n; i++)
    {
        discount+=d[i]->discountPrice();
        cout<<"Prvicna cena bila: "<<d[i]->price()<<endl;
        cout<<"So popust: "<<d[i]->discountPrice()<<endl;
    }
    return discount;
}


int main()
{
    int n;
    cin>>n;
    double newPrice;
    int type;
    Discount **d = new Discount*[n];
    for(int i=0; i<n; i++)
    {
        char proizvod[50];
        double cena;
        cin>>proizvod;
        cin>>cena;
        cin>>type;
        if(type == 1)
        {
            double calories;
            cin>>calories;
            d[i] = new FoodProduct(proizvod, cena, calories);
        }
        else if(type == 2)
        {
            int weight;
            cin>>weight;
            d[i] = new Cosmetics(proizvod, cena, weight);
        }
        else if(type == 3)
        {
            char brand[50];
            bool alcoholic;
            cin>>brand;
            cin>>alcoholic;
            d[i] = new Drinks(proizvod, cena, brand, alcoholic);
        }
    }

    cout<<"Vkupna cena: "<<totalDiscount(d, n)<<endl;
    cout<<"Promena na cena (so isklucok): "<<endl;
    for(int i=0; i<n; i++)
    {
        Cosmetics *castedCosmetics = dynamic_cast<Cosmetics *>(d[i]);
        if(castedCosmetics)
        {
            castedCosmetics->print();
            cout<<"Nova cena: ";
            cin>>newPrice;
            try{
                castedCosmetics->changePrice(newPrice);
            }
            catch(NegativeValueException ex)
            {
                ex.print();
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        delete d[i];
    }
    delete [] d;

    return 0;
}
