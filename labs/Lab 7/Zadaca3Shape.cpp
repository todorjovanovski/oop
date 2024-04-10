#include <iostream>
#include <cmath>
using namespace std;


class Shape{
protected:
    int a;
public:
    Shape(int a = 0)
    {
        this->a = a;
    }

    virtual double plostina() = 0;

    virtual int getType() = 0;

    virtual void pecati() = 0;
};

class Square : public Shape{
public:
    Square(int a = 0) : Shape(a){}

    double plostina()
    {
        return a*a;
    }
    int getType()
    {
        return 1;
    }
    void pecati()
    {
        cout<< "Kvadrat so plostina = " << plostina() <<endl;
    }
};

class Circle : public Shape{
public:
    Circle(int a = 0) : Shape(a){}

    double plostina()
    {
        return 3.14 * a * a;
    }
    int getType()
    {
        return 2;
    }
    void pecati()
    {
        cout<< "Krug so plostina = " << plostina() <<endl;
    }
};

class Triangle : public Shape{
public:
    Triangle(int a = 0) : Shape(a){}

    double plostina()
    {
        return (sqrt(3)/4) * a * a;
    }
    int getType()
    {
        return 3;
    }
    void pecati()
    {
        cout<< "Triagolnik so plostina = " << plostina() <<endl;
    }
};


//TODO: definiraj go metodot void checkNumTypes(Shape** niza, int n)
void checkNumTypes(Shape ** niza, int n)
{
    int squares = 0, circles = 0, triangles = 0;
    for(int i=0; i<n; i++)
    {
        if(niza[i]->getType() == 1)
        {
            squares++;
        }
        else if(niza[i]->getType() == 2)
        {
            circles++;
        }
        else if(niza[i]->getType() == 3)
        {
            triangles++;
        }
    }
    cout<< "Broj na kvadrati vo nizata = " <<squares<<endl;
    cout<< "Broj na krugovi vo nizata = " <<circles<<endl;
    cout<< "Broj na triagolnici vo nizata = " <<triangles<<endl;
}



int main(){


	int n;
	cin >> n;

	//TODO: inicijaliziraj niza od pokazuvachi kon klasata Shape
	Shape ** shapes = new Shape*[n];


	int classType;
	int side;

	//TODO: konstruiraj for ciklus so chija pomosh ke ja popolnish nizata
	for(int i = 0; i < n; ++i){

		cin >> classType;
		cin >> side;
		if(classType == 1)
        {
            shapes[i] = new Square(side);
        }
        else if(classType == 2)
        {
            shapes[i] = new Circle(side);
        }
        else if(classType == 3)
        {
            shapes[i] = new Triangle(side);
        }
	}


	for(int i = 0; i < n; ++i){

		shapes[i]->pecati();
	}

	checkNumTypes(shapes, n);


	return 0;
}
