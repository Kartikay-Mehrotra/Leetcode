class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
    int n = arr.size();
    vector<int> left(n, 0);  // Stores the index of the previous smaller element to the left
    vector<int> right(n, 0);  // Stores the index of the previous smaller element to the right
    stack<int> s;  // Stores elements in increasing order along with their indexes

    // Calculate 'left' array
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        left[i] = (s.empty()) ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack for calculating 'right' array
    while (!s.empty()) {
        s.pop();
    }

    // Calculate 'right' array
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            s.pop();
        }
        right[i] = (s.empty()) ? n : s.top();
        s.push(i);
    }

    long long result = 0;

    // Calculate the contribution of each element to the final sum
    for (int i = 0; i < n; ++i) {
        result = (result + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
    }

    return static_cast<int>(result);
    }
};