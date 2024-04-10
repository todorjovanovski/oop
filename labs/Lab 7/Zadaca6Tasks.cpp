#include<iostream>
#include<cstring>
using namespace std;

class Task{
protected:
    //deklariranje na promenlivite
    char ID[5];
public:
    //konstruktor
    Task(char * ID = "")
    {
        strcpy(this->ID, ID);
    }

    //destruktor

    //2 chisto virtuelni metodi (print i getOrder)
    virtual int getOrder() = 0;
    virtual void print() = 0;
    friend bool operator==(Task * t1, Task & t2);
};

//Preoptovaruvanje na operatorot za sporedba == (prima 2 argumenti bidejki se definira nadvor od klasata Task)
bool operator==(Task * t1, Task & t2)
{
    if(strcmp(t1->ID, t2.ID) == 0 && t1->getOrder() == t2.getOrder())
        return  true;
    else
        return false;
}

class TimedTask : public Task{
private:
    //deklariranje na dopolnitelni promenlivi
    int time;
public:
    //konstruktor
    TimedTask(char *ID = "", int time = 0) : Task(ID)
    {
        this->time = time;
    }
    //prepokrivanje na 2ta metodi shto se nasleduvaat od Task
    int getOrder()
    {
        return time;
    }
    void print()
    {
        cout<<"TT->"<<ID<<":"<<getOrder()<<endl;
    }
};

class PriorityTask : public Task {
private:
    //deklariranje na dopolnitelni promenlivi
    int priority;
public:
    //konstruktor
    PriorityTask(char * ID = "", int priority = 0) : Task(ID)
    {
        this->priority = priority;
    }

    //prepokrivanje na 2ta metodi shto se nasleduvaat od Task
    int getOrder()
    {
        return priority;
    }
    void print()
    {
        cout<<"PT->"<<ID<<":"<<getOrder()<<endl;
    }
};


void bubbleSortTasks(Task ** tasks, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(tasks[i]->getOrder() > tasks[j]->getOrder())
            {
                Task * temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        tasks[i]->print();
    }
}


void scheduleTimedTasks(Task ** tasks, int n, int t)
{
    Task *timedtask[50];
    int counter = 0;
    for(int i=0; i<n; i++)
    {
        TimedTask *castedTimed = dynamic_cast<TimedTask *>(tasks[i]);
        if(castedTimed && castedTimed->getOrder() < t)
        {
            timedtask[counter++] = tasks[i];
        }
    }
    bubbleSortTasks(timedtask, counter);

}


void schedulePriorityTasks(Task ** tasks, int n, int p)
{
    Task *prioritytask[50];
    int counter = 0;
    for(int i=0; i<n; i++)
    {
        PriorityTask *castedPriority = dynamic_cast<PriorityTask *>(tasks[i]);
        if(castedPriority && castedPriority->getOrder() < p)
        {
            prioritytask[counter++] = tasks[i];
        }
    }
    bubbleSortTasks(prioritytask, counter);
}

int main () {
    int testCase;
    int n;
    cin>>testCase;

    if (testCase==0){
        cin>>n;
    	Task ** tasks;
        tasks = new Task * [n];
    	for (int i=0;i<n;i++){
        char id [5];
        int timeOrPriority;
        int type; //0 za timed, 1 za priority
        cin >> type >>id >> timeOrPriority;
        if (type==0)
        	tasks[i] = new TimedTask(id,timeOrPriority);
        else
            tasks[i] = new PriorityTask(id,timeOrPriority);
        //tasks[i]->print();
    	}

    	cout<<"SCHEDULING PRIORITY TASKS WITH PRIORITY DEGREE LESS THAN 10"<<endl;
    	schedulePriorityTasks(tasks,n,10);

    }
    else if (testCase==1) {
        cin>>n;
    	Task ** tasks;
        tasks = new Task * [n];
    	for (int i=0;i<n;i++){
        char id [5];
        int timeOrPriority;
        int type; //0 za timed, 1 za priority
        cin >> type >>id >> timeOrPriority;
        if (type==0)
        	tasks[i] = new TimedTask(id,timeOrPriority);
        else
            tasks[i] = new PriorityTask(id,timeOrPriority);
        //tasks[i]->print();
    	}


        cout<<"SCHEDULING TIMED TASKS WITH EXECUTION TIME LESS THAN 50"<<endl;
        scheduleTimedTasks(tasks,n,50);
    }
    else {
        TimedTask * tt1 = new TimedTask("11",10);
        TimedTask * tt2 = new TimedTask("11",11);
        TimedTask * tt3 = new TimedTask("11",11);
        PriorityTask * pp1 = new PriorityTask("aa",10);
        PriorityTask * pp2 = new PriorityTask("11",10);

        cout << (tt1==(*tt2))<<endl;
        cout << (tt2==(*tt3))<<endl;
        cout << (pp1==(*pp2))<<endl;
        cout << (pp2==(*tt1))<<endl;
    }

	return 0;
}
