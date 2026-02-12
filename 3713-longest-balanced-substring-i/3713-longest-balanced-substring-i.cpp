class Solution {
public:
    int longestBalanced(string s) {
        int maxLength = 0;
        for(int i=0; i<s.length(); i++)
        {
            unordered_map<char,int> mpp;

            for(int j=i; j<s.length(); j++){
                mpp[s[j]]++;

                bool isValid = 1;

                for(auto it: mpp){
                    if(it.second != mpp[s[j]]){
                        isValid = 0;
                    }
                }

                if(isValid){
                    maxLength = max(maxLength, (j-i+1));
                }
            }
        }

        return maxLength;
    }
};