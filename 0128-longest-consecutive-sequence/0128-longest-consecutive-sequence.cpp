class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return 1;
        set<int> s;
        for(auto i:nums)
            s.insert(i);
        nums.clear();
        for(auto i:s)
            nums.push_back(i);
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        int ls=1;
        int cs=1;
        int t=pq.top();
        pq.pop();
        while(pq.size())
        {
            if(pq.top()==t+1)
            {
                cs++;
                t=pq.top();
                pq.pop();
            }
            else
            {
                ls=max(ls,cs);
                cs=1;
                t=pq.top();
                pq.pop();
            }
        }
        ls=max(ls,cs);
        return ls;
    }
};