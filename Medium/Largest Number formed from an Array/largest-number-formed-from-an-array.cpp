//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    struct Compare {
        bool operator()(const string& a, const string& b) const {
            return (a + b) < (b + a);
        }
    };
    
    string printLargest(int n, vector<string> &arr) {
        priority_queue<string, vector<string>, Compare> pq;
        string str = "";

        for(auto it : arr){
            pq.push(it);
        }

        while(!pq.empty()){
            str += pq.top();
            pq.pop();
        }

        return str;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends