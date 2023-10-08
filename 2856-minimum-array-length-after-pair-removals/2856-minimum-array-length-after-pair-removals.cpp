class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        priority_queue<int> pq;
        for(auto i:mp)
        {
           
                pq.push(i.second);
       
        }
     
        while(pq.size()>1)
        {
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            f--;
            s--;
            if(f)
                pq.push(f);
            if(s)
                pq.push(s);
        }
        if(pq.size()==0)
            return 0;
        
        return pq.top();
    }
};