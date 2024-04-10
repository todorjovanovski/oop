#include <iostream>
#include <cstring>
using namespace std;

class Array{
private:
    int * a;
    int n;
    int capacity;

public:
    Array(int capacity = 5)
    {
        this->capacity = capacity;
        a = new int[capacity];
        n = 0;
    }
    Array(const Array &arr)
    {
        capacity = arr.capacity;
        a = new int[arr.capacity];
        n = arr.n;
        for(int i=0; i<n; i++)
        {
            a[i] = arr.a[i];
        }
    }
    Array& operator=(const Array &arr)
    {
        if(this!=&arr)
        {
            capacity = arr.capacity;
            delete [] a;
            a = new int[arr.capacity];
            n = arr.n;
            for(int i=0; i<n; i++)
            {
                a[i] = arr.a[i];
            }
        }
        return *this;
    }
    ~Array()
    {
        delete [] a;
    }

    void change(int x, int y)
    {
        for(int i=0; i<n; i++)
        {
            if(a[i] == x)
            {
                a[i] = y;
            }
        }
    }
    void add(int nov)
    {
        if(capacity == n)
        {
            int *temp = new int[capacity*2];
            for(int i=0; i<n; i++)
            {
                temp[i] = a[i];
            }
            delete [] a;
            a = temp;
            capacity *= 2;
        }
        a[n++] = nov;
    }
    void deleteAll(int del)
    {
        int newN = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i] != del)
            {
                a[newN++] = a[i];
            }
        }
        n = newN;
    }
    void print()
    {
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        for(int i=n; i<capacity; i++)
        {
            cout<<" - ";
        }
        cout<<endl;
    }

};

int main()
{
    Array a;
    for(int i=6; i>=1; i--)
    {
        a.add(i);
    }

    Array b(a);
    Array c;
    c = a;

    b.add(2);
    b.change(2, 6);
    c.deleteAll(6);

    cout<<"a: ";
    a.print();

    cout<<"b: ";
    b.print();

    cout<<"c: ";
    c.print();

    return 0;
}
