 #include<bits/stdc++.h>
 using namespace std;
 

int getMid(int start,int end)
{
    return (start+((end-start)/2.0));
}
//fuction to build the array of segment tree //
void buildTree(int arr[],int *segTree,int start,int end,int node)
{
     
  if(start==end)
  {
    segTree[node]=arr[start];
    return;
    
  } 
 int mid=getMid(start,end);

buildTree(arr,segTree,start,mid,2*node+1);
buildTree(arr,segTree,mid+1,end,2*node+2);
segTree[node]=min(segTree[2*node+1],segTree[2*node+2]);

}

int rangequery(int segTree[],int qs,int qe,int start,int end,int node)
{

    if(end<qs || start>qe)//no overlap condition
    {
        return INT_MAX;
    }
    if(qs<=start && qe>=end)//total overlap condition
    {
    return segTree[node];    
    }
    //partial condition
    int mid=getMid(start,end);
    return min(rangequery(segTree,qs,qe,start,mid,2*node+1),rangequery(segTree,qs,qe,mid+1,end,2*node+2));
}
//function to update the array of segment tree
void Update(int start,int end,int index, int node,int value)
{
    if(start>index || index>end)
        return ;
    if(start==index&&end==index)
        {
            segTree[node]=value;
            return;
        }
    int mid=getMid(start,end);
    Update(start,mid,index,2*node+1,value);
    Update(mid+1,end,index,2*node+2,value);
    segTree[node]=min(segTree[(2*node)+1],segTree[(2*node)+2]);
}

