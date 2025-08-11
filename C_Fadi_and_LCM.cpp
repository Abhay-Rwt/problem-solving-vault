#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main(){     
	ll n;
	cin >> n;
	vector<ll> divs;
	ll ans = LLONG_MAX;
	for(ll i=1; i*i<=n; i++){
		if(n % i == 0){
			ll f1,f2;
			f1 = i;
			f2 = n/i;
			ll g = __gcd(f1, f2);
			if(g == 1){
				ans = min(ans, max(f1, f2));
			}
		}
	}
	cout << n/ans << " " << ans << endl;
}