class Solution {
public:
    bool isSmallestDivisor(vector<int>& nums, int threshold, int mid){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % mid == 0){
                int div = nums[i] / mid;
                sum += div;
            }
            else{
                int div = nums[i] / mid;
                sum += div + 1;               
            }
        }
        if(sum <= threshold){
            return true;
        }
        else{
            return false;
        }
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = 1e6;
        int ans;

        while(start <= end){
            int mid = start + (end-start) / 2;
            if(isSmallestDivisor(nums,threshold,mid) ){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};