// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
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

    int n;

    vector<int> boxs;

    cin >> n;

    for (int i = 0 ; i < n; ++i) {
        
        int t;
        cin >> t;
        boxs.push_back(t);
    }

    sort(boxs.begin(), boxs.end());

    for (int i : boxs) {
        
        printf("%d ", i);
    }
    cout << '\n';
}
