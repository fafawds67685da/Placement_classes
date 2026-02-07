#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

void update(vector<int>&arr, vector<int>&sqrt_array, int n, int num_block, int index, int val)
{
    int change = val - arr[index];
    arr[index] = val;
    sqrt_array[index/num_block]+= change;
}

int range_sum(vector<int>&arr, vector<int>&sqrt_array, int n, int num_block, int l, int r)
{
    int sb = l/num_block, eb = r/num_block;
    int sum = 0;
    for(int i = sb+1; i<eb;i++)
    {
        sum+=sqrt_array[i];
    }
    int st = l, en = (l/num_block + 1)*num_block;
    while(st<en)
    {
        sum+=arr[st++];
    }
    if(l/num_block==r/num_block)
    {
        return sum;
    }
    st = (r/num_block)*num_block, en = r;
    while(st<=en)
    {
        sum+=arr[st++];
    }

    return sum;
}

int main()
{
    vector<int> arr;
    int n;
    cout<<"\t Enter the size of the array\n";
    cin>>n;
    cout<<"\t Enter the array elements \n";
    for(int i = 0;i<n;i++)
    {
        int z ;
        cin>>z;
        arr.push_back(z);
    }
    int num_block = ceil(sqrt(n));
    vector<int> sqrt_array(num_block, 0);
    for(int i =0;i<n;i++)
    {
        sqrt_array[i/num_block]+= arr[i];
    }
    cout<<"\t The original array is \n\n\t";
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
    cout<<"\t The Square root decomposed array is \n\n\t";
    for(int i =0;i<num_block;i++)
    {
        cout<<sqrt_array[i]<<" ";
    }
    cout<<"\n\n";
    int ch = 0;
    int val=0, index = 0, l=0,r=0;
    int sum = 0;
    while(ch!=3)
    {
        cout<<"\t Enter 1 for Update query \n\t Enter 2 for Range Sum query \n\t Enter 3 to terminate the code \n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"\t Enter the value to be updated \n";
                cin>>val;
                cout<<"\t Enter the index of the value \n";
                cin>>index;
                update(arr, sqrt_array, n, num_block, index, val);

                cout<<"\t The original array is \n\n\t";
                for(int i =0;i<n;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<"\n\n";
                cout<<"\t The Square root decomposed array is \n\n\t";
                for(int i =0;i<num_block;i++)
                {
                    cout<<sqrt_array[i]<<" ";
                }
                cout<<"\n\n";
                break;
            }
        case 2:
                cout<<"\t Enter the value of L \n";
                cin>>l;
                cout<<"\t Enter the value of R \n";
                cin>>r;
                sum = range_sum(arr, sqrt_array, n, num_block, l, r);
                cout<<"\n\n\t The sum of the query is: "<<sum<<"\n\n";
                break;
            break;
        default:
            break;
        }
    }
    return 0;
}
