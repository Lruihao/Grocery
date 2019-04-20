#include <iostream>
using namespace std;

class Row
{
        int* m_data = NULL;
        int m_y;
public:
        Row(int y) : m_y(y){ m_data = new int[y+1]; }
        ~Row() { delete m_data; }
        int& operator[](int j)
        {
                if(j > m_y)
                        j = m_y;
                return m_data[j];
        }
};

class CMatrix
{
        int m_x;
        int m_y;
        Row** m_data = NULL;
public:
        CMatrix(int x, int y) : m_x(x), m_y(y)
        {
                m_data = new Row*[x+1];
                for(int i = 0; i <= m_x; i++)
                        m_data[i] = new Row(m_y);
        }
        ~CMatrix()
        {
                for(int i = 0; i <= m_x; i++)
                        delete m_data[i];
                delete m_data;
        }
        Row& operator[](int i)
        {
                if(i > m_x)
                        i = m_x;
                return *m_data[i];
        }
        void Test()
        {
                for(int i = 0; i < m_x; i++)
                        for(int j = 0; j < m_y; j++)
                                (*this)[i][j] = i*m_x+j;
        }
        void Dump()
        {
                for(int i = 0; i < m_x; i++)
                {
                        for(int j = 0; j < m_y; j++)
                                cout << (*this)[i][j] << " ";
                        cout << "(" << (*this)[i][m_y] << ")" << endl;
                }
                for(int j = 0; j <= m_y; j++)
                        cout << "(" << (*this)[m_x][j] << ")";
                cout << endl;
        }
};

int main()
{
        CMatrix cm(2, 3);
        cm.Test();
        cm[0][1] = 5;
        cm[8][9] = 5;
        cm.Dump();
        return 0;
}
