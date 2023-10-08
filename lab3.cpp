#include <iostream>
#include <cstdlib>
using namespace std;

int find_difference(int i,int n,int* all_plates, int summa1, int summa2)
{
    if ((i==n) || (all_plates[i]==0))
        return abs(summa1-summa2);
    else
    {
        int masha_plate=find_difference(++i,n,all_plates,summa1+all_plates[i],summa2);
        int petya_plate=find_difference(++i,n,all_plates,summa1,summa2+all_plates[i]);
        if (masha_plate<petya_plate)
            return masha_plate;
        else
            return petya_plate;
    }     
}

int main()
{   
    int n;
    cin >> n;
    int all_plates[32];
    for (int i=0;i<n;i++)
        cin >> all_plates[i];
    int difference=find_difference(0,n,all_plates,0,0);
    cout << difference;
}
