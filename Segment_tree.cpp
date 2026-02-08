#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

void update_utils(vector<int>&segment_tree, int sl, int sr, int i, int index, int val)
{
    if(sl==sr)
    {
        segment_tree[i] = val;
        return;
    }
    int sm = (sl+sr)/2;
    if(index>sm)
    {
        update_utils(segment_tree, sm+1, sr, 2*i+2, index, val);
    }
    else
    {
        update_utils(segment_tree, sl, sm, 2*i+1, index, val);
    }
    segment_tree[i] = segment_tree[2*i+1]+segment_tree[2*i+2];
}

void update(vector<int>&segment_tree, int seg_size, vector<int>&arr, int n, int index, int val)
{
    arr[index] = val;
    update_utils(segment_tree, 0, n-1, 0, index, val);
}

int range_sum(vector<int>&segment_tree, int sl, int sr, int ql, int qr, int i)
{
    if(qr < sl || ql>sr)
    {
        return 0;
    }
    else if(sl>=ql && sr<=qr)
    {
        return segment_tree[i];
    }
    else
    {
        int sm=(sl+sr)/2;
        return range_sum(segment_tree, sl, sm, ql, qr, 2*i+1) + range_sum(segment_tree, sm+1, sr, ql, qr, 2*i+2);
    }
}

void buildutil(vector<int>&segment_tree, vector<int>&arr, int sl, int sr, int i, int n)
{
    if(sl==sr)
    {
        segment_tree[i] = sl<n?arr[sl]:0;
        return;
    }
    int sm = (sl+sr)/2;
    buildutil(segment_tree, arr, sl, sm, 2*i+1,n);
    buildutil(segment_tree, arr, sm+1, sr, 2*i+2,n);
    segment_tree[i] = segment_tree[2*i+1] + segment_tree[2*i+2];
}
void buildTree(vector<int>&segment_tree, int seg_size, vector<int>&arr, int n)
{
    buildutil(segment_tree, arr, 0, n-1, 0, n);
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
    int seg_size = 2*pow(2,ceil(log(n)))-1;
    cout<<seg_size;
    vector<int>segment_tree(seg_size,0);
    buildTree(segment_tree, seg_size, arr, n);
    cout<<"\n\n";
    cout<<"\t Segment tree is \n";
    for(int i =0;i<seg_size;i++)
    {
        cout<<segment_tree[i]<<" ";
    }
    cout<<"\n\n";

    int ch = 0;
    int ql=0,qr=0,sum=0;
    int i =0,val = 0;
    while(ch!=3)
    {
        cout<<"\t Enter 1 for range sum query \n\t Enter 2 for update query \n\t Enter 3 for code termination \n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"\t Enter the range of the sum query \n";
            cin>>ql>>qr;
            sum = range_sum(segment_tree, 0, n-1, ql, qr, 0);
            cout<<"\t Sum of the range query is: "<<sum<<"\n";
            break;
        case 2:
            cout<<"\t Enter the value to be updated, means new value \n";
            cin>>val;
            cout<<"\t Enter the index \n";
            cin>>i;
            update(segment_tree, seg_size, arr, n, i, val);
            cout<<"\n\n";
            cout<<"\t Segment tree is \n";
            for(int i =0;i<seg_size;i++)
            {
                cout<<segment_tree[i]<<" ";
            }
            cout<<"\n\n";
            break;
        default:
            break;
        }
    }

    return 0;
}
