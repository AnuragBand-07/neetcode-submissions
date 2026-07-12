class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> v(n, vector<int>(m,INT_MAX));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    v[i][j] = 0;
                }
            }
        }
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                if(i+row[k] >= 0 && i+row[k] < n && j+col[k] >= 0 && j+col[k] < m){
                    if(grid[i+row[k]][j+col[k]] == 1){
                        q.push({{i+row[k],j+col[k]},time+1});
                        grid[i+row[k]][j+col[k]] = 2;
                        v[i+row[k]][j+col[k]] = time+1;
                    }
                    else if(grid[i+row[k]][j+col[k]] == 2 && v[i+row[k]][j+col[k]] > time+1){
                        q.push({{i+row[k],j+col[k]},time+1});
                        v[i+row[k]][j+col[k]] = time+1;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)ans = max(ans, v[i][j]);
            }
        }
        return ans;
            
    }
};
