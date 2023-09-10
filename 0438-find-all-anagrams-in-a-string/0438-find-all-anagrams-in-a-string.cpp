class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> f;
        unordered_map<char,int> m;
        vector<int> ans;
        for(int i=0;i<p.length();i++)
        {
            f[p[i]]++;
        }

        int i=0;
        int j=0;
        while(j<s.length())
        {
            m[s[j]]++;
            if((j-i+1)==p.length())
            {
                if(m==f)
                ans.push_back(i);
              
            }
            if((j-i+1)<p.length())
            j++;
            else
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;
                j++;
            }
        }
        return ans;

    }
};