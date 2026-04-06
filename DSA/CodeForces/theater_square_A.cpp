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
    int n,m,a;

    cin >> n;
    cin >> m;
    cin >> a;
    
}

void countingStones(int n, int m, int a){


    int area = n * m;

    int area_stone = a*a;

    int count = 0;
    // if they fit nicely
    if(area % area_stone == 0){

        while (area != 0) {
            
            area -= area_stone;
            count++;
        }
       
    }
    



}

