//662. Maximum Width of Binary Tree : https://leetcode.com/problems/maximum-width-of-binary-tree/description/
//Fails for very large input value - memory limit exceeds

/*Use BFS approach. Add children to the queue and keep track the start and end point of the queue for each level.
For a middle null node, add two null nodes in next level.
start when the leftmost non null node is detected.Traverse till end. Then backtrack till rightmost non null node is detected. the diff is the width.
If the width remains 0 then return (it means that all children node are null so no need to explore next level)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<TreeNode*>q;
        
        if(root==NULL)
            return 0;
        
        q.push_back(root);
        //cout<<"-------"<<endl;
        return helper(q,0,0);
    }
    
    int helper(vector<TreeNode*>& queue,int start,int end){
        int max=0;
        for(int i=start; i<=end; i++){
            if(queue[i]->val == -10){
                //if max>0 it means that leftmost node has been detected and then start incrementing the count.
                if(max>0)
                    max++;
                //for every null node detected, add two null nodes in the next level
                queue.push_back(new TreeNode(-10));
                queue.push_back(new TreeNode(-10));
                continue;
            }
            else{
                //we assume a node with value -1 as null.
                max++;
                if(queue[i]->left){
                    queue.push_back(queue[i]->left);
                }
                else
                    queue.push_back(new TreeNode(-10));

                if(queue[i]->right){
                    queue.push_back(queue[i]->right);
                }
                else
                    queue.push_back(new TreeNode(-10));
            }
        }
        //cout << max << endl;
        if(max==0)
            return 0;
        
        //backtrack and reduce width till the rightmost node is detected.
        for(int j=end;j>=start;j--){
            if(queue[j]->val == -10)
                max--;
            else
                break;             
        }
        
        int temp = helper(queue,end+1,queue.size()-1);
        max = max > temp ? max : temp;
        
        return max;
    }
};

/*TestCases
[1,3,2,5,3,null,9]
[1,2,3,4,null,null,5,6,null,null,7]
[1,3,null,5,3]
[1,3,2,5,null]
[1]
[1,2]
[1,null,3]
[1,2,3,null,null,4]
[1,2,3,null,4,5]
[1,2,3,null,4,null,5,6,7,8,9]
[1,2,3,4,null,5,6,null,7,8,9,10,11,12,null,null,null,13,null,null,null,null,14]
*/
