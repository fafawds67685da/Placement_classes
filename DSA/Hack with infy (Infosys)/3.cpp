#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;
int main()
{
    int  N;
    cout<<"\t Enter the number of elements \n";
    cin>>N;

    vector<int>a;

    cout<<"\t Enter the numbers \n";
    for(int i =0;i<N;i++)
    {
        int z;
        cin>>z;
        a.push_back(z);
    }
    int z = INT_MIN;
    for(int i =1;i<N;i++)
    {
        int diff, days;
        if(a[i]>=a[i-1])
        {
            if(a[i-1]<0)
            {
                diff = abs(a[i-1]-a[i]-1);
            }
            else if(a[i]==a[i-1])
            {
                diff = 1;
            }
            else
            {
                diff = a[i]-a[i-1]-1;
            }
            if(diff==0)
            {
                diff = a[i];
            }
            days = (int)ceil(sqrt(diff));
            cout<<"For loop "<<(i+1)<<"Diff is: "<<diff<<"\n";
            cout<<"For loop "<<(i+1)<<"Days are: "<<days<<"\n";
            if(diff==((days*days)-2))
               {
                   a[i] = a[i]-diff-1;
               }
               else
               {
                   a[i] = a[i]-diff;
               }
        }
        z=max(z,days);
    }
    if(z==INT_MIN)
    {
        z=0;
    }
    cout<<"\t Minimum days required :"<<z<<"\n";
    return 0;

}
