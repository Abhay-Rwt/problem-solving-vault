#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool can(ll mid, ll n, ll k, vector<ll> &a, vector<ll> &b){
    for(int i=0; i<n; i++){
        ll needed = b[i] - (a[i]*mid);
        if(needed < 0){
            k = k + needed;
        }
        if(k < 0) return false;
    }
    return true;
}

int main(){     
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(ll &it: a) cin >> it;
    for(ll &it: b) cin >> it;

    ll low = 0, high = 1e12, ans = -1;
    while(low <= high){
        ll mid = (low+high) / 2;
        if(can(mid, n, k, a, b)){
            ans = mid;
            low = mid+1;
        }
        else{   
            high = mid-1;
        }
    }
    cout << ans << "\n";
}