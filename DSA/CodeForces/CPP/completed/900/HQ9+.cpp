// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <regex>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code

    string i;
    cin >> i;

    regex pattern("[HQ9]");

    if(regex_search(i, pattern)){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << '\n';

}
