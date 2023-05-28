class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = 1000000000;

        while(start <= end){
            int k = start + (end - start) / 2;

            long long hours = 0;
            for(int pile: piles){
                hours += ceil(pile/(double)k);
            }
            if(hours <= h){
                end = k - 1;
            }
            else{
                start = k+1;
            }
        }
        return start;
    }
};