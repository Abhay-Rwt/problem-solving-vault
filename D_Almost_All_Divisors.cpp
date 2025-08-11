#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for(ll &it: arr) cin >> it;
	sort(arr.begin(), arr.end());
	ll num = arr[0] * arr[n-1];
	vector<ll> factors;
	for(ll i=2; i*i<=num; i++){
		if(num % i == 0){
			ll f1,f2;
			f1 = i;
			f2 = num/i;
			factors.push_back(f1);
			if(f1 != f2){
				factors.push_back(f2);
			}
		}
	}
	sort(factors.begin(), factors.end());
	if(arr == factors){
		cout << num << endl;
	}
	else{
		cout << -1 << endl;
	}
}

int main(){     
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}