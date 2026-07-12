class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;

        bool found = false;
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord)found = true;
        }
        if(!found)return 0;
        wordList.push_back(endWord);

        for(int i = 0; i < wordList.size(); i++){
            for(int j = 0; j < wordList.size(); j++){
                if(i != j && wordList[i].length() == wordList[j].length()){
                    int diff = 0;
                    for(int k = 0; k < wordList[i].length(); k++){
                        if(wordList[i][k] != wordList[j][k])diff++;
                    }
                    if(diff <= 1){
                        adj[wordList[i]].push_back(wordList[j]);
                    }
                }
            }
        }
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i].length() == beginWord.length()){
                int diff = 0;
                for(int k = 0; k < wordList[i].length(); k++){
                    if(wordList[i][k] != beginWord[k])diff++;
                }
                if(diff <= 1){
                    adj[beginWord].push_back(wordList[i]);
                }
            }
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_map<string,int> vis;
        vis[beginWord]++;

        while(!q.empty()){
            string node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(node == endWord)return level;
            for(auto it : adj[node]){
                if(vis.find(it) == vis.end()){
                    q.push({it, level+1});
                    vis[it]++;
                }
            }
        }
        return 0;

    }
};
