class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(auto i:s)
        {
            m[i]++;
        }
        for(auto j:t)
        {
            if(m[j]>0)
            {
                m[j]--;
            }
           else if(m[j]==0)
            {
                return j;
            }
        }
        return ' ';
    }
};