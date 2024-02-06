//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	bool check_elements(int arr[], int n, int A, int B)
	{
		// Your code goes here
		bool visited[B - A + 1] = {false}; // Initialize visited arr
        
        // Mark elements within the range as visited
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= A && arr[i] <= B) {
                visited[arr[i] - A] = true;
            }
        }
        
        // Check if all elements in the range have been visited
        for (int i = 0; i < B - A + 1; ++i) {
            if (!visited[i]) {
                return false;
            }
        }
        
        return true;
	}


		 

};
	

//{ Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,A,B;
		cin>>n>>A>>B;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];

        

        Solution ob;
        if (ob.check_elements(a, n, A, B))
			cout << "Yes";
		else
			cout << "No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}







// } Driver Code Ends