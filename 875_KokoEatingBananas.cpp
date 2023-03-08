class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //O(N * MaxP))
        int n = piles.size();
        int k = 0;
        int currHours  =0 ;
        do{
            k++;
            currHours  =0;
            for (int &p:piles){
                currHours+= (p + k - 1)/k;
            }
            
        }while (currHours > h );
        return k ;

        //O(Nlog(MaxP))
        int left  = 1, right = *max_element(piles.begin(), piles.end());
        while(left<right){
            int mid = (left+right)/2;
            int currHours = 0;
            for (int &p:piles){
                currHours+= (p+mid-1)/mid;
            }
            if (currHours >h){
                left  = mid+1;
            }
            else{
                right = mid;
            }

        }
        return left;
    }
};