class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=INT_MAX;
        int op=0;
        int pist=0;
        for(auto i:prices)
        {
            if(l>i)
                l=i;
            
            pist=i-l;
            if(op<pist)
                op=pist;
        }
        return op;
    }
};