class Solution {
public:
    int halveArray(vector<int>& nums) {
       double sum=0;
        
        priority_queue<double> pq;
        for(auto i:nums){
            pq.push(i*1.0);
            sum+=i;
        }
            
        
        
        int ans=0;
        double t=sum/2;
        while(t<sum)
        {
            double val=pq.top()/2;
            t+=val;
            pq.pop();
            pq.push(val);
            ans++;
        }
        return ans;
        
    }
};