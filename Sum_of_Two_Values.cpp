#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){     
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr[i] = {a, i};
    }
    sort(arr.begin(), arr.end());

    int i=0, j=n-1;
    while(i < j){
        ll sum = arr[i].first + arr[j].first;
        if(sum < k){
            i++;
        }
        else if(sum > k){
            j--;
        }
        else{
            cout << arr[i].second + 1 << " " << arr[j].second + 1 << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}