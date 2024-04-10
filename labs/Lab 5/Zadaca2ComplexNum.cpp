#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{
public:
    float real, imaginary;
public:
    ComplexNumber(float real = 0, float imaginary = 0)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    double module()
    {
        return sqrt(pow(real, 2) + pow(imaginary, 2));
    }

    ComplexNumber& operator=(const ComplexNumber &c)
    {
        if(this!=&c)
        {
            real = c.real;
            imaginary = c.imaginary;
        }
        return *this;
    }
    ComplexNumber operator+(ComplexNumber &c)
    {
        ComplexNumber temp(real + c.real, imaginary + c.imaginary);
        return temp;
    }
    ComplexNumber& operator+=(ComplexNumber &c)
    {
        real += c.real;
        imaginary -= c.imaginary;
        return *this;
    }
    ComplexNumber operator-(ComplexNumber &c)
    {
        ComplexNumber temp(real - c.real, imaginary - c.imaginary);
        return temp;
    }
    ComplexNumber& operator-=(ComplexNumber &c)
    {
        real -= c.real;
        imaginary -= c.imaginary;
        return *this;
    }
    ComplexNumber operator*(ComplexNumber &c)
    {
//        ComplexNumber temp(real * c.real - imaginary * c.imaginary,
//                           imaginary * c.real - real * c.imaginary);
        ComplexNumber temp(real * c.real, imaginary * c.imaginary);
        return temp;
    }
    ComplexNumber& operator *=(ComplexNumber &c)
    {
        real = real * c.real;
        imaginary = imaginary * c.imaginary;
        return *this;
    }
    ComplexNumber operator /(ComplexNumber &c)
    {
//        float m = c.real * c.real + c.imaginary * c.imaginary;
//        float r = (real * c.real - imaginary * c.imaginary)/m;
//        float i = (imaginary * c.real + imaginary * c.imaginary)/m;
        ComplexNumber temp(real / c.real, imaginary / c.imaginary);
        return temp;
    }
    ComplexNumber& operator /=(ComplexNumber &c)
    {
        *this = *this/c;
        return *this;
    }
    bool operator <(ComplexNumber &c)
    {
        if(real < c.real)
        {
            return true;
        }
        else if(c.real < real)
        {
            return false;
        }
        else{
            if(imaginary < c.imaginary)
            {
                return true;
            }
            else{
                return false;
            }
        }
    }
    bool operator >(ComplexNumber &c)
    {
        if(real > c.real)
        {
            return true;
        }
        else if(c.real > real)
        {
            return false;
        }
        else{
            if(imaginary > c.imaginary)
            {
                return true;
            }
            else{
                return false;
            }
        }
    }
    bool operator ==(ComplexNumber &c)
    {
        if(real == c.real && imaginary == c.imaginary){
            return true;
        }
        else{
            return false;
        }
    }

    float getReal() const
    {
        return real;
    }
    float getImaginary() const
    {
        return imaginary;
    }

    friend ostream& operator<<(ostream &out, const ComplexNumber &c);

};

ostream& operator<<(ostream &out, const ComplexNumber &c)
{
    if(c.imaginary == 0)
    {
        out<<c.real<<endl;
    }
    else if(c.real == 0){
        out<<c.imaginary<<"i"<<endl;
    }
    else{
        out<<c.real<<"+"<<c.imaginary<<"i"<<endl;
    }
    return out;
}

class Equation{
private:
    ComplexNumber * kompleksni;
    char * operatori;
    int n;
public:
    friend istream& operator>>(istream& is, Equation &e);

    ComplexNumber result()
    {
        ComplexNumber temp;
        for(int i=0; i<n; i++)
        {
            if(operatori[i] == '+')
            {
                temp = kompleksni[i] + kompleksni[i+1];
            }
            else if(operatori[i] == '-')
            {
                temp = kompleksni[i] - kompleksni[i+1];
            }
            else if(operatori[i] == '*')
            {
                temp = kompleksni[i] * kompleksni[i+1];
            }
            else if(operatori[i] == '/')
            {
                temp = kompleksni[i] / kompleksni[i+1];
            }
        }
        return temp;
    }

    double sumModules()
    {
        double sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += kompleksni[i].module();
        }
        return sum;
    }


};

istream& operator>>(istream& is, Equation &e)
{
    is>>e.kompleksni[0].real>>e.kompleksni[0].imaginary>>e.operatori[0];
    e.n = 0;
    char op;
    op = e.operatori[0];
    while(op != '=')
    {
        e.n++;
        is>>e.kompleksni[e.n].real>>e.kompleksni[e.n].imaginary>>e.operatori[e.n];
        op = e.operatori[e.n];
    }
    return is;
}

// Не го менувајте main методот.

int main() {
	int testCase;
	double real, imaginary;
	ComplexNumber first, second, result;

	cin >> testCase;

	if (testCase <= 8) {
		cin >> real;
		cin >> imaginary;
		first = ComplexNumber(real, imaginary);
		cin >> real;
		cin >> imaginary;
		second = ComplexNumber(real, imaginary);
	}

	if (testCase == 1) {
		cout << "===== OPERATOR + =====" << endl;
		result = first + second;
		cout << result;
	}
	else if (testCase == 2) {
		cout << "===== OPERATOR - =====" << endl;
		result = first - second;
		cout << result;
	}
	else if (testCase == 3) {
		cout << "===== OPERATOR * =====" << endl;
		result = first * second;
		cout << result;
//        first*=second;
//        cout<<first;
	}
	else if (testCase == 4) {
		cout << "===== OPERATOR / =====" << endl;
		result = first / second;
		cout << result;
	}
	else if (testCase == 5) {
		cout << "===== OPERATOR == =====" << endl;
		cout << first;
		cout << second;
		if (first == second)
			cout << "EQUAL" << endl;
		else
			cout << "NOT EQUAL" << endl;
	}
	else if (testCase == 6) {
		cout << "===== OPERATOR > =====" << endl;
		cout << first;
		cout << second;
		if (first > second)
			cout << "FIRST GREATER THAN SECOND" << endl;
		else
			cout << "FIRST LESSER THAN SECOND" << endl;
	}
	else if (testCase == 7) {
		cout << "===== OPERATOR < =====" << endl;
		cout << first;
		cout << second;
		if (first < second)
			cout << "FIRST LESSER THAN SECOND" << endl;
		else
			cout << "FIRST GREATER THAN SECOND" << endl;
	}
	else if (testCase == 8) {
		cout << "===== MODULE =====" << endl;
		double module = first.module();
		cout << first;
		cout << "Module: " << module << endl;
		cout << second;
		module = second.module();
		cout << "Module: " << module << endl;
	}
	else if (testCase == 9) {
		cout << "===== OPERATOR >> & SUM OF MODULES =====" << endl;
		Equation equation;
		cin >> equation;
		cout << equation.sumModules();
	}
	else if (testCase == 10) {
		cout << "===== EQUATION RESULT =====" << endl;
		Equation equation;
		cin >> equation;
		result = equation.result();
		cout << result;
	}
	return 0;
}
