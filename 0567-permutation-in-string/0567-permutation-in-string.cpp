class Solution {
public:
  
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())
        return false;
        unordered_map<char,int> f;
        unordered_map<char,int> s;
        for(int i=0;i<s1.length();i++)
        {
            f[s1[i]]++;
        }

        int l=0;
        int r=0;
        while(r<s2.length())
        {
            int c=s2[r];
            s[c]++;
            if((r-l+1)==s1.length())
            {
                cout<<"Hit"<<endl;
                for(auto i:s)
                cout<<i.first<<endl;
                // if(f==s)
                // cout<<"True"<<endl;
                if(f==s)
                return true;
            }
            if((r-l+1)<s1.length())
            r++;
            else
            {
                s[s2[l]]--;
                if(s[s2[l]]==0)
                s.erase(s2[l]);
                l++;
                r++;
            }
        }
return false;
    }
};