#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int ROW,COLUMN;
    ifstream Access;
    Access.open("Input.txt");
    Access>>ROW>>COLUMN;

    cout << "ROW :" << ROW<< "\nCOLUMN : " << COLUMN<< endl;

    int **array;
    array=new int *[ROW];
    for (int i=0;i<ROW;i++)
    {
        array[i]=new int [COLUMN];
    }

    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
        {
            Access>>array[i][j];
        }
    }
    cout<<endl<<"Output (Original Matrix) : "<<endl;
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Output (Transposed Matrix) : "<<endl;
    for(int i=0;i<COLUMN;i++)
    {
        for(int j=0;j<ROW;j++)
        {
            cout<<array[j][i]<<" ";
        }
        cout<<endl;
    }

    ofstream Showcase;
    Showcase.open("Output.txt",ios::app);
    Showcase<<endl<<"--------------------------------\n";
    Showcase<<endl<<"New Output (Original Matrix)    : \n";
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
        {
            Showcase<<array[i][j]<<" ";
        }
        Showcase<<endl;
    }
    Showcase<<endl<<"New Output (Transposed Matrix) : \n";
    for(int i=0;i<COLUMN;i++)
    {
        for(int j=0;j<ROW;j++)
        {
            Showcase<<array[j][i]<<" ";
        }
        Showcase<<endl;
    }
    Showcase<<endl<<"--------------------------------\n";
    return 0;
}
