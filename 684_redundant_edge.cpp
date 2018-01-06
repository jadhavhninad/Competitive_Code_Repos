//https://leetcode.com/problems/redundant-connection/description/

/*Whenever verifying a new edge, recursively check if there is a common parent for the nodes.
Initially each node is its own parent
*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        unordered_map<int,int>nodeParent;
        vector<vector<int>>red;
        int _size = edges.size();
        
        for(int i=0;i<_size;i++)
            nodeParent[i]=i;
        
        for(int i=0 ;i<_size ;i++){
           //cout << edges[i][0] << ","<< edges[i][1] << endl;
           if(fp(edges[i][0],nodeParent) == fp(edges[i][1],nodeParent)){
                    red.push_back(edges[i]);
                }
           else{
                nodeParent[fp(edges[i][1],nodeParent)] = edges[i][0];
            }
        }
        
        return red.back();
    
    }
    
    int fp(int num,unordered_map<int,int>& nodeParent){
        if(num != nodeParent[num])
            nodeParent[num] = fp(nodeParent[num],nodeParent);
        return nodeParent[num];
    }
};
