#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Number {
public:
    //TODO da se deklariraat trite cisto virtuelni metodi
    virtual double doubleValue() = 0;
    virtual int intValue() = 0;
    virtual void print() = 0;

    friend bool operator==(Number& n1, Number& n2);
};

//ТODO preoptovaruvanje na operatorot ==
bool operator==(Number& n1, Number& n2)
{
    if(n1.intValue() == n2.intValue() &&
    n1.doubleValue() == n2.doubleValue())
    {
        return true;
    }
    else{
        return false;
    }
}

class Integer : public Number {
private:
    //TODO da se deklariraat promenlivite
    int integer;

public:
    //TODO konstruktor so eden argument
    Integer(int integer = 0)
    {
        this->integer = integer;
    }

    //TODO da se prepokrijat metodite od klasata Number
    int intValue()
    {
        return integer;
    }
    double doubleValue()
    {
        return 0;
    }
    void print()
    {
        cout << "Integer: " <<integer<<endl;
    }
};

class Double: public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
private:
    //TODO da se deklariraat promenlivite
    double decimal;
public:
    //TODO konstruktor so eden argument
    Double(double decimal = 0)
    {
        this->decimal = decimal;
    }

    //TODO da se prepokrijat metodite od klasata Number
    double doubleValue()
    {
        return decimal - (int)decimal;
    }
    int intValue()
    {
        return (int)decimal;
    }
    void print()
    {
        cout<< "Double: " <<decimal<<endl;
    }
};

class Numbers{
private:
    //TODO deklariranje na promenlivite
    Number ** numbers;
    int count;
public:
    //TODO default konstruktor
    Numbers(Number ** numbers = 0, int count = 0)
    {
        this->count = count;
        this->numbers = new Number*[count];
        for(int i=0; i<count; i++)
        {
            this->numbers[i] = numbers[i];
        }
    }
    //TODO copy konstruktor
    Numbers(const Numbers &n)
    {
        this->count = n.count;
        this->numbers = new Number*[n.count];
        for(int i=0; i<count; i++)
        {
            this->numbers[i] = n.numbers[i];
        }
    }
    //TODO operator =
    Numbers& operator=(const Numbers &n)
    {
        if(this!=&n)
        {
            this->count = n.count;
            this->numbers = new Number*[n.count];
            for(int i=0; i<count; i++)
            {
                this->numbers[i] = n.numbers[i];
            }
        }
        return * this;
    }
    //TODO destruktor
    ~Numbers()
    {
        delete [] numbers;
    }
    //TODO operator += (operatorot da prima pointer od objekt od Number, a ne referenca)
    Numbers& operator+=(Number * n)
    {
        int flag = 0;
        for(int i=0; i<count; i++)
        {
            if(*numbers[i] == *n)
            {
                flag++;
            }
        }
        if(flag == 0)
        {
            Number ** temp = new Number*[count+1];
            for(int i=0; i<count; i++)
            {
                temp[i] = numbers[i];
            }
            temp[count++] = n;
            delete [] numbers;
            numbers = temp;
        }
        return * this;
    }
    //TODO void statistics()
    void statistics()
    {
        double sum = 0, sumInt = 0, sumDouble = 0;
        int countInt = 0, countDouble = 0;
        for(int i=0; i<count; i++)
        {
            Integer *castedInteger = dynamic_cast<Integer*>(numbers[i]);
            Double *castedDouble = dynamic_cast<Double*>(numbers[i]);
            if(castedInteger)
            {
                sumInt+=numbers[i]->intValue();
                sum+=numbers[i]->intValue();
                countInt++;
            }
            else if(castedDouble){
                sumDouble+=(double)numbers[i]->intValue() + numbers[i]->doubleValue();
                sum+=numbers[i]->intValue() + numbers[i]->doubleValue();
                countDouble++;
            }
        }
        cout<< "Count of numbers: " <<count<<endl;
        cout<< "Sum of all numbers: " <<sum<<endl;
        cout<< "Count of integer numbers: "<<countInt<<endl;
        cout<< "Sum of integer numbers: "<<sumInt<<endl;
        cout<< "Count of double numbers: "<<countDouble<<endl;
        cout<< "Sum of double numbers: "<<sumDouble<<endl;
    }

    //TODO void integersLessThan (Integer n)
    void integersLessThan(Integer n)
    {
        int flag = 0;
        for(int i=0; i<count; i++)
        {
            Integer *castedInteger = dynamic_cast<Integer*>(numbers[i]);
            if(castedInteger != 0 && numbers[i]->intValue() < n.intValue())
            {
                numbers[i]->print();
                flag++;
            }
        }
        if (flag == 0) cout<<"None"<<endl;
    }

    //TODO void doublesBiggerThan (Double n)
    void doublesBiggerThan(Double n)
    {
        int flag = 0;
        for(int i=0; i<count; i++)
        {
            Double *castedDouble = dynamic_cast<Double*>(numbers[i]);
            if(castedDouble != 0 && numbers[i]->doubleValue() + numbers[i]->intValue() > n.doubleValue() + n.intValue())
            {
                numbers[i]->print();
                flag++;
            }
        }
        if (flag == 0) cout<<"None"<<endl;
    }
};

int main() {

	int n;
	cin>>n;
	Numbers numbers;
	for (int i=0;i<n;i++){
		int type;
		double number;
		cin>>type>>number;
		if (type==0){//Integer object
			Integer * integer = new Integer((int) number);
			numbers+=integer;
		}
		else {
			Double * doublee = new Double(number);
			numbers+=doublee;
		}
	}

	int lessThan;
	double biggerThan;

	cin>>lessThan;
	cin>>biggerThan;

	cout<<"STATISTICS FOR THE NUMBERS\n";
	numbers.statistics();
	cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl;
	numbers.integersLessThan(Integer(lessThan));
	cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl;
	numbers.doublesBiggerThan(Double(biggerThan));

	return 0;
}
