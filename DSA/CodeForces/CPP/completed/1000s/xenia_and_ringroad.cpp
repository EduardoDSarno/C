// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    ll n,m;

    cin >> n >> m;

    ll count = 0;
    ll loc = 1;
    
    for (int i = 0 ; i < m; ++i) {
    
        ll t;
        cin >> t;

        // maths
        if(loc > t) // if is ahead
        {
            count += (n - loc) + t; // distance to end + beginning to desired
        }
        else 
        {
            count += t - loc;
        }
        loc = t;
        

    }
    cout << count << '\n';
}
