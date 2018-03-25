class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) {
            //cout << c << endl;
            map[c]++;
            //cout << map[c] << endl;
        }
    
    
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        
        while(end<s.size()){
            if(map[s[end++]]-- > 0) counter--; //in t
           // cout << begin << "," << end << endl;
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                //cout << map[s[begin]] << endl;
                if(map[s[begin++]]++ == 0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};