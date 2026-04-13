class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gasBalance=0;
        int gasDeficit=0;
        int stIndex=0;

        for(int i=0; i<n; i++)
        {
            gasBalance += (gas[i]-cost[i]);

            if(gasBalance < 0){
                gasDeficit += abs(gasBalance);
                gasBalance=0;
                stIndex=i+1;
            }
        }

        if(gasBalance >= gasDeficit){
            return stIndex;
        }
        return -1;
    }
};