#include <iostream>
#include <cstring>

using namespace std;


class Employee{
protected:
    char name[50];
    int age, experience;
public:
    Employee(char * name = "", int age = 0, int experience = 0)
    {
        strcpy(this->name, name);
        this->age = age;
        this->experience = experience;
    }

    virtual double bonus() = 0;

    virtual double plata() = 0;

    friend bool operator==(Employee& e1, Employee& e2);
};


bool operator==(Employee& e1, Employee& e2)
{
    if(e1.age == e2.age)
    {
        return true;
    }
    else{
        return false;
    }
}


class SalaryEmployee: public Employee{
private:
    double baseSalary;
public:
    SalaryEmployee(char * name = "", int age = 0, int experience = 0,
    double baseSalary = 0): Employee(name, age, experience)
    {
        this->baseSalary = baseSalary;
    }

    double bonus()
    {
        return baseSalary * (double)experience/100;
    }

    double plata()
    {
        return baseSalary + bonus();
    }
};


class HourlyEmployee: public Employee{
private:
    int totalHrs;
    double hourly;
public:
    HourlyEmployee(char * name = "", int age = 0, int experience = 0,
    int totalHrs = 0, double hourly = 0): Employee(name, age, experience)
    {
        this->totalHrs = totalHrs;
        this->hourly = hourly;
    }

    double bonus()
    {
        double sum = 0;
        if(totalHrs > 320)
        {
            for(int i=320; i<totalHrs; i++)
            {
                sum += hourly*0.5;
            }
        }
        return sum;
    }

    double plata()
    {
        return totalHrs*hourly + bonus();
    }
};


class Freelancer: public Employee{
private:
    int projects;
    double payments[50];
public:
    Freelancer(char * name = "", int age = 0, int experience = 0,
    int projects = 0, double * payments = 0): Employee(name, age, experience)
    {
        this->projects = projects;
        for(int i=0; i<projects; i++)
        {
            this->payments[i] = payments[i];
        }
    }

    double bonus()
    {
        double sum = 0;
        if(projects>5)
        {
            for(int i=5; i<projects; i++)
            {
                sum += 1000;
            }
        }
        return sum;
    }

    double plata()
    {
        double sum = 0;
        for(int i=0; i<projects; i++)
        {
            sum += payments[i];
        }
        return sum + bonus();
    }
};

class Company{
private:
    char companyName[50];
    int n;
    Employee **employees;
public:
    Company(char * companyName = "", int n = 0, Employee **employees = 0)
    {
        strcpy(this->companyName, companyName);
        this->n = n;
        this->employees = new Employee * [n];
        for(int i=0; i<n; i++)
        {
            this->employees[i] = employees[i];
        }
    }
//    Company(char *companyName = "")
//    {
//        strcpy(this->companyName, companyName);
//    }
    Company(const Company &c)
    {
        strcpy(this->companyName, c.companyName);
        this->n = c.n;
        this->employees = new Employee * [c.n];
        for(int i=0; i<n; i++)
        {
            this->employees[i] = c.employees[i];
        }
    }
    Company& operator=(const Company &c)
    {
        if(this!=&c)
        {
            strcpy(this->companyName, c.companyName);
            this->n = c.n;
            delete [] employees;
            this->employees = new Employee * [c.n];
            for(int i=0; i<n; i++)
            {
                this->employees[i] = c.employees[i];
            }
        }
        return *this;
    }
    ~Company()
    {
        delete [] employees;
    }
    Company& operator+=(Employee * e)
    {
        Employee ** temp = new Employee*[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i] = employees[i];
        }
        temp[n++] = e;
        delete [] employees;
        employees = temp;
        return * this;
    }

    double vkupnaPlata()
    {
        double sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += employees[i]->plata();
        }
        return sum;
    }

    double filtriranaPlata(Employee* emp)
    {
        double sum = 0;
        for(int i=0; i<n; i++)
        {
            if(*employees[i] == *emp)
            {
                sum += employees[i]->plata();
            }
        }
        return sum;
    }

    void pecatiRabotnici()
    {
        int salaryEmp = 0, hourlyEmp = 0, freelancer = 0;
        for(int i=0; i<n; i++)
        {
            SalaryEmployee *castedSalary = dynamic_cast<SalaryEmployee *>(employees[i]);
            HourlyEmployee *castedHourly = dynamic_cast<HourlyEmployee *>(employees[i]);
            Freelancer *castedFreelance = dynamic_cast<Freelancer *>(employees[i]);
            if(castedSalary)
            {
                salaryEmp++;
            }
            else if(castedHourly){
                hourlyEmp++;
            }
            else if(castedFreelance){
                freelancer++;
            }
        }
        cout<< "Vo kompanijata " <<companyName<< " rabotat:" <<endl;
        cout<< "Salary employees: " <<salaryEmp<<endl;
        cout<< "Hourly employees: " <<hourlyEmp<<endl;
        cout<< "Freelancers: " <<freelancer<<endl;
    }
};





int main() {

    char name[50];
    cin >> name;
    Company c(name);

    int n;
    cin >> n;

    char employeeName[50];
    int age;
    int experience;
    int type;



//    HourlyEmployee h("todor", 31, 5, 322, 120);
//    cout<<h.bonus()<<endl;
//    cout<<h.plata()<<endl;
//    SalaryEmployee s("vekic", 31, 5, 16000);
//    cout<<s.bonus()<<endl;
//    cout<<s.plata()<<endl;
//    if(h == s)
//    {
//        cout<<"Ista vozrast"<<endl;
//    }
//    else cout<<"Razlicna vozrast"<<endl;

//    Company c("Deki");
//    Employee * temp = new HourlyEmployee("todor", 31, 6, 340, 80);
//    c+= temp;
//    Employee * emp = new HourlyEmployee("Petre_Petrov",31,6,340,80);
//    if(*temp == *emp)
//    {
//        cout<<"BALLS"<<endl;
//    }
//    else cout<<"ekk"<<endl;
//    cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);




    for (int i=0; i <n; ++i) {
      cin >> type;
      cin >> employeeName >> age >> experience;

      if (type == 1) {
        int basicSalary;
        cin >> basicSalary;
        c += new SalaryEmployee(employeeName, age, experience, basicSalary);
      }

      else if (type == 2) {
        int hoursWorked;
        int hourlyPay;
        cin >> hoursWorked >> hourlyPay;
        c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
      }

      else {
        int numProjects;
        cin >> numProjects;
        double projects[10];
        for (int i=0; i < numProjects; ++i) {
          cin >> projects[i];
        }
        c += new Freelancer(employeeName, age, experience, numProjects, projects);
      }
    }


    c.pecatiRabotnici();
    cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
    Employee * emp = new HourlyEmployee("Petre_Petrov",31,6,340,80);
    cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);

    delete emp;

    return 0;
}
