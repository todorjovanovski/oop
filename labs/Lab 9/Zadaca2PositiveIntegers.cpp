#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


class ArithmeticException{
private:
    char text[50];
public:
    ArithmeticException(char * text)
    {
        strcpy(this->text, text);
    }

    void message()
    {
        cout<<text<<endl;
    }
};

class NumbersNotDivisibleException{
private:
    int n;
public:
    NumbersNotDivisibleException(int n = 0)
    {
        this->n = n;
    }

    void message()
    {
        cout<<"Division by "<<n<<" is not supported"<<endl;
    }
};

class ArrayFullException {
private:
    char text[50];
public:
    ArrayFullException(char * text)
    {
        strcpy(this->text, text);
    }

    void message()
    {
        cout<<text<<endl;
    }
};

class IndexOutOfBoundsException{
private:
    int n;
public:
    IndexOutOfBoundsException(int n = 0)
    {
        this->n = n;
    }

    void message()
    {
        cout<<"Index "<<n<<" is out of bounds"<<endl;
    }
};

class NumberIsNotPositiveException {
private:
    int n;
public:
    NumberIsNotPositiveException (int n = 0)
    {
        this->n = n;
    }

    void message()
    {
        cout<<"Number "<<n<<" is not positive integer"<<endl;
    }
};


class PositiveIntegers{
private:
    int *positiveNumbers;
    int n, limit;
public:
    PositiveIntegers(int limit = 0, int * positiveNumbers = 0, int n = 0)
    {
        this->n = n;
        this->positiveNumbers = new int[n];
        for(int i=0; i<n; i++)
        {
            this->positiveNumbers[i] = positiveNumbers[i];
        }
        this->limit = limit;
    }
    PositiveIntegers(const PositiveIntegers &p)
    {
        this->n = p.n;
        this->positiveNumbers = new int[p.n];
        for(int i=0; i<n; i++)
        {
            this->positiveNumbers[i] = p.positiveNumbers[i];
        }
        this->limit = p.limit;
    }
    PositiveIntegers& operator=(const PositiveIntegers &p)
    {
        if(this!=&p)
        {
            this->n = p.n;
            delete [] positiveNumbers;
            this->positiveNumbers = new int[p.n];
            for(int i=0; i<n; i++)
            {
                this->positiveNumbers[i] = p.positiveNumbers[i];
            }
            this->limit = p.limit;
        }
        return * this;
    }
    ~PositiveIntegers()
    {
        delete [] positiveNumbers;
    }

    void print()
    {
        cout<< "Size: "<<n<< " Capacity: "<<limit<< " Numbers: ";
        for(int i=0; i<n; i++)
        {
            cout<<positiveNumbers[i]<< " ";
        }
        cout<<endl;
    }

    void increaseCapacity(int c)
    {
        limit += c;
    }

    PositiveIntegers& operator+=(int &num)
    {
        if(n == limit)
        {
            throw ArrayFullException("The array is full. Increase the capacity");
        }
        else{
            if(num < 1)
            {
                throw NumberIsNotPositiveException(num);
            }
            else{
                int * temp = new int[n+1];
                for(int i=0; i<n; i++)
                {
                    temp[i] = positiveNumbers[i];
                }
                temp[n++] = num;
                delete [] positiveNumbers;
                positiveNumbers = temp;
            }
        }
        return *this;
    }
    PositiveIntegers operator*(const int &num)
    {
        PositiveIntegers temp(limit, positiveNumbers, n);
        for(int i=0; i<n; i++)
        {
            temp.positiveNumbers[i] *= num;
        }
        return temp;
    }
    PositiveIntegers operator/(const int &num)
    {
        PositiveIntegers temp(limit, positiveNumbers, n);
        if(num == 0)
        {
            throw ArithmeticException("Division by zero is not allowed");
        }
        else{
            int flag = 0;
            for(int i=0; i<n; i++)
            {
                if(positiveNumbers[i] % num != 0)
                {
                    flag++;
                    break;
                }
            }
            if(flag)
            {
                throw NumbersNotDivisibleException(num);
            }
            else{
                PositiveIntegers temp(limit, positiveNumbers, n);
                for(int i=0; i<n; i++)
                {
                    temp.positiveNumbers[i] /= num;
                }
                return temp;
            }
        }
        return temp;
    }
    int &operator[](int i)
    {
        if(i<0 || i>n-1)
        {
            throw IndexOutOfBoundsException(i);
        }
        else{
            return positiveNumbers[i];
        }
    }
};





int main() {

	int n,capacity;
	cin >> n >> capacity;
	PositiveIntegers pi (capacity);
	for (int i=0;i<n;i++){
		int number;
		cin>>number;
		try{
            pi+=number;
		}
		catch(NumberIsNotPositiveException error)
		{
		    error.message();
		}
		catch(ArrayFullException error)
		{
		    error.message();
		}

	}
	cout<<"===FIRST ATTEMPT TO ADD NUMBERS==="<<endl;
	pi.print();
	int incCapacity;
	cin>>incCapacity;
	pi.increaseCapacity(incCapacity);
	cout<<"===INCREASING CAPACITY==="<<endl;
	pi.print();

	int n1;
	cin>>n1;
	for (int i=0;i<n1;i++){
		int number;
		cin>>number;
		try{
            pi+=number;
		}
		catch(NumberIsNotPositiveException error)
		{
		    error.message();
		}
		catch(ArrayFullException error)
		{
		    error.message();
		}
	}
	cout<<"===SECOND ATTEMPT TO ADD NUMBERS==="<<endl;

    pi.print();
	PositiveIntegers pi1;

	cout<<"===TESTING DIVISION==="<<endl;

	try{
        pi1 = pi/0;
        pi1.print();
	}
	catch(ArithmeticException error)
	{
	    error.message();
	}

	try{
        pi1 = pi/1;
        pi1.print();
	}
	catch(NumbersNotDivisibleException error)
	{
	    error.message();
	}

    try{
        pi1 = pi/2;
        pi1.print();
	}
	catch(NumbersNotDivisibleException error)
	{
	    error.message();
	}

	cout<<"===TESTING MULTIPLICATION==="<<endl;
	pi1 = pi*3;
	pi1.print();


	cout<<"===TESTING [] ==="<<endl;
	cout<<"PositiveIntegers[-1] = ";
	try{
	    cout<<pi[-1]<<endl;
	}
    catch(IndexOutOfBoundsException error)
    {
        error.message();
    }
	cout<<"PositiveIntegers[2] = ";
    try{
	    cout<<pi[2]<<endl;
	}
    catch(IndexOutOfBoundsException error)
    {
        error.message();
    }
	cout<<"PositiveIntegers[3] = ";
    try{
	    cout<<pi[3]<<endl;
	}
    catch(IndexOutOfBoundsException error)
    {
        error.message();
    }
	cout<<"PositiveIntegers[12] = ";
		try{
	    cout<<pi[12]<<endl;
	}
    catch(IndexOutOfBoundsException error)
    {
        error.message();
    }



	return 0;
}
