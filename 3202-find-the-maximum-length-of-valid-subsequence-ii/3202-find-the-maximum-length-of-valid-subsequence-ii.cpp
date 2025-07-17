
// 55ms
    int maximumLength(vector<int>& n, int k) {
        int r = 0;
        for (int v = 0; v < k; ++v) for (int l[1000]={}; int x: n) 
            r = max(r, l[x%k] = max(l[x%k], 1 + l[(v - x%k + k) % k]));
        return r;
    }
