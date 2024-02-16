class Solution {
public:
    typedef pair<int, int> p;
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int i: arr)
            mp[i]++;
        
        priority_queue<p, vector<p>, greater<p>> pq; //greater means lowest at the top. ulta scnz
        
        for(auto pair : mp){
            pq.push({pair.second, pair.first});
        }
        
        while(!pq.empty()){
            int freq = pq.top().first;
            
            if(k - freq < 0)
                break;
            
            k -= freq;
            // cout << pq.top().second << " " << freq << endl;
            pq.pop();
        }
        
        cout << endl;
        return pq.size();
    }
};
