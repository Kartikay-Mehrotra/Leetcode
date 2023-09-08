class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto i:amount)
            if(i!=0)
            pq.push(i);
        
        int ans=0;
        while(pq.size()>1)
        {
           ans++;
            int a=pq.top();
            a--;
            pq.pop();
            int b=pq.top();
            b--;
            pq.pop();
            if(a!=0)
                pq.push(a);
            if(b!=0)
                pq.push(b);
        }
        if(pq.size())
        return ans+pq.top();
        return ans;
    }
};