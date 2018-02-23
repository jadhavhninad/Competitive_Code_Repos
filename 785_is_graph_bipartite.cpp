//https://leetcode.com/problems/is-graph-bipartite/description/
//Use graph coloring method(think 'chromatic number') and DFS


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int _size = graph.size();
        vector<int> nodes(_size,-1);
        
        for(int i=0; i<_size; i++){
            if(nodes[i] == -1){
                nodes[i] = 0;
            
                bool value = helper(graph,i,nodes);
                //cout << i << ", " << value << endl;
                if(!value)
                    return false;  
            }
        }
        
        return true;
        
    }
    
    bool helper(vector<vector<int>>& graph, int curr_node, vector<int>& nodes){        
        for(int j=0; j<graph[curr_node].size(); j++){
            if(nodes[graph[curr_node][j]] == -1){
                nodes[graph[curr_node][j]] = nodes[curr_node] == 0 ? 1:0;
                bool value = helper(graph,graph[curr_node][j],nodes);
                //cout << graph[curr_node][j] << ", " << value << endl;
                if(!value)
                    return false;   
            }
            else if(nodes[graph[curr_node][j]] == nodes[curr_node]){
                //cout << "found error for " << curr_node << endl;
                return false;
            }
        }
        return true;
    }
    
};

/*
TESTCASES
[[1, 3],[0, 2],[1, 3],[0, 2]]
[[1],[0]]
[[0,1][0,2,4],[1,3,4],[2,5],[1,2,5],[3,4]]
[[1,2,3], [0,2], [0,1,3], [0,2]]
[[4,3],[],[5],[0,5],[0,5][2,3,4]]
*/
