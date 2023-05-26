//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
        int start = 0;
        int end = n-1;

        while(start<end){

            if(arr[start] < arr[end]){
            return start;
        }
            int mid = start + (end-start) /2;

            if(arr[mid] >= arr[start]){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }

        return start;	    
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends