#include <iostream>
#include <cstring>
using namespace std;

class Email{
private:
    char to[100];
    char from[100];
    char subject[200];
    char body[500];
public:
    Email(char * _to, char * _from, char * _subject, char * _body)
    {
        strcpy(to, _to);
        strcpy(from, _from);
        strcpy(subject, _subject);
        strcpy(body, _body);
    }
    void setTo(char * _to)
    {
        strcpy(to, _to);
    }
    void setFrom(char * _from)
    {
        strcpy(from, _from);
    }
    void setSubject(char * _subject)
    {
        strcpy(subject, _subject);
    }
    void setBody(char * _body)
    {
        strcpy(body, _body);
    }

    char * getTo()
    {
        return to;
    }
    char * getFrom()
    {
        return from;
    }
    char * getSubject()
    {
        return subject;
    }
    char * getBody()
    {
        return body;
    }

    void print()
    {
        cout<<"To: "<<to<<endl;
        cout<<"From: "<<from<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"Body: "<<body<<endl;
    }

};

bool checkMail(char * mail)
{
    int br = 0;
    for(int i=0; i<strlen(mail); i++)
    {
        if(mail[i] == '@')
        {
            br++;
        }
    }
    if (br == 1)
    {
        return true;
    }
    else{
        return false;
    }
}


int main()
{
    char to[100], from[100], subject[200], body[500];
    cin>>to;
    if(checkMail(to))
    {
        cin>>from>>subject>>body;
        Email poraka(to, from, subject, body);
        cout<<"Sent: "<<endl;
        poraka.print();
    }
    else{
        cout<<"Nevalidna adresa."<<endl;
    }
}
