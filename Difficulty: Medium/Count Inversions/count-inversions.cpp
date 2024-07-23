//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  long long int merse(long long arr[], long long start, long long mid, long long end) {
        long long left = start, right = mid + 1;
        long long int cnt = 0;
        vector<long long> temp;
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                cnt += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= end) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = start; i <= end; i++) {
            arr[i] = temp[i - start];
        }
        return cnt;
    }


    long long merseSort(long long arr[], long long start, long long end) {
        long long cnt = 0;
        if (start >= end) return cnt;
        long long mid = start + (end - start) / 2;
        cnt += merseSort(arr, start, mid);
        cnt += merseSort(arr, mid + 1, end);
        cnt += merse(arr, start, mid, end);
        return cnt;

    }

    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        return merseSort(arr, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends