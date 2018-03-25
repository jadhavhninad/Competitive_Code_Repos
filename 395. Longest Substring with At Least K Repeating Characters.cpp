class Solution {
public:
    int longestSubstring(string s, int k) {
        
        string T="";
        vector<int> map(128,0);
        
        if(s.size() == 1)
            return s.size() < k ? 0 : 1;
        
        for(auto c:s){
            map[c]++;
        }
        
        //Generate the required T String.
        for(int itr=0; itr<map.size(); itr++){
            if(map[itr]>=k){ 
                T+= char(itr);
            }
            else{
                map[itr] = -1;
            }
        }
        
        //Get the substring 
        vector<int> Tcount(128,0);
        int counter = T.size()*k;
        int start=0, end, d=0; 
        
        for(end=0; end<=s.size(); end++){
            
            //cout << map[s[end]] << endl;
            if(map[s[end]] == -1 || end == s.size()){
                //cout << "found no char" << endl;
                
                //cout << end << "," << start << endl;
                //check the substring to see if all characters appear atleast k times.
                int head = start;
                //cout << "end = " << end << endl;
                while(head < end){
                    if(Tcount[s[head]] < k) {
                        start=head+1;
                    }
                                    
                    cout << start << ","  << head << endl;
                    head++;
                }
                cout << "d = " << d << endl;
                //cout << start << "," << end << endl;
                if((end - start) > d && end!=start+1) d = end - start;
              
               
                //Also reset the occurance count.
                int _sizeT = T.size();
                //T="";
                for(int itr=0; itr<_sizeT; itr++){
                    //if(map[T[itr]] < k) map[T[itr]] = -1;
                    //else
                        //T+=T[itr];
                    
                    Tcount[T[itr]]=0;
                }
                
                
            }
            else if(map[s[end]]-- > 0 ){
               // cout << "found char" << endl;
                Tcount[s[end]]+=1;
                //counter--;  
            }
            //cout << "counter = " << counter << endl;
            //cout << d << endl;
        }
        
        cout << T << endl;
        return d >= k ? d : 0;
    }
   
};

/*
"ababbbcghbaabbbbb"
3
"ababbcbbbvbaabbab"
4
"bbaaacbd"
3
"ababbcbbbvbaabbabbbb"
4
"ababbcbbbvbaabba"
4
"a"
1
"ab"
2
"ab"
1
"a"
2
"ababacb"
3
"baaabcb"
3
"aaabbbacccbdc"
4
*/