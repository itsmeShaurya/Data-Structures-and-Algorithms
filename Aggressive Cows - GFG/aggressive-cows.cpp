//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool canPlaceCows(vector<int> &stalls, int k, int n, int mid){
        int cowsCoordinate = stalls[0];
        int count  = 1;
        
        for(int i=1; i<n; i++){
            if(stalls[i] - cowsCoordinate >= mid){
                count++;
                cowsCoordinate = stalls[i];
            }
            
            if(count == k){
                return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        
        int start = 1;
        int end = stalls[n-1] - stalls[0];
        int res;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            
            if(canPlaceCows(stalls,k,n,mid)){
                res = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends