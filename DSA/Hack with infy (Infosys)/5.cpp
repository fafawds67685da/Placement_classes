#include <iostream>
#include <unordered_map>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main()
{
    string s;
    cin >> s;

    unordered_map<char,int> mp;

    int l = s.length();
    for(int i =0;i<l;i++)
    {
        if(mp.find(s[i])!=mp.end())
        {
            mp[s[i]]+=1;
        }
        else
        {
            mp[s[i]]=1;
        }
    }
    int arr[mp.size()];
    int z = 0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        arr[z++]=it->second;
    }
    int x=0;
    for(int i =0;i<mp.size()-1;i++)
    {
        x = gcd(arr[i],arr[i+1]);
    }
    if(x==0)
    {
        cout<<"\t Maximum number of pieces we can get are: "<<arr[0]<<"\n";
        return 0;
    }
    cout<<"\t Maximum number of pieces we can get are: "<<x<<"\n";
    return 0;
}
