class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end  = arr.size() - 1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid] - mid > k){
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return k+start;
    }
};