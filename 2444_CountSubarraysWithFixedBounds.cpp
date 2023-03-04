class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        //O(n)
        int n = nums.size();
        long long ans = 0,minIdx = -1 , maxIdx = -1 , badIdx = -1;
        for (int i=0 ;i<n ;i++ ){
            if (nums[i] == minK) minIdx = i;
            if (nums[i] == maxK) maxIdx = i;
            if (nums[i]<minK || nums[i]>maxK )  badIdx = i;

            ans += max(0LL , min(minIdx,maxIdx) - badIdx );
        }
        
        return ans;
        

        //O(n^2)
        int n = nums.size();
        long long ans = 0;
        for (int i = 0 ; i<n ;i++) {
            bool isMin = false ,isMax = false;
            for (int j = i ; j<n; j++ ){
                if (nums[j]== minK){
                    isMin = true;
                }
                if (nums[j] == maxK){
                    isMax = true;
                }
                if (nums[j]<minK ||  nums[j]>maxK ){
                    break;
                }
                else if (isMin && isMax) {
                    ans++;
                }
            }
        }   
        return ans;
    }
};