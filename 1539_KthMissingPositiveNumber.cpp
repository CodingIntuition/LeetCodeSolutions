class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {  
        //O(n)
        int missing = 0 , n = arr.size();
        for (int i = 0 ;i<n ;i++){
            missing = arr[i] - (i +1);
            if (missing >= k){
                int back = missing - k;
                int ans =  arr[i] - back -1;
                return ans;
            }
        }
        if (missing < k ){
            return arr[n-1] + (k - missing);
        }
        return 0;

        
        
        //O(log(n))
        int l = 0 , r  = arr.size();

        while (l < r){
            int m = (l+r)/2;
            if (arr[m] - (m+1) < k ) {
                l = m+1;
            }
            else {
                r  = m;
            }
        }
        return l + k;
    }
};