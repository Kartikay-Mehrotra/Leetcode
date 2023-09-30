class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
       
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        int ls=0;
        int cs=1;
        int prev=pq.top();
        pq.pop();
        while(pq.size())
        {
            int t=pq.top();
            if(t-prev==1)
            {
                cs++;
            }
            else if(t-prev >1)
            {
                ls=max(ls,cs);
                cs=1;
            }
            prev=t;
            pq.pop();
        }
        ls=max(ls,cs);
        return ls;
       
    }
};