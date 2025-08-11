#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){     
	ll n, k;
	cin >> n >> k;
	ll totMins = 240;

	ll low = 0, high = n, ans = 0;
	while(low <= high){
		ll mid = (low+high)/2;
		if(k+((mid*(mid+1))/2)*5 <= totMins){
			ans = mid;
			low = mid+1; // do more questions
		}
		else{
			high = mid-1; // do less questions
		}
	}
	cout << ans << "\n";
}