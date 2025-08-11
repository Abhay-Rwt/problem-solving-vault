#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll solve(int ind, string &s){
	if(ind == s.size()) return 0;

	ll notpick = solve(ind+1, s);
	ll pick = solve(ind-1, s);

	if(notpick % 8 == 0){
		return notpick;
	}
	else if(pick % 8 == 0){
		return pick;
	}
	return 0;
}

int main(){     
	string s;
	cin >> s;
	ll ans = solve(0, s);
	if(ans){
		cout << "YES" << endl;
		cout << ans << endl; 
	}
	else{
		cout << "NO" << endl;
	}
}