class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       map<char,int> mp;
        for(auto i:magazine)
            mp[i]++;
        for(auto i:ransomNote)
        {
            if(mp.count(i))
            {
                mp[i]--;
                if(mp[i]==0)
                    mp.erase(i);
            }
            else
                return false;
        }
        return true;
    }
};