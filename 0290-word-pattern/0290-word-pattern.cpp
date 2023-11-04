class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string words;
        vector<string> temp;
        while(ss>>words)
            temp.push_back(words);
        if(pattern.size()!=temp.size())
            return false;
        map<char,string> mp;
        int j=0;
        for(int i=0;i<pattern.size();i++)
        {
            if(mp.find(pattern[i])==mp.end())
            {
                mp[pattern[i]]=temp[i];
            }
            else
            {
                auto t=mp.find(pattern[i]);
                if(t->second!=temp[i])
                {
                    return false;
                }
            }
        }
    set<string> te;
        for(auto i:mp)
        {
            te.insert(i.second);
        }
        if(te.size()==mp.size())
        return true;
        return false;
    }
};