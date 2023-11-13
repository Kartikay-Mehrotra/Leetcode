class Solution {
public:
    string sortVowels(string st) {
        
        string temp="";
        set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        s.insert('A');
        s.insert('E');
        s.insert('I');
        s.insert('O');
        s.insert('U');
        vector<char> v;
        for(auto i:st)
        {
            if(s.find(i)==s.end())
                temp+=i;
            else
            {
                temp+='#';
                v.push_back(i);
            }
        }
        sort(v.begin(),v.end());
        int c=0;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='#')
                temp[i]=v[c++];
        }
        return temp;
        
        
    }
};