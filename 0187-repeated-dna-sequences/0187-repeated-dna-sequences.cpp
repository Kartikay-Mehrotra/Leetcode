class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len=s.size();
        if(len<10)
            return {};
        string temp="";
        for(int i=0;i<10;i++)
            temp+=s[i];
        map<string,int> mp;
        mp[temp]++;
        for(int i=10;i<len;i++)
        {
            temp.erase(0,1);
            temp.push_back(s[i]);
            mp[temp]++;
        }
        vector<string> ans;
        for(auto i:mp)
        {
            if(i.second>1)
                ans.push_back(i.first);
        }
        return ans;
    }
};