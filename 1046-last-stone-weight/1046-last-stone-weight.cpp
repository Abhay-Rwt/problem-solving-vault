class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone: stones){
            pq.push(stone);
        }

        while(pq.size() > 1){
            auto s1 = pq.top(); pq.pop();
            auto s2 = pq.top(); pq.pop();

            if(s1 == s2){
                continue;
            }
            else{
                pq.push(max(s1, s2) - min(s1, s2));
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};