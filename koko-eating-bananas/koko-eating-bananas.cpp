class Solution {
public:
    long long int totalHours(vector<int>& piles, int k){
        long long int hours = 0;
        for(int pile: piles){
            hours += ceil(pile*1.0/k);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = 1000000000;

        while(start <= end){
            int k = start + (end - start) / 2;

            if(totalHours(piles,k) <= h){
                end = k - 1;
            }
            else{
                start = k+1;
            }
        }
        return start;
    }
};