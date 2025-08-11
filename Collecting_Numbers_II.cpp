#include<bits/stdc++.h>
using namespace std;

int main(){     
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), hash(n+1);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        hash[arr[i]] = i;
    }

    int rounds = 1;
        for(int i=1; i<=n; i++){
            if(hash[i-1] > hash[i]){
                rounds++;
            }
    }

    while(m--){
        int a, b;
        cin >> a >> b;

        if(hash[arr[a-1]] < hash[arr[b-1]]){
            cout << rounds+1 << "\n";
        }
        else{ 
            cout << rounds-1 << "\n";
        }
    }
}