#include <iostream>
#include <cstring>
using namespace std;

class Category{
private:
    char ime[20];
public:
    Category()
    {
        strcpy(ime, "unnamed");
    }
    Category(char * ime)
    {
        strcpy(this->ime, ime);
    }

    void print()
    {
        cout<<"Category: "<<ime<<endl;
    }
};

class NewsArticle{
private:
    Category kategorija;
    char naslov[30];
public:
    NewsArticle()
    {
        strcpy(naslov, "untitled");
    }
    NewsArticle(Category kategorija, char * naslov = "untitled")
    {
        strcpy(this->naslov, naslov);
        this->kategorija = kategorija;
    }

    void print()
    {
        cout<<"Article title: "<<naslov<<endl;
        kategorija.print();
    }
};

class FrontPage{
private:
    NewsArticle article;
    float price;
    int editionNumber;
public:
    FrontPage()
    {
        price = 0;
        editionNumber = 0;
    }
    FrontPage(NewsArticle article, float price = 0, int editionNumber = 0)
    {
        this->price = price;
        this->editionNumber = editionNumber;
        this->article = article;
    }

    void print()
    {
        cout<<"Price: "<<price<<", Edition number: "<<editionNumber<<endl;
        article.print();
    }

};

int main() {
	char categoryName[20];
	char articleTitle[30];
	float price;
	int editionNumber;

	int testCase;
	cin >> testCase;


	if (testCase == 1) {
		int iter;
		cin >> iter;
		while (iter > 0) {
			cin >> categoryName;
			cin >> articleTitle;
			cin >> price;
			cin >> editionNumber;
			Category category(categoryName);
			NewsArticle article(category, articleTitle);
			FrontPage frontPage(article, price, editionNumber);
			frontPage.print();
			iter--;
		}
	}
	else if (testCase == 2) {
		cin >> categoryName;
		cin >> price;
		cin >> editionNumber;
		Category category(categoryName);
		NewsArticle article(category);
		FrontPage frontPage(article, price, editionNumber);
		frontPage.print();
	}// test case 3
	else if (testCase == 3) {
		cin >> categoryName;
		cin >> articleTitle;
		cin >> price;
		Category category(categoryName);
		NewsArticle article(category, articleTitle);
		FrontPage frontPage(article, price);
		frontPage.print();
	}
    else {
    	FrontPage frontPage = FrontPage();
        frontPage.print();
    }
	return 0;
}
