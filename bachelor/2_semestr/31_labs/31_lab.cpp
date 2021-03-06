#include <iostream>

#define max_init 1000 

using namespace std;

class Graph
{
    private:
    int **arr;
    int d[6];
    int v[6];
    int tmp, min_index, min;
    public:
    Graph(int n = 6)
    {
        arr = new int * [n];
        for(int counter = 0; counter < 6; counter++)
        {
            arr[counter] = new int [n];
        }
    }
    void make()
    {
        arr[0][1] =  2;
        arr[0][5] = 57;
        arr[1][0] =  2;
        arr[1][2] =  3;
        arr[1][3] =  8;
        arr[1][5] = 13;
        arr[2][1] =  3;
        arr[2][3] =  5;
        arr[3][1] =  8;
        arr[3][2] =  5;
        arr[3][4] = 34;
        arr[3][5] = 21;
        arr[4][3] = 34;
        arr[4][5] = 45;
        arr[5][0] = 57;
        arr[5][1] = 13;
        arr[5][3] = 21;
        arr[5][4] = 45;
    }
    void print()
    {
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                cout << arr[i][j] << '\t';
            }
            cout << endl;
        }
    }
    void min_d(int num)
    {
        for(int i = 0; i < 6; i++)
        {
            d[i] = max_init;
            v[i] = 1;
        }
        d[num] = 0;
        do
        {
            min_index = max_init;
            min = max_init;
            for(int i = 0; i < 6; i++)
            {
                if((v[i] == 1) and (d[i] < min))
                {
                    min = d[i];
                    min_index = i;
                }
            }
            if(min_index != max_init)
            {
                for(int i = 0; i < 6; i++)
                {
                    if(arr[min_index][i] > 0)
                    {
                        tmp = min + arr[min_index][i];
                        if(tmp < d[i])
                        {
                            d[i] = tmp;
                        }
                    }
                }
                v[min_index] = 0;
            }
        }while(min_index < max_init);
        cout << "Кратчиайшее растояние от вершины " << num + 1 << endl;
        for(int i = 0; i < 6; i++)
        {
            if(i != num)
            {
                cout << num + 1 << " - " << i + 1 << " = " << d[i] << endl;
            }
        }
    }
    ~Graph()
    {
        for(int i = 0; i < 6; i++)
        {
            delete [] arr[i];
        }
    }
};

int main(int argc, char* argv[])
{
    Graph lab;
    lab.make();
    lab.print();
    for(int i = 0; i < 6; i++)
    {
        lab.min_d(i);
    }
    
    return 0;
}
