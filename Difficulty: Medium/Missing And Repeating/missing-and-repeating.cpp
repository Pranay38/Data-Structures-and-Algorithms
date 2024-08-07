//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> res(2, -1);
        for (int i = 0; i < n; i++) {
            if (arr[abs(arr[i]) - 1] > 0) {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            } 
            else {
                res[0] = abs(arr[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                res[1] = i + 1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends