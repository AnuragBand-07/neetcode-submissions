class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> mp;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())return "";
    
        int l = 0; int r = mp[key].size()-1;
        string ans = "";
        while(l <= r){
            int mid = (l+r) >> 1;

            if(mp[key][mid].first <= timestamp){
                ans = mp[key][mid].second;
                l = mid + 1;
            }
            else r = mid -1;
        }
        return ans;
    }
};
