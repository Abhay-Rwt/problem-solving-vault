#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n;
	cin >> n;
	int moves = 0;

	while(n != 1){
		if(n % 6 == 0){
			n /= 6;
		}
		else if(n < 6 && n % 2 == 0){
			cout << -1 << "\n";
			return;
		}
		else{
			n *= 2;
		}
		moves++;
	}
	cout << moves << "\n";
}

int main(){     
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}