#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main(){     
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int &it: arr) cin >> it;
	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	int maxi = *maximum_element(arr.begin(), arr.end());
	int prime[maxi+1] = {0};
	for(int i=2; i<=maxi; i++){
		for(int j=i; j<=maxi, j+=i){
			prime[j]++;
		}
	}
}