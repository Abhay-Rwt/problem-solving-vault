#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool can(ll mid, string s, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll r){
	ll breads = 0, sausages = 0, cheese = 0;
	for(char ch: s){
		if(ch == 'B') breads++;
		else if(ch == 'S') sausages++;
		else cheese++;
	}

	nb -= (mid*breads);
	ll cost = 0;
	if(nb < 0){
		cost += (1LL*abs(nb)*pb);
	}
	ns -= (mid*sausages);
	if(ns < 0){
		cost += (1LL*abs(ns)*ps);
	}
	nc -= (mid*cheese);
	if(nc < 0){
		cost += (1LL*abs(nc)*pc);
	}

	return (cost <= r);
}

int main(){     
	string s;
	cin >> s;
	ll nb, ns, nc, pb, ps, pc;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	ll r;
	cin >> r;

	ll low = 0, high = 1e13, ans = -1;
	while(low <= high){
		ll mid = (low + high) / 2;

		if(can(mid, s, nb, ns, nc, pb, ps, pc, r)){
			ans = mid;
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}

	cout << ans << "\n";
}