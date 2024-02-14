//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        unordered_set<int>s;
        for(int i=0;i<N;i++)
        {
            
            int key=frogs[i];
            int key1=frogs[i];
            if(s.find(key)==s.end()){
            while(key<=leaves)
            {
                s.insert(key);
                key=key+key1;
            }
            }
        }
        return (leaves-s.size());
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends