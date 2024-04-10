#include <iostream>
#include <cstring>

using namespace std;

class InvalidPassword{
private:
    char error[50];
public:
    InvalidPassword(char * error)
    {
        strcpy(this->error, error);
    }
    void message()
    {
        cout<<error<<endl;
    }
};

class InvalidEmail{
private:
    char error[50];
public:
    InvalidEmail(char * error)
    {
        strcpy(this->error, error);
    }
    void message()
    {
        cout<<error<<endl;
    }
};

class MaximumSizeLimit{
private:
    int limit;
public:
    MaximumSizeLimit(int limit)
    {
        this->limit = limit;
    }

    void message()
    {
        cout<<"You can't add more than "<<limit<<" users."<<endl;
    }
};


class User{
protected:
    char username[50];
    char password[50];
    char email[50];
public:
    User(char * username = "", char * password = "", char * email = "")
    {
        strcpy(this->username, username);
        strcpy(this->password, password);
        strcpy(this->email, email);
        int lowercase = 0, uppercase = 0, numbers = 0;
        for(int i=0; i<strlen(password); i++)
        {
            if(password[i] >= 'a' && password[i] <= 'z')
            {
                lowercase++;
            }
            else if(password[i] >= 'A' && password[i] <= 'Z')
            {
                uppercase++;
            }
            else if(password[i] >= '0' && password[i] <= '9')
            {
                numbers++;
            }
        }
        int at = 0;
        for(int i=0; i<strlen(email); i++)
        {
            if(email[i] == '@')
            {
                at++;
            }
        }
        if(at != 1)
        {
            throw InvalidEmail("Mail is not valid.");
        }
        if(lowercase < 1 || uppercase < 1 || numbers < 1)
        {
            throw InvalidPassword("Password is too weak.");
        }
    }

    virtual double popularity() = 0;
};


class FacebookUser: public User{
private:
    int friends, likes, comments;
    const static double likesCoef;
    const static double commentsCoef;
public:
    FacebookUser(char * username = "", char * password = "", char * email = "",
    int friends = 0, int likes = 0, int comments = 0): User(username, password, email)
    {
        this->friends = friends;
        this->likes = likes;
        this->comments = comments;
    }

    double popularity()
    {
        return friends + likes * likesCoef + comments * commentsCoef;
    }
};
const double FacebookUser::likesCoef = 0.1;
const double FacebookUser::commentsCoef = 0.5;


class TwitterUser: public User{
private:
    int followers, tweets;
    const static double coefTweets;
public:
    TwitterUser(char * username = "", char * password = "", char * email = "",
    int followers = 0, int tweets = 0): User(username, password, email)
    {
        this->followers = followers;
        this->tweets = tweets;
    }

    double popularity()
    {
        return followers + tweets * coefTweets;
    }
};
const double TwitterUser::coefTweets = 0.5;


class SocialNetwork{
private:
    User ** users;
    int n;
    static int max_users;
public:
    SocialNetwork(User ** users = 0, int n = 0)
    {
        this->n = n;
        this->users = new User * [n];
        for(int i=0; i<n; i++)
        {
            this->users[i] = users[i];
        }
    }
    SocialNetwork(const SocialNetwork &sn)
    {
        this->n = sn.n;
        this->users = new User * [sn.n];
        for(int i=0; i<n; i++)
        {
            this->users[i] = sn.users[i];
        }
    }
    SocialNetwork& operator=(const SocialNetwork &sn)
    {
        if(this!=&sn)
        {
            this->n = sn.n;
            delete [] users;
            this->users = new User * [sn.n];
            for(int i=0; i<n; i++)
            {
                this->users[i] = sn.users[i];
            }
        }
        return * this;
    }
    ~SocialNetwork()
    {
        delete [] users;
    }

    SocialNetwork& operator+=(User *u)
    {
        if(n == max_users)
        {
            throw MaximumSizeLimit(max_users);
        }
        else
        {
            User ** temp = new User*[n+1];
            for(int i=0; i<n; i++)
            {
                temp[i] = users[i];
            }
            temp[n++] = u;
            delete [] users;
            users = temp;
        }
        return *this;
    }

    double avgPopularity()
    {
        double sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += users[i]->popularity();
        }
        return (double)sum/n;
    }

    void changeMaximumSize(int number)
    {
        max_users = number;
    }
};
int SocialNetwork::max_users = 5;



int main() {

  SocialNetwork network = SocialNetwork();
    int n;
    cin >> n;
    char username[50];
    char password[50];
    char email[50];
    int userType;
    for (int i=0; i < n; ++i) {
      cin >> username;
      cin >> password;
      cin >> email;
      cin >> userType;
      if (userType == 1) {
        int friends;
        int likes;
        int comments;
        cin >> friends >> likes >> comments;

        // TODO: Try-catch
        try{
        User * u = new FacebookUser(username,password,email,friends,likes,comments);
        network += u;
        }
        catch(InvalidEmail ie){
            ie.message();
        }
        catch(InvalidPassword ip){
            ip.message();
        }
        catch(MaximumSizeLimit ml){
            ml.message();
        }


      }
      else {
        int followers;
        int tweets;
        cin >> followers >> tweets;

        // TODO: Try-catch
        try{
        User * u= new TwitterUser(username,password,email,followers,tweets);
        network += u;
        }
        catch(InvalidEmail ie){
        ie.message();
        }
        catch(InvalidPassword ip){
            ip.message();
        }
        catch(MaximumSizeLimit ml){
            ml.message();
        }
    }

}
    network.changeMaximumSize(6);
    cin >> username;
    cin >> password;
    cin >> email;
    int followers;
    int tweets;
    cin >> followers >> tweets;

    // TODO: Try-catch

    try {
    User * u= new TwitterUser(username,password,email,followers,tweets);
    network += u;
    }
    catch(InvalidEmail ie){
        ie.message();
    }
    catch(InvalidPassword ip){
        ip.message();
    }
    catch(MaximumSizeLimit ml){
        ml.message();
    }

    cout << network.avgPopularity();

    return 0;
}
