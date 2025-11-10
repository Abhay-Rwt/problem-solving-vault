class Solution {
    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }

public:
    int minOperations(int n, int m) {
        // Approach:: Appoarch is simple we need to get the min cost i.e. shortest path 
        // to reach m by the given operations. So, we can use a modified dijkstra's here
        // ,we will push all posibilities into a priority queue except the prime ones
        // and the ones that are visited already. And at the end we'll return our answer

        // base case
        if(isPrime(n) || isPrime(m)) return -1;
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq; // {sum, node}
        unordered_map<string, int> dist;

        string N = to_string(n);
        string M = to_string(m);
        
        pq.push({n, N});
        dist[N] = n;

        while(!pq.empty()){
            auto [sum, node] = pq.top();
            pq.pop();
            if(sum > dist[node]) continue;

            if(node == M) return sum;

            for(int i=0; i<node.length(); i++){
                char ch = node[i];
                
                // increasing by 1;
                if(node[i] != '9'){
                    node[i]++;
                    if(!isPrime(stoi(node)) && (!dist.count(node) || dist[node] > sum + stoi(node))){
                        dist[node] = sum + stoi(node);
                        pq.push({dist[node], node});
                    }
                    node[i] = ch;
                }

                // decreasing by 1;
                if(node[i] != '0' && !(i == 0 && node[i] == '1')){
                    node[i]--;
                    if(!isPrime(stoi(node)) && (!dist.count(node) || dist[node] > sum + stoi(node))){
                        dist[node] = sum + stoi(node);
                        pq.push({dist[node], node});
                    }
                    node[i] = ch;
                }
            }
        }
        return -1;
    }
};










