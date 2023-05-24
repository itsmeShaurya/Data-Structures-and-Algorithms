//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
    int binarySearch(int arr[], int n, int x, bool firstIndex){
        int start = 0;
        int end = n-1;
        int ans = -1;;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == x){
                ans = mid;
                if(firstIndex){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else if(x > arr[mid]){
                start = mid+1;
            }
            else{
                end  = mid-1;
            }
        }
        return ans;
    }	
    
    
	int count(int arr[], int n, int x) {
	    // code here
	    vector<int>ans(2,-1);
	    ans[0] = binarySearch(arr,n,x,true);
	    ans[1] = binarySearch(arr,n,x,false);
	    
	    int result;
	    if(ans[0] == -1 || ans[1] == -1){
	        result = 0;
	    }
	    else{
	        result  = ans[1] - ans[0] + 1;
	    }
	    return result;
	}
};







//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends