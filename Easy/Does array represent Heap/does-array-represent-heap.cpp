//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for (int i = (n - 2) / 2; i >= 0; --i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            if ((left < n && arr[left] > arr[i]) || (right < n && arr[right] > arr[i]))
                return false;
            
            if (left < n && !checkMaxHeapProperty(arr, n, left))
                return false;
            
            if (right < n && !checkMaxHeapProperty(arr, n, right))
                return false;
        }
        return true;
    }


    bool checkMaxHeapProperty(int arr[], int n, int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && arr[left] > arr[index])
            return false;

        if (right < n && arr[right] > arr[index])
            return false;

        if (left < n && !checkMaxHeapProperty(arr, n, left))
            return false;
        
        if (right < n && !checkMaxHeapProperty(arr, n, right))
            return false;

        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends