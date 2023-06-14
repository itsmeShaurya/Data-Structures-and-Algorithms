class Solution {
public:
    void findComibination(int ind, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &ds){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        //pickup the element
        if(target >= arr[ind]){
            ds.push_back(arr[ind]);
            findComibination(ind, target-arr[ind], arr,ans,ds);
            ds.pop_back();
        }

        findComibination(ind+1, target, arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findComibination(0,target,candidates,ans,ds);
        return ans;
    }
};