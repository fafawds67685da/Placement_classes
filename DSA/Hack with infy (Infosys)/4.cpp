#include<iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
using namespace std;
int main()
{
    int N;
    cout<<"\t Enter the total number of elements \n";
    cin>>N;


    vector<int> nums;
    cout<<"\t Enter the elements \n";
    for(int i =0;i<N;i++)
    {
        int z;
        cin>>z;
        nums.push_back(z);
    }
    vector<int>org_nums = nums;
    bool even = false;
    int add_on_peak;
    if(N%2==0)
    {
        add_on_peak = (N/2)-1;
        even = true;
    }
    else
    {
        add_on_peak = N/2;
    }
    int left = 0,right = N-1;
    while(add_on_peak>0)
    {
        nums[left]+=add_on_peak;
        nums[right]+=add_on_peak;
        add_on_peak-=1;
        left+=1;
        right-=1;
    }

    unordered_map<int, int>freq;
    for(int i =0;i<N;i++)
    {
        if(freq.find(nums[i]) != freq.end())
        {
            freq[nums[i]]+=1;
        }
        else
        {
            freq[nums[i]] = 1;
        }
    }
    int maxi = 0, new_key=0;
    for(auto it = freq.begin();it!=freq.end();it++)
    {
        if(maxi<it->second)
        {
            maxi = it->second;
            new_key=it->first;
        }
    }
    maxi = new_key;
    cout<<"\t"<<maxi<<"\n";
    vector<int>nums2 (N,0);
    if(even)
    {
        nums2[N/2] = maxi;
        nums2[(N/2)-1] = maxi;
        left = (N/2)-2;
        right = (N/2)+1;

    }
    else
    {
        nums2[N/2] = maxi;
        left = (N/2)-1;
        right = (N/2)+1;
    }
    maxi-=1;
    while(maxi>0)
    {
        nums2[left] = maxi;
        nums2[right] = maxi;
        maxi-=1;
        left-=1;
        right+=1;
    }
    for(int i =0;i<N;i++)
    {
        cout<<" "<<nums[i];
    }
    cout<<"\n";
    for(int i =0;i<N;i++)
    {
        cout<<" "<<nums2[i];
    }

    int z = 0;
    for(int i =0;i<N;i++)
    {
        if(org_nums[i]!=nums2[i])
        {
            z+=1;
        }
    }
    cout<<"\t Changes to be made are : "<<z<<"\n";

    return 0;

}
