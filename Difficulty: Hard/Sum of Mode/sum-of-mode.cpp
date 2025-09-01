class Solution {
    void update(int x, int lx, int rx, int i, int v, vector<int> &seg) {
        if(rx - lx == 1) {
            seg[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) update(2 * x + 1, lx, m, i, v, seg);
        else update(2 * x + 2, m, rx, i, v, seg);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    int find(int x, int lx, int rx, vector<int> &seg) {
        if(rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        if(seg[2 * x + 1] >= seg[2 * x + 2]) return find(2 * x + 1, lx, m, seg);
        return find(2 * x + 2, m, rx, seg);
    }
  public:
    int sumOfModes(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), m = 0, s = 1, ans = 0;
        for(int i = 0; i < n; i++) {
            m = max(m, arr[i]);
        }
        for(; s <= m; s *= 2);
        vector<int> seg(2 * s, 0);
        for(int i = 0, j = 0; j < n; j++) {
            update(0, 0, s, arr[j], 1, seg);
            if(j - i + 1 == k) {
                ans += find(0, 0, s, seg);
                update(0, 0, s, arr[i++], -1, seg);
            }
        }
        return ans;
    }
};