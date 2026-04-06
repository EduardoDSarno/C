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
void countingStones(int n, int m, int a);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int n,m,a;

    cin >> n;
    cin >> m;
    cin >> a;

    countingStones(n, m, a);
    
}

void countingStones(int n, int m, int a){


    int area = n * m;

    int area_stone = a*a;

    int num_stones_width  = (n + a - 1) / a; // + 1 t round up
    int num_stones_height = (m + a - 1) / a;


    int total_stones = num_stones_width * num_stones_height;

    cout << total_stones << '\n';


}


