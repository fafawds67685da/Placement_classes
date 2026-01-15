#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int E, N;
    cout<<"\t Enter the total Energy E \n";
    cin>>E;
    cout<<"\t Enter the number of exercises \n";
    cin>>N;
    vector<int>a;
    cout<<"\t Enter the exercises \n";
    for(int i =0;i<N;i++)
    {
        int z;
        cin>>z;
        a.push_back(z);
    }

    if(E<=0)
    {
        cout<<"\t -1 \n";
        return 0;
    }
    sort(a.rbegin(), a.rend());
    int x = 0;
    for(int i =0;i<N;i++)
    {
        E-=a[i];
        x+=1;
        if(E<=0)
        {
            cout<<"\t"<<x<<"\n";
            return 0;
        }
        else
        {
            E-=a[i];
            x+=1;
            if(E<=0)
                {
                    cout<<"\t"<<x<<"\n";
                    return 0;
                }
        }
    }
    if(E>0)
        {
            cout<<"\t -1 \n";
        }
    return 0;

}
