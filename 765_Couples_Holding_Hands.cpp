//https://leetcode.com/contest/weekly-contest-67/problems/couples-holding-hands/
//765. Couples Holding Hands
//Use priority queue

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        int res=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > cp={};
        int _size = row.size();
        
        //Get all the pairs that need swapping and place into priority queue.
        for(int i=0; i< _size-1; i+=2){
            if(row[i]%2 == 0 && row[i+1] == row[i]+1){
                    continue;
            }
            else if(row[i]%2 != 0 && row[i+1] == row[i]-1)
                continue;
            else{
                //cp.[row[i]] = row[i+1];
                int a = min(row[i+1], row[i]);
                int b = max(row[i+1], row[i]);
                cp.push(make_pair(a,b));
                
                /*
                if(row[i] > row[i+1]){
                    cp.push(make_pair(row[i+1],row[i]));
                    //cout << row[i+1] << "," << row[i] << endl;
                }
                else{
                    cp.push(make_pair(row[i],row[i+1]));
                    //cout << row[i] << "," << row[i+1] << endl;
                }
                */
            }
        }
        
        //cout << "size = " << cp.size() << endl;
        
        while(!cp.empty()){
            pair<int,int> m_one = cp.top();
            cp.pop();
            //cout << "m_one = " << m_one.first << m_one.second << endl;
            
            pair<int,int> m_two = cp.top();
            cp.pop();
            //cout << "m_two = " << m_two.first << m_two.second << endl;
            
            res+=1;
            
            if(m_one.second%2==0 && m_two.second == m_one.second + 1){
                    continue;
            }
            else if(m_one.second%2!=0 && m_two.second == m_one.second - 1)
                continue;
            else{
                int a = min(m_one.second, m_two.second);
                int b = max(m_one.second, m_two.second);
                cp.push(make_pair(a,b));
                
                /*
                if(m_one.second > m_two.second)
                    cp.push(make_pair(m_two.second,m_one.second));
                else
                    cp.push(make_pair(m_one.second,m_two.second));
                */
            }
            
            //cout << cp.size() << endl;
        }
        //cout << "----" << endl;
        return res;
    }
};

/*Test
[3,2,1,5,4,6,7,0]
[3, 2, 0, 1]
[1,8,3,4,9,5,0,2,6,7]
[1,4,0,5,8,7,6,3,2,9]
*/
