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
        
        DSU d(n+1);
        
        vector<vector<int>> edges;
        for(int i = 0; i < points.size(); i++){
            for(int j = i; j < points.size(); j++){
                if(i != j){
                    edges.push_back({abs(points[i][0]-points[j][0])+ abs(points[i][1]-points[j][1]), i, j});
                }
            }
        }
      
        sort(edges.begin(), edges.end());

        int ans = 0; int cnt = 0;
        for(auto it : edges){
            if(cnt == n-1)break;
            int wt = it[0];
            int u = it[1];
            int v = it[2];

            if(d.getParent(u) != d.getParent(v)){
                ans += wt;
                cnt++;
                d.Union(u,v);
            }
        }
        return ans;
    }
};
