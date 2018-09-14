#include<bits/stdc++.h>
using namespace std;
int *arr;
void updateBIT(int val,int node,int size)
{
while(node<size)
 {
    arr[node]+=val;
    node+=(node&(-node));
 }
}
void buildBIT(int size)
{
    arr=new int[size+1];
    for(int i=0;i<size+1;++i)
    arr[i]=0;
    for(int node=1;node<size+1;node++)
    {
        int temp;
        cin>>temp;
        updateBIT(temp,node,size+1);
    }    
}
int sum(int range)
{
    int ans=0;
    while(range>0)
    {
        ans+=arr[range];
        range-=(range & (-range));
    }

    return ans;
}
int getsum(int left,int right)
{
   return sum(right)-sum(left-1);                                               
}
