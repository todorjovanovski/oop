#include <cstring>
#include <iostream>
using namespace std;

// Your Code goes here
class Pizza{
protected:
    char ime[21];
    char sostojki[101];
    double cena;
public:
    Pizza(char * ime, char * sostojki, double cena)
    {
        strcpy(this->ime, ime);
        strcpy(this->sostojki, sostojki);
        this->cena = cena;
    }

    virtual double prodaznaCena() = 0;
    virtual void pecati(ostream& where) = 0;

    friend bool operator <(Pizza &p1, Pizza &p2);
    friend ostream& operator<<(ostream& os, Pizza &p);
};
bool operator <(Pizza &p1, Pizza &p2)
{
    if(p1.prodaznaCena() < p2.prodaznaCena())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& os, Pizza &p)
{
    p.pecati(os);
    return os;
}

enum Size{
mala, golema, familijarna
};

class FlatPizza : public Pizza{
private:
    Size golemina;
public:
    FlatPizza(char * ime, char * sostojki, double cena = 0, Size golemina = mala) : Pizza(ime, sostojki, cena)
    {
        this->golemina = golemina;
    }

    double prodaznaCena()
    {
        if(golemina == mala)
        {
            return cena*1.1;
        }
        else if(golemina == golema)
        {
            return cena*1.5;
        }
        else if(golemina == familijarna)
        {
            return cena*1.3;
        }
    }

    void pecati(ostream &os)
    {
        os<<ime<< ": " <<sostojki<< ", " ;
        if(golemina == mala)
        {
            os<<"small";
        }
        else if(golemina == golema)
        {
            os<<"big";
        }
        else if(golemina == familijarna)
        {
            os<<"family";
        }
        os<<" - "<<prodaznaCena()<<endl;
    }
};

class FoldedPizza: public Pizza{
private:
    bool belo;
public:
    FoldedPizza(char * ime, char * sostojki, double cena = 0, bool belo = true) : Pizza(ime, sostojki, cena)
    {
        this->belo = belo;
    }

    double prodaznaCena()
    {
        if(belo)
        {
            return cena*1.1;
        }
        else
        {
            return cena*1.3;
        }
    }

    void pecati(ostream& os)
    {
        os<<ime<< ": " <<sostojki<< ", " ;
        if(belo)
        {
            os<<"wf";
        }
        else
        {
            os<<"nwf";
        }
        os<<" - "<<prodaznaCena()<<endl;
    }

    void setWhiteFlour(bool brasno)
    {
        belo = brasno;
    }

};

void expensivePizza(Pizza ** pici, int n)
{
    Pizza * max = pici[0];
    for(int i=0; i<n; i++)
    {
        if(*max < *pici[i])
        {
            max = pici[i];
        }
    }
    cout<<*max;
}


// Testing

int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Size size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Size)s);
    cout << fp;

  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setWhiteFlour(false);
    cout << fp;

  } else if (test_case == 5) {
	// Test Cast - operator <, price
    int s;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp1;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp2;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setWhiteFlour(false);
    cout << *fp4;

    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->prodaznaCena()<<endl;
    else cout<<fp2->prodaznaCena()<<endl;

    if(*fp1<*fp3)
        cout<<fp1->prodaznaCena()<<endl;
    else cout<<fp3->prodaznaCena()<<endl;

    if(*fp4<*fp2)
        cout<<fp4->prodaznaCena()<<endl;
    else cout<<fp2->prodaznaCena()<<endl;

    if(*fp3<*fp4)
        cout<<fp3->prodaznaCena()<<endl;
    else cout<<fp4->prodaznaCena()<<endl;

  } else if (test_case == 6) {
	// Test Cast - expensivePizza
    int num_p;
    int pizza_type;

    cin >> num_p;
    Pizza **pi = new Pizza *[num_p];
    for (int j = 0; j < num_p; ++j) {

      cin >> pizza_type;
      if (pizza_type == 1) {
        cin.get();
        cin.getline(name,20);

        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << (*fp);
        pi[j] = fp;
      }
      if (pizza_type == 2) {

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp =
            new FoldedPizza (name, ingredients, inPrice);
        if(j%2)
          (*fp).setWhiteFlour(false);
        cout << (*fp);
        pi[j] = fp;

      }
    }

    cout << endl;
    cout << "The most expensive pizza:\n";
    expensivePizza(pi,num_p);


  }
  return 0;
}
