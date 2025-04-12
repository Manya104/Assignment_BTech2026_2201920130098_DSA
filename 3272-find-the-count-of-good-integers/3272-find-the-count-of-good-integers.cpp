class Solution {
public:
    long long pr[11] = {0};
    long long fr[11] = {0};
    long long ans;
    set<long long> s;

    void recur(vector<int> &arr, long long num, int idx, int n, int lim, int k) {
        if (idx == lim) {
            if (num % k) return;

            long long temp = 0;
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < arr[i]; j++) {
                    temp = temp * 10 + i;
                }
            }
            if (s.find(temp) != s.end()) return;
            s.insert(temp);

            int tc = 0, zc = 0;
            long long val = 1;

            for(int i = 1; i < 10; i++) {
                tc += arr[i];
            }
            zc = arr[0];

            for(int i = 0; i < n; i++) {
                val = val * tc;
                if (i == 0) {
                    tc = tc + zc;
                }
                --tc;
            }
            // cout<<num<<"\n";
            for(int i = 0; i < 10; i++) {
                // cout<<arr[i]<<" ";
                val = val / (fr[arr[i]]);
            }
            // cout<<val<<"\n";
            ans += val;
            return;
        }

        long long st = 0, v, vv;
        if (idx == 0) {
            st++;
        }
        for(int i = st; i < 10; i++) {
            
            if (n == (2 * idx + 1)) {
                v = i * pr[idx];
                vv = 1;
            }
            else {
                v = (i * pr[n - 1 - idx]) + (i * pr[idx]);
                vv = 2;
            }
            arr[i] += vv;
            num = num + v;
            recur(arr, num, idx + 1, n, lim, k);
            num = num - v;
            arr[i] -= vv;
        }
    }

    long long countGoodIntegers(int n, int k) {
        int lim;
        vector<int> arr(10, 0);
        ans = 0;
        s.clear();

        if (pr[0] == 0) {
            for(int i = 0; i <= 10; i++) {
                if (i == 0) {
                    pr[i] = 1;
                    fr[i] = 1;
                } else {
                    pr[i] = pr[i - 1] * 10;
                    fr[i] = fr[i - 1] * i;
                }
            }
        }
        lim = n / 2 + n % 2;
        recur(arr, 0, 0, n, lim, k);
        return ans;
    }
};