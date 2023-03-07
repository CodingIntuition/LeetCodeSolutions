class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        //O(n.log(min*totalTrips))
        long long left = 1, right = 1LL * *min_element(time.begin(), time.end()) * totalTrips;
        long long currTrips,mid;
        while (left <= right) {
            mid = (left + right)/2;
            currTrips =0 ;
            for (int &t : time ){
                currTrips += (mid/t);
            }
            if (currTrips >= totalTrips){
                right =  mid -1;
            }
            else {
                left  = mid +1;
            }
        }
        return left;

        //O(n*min*totalTrip)
        int currTime  =0; 
        int currTrips =0;
        while (currTrips<totalTrips){
            currTrips = 0;
            currTime++;
            for (int &t : time)
            {
                currTrips += (currTime/t);
            }
        }
        return currTime;
    }
};