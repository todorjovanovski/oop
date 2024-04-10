#include <iostream>
#include <cstring>
using namespace std;

class WebPage{
private:
    char url[100];
    char * sodrzina;
public:
    WebPage(char * url ="", char * sodrzina = "")
    {
        strcpy(this->url, url);
        this->sodrzina = new char[strlen(sodrzina) + 1];
        strcpy(this->sodrzina, sodrzina);
    }
    WebPage(const WebPage &wp)
    {
        strcpy(this->url, wp.url);
        this->sodrzina = new char[strlen(wp.sodrzina) + 1];
        strcpy(this->sodrzina, wp.sodrzina);
    }
    WebPage& operator=(const WebPage &wp)
    {
        if(this!=&wp)
        {
            strcpy(this->url, wp.url);
            delete [] sodrzina;
            this->sodrzina = new char[strlen(wp.sodrzina) + 1];
            strcpy(this->sodrzina, wp.sodrzina);
        }
        return *this;
    }
    ~WebPage()
    {
        delete [] sodrzina;
    }

    bool daliIsti(WebPage &dr)
    {
        return strcmp(url, dr.url) == 0;
    }

    friend class WebServer;
};

class WebServer{
private:
    char ime[30];
    WebPage * stranici;
    int n;
public:
    WebServer(char * ime = 0, int n = 0, WebPage * wp = 0)
    {
        strcpy(this->ime, ime);
        this->n = n;
        stranici = new WebPage[n];
        for(int i=0; i<n; i++)
        {
            stranici[i] = wp[i];
        }
    }
    WebServer(const WebServer &ws)
    {
        strcpy(ime, ws.ime);
        n = ws.n;
        stranici = new WebPage[ws.n];
        for(int i=0; i<n; i++)
        {
            stranici[i] = ws.stranici[i];
        }
    }
    WebServer& operator=(const WebServer &ws)
    {
        if(this!=&ws)
        {
            strcpy(ime, ws.ime);
            n = ws.n;
            delete [] stranici;
            stranici = new WebPage[ws.n];
            for(int i=0; i<n; i++)
            {
                stranici[i] = ws.stranici[i];
            }
        }
        return *this;
    }
    ~WebServer()
    {
        delete [] stranici;
    }
    WebServer& addPage(WebPage nova)
    {
        WebPage *temp = new WebPage[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i] = stranici[i];
        }
        temp[n++] = nova;
        delete [] stranici;
        stranici = temp;
        return *this;
    }
    WebServer& deletePage(WebPage del)
    {
        int newN = 0;
        for(int i=0; i<n; i++)
        {
            if(stranici[i].daliIsti(del) == false)
            {
                newN++;
            }
        }
        WebPage * temp = new WebPage[newN];
        int j = 0;
        for(int i=0; i<n; i++)
        {
            if(stranici[i].daliIsti(del) == 0)
            {
                temp[j++] = stranici[i];
            }
        }
        delete [] stranici;
        stranici = temp;
        n = newN;
        return *this;
    }
    void listPages()
    {
        for(int i=0; i<n; i++)
        {
            cout<<stranici[i].sodrzina<<" - "<<stranici[i].url<<endl;
        }
    }

};

int main()
{
    WebPage wp1("www.google.com", "search enginge");
    WebPage wp2("www.facebook.com", "social media");
    WebPage wp3("www.time.mk", "vesti");

    WebServer ws("Server 1");

    ws.addPage(wp1);
    ws.addPage(wp2);
    ws.addPage(wp3);

    ws.listPages();
    cout<<"After delete: "<<endl;
    ws.deletePage(wp2);

    ws.listPages();

    return 0;
}
