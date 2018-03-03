/*395. Longest Substring with At Least K Repeating Characters*/
/*The interval merging approach is failing for cases like ababbc or aaabbbcbbbd. Currently cannot find a clean solution using this.*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int _size = s.size();
        unordered_map<char, vector<int>> charinfo;
        
        //count, start,end
        for(int i=0;i<_size;i++){
            if(charinfo.find(s[i]) == charinfo.end()){
                vector<int> temp;
                temp.push_back(1);
                temp.push_back(i);
                temp.push_back(i);
                charinfo[s[i]] = temp;
            }
            else{
                vector<int> temp = charinfo[s[i]];
                temp[0] += 1;
                temp[2] = i;
                //cout << temp[2] << endl;
                charinfo[s[i]] = temp;
            }
        }
        
        int start=_size+1,end=-1,maxLen=0,newstart=_size+1;
        
        for(auto itr = charinfo.begin(); itr!=charinfo.end(); itr++){            
            if(itr->second[0] >= k){
                if(itr->second[1] <= end){
                    start = start < itr->second[1] ? start : itr->second[1];
                    end = end > itr->second[2] ? end : itr->second[2];  
                }
                else{
                    maxLen = maxLen > (end-start+1) ? maxLen : (end-start+1);
                    start = itr->second[1];
                    end = itr->second[2];
                }
            }
            else{
                newstart = itr->second[2];
            }
        }
        
        cout << start << end << endl;
        return maxLen;
        
    }
};
