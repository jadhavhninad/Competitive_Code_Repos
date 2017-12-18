/*
378. Kth Smallest Element in a Sorted Matrix
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue< pair< int, pair<int,int> > , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >val_heap;
        
        int _size = matrix[0].size();
        
        //Push all elements of first row in the heap
        for(int i=0;i<_size;i++){   
            val_heap.push(make_pair(matrix[0][i],make_pair(0,i)));
            //cout << val_heap.top().first << endl;
        }
        
        //Pop the top and insert matrixi element of the same column in the next row.
        for(int t=0;t<k-1;t++){
            //cout << val_heap.top().first << endl;
            pair<int,int> num = val_heap.top().second;
            val_heap.pop();
            
            if(num.first == _size -1)
                continue;
            else
                val_heap.push(make_pair(matrix[num.first+1][num.second],make_pair(num.first + 1 , num.second)));
        }
        
        
        //cout << "top is" << val_heap.top().first << endl;
        return val_heap.top().first;
    }
};
