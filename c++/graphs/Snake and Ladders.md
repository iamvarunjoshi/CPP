## [Practice Link](https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0/)

Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) . 

### Example
For the above board output will be 3 
For 1st throw get a 2
For 2nd throw get a 6
For 3rd throw get a 2

### Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes present. Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes to a position 'b'.

### Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

### Constraints:
1 <= T <= 100
1 <= N <= 10
1 <= a <= 30
1 <= b <= 30

### Example:
#### Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30

#### Output:
3
1

### Explanation:
Testcase 1:
For 1st throw get a 2, which contains ladder to reach 22
For 2nd throw get a 6, which will lead to 28
Finally get a 2, to reach at the end 30. Thus 3 dice throws required to reach 30.

````cpp
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,a,b;
	    cin>>n;
	    map<int,int>mp;
	    //queue cache is for BFS traversal thr the group
	    queue<int>cache;
	    
	    //vis array stores the no of die rolls that are required to reach that no
	    int vis[40]={0};
	    
	    //map named mp to store the ladders and snake tails in the route
	   for(int i=0;i<n;i++)
	   {
	       cin>>a>>b;
	       mp[a]=b;
	   }
	   //to reach a no i from 1 we require i-1 rolls i.e
	   /*
	    0   rolls are required to reach 1 from 1 
	    1   rolls are required to reach 2 from 1
	    2   rolls are required to reach 3 from 1
	   */
	   for(int i=1;i<=40;i++)
	        vis[i]=i-1;
	   
	   //pushing starting position in queue
	   cache.push(1);
	   int num;
	   
	  while(!cache.empty()){
	      //remove the current point from queue
	      num=cache.front();cache.pop();
	      //break loop as the calcultion required to reach 30pos would have be calcuted in last trial
	      if(num>=30)
	        break;
	      else
	      {
	          //look if a ladder exists and avoiding snakes
	        if(mp.count(num)>0&&mp[num]>num)
	        {
	                int dest=mp[num];
	                //no of rolls required to reach the pos thr ladder would be same as the rolls required for the current position
	                vis[dest]=vis[num];
	                cache.push(dest);
	                //erase the current ladder used
	                   mp.erase(num);
	        }
	        //if it doesn't exists in map try out six diff possibility
	        else
	        {
	            //if no ladder exists then explore the next 6 paths we can reach by rolling die
	            for(int i=1;i<=6&&(num+i<=30);i++){
	                //if it required more die rolls to reach a number than dont queue that path
	                if(vis[num+i]>=vis[num]+1)
	                {
	                    vis[num+i]=vis[num]+1;
	                    cache.push(num+i);
	                }
	            }
	            
	        }
	      }
	  }
	  cout<<vis[30]<<endl;
	}
	return 0;
}
````
## Aternate Solution
`````cpp
struct queueEntry 
{ 
    int v;     // Vertex number 
    int dist;  // Distance of this vertex from source 
}; 
  
// This function returns minimum number of dice throws required to 
// Reach last cell from 0'th cell in a snake and ladder game. 
// move[] is an array of size N where N is no. of cells on board 
// If there is no snake or ladder from cell i, then move[i] is -1 
// Otherwise move[i] contains cell to which snake or ladder at i 
// takes to. 
int getMinDiceThrows(int move[], int N) 
{ 
    // The graph has N vertices. Mark all the vertices as 
    // not visited 
    bool *visited = new bool[N]; 
    for (int i = 0; i < N; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    queue<queueEntry> q; 
  
    // Mark the node 0 as visited and enqueue it. 
    visited[0] = true; 
    queueEntry s = {0, 0};  // distance of 0't vertex is also 0 
    q.push(s);  // Enqueue 0'th vertex 
  
    // Do a BFS starting from vertex at index 0 
    queueEntry qe;  // A queue entry (qe) 
    while (!q.empty()) 
    { 
        qe = q.front(); 
        int v = qe.v; // vertex no. of queue entry 
  
        // If front vertex is the destination vertex, 
        // we are done 
        if (v == N-1) 
            break; 
  
        // Otherwise dequeue the front vertex and enqueue 
        // its adjacent vertices (or cell numbers reachable 
        // through a dice throw) 
        q.pop(); 
        for (int j=v+1; j<=(v+6) && j<N; ++j) 
        { 
            // If this cell is already visited, then ignore 
            if (!visited[j]) 
            { 
                // Otherwise calculate its distance and mark it 
                // as visited 
                queueEntry a; 
                a.dist = (qe.dist + 1); 
                visited[j] = true; 
  
                // Check if there a snake or ladder at 'j' 
                // then tail of snake or top of ladder 
                // become the adjacent of 'i' 
                if (move[j] != -1) 
                    a.v = move[j]; 
                else
                    a.v = j; 
                q.push(a); 
            } 
        } 
    } 
  
    // We reach here when 'qe' has last vertex 
    // return the distance of vertex in 'qe' 
    return qe.dist; 
} 

`````
