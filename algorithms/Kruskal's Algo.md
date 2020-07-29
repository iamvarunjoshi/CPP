## Kruskal's Algo With Union Find
- mst is the vector storing edges of MST
- parents is the array storing parents of each vertex
- v is the edge list of graph

````cpp

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;
//normal Kruskal's Algo

bool compare(pp a,pp b){
    return (a.first>b.first)?true:false;
}

int parent[100];
vector<pp> mst;

int root(int x)
{
    while(x!=parent[x]){
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}

void unionfunc(int a,int b)
{
    parent[a]=b;
}

void kruskals(vector<pp> v,int vertices){
    int count=0,p1,p2;
    for(int i=0;i<100;i++)
        parent[i]=i;
    
    while(!v.empty()&&count<vertices-1)
    {
        pp temp=v[v.size()-1];
        v.pop_back();
        p1=root(temp.second.first);   
        p2=root(temp.second.second);
        
        if(p1!=p2)
        {   
            unionfunc(p1,p2);
            count++;
            mst.push_back(temp);
        }
    }
}

int main()
{

    vector<pp> v={  {1,{0,1}}, {5,{0,2}}, {10,{2,3}}, {4,{0,3}},    {3,{1,3}},  {6,{1,2}},  {7,{3,4}},  
    {8,{2,4}},  {2,{4,5}},  {9,{2,5}},  {6,{3,5}}};
    
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" {"<<v[i].second.first<<","<<v[i].second.second<<'}'<<endl;
        
    cout<<endl<<endl;   
    kruskals(v,6);

    sort(v.begin(),v.end(),compare);

    for(int i=0;i<mst.size();i++)
        cout<<mst[i].first<<" {"<<mst[i].second.first<<","<<mst[i].second.second<<'}'<<endl;
    

    return 0;
}

````
