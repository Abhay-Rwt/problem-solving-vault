#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool can(ll mid, ll n, ll &cnt){
	ll pipelines = 0;
	for(int i=mid; i>=2; i--){
		pipelines += i;
		cnt++;
		if(pipelines == n){
			return true;
		}
		else{
			pipelines--;
		}
	}
	return false;
}

int main(){     
	ll n, k;
	cin >> n >> k;

	ll low = 2, high = k, ans = -1;
	while(low <= high){
		ll mid = (low + high)/2;
		ll cnt = 0;
		if(can(mid, n, cnt)){
			ans = cnt;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	cout << ans << "\n";
}