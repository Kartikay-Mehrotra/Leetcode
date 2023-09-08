class Solution {
public:
    int largestInteger(int num) {
        int lar_int = 0, n = num;
        priority_queue <int, vector <int>, greater <int>> pq1, pq2;
        while(n > 0) {
            int digit = n % 10;
            n /= 10;
            if(digit % 2 != 0) {
                pq1.push(digit);
            }
            else {
                pq2.push(digit);
            }
        }
        n = num;
        long long k = 1;
        while(n > 0) {
            int t = n%10; n /= 10;
            if(t % 2 == 0) {
                lar_int += (pq2.top()) * k;
                pq2.pop();
            }
            else {
                lar_int += (pq1.top()) * k;
                pq1.pop();
            }
            k *= 10;
        }
        return lar_int;
    }
};