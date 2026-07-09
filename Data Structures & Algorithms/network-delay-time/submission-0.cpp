class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            int a = it[0]; int b = it[1]; int c = it[2];
            adj[a].push_back({b,c});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        using state = pair<int,int>;
        priority_queue<state, vector<state>, greater<state>> q;
        q.push({0,k});
        while(!q.empty()){
            int node = q.top().second;
            int t = q.top().first;
            q.pop();
            if(t > dist[node])continue;
            for(auto it : adj[node]){
                if(t + it.second < dist[it.first]){
                    dist[it.first] = t + it.second;
                    q.push({t + it.second, it.first});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX)return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
