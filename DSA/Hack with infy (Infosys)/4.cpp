#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int M, N;
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

    int x = 0;
    for(int i =0;i<N/2;i++)
    {
        if(i!=0)
        {
            if(a[i]==a[i-1])
            {
                x+=1;
                if(a[i]==a[N-1-i])
                {
                    x+=1;
                }
            }
        }
        else{
        if(a[i]!=a[N-1-i])
        {
            x+=1;
        }}
    }
    cout<<"\t"<<x<<"\n";
    return 0;

}
