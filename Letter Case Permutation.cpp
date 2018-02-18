//https://leetcode.com/problems/letter-case-permutation/description/
//Use backtracking to generate the list

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        
        int _size = S.length();
        vector<string>ret;
        if(_size == 0){
            ret.push_back("");
            return ret;
        }
        helper(S,ret);
        sort(ret.rbegin(),ret.rend());
        return listS;
    }
    
    void helper(string S, vector<string> &listS){
        char ch,val;
        //cout << S[0]-'0' << endl;
        if(S.length() == 1){    
            listS.push_back(S);
            if((S[0] - '0') > 9){
                
                if((S[0] - '0') > 47)
                    ch = char(toupper(S[0]));
                else
                    ch = char(tolower(S[0]));
                
                string tempS = "" ;
                tempS += ch;
                listS.push_back(tempS);
            }
        }
        else{
            helper(S.substr(1,S.length()-1),listS);   
            int curr_size = listS.size();
            for(int j=0; j<curr_size; j++){
                string orignal = listS[j];
                listS[j] = S[0] + orignal;

                if((S[0] - '0')>9){
                    if((S[0] - '0') > 48)
                        val = char(toupper(S[0]));
                    else
                        val = char(tolower(S[0]));
                    
                    string temp="";
                    temp = val + orignal;
                    //cout << temp << endl;
                    listS.push_back(temp);
                }
            }
        }
    }
};
