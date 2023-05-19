class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        if(nums.size() == 0){
            return 0;
        }

        int longest = 1;

        for(auto it: s){
            if(s.find(it-1) == s.end()){ 
                int count  = 1;
                int x = it;

                while(s.find(x+1) != s.end()){  
                    x = x+1;
                    count = count + 1;
                   
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};