///https://leetcode.com/problems/distribute-coins-in-binary-tree/submissions/
/*
979. Distribute Coins in Binary Tree
Medium

1529

62

Add to List

Share
Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.*/
```
Example 1:

Input: [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Example 2:
Input: [0,3,0]

Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves].  Then, we move one coin from the root of the tree to the right child.

Example 3:
Input: [1,0,2]
Output: 2
Example 4:



Input: [1,0,0,null,3]
Output: 4
 
Note:
1<= N <= 100
0 <= node.val <= N
```



//Regular Solution
````
class Solution {
public:
  
   int f(TreeNode* root,TreeNode* parent){
    int moves=0;
     if(!root) return moves;
     
    moves+=f(root->left,root);
    moves+=f(root->right,root);
    
     if(root->val==1) return moves;
     else if(root->val==0)
     {  
       moves++;
       root->val=1;
       parent->val-=1;
     }
     else if(root->val>1)
     {
       int temp=root->val;
       moves=moves+temp-1;
       parent->val=parent->val+temp-1;
       root->val=1;
     }
     else if(root->val<0)
     {
       int temp=root->val;
       parent->val=parent->val+temp-1;
       root->val=1;
       moves=moves+abs(temp)+1;
     }
     return moves;
 }
 
 int distributeCoins(TreeNode* root) {
      if(!root) return 0;
        int moves=f(root,NULL);
        return moves;   
 }
};
````



//Solution Using Class data Member
```````
class Solution {
    int moves=0;
public:
  
   void f(TreeNode* root,TreeNode* parent){
    if(!root) return;
     
    f(root->left,root);
    f(root->right,root);
    
     if(root->val==1) return;
     if(root->val==0)
     {  
       moves++;
       root->val=1;
       parent->val-=1;
       return;
     }
     if(root->val>1)
     {
       int temp=root->val;
       moves=moves+temp-1;
       parent->val=parent->val+temp-1;
       root->val=1;
       return;
     }
     if(root->val<0)
     {
       int temp=root->val;
       parent->val=parent->val+temp-1;
       root->val=1;
       moves=moves+abs(temp)+1;
     }
 }
 
 int distributeCoins(TreeNode* root) {
      if(!root) return 0;
        moves=0;
        f(root,NULL);
        return moves;   
 }
};
`````
