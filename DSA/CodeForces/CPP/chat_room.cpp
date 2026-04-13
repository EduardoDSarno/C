// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code

    string hello;
    cin >> hello;


    string hello2 = "hello";
    string check_hello;
    int i = 0;

    for (char c : hello) {
        
        if(c == hello2[i]){
            check_hello.push_back(c);
            i++;
        }
    }
    if(check_hello == "hello"){
        cout << "YES" ;
    }
    else {
        cout << "NO";
    }
    cout << '\n' ;
}
