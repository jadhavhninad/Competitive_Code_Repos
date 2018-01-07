//760.Anagram Mapping
//https://leetcode.com/contest/weekly-contest-66/problems/find-anagram-mappings/
//Discuss : https://discuss.leetcode.com/topic/116319/c-10ms-solution-using-hashmap-and-simple-solution-using-sequential-search

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        
        int _size = B.size();
        vector<int> pos;
        unordered_map<int,vector<int>>num_loc;
        
        //Insert the indexex in reverse order so that while searching the last pos in the map for an element is its first occurance.
        for(int i=_size-1;i>=0;i--){
            num_loc[B[i]].push_back(i);
        }
        
        for(int i=0;i<_size;i++){
            pos.push_back(num_loc[A[i]].back());
            num_loc[A[i]].pop_back();
        }
        
        return pos;
        
    }
    
    vector<int> anagramMappingsUsingSequentialSearch(vector<int>& A, vector<int>& B) {
        
        int _size = B.size();
        vector<int> pos;
        
        for(int i=0;i<_size;i++){
            int loc = find(B.begin(),B.end(),A[i]) - B.begin();
            pos.push_back(loc);
            B[loc] = -1;
        }
        
        return pos;
        
    }
};
