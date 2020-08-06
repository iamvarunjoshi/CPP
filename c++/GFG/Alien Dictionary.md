# [Link to Problem](https://practice.geeksforgeeks.org/problems/alien-dictionary/1)
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order.

### Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N and k denoting the size of the dictionary. Then in the next line are sorted space separated values of the alien dictionary.

### Output:
For each test case in a new line output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

### Your Task:
You don't need to read input or print anything. Your task is to complete the function findOrder() which takes the string array dict[], its size N and the integer K as inputs and returns a string denoting the order of characters in the alien language.

### Expected Time Complexity: O(N + K).
### Expected Auxiliary Space: O(K).

### Constraints:
1 <= T <= 1000
1 <= N <= 300
1 <= k <= 26
1 <= Length of words <= 50

## Example:
### Input:
2
5 4
baa abcd abca cab cad
3 3
caa aaa aab

### Output:
1
1

### Explanation:
Test Case 1:
Input:  Dict[ ] = { "baa", "abcd", "abca", "cab", "cad" }, k = 4
Output: Function returns "bdac"
Here order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa"
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Test Case 2:
Input: Dict[] = { "caa", "aaa", "aab" }, k = 3
Output: Function returns "cab"

````cpp
void topoSort(vector<int> adj[],stack<int>&s,vector<bool>&visited,int cv)
{
    //first traverse all adj edges and then push current vertex
    visited[cv]=true;
    
    for(int i=0;i<adj[cv].size();i++)
        if(!visited[adj[cv][i]])
            topoSort(adj,s,visited,adj[cv][i]);
    
    s.push(cv);
}


string findOrder(string dict[], int n, int v) {

//v is the no of verticies we're having
    vector<int> adj[26];
    
    //making graph out of dictionary 
    for(int i=0;i<n-1;i++)
    {
        string word1=dict[i] , word2=dict[i+1];
        int n1=word1.size(),n2=word2.size(),len=min(n1,n2);
     for(int j=0;j<len;j++){
         
      if(word1[j]!=word2[j]){
       adj[word1[j]-'a'].push_back(word2[j]-'a');
        break;
      }
      
     }
    }
    
    stack<int>s;
    vector<bool> visited(26,false);
    
    for(int i=0;i<26;i++)
        if(!visited[i])
            topoSort(adj,s,visited,i);
    
    string ans;
    while(!s.empty())
    {
        char c='a'+s.top();
        s.pop();
        ans.push_back(c);
    }
return ans;
}


`````
