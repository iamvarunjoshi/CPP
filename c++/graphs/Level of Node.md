# Problem Statement
Given an Undirected Graph and a node X. The task is to find the level of X from 0.

## Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'V' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v . The final line contains X whose level you have to find.

## Output:
For each testcase, print the level of the given node X.

### Your Task:
You don't need to read input or print anything. Your task is to complete the function levels() which takes the graph, number of vertices (V) and a node (X) as inputs and returns the level of X relative to the node 0. If X does not exist in the graph or is not connected (directly/indirectly) to 0 then return -1.
Refer the following image for more details:


### Expected Time Complexity: O(V + E).
### Expected Auxiliary Space: O(V).

### Constraints:
1 <= T <= 100
1 <= E, V <= 102
1 <= X <= 102

## Example:
### Input:
2
8 8
0 1 0 2 1 3 1 4 1 5 2 6 6 7 2 5
7
2 1
0 1
1

### Output:
3
1

### Explanation:
Testcases 1: In the given graph(above), 7 is at 3rd level starting from source node 0 which is at 0th level.

````cpp
int levels(vector<int> g[], int N, int X)
{
vector<bool>visited(N+1,false);
queue<int>q;q.push(0);
int cv,i,k,j;
int level=0;

while(!q.empty())
{
    level++;
    k=q.size();
    for(i=0;i<k;i++)
    {
        cv=q.front();q.pop();
        visited[cv]=true;
        for(j=0;j<g[cv].size();j++)
        {
            if(X==g[cv][j]) return level;
            if(!visited[g[cv][j]])
            {
                q.push(g[cv][j]);
                visited[g[cv][j]]=true;
            }
        }    
    }    
}
    
    return -1;
}
`````
