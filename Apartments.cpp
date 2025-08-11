#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){     
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for(int &it: a) cin >> it;
	for(int &it: b) cin >> it;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i=0, j=0, cnt = 0;
	while(i < n && j < m){
		if(a[i]-k <= b[j] && b[j] <= a[i]+k){
			cnt++;
			i++;
			j++;
		}
		else if(b[j] < a[i]-k){
			j++;
		}
		else{
			i++;
		}
	}
	cout << cnt << "\n";
}