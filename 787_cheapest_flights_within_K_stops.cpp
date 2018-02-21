//787. Cheapest Flights Within K Stops
//https://leetcode.com/contest/weekly-contest-72/problems/cheapest-flights-within-k-stops/


//Using dynamic programming

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        const int INF = 1e9;
        vector<vector<int>> ans(n, vector<int>(K+1));
        
	//Assign infinite distance
	for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= K; j++)
            {
                //cout << ans[i][j] << endl;
                ans[i][j] = INF;
            }
        }
        
        //For given flights, update the edges with direct path from source to destination
        ans[src][0] = 0;
        for(const vector<int>& f : flights){
            if(f[0] == src)
                ans[f[1]][0] = f[2];
        }
        
	//For each no. of stop, find the smallest cost for all the nodes.
        for(int i = 1; i <= K; i++)
        {
            cout << "K is " << K << endl;
            for(int j = 0; j < n; j++)
                ans[j][i] = ans[j][i-1];
            for(const vector<int>& f: flights)
            {
                //Since its upto 'K' stops we need to keep the lowest cost for 0..K
                ans[f[1]][i] = min(ans[f[1]][i], ans[f[0]][i-1] + f[2]);
            }
        }
        
        if(ans[dst][K] == INF) return -1;
        return ans[dst][K];
    }
};
