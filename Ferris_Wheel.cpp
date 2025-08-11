#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){     
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for(int &it: arr) cin >> it;

	sort(arr.begin(), arr.end());
	int i=0, j=n-1, cnt=0;

	while(i <= j){
		if(i == j){
			cnt++;
			break;
		}
		if(1LL*(arr[i] + arr[j]) <= x){
			i++;
			j--;
		}
		else{
			j--;
		}
		cnt++;
	}
	cout << cnt << "\n";
}