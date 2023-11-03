class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        set<int> s;
        for(auto i:target)
            s.insert(i);
        set<int> valid;
        for(int i=1;i<=n;i++)
        {
            if(valid==s)
                return ans;
            if(s.find(i)!=s.end())
            {
                valid.insert(i);
                ans.push_back("Push");
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};