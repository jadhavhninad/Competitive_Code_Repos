//758. Bold word in string
//https://leetcode.com/contest/weekly-contest-66/problems/bold-words-in-string/
//Discussion : https://discuss.leetcode.com/topic/116323/simple-fast-c-solution-by-actually-converting-chars-to-bold


class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        
           //unordered_map<int,int>start_end;
        map<int,int>start_end;
        int _size = words.size();
        string str1="<b>";
        string str2="</b>";
        string ret = S;
        locale loc;
        
        for(int i=0;i<_size;i++){
            int _len = words[i].length();
            //cout << "len = " << _len << endl;
            size_t pos = S.find(words[i], 0);
            //cout << "pos = " << pos << "pos + _len = " << int(pos) + _len << endl;
            
            while(pos != string::npos){    
                for(int z=pos; z<int(pos)+_len;z++){
                    ret[z] = toupper(S[z],loc);
                    //S[z] = c;
                }
                pos = S.find(words[i],pos+1);
            }
        }
        
        //cout << ret << endl;
         
        for(int j=0;j<ret.length();j++){
            if(islower(ret[j],loc))
                continue;
            
            ret.insert(j,str1);
            j=j+3;
            while(j<ret.length() && isupper(ret[j])) {
                char c = tolower(ret[j],loc);
                ret[j] = c;
                j++;
            }
            
            ret.insert(j,str2);
            j=j+4;
            
            //cout << "j=" << j << endl;
                
        }
            
        return ret;
    }
};

