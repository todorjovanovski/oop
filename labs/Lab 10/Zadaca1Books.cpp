#include <iostream>
#include <cstring>

using namespace std;


class Book{
protected:
    char ISBN[21], title[51], author[31];
    double price;
public:
    Book(char * ISBN = "", char * title = "", char * author = "", double price = 0)
    {
        strcpy(this->ISBN, ISBN);
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->price = price;
    }
    Book(const Book &b)
    {
        strcpy(this->ISBN, b.ISBN);
        strcpy(this->title, b.title);
        strcpy(this->author, b.author);
        this->price = b.price;
    }
    Book& operator=(const  Book &b)
    {
        if(this!=&b)
        {
            strcpy(this->ISBN, b.ISBN);
            strcpy(this->title, b.title);
            strcpy(this->author, b.author);
            this->price = b.price;
        }
        return *this;
    }

    virtual double bookPrice()= 0;

    friend bool operator>(Book &b1, Book &b2);
    friend ostream& operator<<(ostream& os, Book &b);
};
bool operator>(Book &b1, Book &b2)
{
    if(b1.bookPrice() > b2.bookPrice())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& os, Book &b)
{
    os<<b.ISBN<< ": " <<b.title<< ", " <<b.author<< " " <<b.bookPrice()<<endl;
}

class OnlineBook: public Book{
private:
    char * url;
    int MB;
public:
    OnlineBook(char * ISBN = "", char * title = "", char * author = "", double price = 0,
    char * url = "", int MB = 0) : Book(ISBN, title, author, price)
    {
        this->MB = MB;
        this->url = new char[strlen(url) + 1];
        strcpy(this->url, url);
    }
    OnlineBook(const OnlineBook &ob) : Book(ob)
    {
        this->MB = ob.MB;
        this->url = new char[strlen(ob.url) + 1];
        strcpy(this->url, ob.url);
    }
    OnlineBook& operator=(const OnlineBook &ob)
    {
        if(this!=&ob)
        {
            Book::operator=(ob);
            this->MB = ob.MB;
            delete [] url;
            this->url = new char[strlen(ob.url) + 1];
            strcpy(this->url, ob.url);
        }
        return * this;
    }
    ~OnlineBook()
    {
        delete [] url;
    }

    void setISBN(char * newISBN)
    {
        strcpy(ISBN, newISBN);
    }
    double bookPrice()
    {
        if(MB > 20)
        {
            return price*1.2;
        }
        else{
            return price;
        }
    }

};

class PrintBook: public Book{
private:
    double kg;
    bool stock;
public:
    PrintBook(char * ISBN = "", char * title = "", char * author = "", double price = 0,
    double kg = 0, bool stock = false) : Book(ISBN, title, author, price)
    {
        this->kg = kg;
        this->stock = stock;
    }

    double bookPrice()
    {
        if(kg > 0.7)
        {
            return price*1.15;
        }
        else{
            return price;
        }
    }
};


void mostExpensiveBook (Book** books, int n)
{
    int onlineCounter = 0, printCounter = 0;
    Book *max = books[0];
    for(int i=0; i<n; i++)
    {
        OnlineBook *castedOnline = dynamic_cast<OnlineBook *>(books[i]);
        PrintBook *castedPrint = dynamic_cast<PrintBook *>(books[i]);
        if(castedOnline)
        {
            ++onlineCounter;
        }
        else if(castedPrint)
        {
            ++printCounter;
        }
        if(*books[i] > *max)
        {
            max =  books[i];
        }
    }
    cout<< "FINKI-Education" <<endl;
    cout<< "Total number of online books: " <<onlineCounter<<endl;
    cout<< "Total number of print books: " <<printCounter<<endl;
    cout<< "The most expensive book is: "<<endl;
    cout<<*max;
}


int main(){

	char isbn[20], title[50], author[30], url[100];
	int size, tip;
	float price, weight;
	bool inStock;
	Book  **books;
	int n;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing OnlineBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> url;
			cin >> size;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new OnlineBook(isbn, title, author, price, url, size);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 2){
		cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
		cin >> isbn;
		cin.get();
		cin.getline(title, 50);
		cin.getline(author, 30);
		cin >> price;
		cin >> url;
		cin >> size;
		cout << "CONSTRUCTOR" << endl;
		OnlineBook ob1(isbn, title, author, price, url, size);
		cout << ob1 << endl;
		cout << "COPY CONSTRUCTOR" << endl;
		OnlineBook ob2(ob1);
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
		cout << "OPERATOR =" << endl;
		ob1 = ob2;
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
	}
	if (testCase == 3){
		cout << "====== Testing PrintBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> weight;
			cin >> inStock;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 4){
		cout << "====== Testing method mostExpensiveBook() ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i<n; i++){

			cin >> tip >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			if (tip == 1) {

				cin >> url;
				cin >> size;

				books[i] = new OnlineBook(isbn, title, author, price, url, size);

			}
			else {
				cin >> weight;
				cin >> inStock;

				books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			}
		}

		mostExpensiveBook(books, n);
	}

	for (int i = 0; i<n; i++) delete books[i];
		delete[] books;
	return 0;
}
