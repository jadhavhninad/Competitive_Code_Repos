//https://leetcode.com/contest/weekly-contest-67/problems/partition-labels/
//763. Partition Labels
//Use interval merging to solve the problem.

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        int _size = S.length();
        unordered_map<char,pair<int,int>> charIndex={};
        vector<int> res={};
        
        // Get first and last index of each char in the string
        for(int i=0;i<_size;i++){
            if(charIndex.find(S[i]) != charIndex.end()){
                charIndex[S[i]].second = i;
            }
            else{
                charIndex[S[i]]=make_pair(i,i);
            }
            //cout << S[i] << ","<< charIndex[S[i]].first << "," << charIndex[S[i]].second<<endl;
        }
        
        priority_queue<pair<int,int>,  vector<pair<int,int>>, greater<pair<int,int>>> charQ={};
        for(auto itr = charIndex.begin(); itr!=charIndex.end(); itr++){
            charQ.push(itr->second);
        }
        
        
        int start=-1,end = -1;
        
        //Merge the intervals;
        while(!charQ.empty()){
            pair<int,int> temp = charQ.top();
            //cout << temp.first << "," << temp.second << endl;
            
            if(temp.first > end){
                if(start != -1)
                    res.push_back(end-start+1);
                //cout << "pushed :" << start << "," << end << endl;
                //cout << "-------" << endl;
                start = temp.first;
                end = temp.second;
            }
            else if(temp.first < end){
                end = end > temp.second ? end : temp.second;
            }
            
            charQ.pop();
        }
        
        if(start!= -1)
            res.push_back(end-start+1);
        
        return res;
    }
};
