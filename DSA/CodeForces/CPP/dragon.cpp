// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int s,n;

    cin >> s >> n;

    vector<pair<int, int>> dragons(n);

    for (int i = 0; i < n; i++) {
        
        int d_s, bn;
        cin >> d_s >> bn;

        dragons[i] = {d_s,bn};
    }
    sort(dragons.begin(), dragons.end());

    int f = 1;
    for (int i = 0; i < n; ++i) 
    {
        
        if(dragons[i].first < s) {
            s += dragons[i].second;
        }
        else 
        {
            f = 0;
            break;
        }
    }

    f == 1 ? cout << "YES" :cout << "NO";
    cout << '\n';
}
