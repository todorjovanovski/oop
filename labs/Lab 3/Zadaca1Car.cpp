#include <iostream>
#include <cstring>
using namespace std;

class Person{
private:
    char ime[20];
    char prezime [20];
public:
    Person()
    {
        strcpy(ime, "not specified");
        strcpy(prezime, "not specified");
    }
    Person(char * ime, char * prezime)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
    }
    Person(const Person &p)
    {
        strcpy(ime, p.ime);
        strcpy(prezime, p.prezime);
    }

    void print()
    {
        cout<<ime<<" "<<prezime<<endl;
    }
};

class Date{
private:
    int den, mesec, godina;
public:
    Date(){}
    Date(int godina, int mesec, int den)
    {
        this->den = den;
        this->mesec = mesec;
        this->godina = godina;
    }
    Date(const Date &d)
    {
        den = d.den;
        mesec = d.mesec;
        godina = d.godina;
    }

    void print()
    {
        cout<<godina<<"."<<mesec<<"."<<den<<endl;
    }

};

class Car{
private:
    Person sopstvenik;
    Date datum;
    float price;
public:
    Car(){}
    Car(Person s, Date d, float p = 0)
    {
        sopstvenik = s;
        datum = d;
        price = p;
    }

    float getPrice()
    {
        return price;
    }
    void print()
    {
        sopstvenik.print();
        datum.print();
        cout<<"Price: "<<price<<endl;
    }
};

void cheaperThan(Car * cars, int numCars, float price)
{
    for(int i=0; i<numCars; i++)
    {
        if(cars[i].getPrice() < price)
        {
            cars[i].print();
        }
    }
}

int main() {
	char name[20];
	char lastName[20];
	int year;
	int month;
	int day;
	float price;

	int testCase;
	cin >> testCase;

	if (testCase == 1) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(year, month, day);

		cin >> price;
		Car car(lik, date,  price);

		car.print();
	}
	else if (testCase == 2) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(Date(year, month, day));

		cin >> price;
		Car car(lik, date,  price);
		car.print();
	}
	else {
		int numCars;
		cin >> numCars;

		Car cars[10];
		for (int i = 0; i < numCars; i++) {
			cin >> name;
			cin >> lastName;
			Person lik(name, lastName);

			cin >> year;
			cin >> month;
			cin >> day;
			Date date(year, month, day);

			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
        float priceLimit;
        cin >> priceLimit;
		cheaperThan(cars, numCars, priceLimit);
	}


	return 0;
}
