/*
230. Kth Smallest Element in a BST
*/

/*
Traverse to the smallest element and reach the left-most element. From there start to backtrack and keep count of the smallest elements seen so far.
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
    int kthSmallest(TreeNode* root, int k) {
        
        int count=0;
        int val = helperfunc(root,k,&count);
        return val;
    }
    
    int helperfunc(TreeNode* node, int k, int* count){
        
        if(node->left == NULL && node->right==NULL){
            *count+=1;
            //cout << "leaf found=  " << node->val << endl;
            //cout << "count = " << *count << endl;
        
            if(*count == k){
                //cout << "found kth smallest - " << node->val << endl;
                return node->val;
            }
            else
                return -1;
        }
        
        if(node->left){
            //cout << "count before visiting left = " << *count << "for node "<< node->val << endl;
            int val_left = helperfunc(node->left,k,count);
            //cout << "count after visiting left = " << *count << "for node "<< node->val << endl;
            if(*count == k)
                return val_left;
        }
        
        *count+=1;
        if(*count == k)
            return node->val;
        
        if(node->right){
            int val_right=helperfunc(node->right,k,count);
            if(*count == k)
                return val_right;
        }
        
        //if the neither the current node or its left child or its right child is the kth smallest element, return -1.
       // cout << "count = " << *count << endl;
        return -1;
    }
};

