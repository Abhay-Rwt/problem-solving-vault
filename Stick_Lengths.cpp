#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){     
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int median = arr[n/2];
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += abs(arr[i]-median);
    }
    cout << ans << "\n";
}