#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

bool isPrime(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){     
	int n, k;
	cin >> n >> k;
	vector<int> prime;
	for(int i=2; i<=n; i++){
		if(isPrime(i)){
			prime.push_back(i);
		}
	}
	int cnt = 0;
	for(int i=1; i<prime.size(); i++){
		int a = prime[i-1], b = prime[i], c = 1;
		if(a+b+c <= n && isPrime(a+b+c)){
			cnt++;
		}
	}
	if(cnt >= k){
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;
}