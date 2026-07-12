class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(int i = 0; i < v.size(); i++){
            adj[v[i][1]].push_back(v[i][0]);
            indeg[v[i][0]]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i = 0;i < n; i++){
            if(indeg[i] == 0)q.push(i);
        }

        if(q.size() == 0)return {};

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto it : adj[node]){
                if(indeg[it] == 1){
                    indeg[it]--;
                    q.push(it);
                }
                else{
                    indeg[it]--;
                }
            }
        }

        for(auto x : indeg){
            if(x != 0)return {};
        }
        return ans;
    }
};
