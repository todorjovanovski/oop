#include <iostream>
#include <cstring>

using namespace std;

//class Matrica{
//private:
//    int ** matrix;
//    int rows, cols;
//public:
//    Matrica(int **matrix = 0, int rows = 0, int cols = 0)
//    {
//        this->rows = rows;
//        this->cols = cols;
//        this->matrix = new int*[rows];
//        for(int i=0; i<rows; i++)
//        {
//            this->matrix[i] = new int[cols];
//            for(int j=0; j<cols; j++)
//            {
//                this->matrix[i][j] = matrix[i][j];
//            }
//        }
//    }
//    ~Matrica()
//    {
//        for(int i=0; i<rows; i++)
//        {
//            delete [] matrix[i];
//        }
//        delete [] matrix;
//    }
//    Matrica(const Matrica &m)
//    {
//        this->rows = m.rows;
//        this->cols = m.cols;
//        this->matrix = new int*[m.rows];
//        for(int i=0; i<m.rows; i++)
//        {
//            this->matrix[i] = new int[m.cols];
//            for(int j=0; j<m.cols; j++)
//            {
//                this->matrix[i][j] = m.matrix[i][j];
//            }
//        }
//    }
//    Matrica& operator=(const Matrica &m)
//    {
//        if(this!=&m)
//        {
//            this->rows = m.rows;
//            this->cols = m.cols;
//            for(int i=0; i<rows; i++)
//            {
//                delete [] matrix[i];
//            }
//            delete [] matrix;
//            this->matrix = new int*[m.rows];
//            for(int i=0; i<m.rows; i++)
//            {
//                this->matrix[i] = new int[m.cols];
//                for(int j=0; j<m.cols; j++)
//                {
//                    this->matrix[i][j] = m.matrix[i][j];
//                }
//            }
//        }
//        return * this;
//    }
//
//    friend istream& operator>>(istream& is, Matrica& m)
//    {
//        cout<<"ROWS: "<<endl;
//        is>>m.rows;
//        cout<<"COLS: "<<endl;
//        is>>m.cols;
//        for(int i=0; i<m.rows; i++)
//        {
//            for(int j=0; j<m.cols; j++)
//            {
//                is>>m.matrix[i][j];
//            }
//        }
//        return is;
//    }
//
//    friend ostream& operator<<(ostream& os, Matrica& m)
//    {
//        for(int i=0; i<m.rows; i++)
//        {
//            for(int j=0; j<m.cols; j++)
//            {
//                os<<m.matrix[i][j]<<" ";
//            }
//            os<<endl;
//        }
//        return os;
//    }
//
//};


class Matrica{
private:
    float matrica[10][10];
    int rows, cols;
public:
    friend istream& operator>>(istream& is, Matrica &m);
    friend ostream& operator<<(ostream& os, Matrica &m);

    Matrica& operator+(float num)
    {
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                matrica[i][j] += num;
            }
        }
        return *this;;
    }

    Matrica& operator-(Matrica m)
    {
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                matrica[i][j] -= m.matrica[i][j];
            }
        }
        return *this;
    }

    Matrica& operator*(Matrica m)
    {
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                matrica[i][j] *= m.matrica[i][j];
            }
        }
        return *this;
    }


};

istream& operator>>(istream& is, Matrica &m)
{
    is>>m.rows>>m.cols;
    for(int i=0; i<m.rows; i++)
    {
        for(int j=0; j<m.cols; j++)
        {
            is>>m.matrica[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, Matrica &m)
{
    for(int i=0; i<m.rows; i++)
    {
        for(int j=0; j<m.cols; j++)
        {
            os<<m.matrica[i][j]<<" ";
        }
        os<<endl;
    }
    os<<endl;
    return os;
}



vashiot kod ovde

int main()
{
    Matrica A;
    Matrica B;
    Matrica C;
    cin>>A>>B>>C;
    Matrica D=B*C;
    Matrica R=A-D+2;
    cout<<R;

    return 0;
}
