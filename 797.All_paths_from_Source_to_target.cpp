//https://leetcode.com/contest/weekly-contest-75/problems/all-paths-from-source-to-target/
class Solution {

//Needs more robust code structure.

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int start=0;
        int end = graph.size();
        vector<int> startVec = graph[0];
        vector<vector<int>> res = helper(0, startVec, graph);
        vector<int>::iterator it;
        
        for(int j=0 ;j<res.size();j++){
            it = res[j].begin();
            res[j].insert ( it , 0 );
            res[j].pop_back();
        }
        return res;
    }
    
    vector<vector<int>>helper(int node, vector<int>& startVec, vector<vector<int>>& graph){
        int _size = startVec.size();
        vector<vector<int>> result;
        
        if(node == graph.size()-1){
            vector<int> temp = {graph.size()-1};
            result.push_back(temp);
        }
        else{   
            for(int i=0;i<_size;i++){
                vector<vector<int>>temp = helper(startVec[i],graph[startVec[i]],graph);
                vector<int>::iterator it;
                
                for(int j=0 ;j<temp.size();j++){
                    it = temp[j].begin();
                    temp[j].insert ( it , startVec[i] );
                    result.push_back(temp[j]);
                }

            }
        }
        return result;
    }
};