class Solution {
public:
    int minOperations(string s) {
        string p1,p2;
        char ch = '0';

        for(int i=0; i<s.length(); i++){
            p1 += ch;
            if(ch == '0'){
                ch = '1';
            }
            else{
                ch = '0';
            }
        }

        ch = '1';
        for(int i=0; i<s.length(); i++){
            p2 += ch;
            if(ch == '0'){
                ch = '1';
            }
            else{
                ch = '0';
            }
        }

        int c1, c2;
        c1 = c2 = 0;
        for(int i=0; i<s.length(); i++){
            if(p1[i] != s[i]) c1++;
            if(p2[i] != s[i]) c2++;
        }

        return min(c1, c2);
    }
};