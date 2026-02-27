class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> hash(26, 0);

        for(char &c: p){
            hash[c - 'a']++;
        }

        int l=0;
        vector<int> indices;

        for(int r=0; r<n; r++)
        {
            hash[s[r] - 'a']--;

            while(l <= r && hash[s[r] - 'a'] < 0){
                hash[s[l] - 'a']++;
                l++;
            }

            bool valid=true;
            for(int i=0; i<26; i++){
                if(hash[i] != 0){
                    valid = false;
                    break;
                }
            }

            if(valid){
                indices.push_back(l);
            }
        }

        return indices;
    }
};