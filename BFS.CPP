#include<bits/stdc++.h>
using namespace std;
void bfs(vector<list<int>>g,int src)
{
    vector<bool>visited(g.size(),false);
    queue<int>q;
    q.push(src);
    visited[src]=true;
    
    list<int>::iterator i; 
    while(!q.empty())
    {
      int l=q.front();
      q.pop();
      cout<<l<<" ";
      for(i=g[l].begin();i!=g[src].end();i++)
      {
          if(!visited[*i])
                q.push(*i);
            visited[*i] = true;
      }
    }
}
int main()
{
    vector<list<int>> g;
    int v,e,src,des;
    cin>>v>>e;
    g.resize(v);
    while(e--)
    {
        cin>>src>>des;
        g[src].push_back(des);
        g[des].push_back(src);
        
    }
    cin>>src;
    bfs(g,src);
    return 0;
}
