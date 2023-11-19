#define MAX 100000

class Solution {
public:
    int cnt[MAX + 1];

    int maxFrequency(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        for (auto& e : nums) cnt[e]++;

        int i = 1;
        while (i <= MAX && cnt[i] == 0) i++;
        int j = i;

        int r = cnt[i];
        long long x = 0, c = 0;
        while (j <= MAX) {
            c += cnt[j];

            int h = j;
            j++;
            while (j <= MAX && cnt[j] == 0) j++;

            if (j > MAX) break;

            x += c * (j - h);

            while (x > k && i < j) {
                if (cnt[i] > 0) {
                    c--;
                    cnt[i]--;
                    x -= j - i;
                } else {
                    i++;
                    while(i <= MAX && cnt[i] == 0) i++;
                }
            }

            if (r < c + cnt[j]) r = c + cnt[j];
        }
        return r;
    }
};