#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n;
	cin >> n;
	ll cows = n/4;
	n = n - 4*cows;
	ll chicks = n/2;
	cout << cows + chicks << "\n";
}

int main(){     
	ll tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}