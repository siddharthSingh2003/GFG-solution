//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
        vector<int> count(maxx + 2, 0);

    // Use the difference array technique to mark the range increments and decrements
    // For each range [l[i], r[i]], increment count[l[i]] and decrement count[r[i] + 1]
    for(int i = 0; i < n; i++) {
        int left = l[i];
        int right = r[i];
        count[left]++;
        count[right + 1]--;
    }

    // Convert the difference array to a prefix sum array to get the actual counts
    // This step computes the number of times each index appears in the ranges
    int current = 0;
    for(int i = 0; i < count.size(); i++) {
        current += count[i];
        count[i] = current;
    }

    // Find the integer with the maximum count
    // Initialize variables to track the maximum count and the corresponding integer
    int maxCount = 0, result = 0;
    // Iterate through the count array to find the index with the highest count
    for(int i = 1; i <= maxx; i++) {
        if(count[i] > maxCount) {
            maxCount = count[i];
            result = i;
        }
    }
    
    // Return the integer with the maximum count
    return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends