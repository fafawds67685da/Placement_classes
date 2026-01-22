#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int M, N;
    cout<<"\t Enter the total number of villian \n";
    cin>>N;
    cout<<"\t Enter the number of Heroes \n";
    cin>>M;
    int x;
    cout<<"\t Enter the health of the heroes \n";
    cin>>x;

    vector<int> heroes(M, x);


    vector<int>villian;

    cout<<"\t Enter the health of the villians \n";
    for(int i =0;i<N;i++)
    {
        int z;
        cin>>z;
        villian.push_back(z);
    }
    int left = 0;
    int right = N-1;
    while(left<M && right>-1)
    {
        if(heroes[left]>=villian[right])
        {
            heroes[left]-=villian[right];
            right-=1;
        }
        else if(heroes[left]<villian[right])
        {
            left+=1;
        }
        else
        {
            left+=1;
            right-=1;
        }
    }
    if(right!=-1)
    {
        cout<<right+1<<"\n";
    }
    else
    {
        cout<<0<<"\n";
    }

    return 0;
}
