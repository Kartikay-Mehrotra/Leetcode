class Solution {
public:
    bool backspaceCompare(string s, string t) {
     
        vector<char> s1,s2;
        for(auto i:s)
        {
            if(i=='#' && s1.size())
            {
                s1.pop_back();
            }
            else if(i!='#')
                s1.push_back(i);
        }
        for(auto i:t)
        {
            if(i=='#' && s2.size())
                s2.pop_back();
            else if(i!='#')
                s2.push_back(i);
        }
        for(auto i:s1)
            cout<<i<<" ";
        cout<<endl;
        for(auto i:s2)
            cout<<i<<" ";
        return s1==s2;
    }
};