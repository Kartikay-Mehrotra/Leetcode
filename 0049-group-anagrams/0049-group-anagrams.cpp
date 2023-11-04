class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto i:strs)
        {
            string t=i;
            sort(t.begin(),t.end());
            mp[t].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};