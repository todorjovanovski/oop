#include<cstring>
#include<iostream>
using namespace std;

class Secret{
public:
    //deklariranje na chisto virtuelnite metodi
    virtual double simpleEntropy() = 0;
    virtual int total() = 0;

    friend bool operator==(Secret & s1, Secret & s2);

    friend bool operator!=(Secret & s1, Secret & s2);
};

//preoptovaruvanje na operator ==
bool operator==(Secret & s1, Secret & s2)
{
    if(s1.simpleEntropy() == s2.simpleEntropy() && s1.total() == s2.total())
        return true;
    else
        return false;
}

//preoptovaruvanje na operator !=
bool operator!=(Secret & s1, Secret & s2)
{
    if(s1.simpleEntropy() != s2.simpleEntropy() && s1.total() != s2.total())
        return true;
    else
        return false;
}



class DigitSecret : public Secret{ //da se dopolni so izraz za nasleduvanje
private:
    // da se deklariraat potrebnite promenlivi
    int digits[100];
    int n;
public:
    //default konstruktor
    DigitSecret(int * digits = 0, int n = 0) : Secret()
    {
        this->n = n;
        for(int i=0; i<n; ++i)
        {
            this->digits[i] = digits[i];
        }
    }

    //prepokrivanje na dvata chisto virtuelni metodi od Secret
    double simpleEntropy()
    {
        int unique = 0;
        for(int i=0; i<n; i++)
        {
            int counter = 0;
            for(int j=0; j<n; j++)
            {
                if(digits[i] == digits[j])
                {
                    counter++;
                }
            }
            if(counter == 1)
            {
                unique++;
            }
        }
        return (double)unique/n;
    }
    int total()
    {
        return n;
    }

    //preoptovaruvanje na operatorot za pechatenje <<
    friend ostream& operator<<(ostream & os, DigitSecret & ds);
};

ostream& operator<<(ostream & os, DigitSecret & ds)
{
    for(int i=0; i<ds.n; ++i)
    {
        os<<ds.digits[i];
    }
    os<< " Simple entropy: " <<ds.simpleEntropy()<< " Total: "<<ds.total()<<endl;
    return os;
}


class CharSecret : public Secret{ //da se dopolni so izraz za nasleduvanje
private:
    // da se deklariraat potrebnite promenlivi
    char lowercase[100];

public:
    //default konstruktor
    CharSecret(char * lowercase = "") : Secret()
    {
        strcpy(this->lowercase, lowercase);
    }

    //prepokrivanje na dvata chisto virtuelni metodi od Secret
    double simpleEntropy()
    {
        int n = strlen(lowercase);
        int unique = 0;
        for(int i=0; i<n; i++)
        {
            int counter = 0;
            for(int j=0; j<n; j++)
            {
                if(lowercase[i] == lowercase[j])
                {
                    counter++;
                }
            }
            if(counter == 1)
            {
                unique++;
            }
        }
        return (double)unique/n;
    }
    int total()
    {
        return strlen(lowercase);
    }

    //preoptovaruvanje na operatorot za pechatenje <<
    friend ostream & operator<<(ostream & os, CharSecret & cs);
};

ostream & operator<<(ostream & os, CharSecret & cs)
{
    os<<cs.lowercase<< " Simple entropy: " <<cs.simpleEntropy()<< " Total: "<<cs.total()<<endl;
    return os;
}


void process(Secret ** secrets, int n)
{
    Secret * max = secrets[0];
    int index = 0;
    for(int i=0; i<n; i++)
    {
        if(secrets[i]->simpleEntropy() > max->simpleEntropy())
        {
            max = secrets[i];
        }
    }

    DigitSecret *castedDigit = dynamic_cast<DigitSecret *>(max);
    CharSecret *castedChar = dynamic_cast<CharSecret *>(max);
    if(castedDigit)
    {
        cout<<*castedDigit;
    }
    else if(castedChar)
    {
        cout<<*castedChar;
    }
}

void printAll (Secret ** secrets, int n)
{
    for(int i=0; i<n; i++)
    {
        DigitSecret *castedDigit = dynamic_cast<DigitSecret *>(secrets[i]);
        CharSecret *castedChar = dynamic_cast<CharSecret *>(secrets[i]);
        if(castedDigit)
        {
            cout<<*castedDigit;
        }
        else if(castedChar)
        {
            cout<<*castedChar;
        }
    }
}


int main() {

    int n;
    cin >> n;
    if(n == 0) {
		cout << "Constructors" << endl;
		int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5);
        CharSecret cs("abcabc");
        cout << "OK" << endl;
    } else if(n == 1) {
  		cout << "operator <<" << endl;
		int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5);
        CharSecret cs("abcabc");
        cout << ds;
        cout << cs << endl;
    }  else if(n == 2) {
  		cout << "== and !=" << endl;
		int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5);
        CharSecret cs("abcabc");
        CharSecret css("abcabc");
        cout << (ds == cs) << endl;
        cout << (cs != ds) << endl;
        cout << (cs == css) << endl;
        cout << (cs != css) << endl;
    } else if(n == 3) {
  		cout << "Secret processor" << endl;
		int numbers1 [] = {1,2,3,4,5,6,4,3,2,1,1,2,3,4,5};
        DigitSecret ds1(numbers1,15);
		int numbers2 [] = {1,2,3,4,5,0,0,0,5,5,4,4,3,3,2};
        DigitSecret ds2(numbers2,15);
		int numbers3 [] = {1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2};
        DigitSecret ds3(numbers3,20);
        CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
        CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw");
        CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
        Secret** s = new Secret*[6];
        s[0] = &ds1;
        s[1] = &ds2;
        s[2] = &ds3;
        s[3] = &cs1;
        s[4] = &cs2;
        s[5] = &cs3;
        process(s,6);
        delete [] s;
    }
    else if (n==4){
        cout << "Print all secrets" << endl;
		int numbers1 [] = {1,2,3,4,5,5,4,3,2,1,1,2,3,4,5};
        DigitSecret ds1(numbers1,15);
		int numbers2 [] = {1,2,3,4,5,0,0,0,5,5,4,4,3,3,2};
        DigitSecret ds2(numbers2,15);
		int numbers3 [] = {1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2};
        DigitSecret ds3(numbers3,20);
        CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
        CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw");
        CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
        Secret** s = new Secret*[6];
        s[0] = &ds1;
        s[1] = &ds2;
        s[2] = &ds3;
        s[3] = &cs1;
        s[4] = &cs2;
        s[5] = &cs3;
        printAll(s,6);
        delete [] s;
    }

    return 0;
}
