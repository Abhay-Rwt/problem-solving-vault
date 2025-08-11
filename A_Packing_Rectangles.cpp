#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){     
	int w, h, n;
	cin >> w >> h >> n;

	ll low = 0, high = 1LL * max(w, h) * n, ans = -1;
	while(low <= high){
		ll mid = (low + high) / 2;
		ll cw = mid / w;
		ll ch = mid / h;
		if (cw >= 0 && ch >= 0 && cw * ch >= n){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	cout << ans << "\n";
}
