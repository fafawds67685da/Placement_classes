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
    vector<int>h2 = villian;
    int j=0;
    for(int i =0;i<M;i++)
    {
        while(heroes[i] > 0 && j < N)
        {
            if(villian[j]<heroes[i])
            {
                heroes[i]-=villian[j];
                j+=1;
            }
            else if(villian[j]==heroes[i])
            {
                j+=1;
                break;
            }
            else
            {
                break;
            }
        }
    }
    if(j==N)
    {
        cout<<"\t 0 \n";
    }
    else
    {
        j = 0;
        reverse(h2.begin(), h2.end());
        for(int i =0;i<M;i++)
        {
            while(h2[i]>0)
            {
                if(villian[j]<h2[i])
                {
                    h2[i]-=villian[j];
                    j+=1;
                }
                else if(villian[j]==h2[i])
                {
                    j+=1;
                    break;
                }
                else
                {
                    break;
                }
            }
        }

        cout<<"\t"<<N-j<<"\n";

    }
    return 0;

}
