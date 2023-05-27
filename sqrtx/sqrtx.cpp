class Solution {
public:
    int mySqrt(int x) {

        int start = 1;
        int end = x;
        long long int ans = 0;
        
        while(start <= end){
            long long int mid = start + (end-start)/2;
            long long int square = mid*mid;
            
            if(square == x){
                return mid;
            }
            else if(square > x){
                end = mid-1;
            }
            else{
                ans = mid;
                start = mid+1;
            }
        }
        return ans;
    }
};