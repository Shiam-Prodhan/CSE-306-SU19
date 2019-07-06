#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *Array, int Size) {
   for(int i = 0; i<Size; i++)
   cout << Array[i] << " ";
   cout << endl;
}



void merge(int *Array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-Arrayays
   nl = m-l+1; nr = r-m;
   int lArray[nl], rArray[nr];
   //fill left and right sub-Arrayays
   for(i = 0; i<nl; i++)
      lArray[i] = Array[l+i];
   for(j = 0; j<nr; j++)
      rArray[j] = Array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp Arrayays to real Arrayay
   while(i < nl && j<nr) {
      if(lArray[i] <= rArray[j]) {
         Array[k] = lArray[i];
         i++;
      }else{
         Array[k] = rArray[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left Arrayay
      Array[k] = lArray[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right Arrayay
      Array[k] = rArray[j];
      j++; k++;
   }
}
void mergeSort(int *Array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second Arrayays
      mergeSort(Array, l, m);
      mergeSort(Array, m+1, r);
      merge(Array, l, m, r);
   }
}

int main()
{
    int Size,i,j,k,l,m,Temp;
    ifstream Access;
    Access.open("Input_100000.txt");
    Access>>Size;
    cout<<"Size of the file is : "<<Size;
    ofstream Show;
    srand(17272345);
    Show<<endl;
    Show.open("Input_100000.txt",ios::app);
    for(i=0;i<100000;i++)
    {
        Show << rand() <<"\n";
    }
    Show.close();

    int *Array = new int [Size];
    for(i=0;i<Size;i++)
    {
        Access>>Array[i];
    }
    cout<<"\n\nRandom Inputs : ";
    for(i=0;i<Size;i++)
    {
        cout<<Array[i]<<" ";
    }
    cout<<endl;
    clock_t starTime=clock();//TimeStart

    mergeSort(Array, 0, Size-1);
    clock_t endTime=clock();//EndTime
    double timeLapse=double(endTime-starTime)/CLOCKS_PER_SEC;//CountTime


    cout<<endl<<"\nSorted output : ";

    display(Array, Size);
    ofstream Print;
    Print.open("Output_100000.txt");

    for(int i = 0; i<Size; i++)
    {
        Print << Array[i] << "\n";
    }


    cout <<"\n\nTime for Merge Sort Algorithm : "<< timeLapse<< endl;
    Print <<"\n\nTime for Merge Sort Algorithm : "<< timeLapse<< endl;
    delete []Array;

    return 0;
}

