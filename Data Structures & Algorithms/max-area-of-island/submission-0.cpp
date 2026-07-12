
class DSU{
private:
    vector<int> size, parent;
public:
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i < n+1; i++){
            parent[i] = i;
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
    vector<int> groups(){
        return size;
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU d(n*m);

        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        if(i+row[k] >= 0 && i+row[k] < n && j+col[k] >= 0 && j+col[k] < m){
                            if(grid[i+row[k]][j+col[k]] == 1){
                                d.Union(i*m + j+1, (i+row[k])*m + (j+col[k])+1);
                            }
                        }
                    }
                }
            }
        }

        vector<int> v = d.groups();
        
        int ans = 0; 
        for(int i = 1; i < v.size(); i++){
            int x = (i-1)/m; int y = (i-1) - x*m;
            if(grid[x][y] != 0){
                ans = max(ans, v[d.getParent(i)]);
            }
        }
        return ans;
    }
};
