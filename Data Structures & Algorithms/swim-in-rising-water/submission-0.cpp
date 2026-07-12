class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(n,0));

        using state = vector<int>;
        priority_queue<state, vector<state>, greater<state>> q;

        q.push({grid[0][0],0,0});
        vis[0][0] = 1;

        int ans = 0;
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};
        while(!q.empty()){
            int i = q.top()[1];
            int j = q.top()[2];
            int mx = q.top()[0];
            q.pop();

            if(i == n-1 && j == n-1){
                ans = mx;
                break;
            }
            for(int k = 0; k < 4; k++){
                int i1 = i+row[k]; int j1 = j+col[k];
                if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && vis[i1][j1] == 0){
                    q.push({max(mx,grid[i1][j1]), i1, j1});
                    vis[i1][j1] = 1;
                }
            }
        }
        return ans;
    }
};
