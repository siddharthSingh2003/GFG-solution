//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string fin = "";
        int opened = 0;
        for(auto i : s){
            if (i == '('){
                opened++;
                if (opened > 1){
                    fin.push_back(i);
                }
            }
            else{
                opened--;
                if (opened > 0){
                    fin.push_back(i);
                }
            }
        }
        return fin;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends