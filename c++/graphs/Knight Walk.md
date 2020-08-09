## [Practice Link](https://practice.geeksforgeeks.org/problems/knight-walk/0/)
Given a chess board of order N x M and source points (s1, s2) and destination points (d1, d2). The task to find minimum number of moves required by the Knight to go to the destination cell.
Note: The chess board consists of rows numbered (1 to N) and columns (1 to M).

## Input:
The first line of input contains an integer T denoting the number of testcases. Then T test cases follow. Each test case contains two lines. The first line of each testcase contains two space separated integers N and M. Then in the next line are four space separated values s1, s2 and d1, d2.

## Output:
For each testcase in a new line print the minimum number of moves required by the knight to go to the destination from the source. If no such move is possible print -1.

## Constraints:
1 <= T <= 100
1 <= N, M <= 25

## Example:
## Input:
2
4 7
2 6 2 4
7 13
2 8 3 4

## Output:
2
3

## Explanation:
Testcase 1: One possible move for Knight is from 2, 6 to 4, 5 and then to 2, 4 which is our destination.]

```cpp
// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int,int);

// Driver code to test above methods
int main() {
    // size of square board
    int t;
    cin >> t;
    while (t--) {
        int N;
        int a, b, c, d,M;
        cin >> N>>M;
        cin >> a >> b;
        cin >> c >> d;
        int knightPos[] = {a-1, b-1};
        int targetPos[] = {c-1, d-1};
        cout << minStepToReachTarget(knightPos, targetPos, N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size
int movesx[8]={-2,-2,-1,1,2,2,1,-1};
int movesy[8]={-1,1,2,2,1,-1,-2,-2};

bool valid(int di,int dj,int n,int m)
{
    if(di<0||dj<0||di>=n||dj>=m) return false;
    
    return true;
}

int minStepToReachTarget(int knightPos[], int targetPos[], int n,int m) {
bool visited[1001][1001]={false};
    queue<int>xpos,ypos;xpos.push(knightPos[0]);ypos.push(knightPos[1]);
    int i,j;
    
    int steps=-1;
    while(!xpos.empty()){
    steps++;
    int size=xpos.size();
        for(int k=0;k<size;k++)
        {
            i=xpos.front();xpos.pop();
            j=ypos.front();ypos.pop();
            visited[i][j]=true;
            if(i==targetPos[0]&&j==targetPos[1])
            {
                //cout<<i<<' '<<j<<' '<<targetPos[0]<<' '<<targetPos[1]<<endl; 
                return steps;
            }
            for(int l=0;l<8;l++)
            {
                int di=i+movesx[l];
                int dj=j+movesy[l];
                if(valid(di,dj,n,m)&&!visited[di][dj])
                {
                    xpos.push(di);
                    ypos.push(dj);
                    visited[di][dj]=true;
                }
            }
        }
    }
return -1;
}


 `````
 
