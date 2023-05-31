class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid){
        int sum = 0;
        int count  = 1;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > mid){
                count ++;
                sum = nums[i];
            }
        }
        return (count <= k);
    }

    int splitArray(vector<int>& nums, int k) {
        int maxSum = 0;
        for(int i=0; i<nums.size(); i++){
            maxSum += nums[i];
        }

        int start = *max_element(nums.begin(), nums.end());
        int end = maxSum;
        int ans;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(isPossible(nums,k,mid)){
                ans = mid;
                end  = mid-1;
            }
            else{
                start = mid +1;
            }
        }
        return ans;
    }
};