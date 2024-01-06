// https://leetcode.com/problems/time-based-key-value-store/
#include <bits/stdc++.h>

using namespace std;
class TimeMap {
public:
    unordered_map<string , map<int,string>> timemap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
       if(timemap.find(key)!=timemap.end()){
            auto it= timemap[key].lower_bound(timestamp);
            if(it->first==timestamp){
                return it->second;
            }
            it--;
            if(it->first < timestamp){
                return it->second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */