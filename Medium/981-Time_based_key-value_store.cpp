class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> map;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        this->map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> &temp_map = this->map[key];

        int l = 0;
        int r = temp_map.size() - 1;
        string res = "";

        while(l<=r){
            int m = (l+r)/2;

            if( temp_map[m].second <= timestamp ){
                res = temp_map[m].first;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */