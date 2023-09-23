class Solution {
public:

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){ return a.length()<b.length() ;});
       unordered_map<string,int> mp;
       int len=1;
       for(auto word:words)
       {
           mp[word]=1;
           for(int i=0;i<word.length();i++)
           {
               string di=word.substr(0,i)+word.substr(i+1);
               if(mp.find(di)!=mp.end())
               {
                   mp[word]=max(mp[di]+1,mp[word]);
                   len=max(len,mp[word]);
               }
               else
                continue;
           }
       }
       return len;
    }
};