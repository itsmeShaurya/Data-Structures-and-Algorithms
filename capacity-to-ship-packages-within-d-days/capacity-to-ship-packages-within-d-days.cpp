class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid){
        int count = 1; 
        int sum = 0;

        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            if(sum > mid){
                count++;
                sum = weights[i];
            }
        }
        if(count <= days){
            return true;
        }
        else{
            return false;
        }
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity = 0;
        for(int i=0; i<weights.size(); i++){
            maxCapacity += weights[i];
        }

        int start = *max_element(weights.begin(), weights.end());
        int end = maxCapacity;
        int ans;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(isPossible(weights, days, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};