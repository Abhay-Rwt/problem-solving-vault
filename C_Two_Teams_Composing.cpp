#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> mpp;
    int distincts = 0, maxFreq = 0;
    for(int &it: arr){
        cin >> it;
        mpp[it]++;
        maxFreq = max(maxFreq, mpp[it]);
    }
    distincts = mpp.size();
    if(maxFreq == distincts){
        cout << maxFreq-1 << "\n";
    }
    else if(maxFreq < distincts){
        cout << min(maxFreq, distincts-1) << "\n"; // as same elements' 1 frequency would be present in distincts cnt as  well
    }
    else{
        cout << min(maxFreq-1, distincts) << "\n";
    }
}

int main(){     
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}