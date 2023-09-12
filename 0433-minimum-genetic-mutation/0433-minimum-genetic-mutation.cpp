class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& bank) {
        if(bank.size()==0)
        return -1;
        if(beginWord==endWord)
        return 0;
 unordered_set<string> s(bank.begin(),bank.end());
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        s.erase(beginWord);
        const vector<char> fuck={'A','C','G','T'};
        while(q.size())
        {
            string val=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(val==endWord)
            return steps;
            for(int i=0;i<val.length();i++)
            {
                char original=val[i];
                for(int j=0;j<4;j++)
                {
                    val[i]=fuck[j];
                    if(s.find(val)!=s.end())
                    {
                        s.erase(val);
                        q.push({val,steps+1});
                    }
                }
                val[i]=original;
            }
        }
        return -1;
    }
};