#include "definicje.h"
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
int main()
{
    /*
    double _time;
    ofstream plik("czas.txt");
    srand (time(NULL));
    cout<<"ilu elementowy ma byc graf?"<<endl;
    int i;
    cin>>i;
    ListGraph L(i);
    MatrixGraph M(i);
    ListGraph L1(4);
	L1.Add(0,1);
	L1.Add(1,2);
	L1.Add(2,0);
	L1.Add(2,3);
	MatrixGraph M1(4);
    M1.Add(0,1);
	M1.Add(1,2);
	M1.Add(2,0);
	M1.Add(2,3);
    //////////////////////////////////////////////////////////////

    randE(M,i);
    StartCounter();

    M.EnhancedNaiveBridges();
    _time=GetCounter();
    plik<<_time<<endl;
    cout<<"generowanie Macierzowego grafu o wielkosci: "<<i<<" zajelo nam"<<_time<<endl<<endl;
    /*
    cout<<"Dodaje i elementow do grafu listowego"<<endl;
    StartCounter();
    randG(L,i);

    cout<<"generowanie listowego grafu o wielkosci: "<<i<<" zajelo nam"<<time<<endl<<endl;

    //////////////////////////////////////////////////////////////
    cout<<"Dodaje i elementów do grafu macierzowego"<<endl;
    StartCounter();
    randE(M,i);
    cout<<"generowanie Macierzowego grafu o wielkosci: "<<i<<" zajelo nam"<<GetCounter()<<endl<<endl;
    //////////////////////////////////////////////////////////////
    cout<<"znajdowanie mostów w grafie Listowym i ich czasy: "<<endl;
    StartCounter();
    L.EnhancedNaiveBridges();

    cout<<"Naiwny ale lepszy zajelo nam to: "<<_time<<endl;

      StartCounter();
    L.NaiveBridges();
    _time=GetCounter();
    plik<<_time<<endl;
    cout<<"Naiwny  zajelo nam to: "<<_time<<endl;
    StartCounter();
    L.EnhancedNaiveBridges();
    cout<<"Naiwny ale lepszy zajelo nam to: "<<GetCounter()<<endl;
    StartCounter();
    L1.tarjan_bridges();
    cout<<"tarjan zajelo nam to: "<<GetCounter()<<endl<<endl<<endl<<endl;
    //////////////////////////////////////////////////////////////
    cout<<"znajdowanie mostów w grafie Macierzowym i ich czasy: "<<endl;
    StartCounter();
    M.NaiveBridges();
    cout<<"Naiwny  zajelo nam to: "<<GetCounter()<<endl;
    StartCounter();
    M.EnhancedNaiveBridges();
    cout<<"Naiwny ale lepszy zajelo nam to: "<<GetCounter()<<endl;
    StartCounter();
    //M1.tarjan_bridges();
    cout<<"tarjan zajelo nam to: "<<GetCounter()<<endl<<endl<<endl<<endl;
    */

    ListGraph L2(10);
    L2.Add(0, 1);
    L2.Add(0, 2);
    L2.Add(1, 2);
    L2.Add(1, 5);
    L2.Add(2, 3);
    L2.Add(3, 4);
    L2.Add(3, 5);
    L2.Add(4, 5);
    L2.Add(5, 6);
    L2.Add(6, 7);
    L2.Add(6, 9);
    L2.Add(7, 8);
    L2.Add(8, 9);
    //L2.NaiveBridges();
    //L2.EnhancedNaiveBridges();
    L2.tarjan_bridges();
}
