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
void cal_distance(int a);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int a;

    cin >> a;

    cal_distance(a);    

    
}


void cal_distance(int a){

    int count = 0;
    int max_step =5;
    while (a > 0) {
        
        a-=max_step;
        count++;
    }
    cout << count << "\n";
}
