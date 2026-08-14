class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordSet(wordList.begin(),wordList.end());
        if(!wordSet.count(endWord))
          return 0;
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>visited;
        visited.insert(beginWord);
        int level=1;
        while(!q.empty()){
            int size=q.size();
            for(int j=0;j<size;j++){
                string current=q.front();
                q.pop();
                if(current==endWord){
                    return level;
                }
                for(int i=0;i<current.size();i++){
                    char original=current[i];
                    for(char ch='a';ch<='z';ch++){
                        current[i]=ch;
                        if(wordSet.count(current) && !visited.count(current)){
                            visited.insert(current);
                            q.push(current);
                        }
                    }
                    current[i] = original;
                }
            }
             level++;
        }
         return 0;
    }
};