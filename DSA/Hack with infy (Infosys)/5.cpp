#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char,int> mp;

    // count characters
    for(char c : s)
        mp[c]++;

    int odd = -1;

    // find any odd count
    for(auto p : mp)
    {
        if(p.second % 2 != 0)
        {
            odd = p.second;
            break;
        }
    }

    // if odd exists
    if(odd != -1)
    {
        for(auto p : mp)
        {
            if(p.second % odd != 0)
            {
                cout << 1;
                return 0;
            }
        }
        cout << odd;
    }
    else
    {
        int smallest = 1e9;

        for(auto p : mp)
            smallest = min(smallest, p.second);

        for(auto p : mp)
        {
            if(p.second % smallest != 0)
            {
                cout << 1;
                return 0;
            }
        }
        cout << smallest;
    }

    return 0;
}
