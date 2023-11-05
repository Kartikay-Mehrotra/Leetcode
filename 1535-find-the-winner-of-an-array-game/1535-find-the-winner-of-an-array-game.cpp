class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        if(n==2)
            return max(arr[0],arr[1]);
        if(k>=n-1)
            return *max_element(arr.begin(),arr.end());
        queue<int> q;
        for(int i=2;i<n;i++)
        {
            q.push(arr[i]);
        }
        int first=arr[0];
        int second=arr[1];
        int winner;
        unordered_map<int,int> mp;
        while(1)
        {
            if(first>second)
            {
                winner=first;
                q.push(second);
            }
            else
            {
                winner=second;
                q.push(first);
            }
            first=winner;
            second=q.front();
            q.pop();
            mp[winner]++;
            if(mp[winner]==k)
                return winner;
        }
        return -1;
    }
};