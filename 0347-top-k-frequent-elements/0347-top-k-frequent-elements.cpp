class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> numToFreq;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            numToFreq[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(auto it: numToFreq){
            int num = it.first;
            int freq = it.second;

            minHeap.push({freq, num});

            while(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};