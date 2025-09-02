class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n < 2) return -1;

        sort(arr.begin(), arr.end());

        int k = n - 1;
        while (k > 0 && arr[k] == arr[k - 1]) {
            k--;
        }

        if (k <= 0) return -1;
        return arr[k - 1];
    }
};