class DSU{
private:
    vector<int> size, parent;
public:
    DSU(int n){
        size.resize(n+1,1);
        for(int i = 0; i <= n; i++){
            parent.push_back(i);
        }
    }
    int getParent(int u){
        if(parent[u] == u)return u;
        else{
            return parent[u] = getParent(parent[u]);
        }
    }
    void Union(int u, int v){
        int pu = getParent(u);
        int pv = getParent(v);
        int su = size[pu];
        int sv = size[pv];

        if(pu == pv)return;
        else if(su > sv){
            parent[pv] = pu;
            size[pu]+= size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv]+= size[pu];
        }
    }
    int getSize(int u){
        int p = getParent(u);
        return size[p];
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                adj[i].push_back({j, abs(points[i][0]-points[j][0])+ abs(points[i][1]-points[j][1])});
                adj[j].push_back({i, abs(points[j][0]-points[i][0])+ abs(points[j][1]-points[i][1])});
            }
        }
      
        using state = pair<int,int>;
        priority_queue<state, vector<state>, greater<state>> q;
        vector<int> vis(n,0);
        q.push({0,0});
        int ans = 0;
        while(!q.empty()){
            int node = q.top().second;
            int wt = q.top().first;
            q.pop();

            if(vis[node] == 1)continue;
            ans += wt;
            vis[node] = 1;
            for(auto it : adj[node]){
                if(vis[it.first] == 0)q.push({it.second,it.first});
            }

        }
        return ans;
    }
};
