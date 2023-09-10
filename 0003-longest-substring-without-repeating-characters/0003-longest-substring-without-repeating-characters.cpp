class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
        return 0;
        unordered_map<char,int> mp;
        int ans=0;
        int j=0;
       int i=0;
       while(j<s.length())
       {
           mp[s[j]]++;
          while(mp[s[j]]>1)
          mp[s[i++]]--;
          ans=max(ans,j-i+1);

          j++;
           
       }
        return ans;
    }
};