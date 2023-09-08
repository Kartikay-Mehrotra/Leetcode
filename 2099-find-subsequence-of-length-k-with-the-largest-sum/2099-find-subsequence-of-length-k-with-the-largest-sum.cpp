class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> n;
        for(int i=0;i<nums.size();i++)
        {
            n.push_back({nums[i],i});
        }
        sort(n.begin(),n.end());
        int t=n.size()-1;
        while(k--)
        {
            cout<<t<<endl;
            pq.push(n[t].second);
            t--;
        }
        for(auto i:n) cout<<i.first<<" ";
        vector<int> ans;
        while(pq.size())
        {
            ans.push_back(nums[pq.top()]);
            pq.pop();
        }
        return ans;
    }
};