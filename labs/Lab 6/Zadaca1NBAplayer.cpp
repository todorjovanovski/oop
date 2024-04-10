#include <iostream>
#include <cstring>

using namespace std;

class NBAPlayer{
protected:
    char * ime;
    char team[40];
    double points, assists, rebounds;
public:
    NBAPlayer(char * ime = "", char * team = "", double points = 0, double assists = 0, double rebounds = 0)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        strcpy(this->team, team);
        this->points = points;
        this->assists = assists;
        this->rebounds = rebounds;
    }
    NBAPlayer(const NBAPlayer &p)
    {
        this->ime = new char[strlen(p.ime) + 1];
        strcpy(this->ime, p.ime);
        strcpy(this->team, p.team);
        this->points = p.points;
        this->assists = p.assists;
        this->rebounds = p.rebounds;
    }
    NBAPlayer& operator=(const NBAPlayer &p)
    {
        if(this!=&p)
        {
            delete [] ime;
            this->ime = new char[strlen(p.ime) + 1];
            strcpy(this->ime, p.ime);
            strcpy(this->team, p.team);
            this->points = p.points;
            this->assists = p.assists;
            this->rebounds = p.rebounds;
        }
        return *this;
    }
    virtual ~NBAPlayer()
    {
        delete [] ime;
    }

    double rating()
    {
        return (points*0.45 + assists*0.3 + rebounds*0.25);
    }

    void print()
    {
        cout<<ime<<" - "<<team<<endl;
        cout<< "Points: " <<points<<endl;
        cout<< "Assists: " <<assists<<endl;
        cout<< "Rebounds: " <<rebounds<<endl;
        cout<< "Rating: " <<this->rating()<<endl;
    }
};

class AllStarPlayer: public NBAPlayer{
private:
    double allStarPoints, allStarAssists, allStarRebounds;
public:
    AllStarPlayer(char * ime = "", char * team = "", double points = 0, double assists = 0, double rebounds = 0,
    double allStarPoints = 0,  double allStarAssists = 0, double allStarRebounds = 0) : NBAPlayer(ime, team, points, assists, rebounds)
    {
        this->allStarPoints = allStarPoints;
        this->allStarAssists = allStarAssists;
        this->allStarRebounds = allStarRebounds;
    }
    AllStarPlayer(const NBAPlayer &p, double allStarPoints = 0, double allStarAssists = 0, double allStarRebounds = 0):NBAPlayer(p)
    {
        this->allStarPoints = allStarPoints;
        this->allStarAssists = allStarAssists;
        this->allStarRebounds = allStarRebounds;
    }
    AllStarPlayer(const AllStarPlayer &asp) : NBAPlayer(ime, team, points, assists, rebounds)
    {
        this->allStarPoints = asp.allStarPoints;
        this->allStarAssists = asp.allStarAssists;
        this->allStarRebounds = asp.allStarRebounds;
    }
    AllStarPlayer& operator=(const AllStarPlayer &asp)
    {
        NBAPlayer::operator=(asp);
        if(this!=&asp)
        {
            this->allStarPoints = asp.allStarPoints;
            this->allStarAssists = asp.allStarAssists;
            this->allStarRebounds = asp.allStarRebounds;
        }
        return *this;
    }
    ~AllStarPlayer(){}

    double allStarRating()
    {
        return (allStarPoints*0.3 + allStarAssists*0.4 + allStarRebounds*0.3);
    }
    double rating()
    {
        return (NBAPlayer::rating() + allStarRating())/2;
    }
    double print()
    {
        NBAPlayer::print();
        cout<< "All Star Rating: " << this->allStarRating()<<endl;
        cout<< "New Rating: " <<this->rating()<<endl;
    }


};


int main() {

  char name[50];
  char team[40];
  double points;
  double assists;
  double rebounds;
  double allStarPoints;
  double allStarAssists;
  double allStarRebounds;

  NBAPlayer * players = new NBAPlayer[5];
  AllStarPlayer * asPlayers = new AllStarPlayer[5];
  int n;
  cin >> n;

  if (n == 1) {

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 5; ++i) {
      cin >> name >> team >> points >> assists >> rebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      players[i].print();
    }
  }
  else if (n == 2) {

    for (int i=0; i < 5; ++i){
      cin >> name >> team >> points >> assists >> rebounds;
      cin >> allStarPoints >> allStarAssists >> allStarRebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
    }

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      players[i].print();

    cout << "ALL STAR PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      asPlayers[i].print();

    }
    else if (n == 3) {

      for (int i=0; i < 5; ++i){
        cin >> name >> team >> points >> assists >> rebounds;
        cin >> allStarPoints >> allStarAssists >> allStarRebounds;
        asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                     allStarPoints,allStarAssists,allStarRebounds);
      }
      cout << "ALL STAR PLAYERS:" << endl;
      cout << "=====================================" << endl;
      for (int i=0; i < 5; ++i)
        asPlayers[i].print();

    }

    delete [] players;
    delete [] asPlayers;
}
