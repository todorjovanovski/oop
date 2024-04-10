#include<iostream>
#include<cstring>

using namespace std;

enum Extension{
    pdf, txt, exe
};

ostream &operator << (ostream& strm, Extension ext)
{
   const string nameTT[] = { "txt", "pdf", "exe"};
   return strm << nameTT[ext];
}

class File{
private:
    char * ime;
    Extension ekstenzija;
    char * sopstvenik;
    int golemina;
public:
    File(){}
    File(char * ime, char * sopstvenik, int golemina, Extension ekstenzija)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->sopstvenik = new char[strlen(sopstvenik) + 1];
        strcpy(this->sopstvenik, sopstvenik);
        this->golemina = golemina;
        this->ekstenzija = ekstenzija;
    }
    File(const File &dat)
    {
        ime = new char[strlen(dat.ime) + 1];
        strcpy(ime, dat.ime);
        sopstvenik = new char[strlen(dat.sopstvenik) + 1];
        strcpy(sopstvenik, dat.sopstvenik);
        golemina = dat.golemina;
        ekstenzija = dat.ekstenzija;
    }
    File& operator=(const File &dat)
    {
        if(this!=&dat)
        {
            delete [] ime;
            ime = new char[strlen(dat.ime) + 1];
            strcpy(ime, dat.ime);
            delete [] sopstvenik;
            sopstvenik = new char[strlen(dat.sopstvenik) + 1];
            strcpy(sopstvenik, dat.sopstvenik);
            golemina = dat.golemina;
            ekstenzija = dat.ekstenzija;
        }
        return *this;
    }
    ~File()
    {
        delete [] ime;
        delete [] sopstvenik;
    }
    bool equals(const File & that)
    {
        if(strcmp(ime, that.ime) == 0 &&
           strcmp(sopstvenik, that.sopstvenik) == 0 &&
           ekstenzija == that.ekstenzija) return true;
        else{
            return false;
        }
    }
    bool equalsType(const File & that)
    {
        if(strcmp(ime, that.ime) == 0 &&
           ekstenzija == that.ekstenzija) return true;
        else{
            return false;
        }
    }
    void print()
    {
        cout<<"File name: "<<ime<<".";
        if(ekstenzija == 0) cout<<"pdf"<<endl;
        else if(ekstenzija == 1) cout<<"txt"<<endl;
        else if(ekstenzija == 2) cout<<"exe"<<endl;
        cout<<"File owner: "<<sopstvenik<<endl;
        cout<<"File size: "<<golemina<<endl;
    }
};

class Folder{
private:
    char * name;
    int n;
    File * datoteki;
public:
    Folder(const char * name)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        n = 0;
        datoteki = new File[n];
        for(int i=0; i<n; i++)
        {
            this->datoteki[i] = datoteki[i];
        }
    }
    Folder(const Folder &dir)
    {
        name = new char[strlen(dir.name) + 1];
        strcpy(name, dir.name);
        n = dir.n;
        datoteki = new File[n];
        for(int i=0; i<n; i++)
        {
            datoteki[i] = dir.datoteki[i];
        }
    }
    Folder& operator=(const Folder &dir)
    {
        if(this!=&dir)
        {
            delete [] name;
            name = new char[strlen(dir.name) + 1];
            strcpy(name, dir.name);
            n = dir.n;
            delete [] datoteki;
            datoteki = new File[n];
            for(int i=0; i<n; i++)
            {
                datoteki[i] = dir.datoteki[i];
            }
        }
        return *this;
    }
    ~Folder()
    {
        delete [] name;
        delete [] datoteki;
    }
    void add(const File & file)
    {
        File * temp = new File[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i] = datoteki[i];
        }
        temp[n++] = file;
        delete [] datoteki;
        datoteki = temp;
    }
    void remove(const File & file)
    {
        //File * temp = new File[n-1];
        int i;
        int check = 0;
        int counter = 0;
        for(i=0; i<n; i++)
        {
            if(datoteki[i].equals(file) == false)
            {
                //temp[counter++] = datoteki[i];
                datoteki[counter++] = datoteki[i];
            }
            else{
                break;
            }
        }
        for(int j=i+1; j<n; j++)
        {
            //temp[counter++] = datoteki[i];
            datoteki[counter++] = datoteki[i];
        }
        //delete [] datoteki;
        //datoteki = temp;
        n = counter;
//        int newN = 0;
//        for(int i=0; i<n; i++)
//        {
//            if(datoteki[i].equals(file) == false)
//            {
//                newN++;
//            }
//        }
//        File * temp = new File[newN];
//        int j = 0;
//        for(int i=0; i<n; i++)
//        {
//            if(datoteki[i].equals(file) == false)
//            {
//                temp[j++] = datoteki[i];
//            }
//        }
//        delete [] datoteki;
//        datoteki = temp;
//        n = newN;
    }
    void print()
    {
        if(n == 0)
        {
            cout<<"Folder name: "<<name<<endl;
        }
        else{
            for(int i=0; i<n; i++)
            {
                datoteki[i].print();
            }
        }
    }

};

int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;

		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
        cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
        cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);
		folder.print();

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

        folder.print();
		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}

	return 0;
}
