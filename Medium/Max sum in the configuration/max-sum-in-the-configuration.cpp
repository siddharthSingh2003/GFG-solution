//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum1=0, sum2=0;
        long long N=n;
        for(long long i=0;i<N;i++){
            sum1+=a[i];// sum up all the elements for a single instance
            sum2+=a[i]*i;// sum up all the elements as the number of instance == i;
        }
        long long ans=sum2;
        for(long long i=1;i<N;i++){
            sum2=sum2-(sum1-a[i-1])+(a[i-1]*(N-1));// removing all single instances except the 0th elemnet, and then take the 0th element and put it at the last making (n-1) instances
            ans=max(ans,sum2);//then simply get the maximun answer
        }
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends