#include <iostream>
#include <cstring>
using namespace std;

class List{
private:
    int * broevi;
    int n;
public:
    List(int * broevi = 0, int n = 0)
    {
        this->n = n;
        this->broevi = new int[n];
        for(int i=0; i<n; i++)
        {
            this->broevi[i] = broevi[i];
        }
    }
    List(const List &li)
    {
        n = li.n;
        broevi = new int[li.n];
        for(int i=0; i<n; i++)
        {
            broevi[i] = li.broevi[i];
        }
    }
    List& operator=(const List &li)
    {
        if(this!=&li)
        {
            n = li.n;
            delete [] broevi;
            broevi = new int[li.n];
            for(int i=0; i<n; i++)
            {
                broevi[i] = li.broevi[i];
            }
        }
        return *this;
    }
    ~List()
    {
        delete [] broevi;
    }

    int sum()
    {
        int zbir = 0;
        for(int i=0; i<n; i++)
        {
            zbir += broevi[i];
        }
        return zbir;
    }
    double average()
    {
        return (double)sum()/n;
    }
    void pecati()
    {
        cout<<n<<": ";
        for(int i=0; i<n; i++)
        {
            cout<<broevi[i]<<" ";
        }
        cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
    }
    int getN()
    {
        return n;
    }
};

class ListContainer{
private:
    List * listi;
    int n;
    int obidi;
    int s = 0;
    int f = 0;
public:
    ListContainer(List * listi = 0, int n = 0, int obidi = 0)
    {
        this->n = n;
        this->obidi = obidi;
        this->listi = new List[n];
        for(int i=0; i<n; i++)
        {
            this->listi[i] = listi[i];
        }
    }
    ListContainer(const ListContainer &li)
    {
        n = li.n;
        obidi = li.obidi;
        listi = new List[li.n];
        for(int i=0; i<n; i++)
        {
            listi[i] = li.listi[i];
        }
    }
    ListContainer& operator=(const ListContainer &li)
    {
        if(this!=&li)
        {
            n = li.n;
            s = li.s;
            f = li.f;
            obidi = li.obidi;
            delete [] listi;
            listi = new List[li.n];
            for(int i=0; i<n; i++)
            {
                listi[i] = li.listi[i];
            }
        }
        return *this;
    }
    ~ListContainer()
    {
        delete [] listi;
    }

    int sum()
    {
        int zbir = 0;
        for(int i=0; i<n; i++)
        {
            zbir += listi[i].sum();
        }
        return zbir;
    }
    double average()
    {
        int brojac = 0;
        for(int i=0; i<n; i++)
        {
            brojac += listi[i].getN();
        }
//        double prosek = 0;
//        for(int i=0; i<n; i++)
//        {
//            prosek += listi[i].average();
//        }
//        return (double)prosek/n;
        return (double)sum()/brojac;
    }
    void addNewList(List l)
    {
        int check = 0;
        for(int i=0; i<n; i++)
        {
            if(l.sum() == listi[i].sum())
            {
                check = 1;
            }
        }
        if(check == 0)
        {
            List *temp = new List[n+1];
            for(int i=0; i<n; i++)
            {
                temp[i] = listi[i];
            }
            temp[n++] = l;
            delete [] listi;
            listi = temp;
            s++;
        }
        else{
            f++;
        }
    }
    void pecati()
    {
        if(s == 0)
        {
            cout<<"The list is empty"<<endl;
        }
        else{
            for(int i=0; i<n; i++)
            {
                cout<<"List number: "<<i+1<<" List info: ";
                listi[i].pecati();
            }
            cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
            cout<<"Successful attempts: "<<s<<" Failed attempts: "<<f<<endl;
        }
    }
};


int main() {

	ListContainer lc;
	int N;
	cin>>N;

	for (int i=0;i<N;i++) {
		int n;
		int niza[100];

		cin>>n;

		for (int j=0;j<n;j++){
			cin>>niza[j];

		}

		List l=List(niza,n);

		lc.addNewList(l);
	}


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.pecati();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.pecati();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.pecati();
    }
}
