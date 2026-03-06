class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = s[0] - '0';
        for(int i=1; i<s.length(); i++){
            if(s[i-1] == s[i] && s[i] == '1'){
                continue;
            }
            else if(s[i] == '1'){
                cnt++;
            }
        }
        return cnt == 1;
    }
};