//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	     int cnt = 0 ;
        vector<int>p1,p2;
        for(auto i:mat1){
            for (int j:i){
                p1.push_back(j);
            }
        }
        for(auto i:mat2){
            for (int j:i){
                p2.push_back(j);
            }
        }
        for(int i:p1){
            int l = 0 , h = n*n -1 , mid ;
            while(l<=h){
                mid = l + (h-l)/2;
                if(p2[mid]==x-i){cnt++;break;}
                else if(p2[mid]>x-i)h= mid-1;
                else l = mid +1 ;
            }
        }
        return cnt ;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends