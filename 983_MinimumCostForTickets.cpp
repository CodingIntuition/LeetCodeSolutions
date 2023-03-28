//983_MinimumCostForTickets
//Recursion 
class Solution {
public:
    int getMinCost (vector<int>& days, vector<int>& costs, int currDayIdx ){
        int n = days.size();
        if (currDayIdx >= n ) return 0;

        int costDay = costs[0] + getMinCost(days, costs, currDayIdx + 1);

        int daysIdxAfterWeek = currDayIdx;
        while (daysIdxAfterWeek < n && days[daysIdxAfterWeek] <  days[currDayIdx] + 7 ) 
            daysIdxAfterWeek++;
        int costWeek  = costs[1] + getMinCost(days, costs, daysIdxAfterWeek );

        int daysIdxAfterMonth  = currDayIdx;
        while(daysIdxAfterMonth < n && days[daysIdxAfterMonth] < days[currDayIdx] + 30 ) 
            daysIdxAfterMonth++;
        int costMonth = costs[2] + getMinCost(days, costs, daysIdxAfterMonth);

        return min({costDay, costWeek , costMonth});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return getMinCost(days, costs, 0);
    }
};
//Top Down
class Solution {
public:
    vector<int> dp;
    int getMinCost (vector<int>& days, vector<int>& costs, int currDayIdx ){
        int n = days.size();
        if (currDayIdx >= n ) return 0;

        if (dp[currDayIdx] != -1 ) return dp[currDayIdx];

        int costDay = costs[0] + getMinCost(days, costs, currDayIdx + 1);

        int daysIdxAfterWeek = currDayIdx;
        while (daysIdxAfterWeek < n && days[daysIdxAfterWeek] <  days[currDayIdx] + 7 ) 
            daysIdxAfterWeek++;
        int costWeek  = costs[1] + getMinCost(days, costs, daysIdxAfterWeek );

        int daysIdxAfterMonth  = currDayIdx;
        while(daysIdxAfterMonth < n && days[daysIdxAfterMonth] < days[currDayIdx] + 30 ) 
            daysIdxAfterMonth++;
        int costMonth = costs[2] + getMinCost(days, costs, daysIdxAfterMonth);

        return dp[currDayIdx] = min({costDay, costWeek , costMonth});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(366,-1);
        return getMinCost(days, costs, 0);
    }
};
//Bottom Up
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        unordered_set<int> daysSet(days.begin(), days.end());
        vector<int> dp(366);

        for (int i = 1 ; i<366 ; i++) {
            dp[i] = dp[i-1];
            if (daysSet.find(i) != daysSet.end()){
                dp[i] = min({costs[0] + dp[i-1],
                             costs[1] + dp[max(0,i-7)],
                             costs[2] + dp[max(0,i-30)]});
            }
        }
        return dp[365];     
    }
};