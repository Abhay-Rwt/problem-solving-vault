#include<bits/stdc++.h>
using namespace std;

int main(){     
    int n;
    cin >> n;
    vector<int> arr(n), hash(n+1); // 1.....n
    for(int i=0; i<n; i++){
        cin >> arr[i];
        hash[arr[i]] = i;
    }

    int cnt = 1; // in one round we can always place a elem in its right place;
    for(int i=1; i<=n; i++){
        if(hash[i-1] > hash[i]){
            // if so, then we will require another round to get this to its place;    
            cnt++;
        }
    }
    cout << cnt << "\n";
}