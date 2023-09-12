class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord);
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
                for(char c='a';c<='z';c++)
                {
                    val[i]=c;
                    if(s.find(val)!=s.end())
                    {
                        s.erase(val);
                        q.push({val,steps+1});
                    }
                }
                val[i]=original;
            }
        }
        return 0;
    }
};