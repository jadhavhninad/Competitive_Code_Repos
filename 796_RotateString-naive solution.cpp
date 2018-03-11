//796. Rotate String - naive solution

class Solution {
public:
    bool rotateString(string A, string B) {
        
        int _size = A.length();
        bool ret = false;
        
        for(int i=0;i<_size;i++){
            A+=A[0];
            A.erase(0,1);
            //cout << A << "," << B << endl;
            if(A == B){
                ret = true;
                break;
            }
        }
        return ret;
    }
};