class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        int totaltime=0;
        for(int i=0;i<timeSeries.size()-1;i++){
            int timeDiff=timeSeries[i+1]-timeSeries[i];
            totaltime+=min(timeDiff, duration);
        }
        return totaltime+duration;
    }
};