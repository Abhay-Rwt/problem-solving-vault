#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	ll low = 1, high = k, ans = -1;
	while(low <= high){
		ll mid = (low + high) / 2;
		ll count = mid;
		ll sum = (mid*(mid+1)) / 2;

		if(sum % k == 0) {
			ans = count;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	cout << ans << "\n";
}

int main(){     
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}