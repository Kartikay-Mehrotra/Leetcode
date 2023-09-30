#include <string.h>
class Solution {
public:
bool static  comp(const pair<char,int> &a,const pair<char,int> &b)
{
    return a.second>b.second;
}
    string frequencySort(string s) {
        unordered_map<char,int> frq;
        for(int i=0;i<s.length();i++)
        {
            frq[s[i]]++;
        }
        vector<pair<char,int>> re;
        for(auto i:frq)
        {
            char ch=i.first;
            int t=i.second;
            pair<char,int> p=make_pair(ch,t);
            re.push_back(p);
        }
        sort(re.begin(),re.end(),comp);
        string temp="";
        for(auto i:re)
        temp.append(i.second,i.first);
        return temp;
    }
};