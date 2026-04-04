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

void maximize_medians_permutation(int n);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int tests;

    cin >> tests;

    // read first line
    for(int i = 0; i < tests ;++i){

        int x;
        cin >> x;
        maximize_medians_permutation(x);

    }

    
}

void maximize_medians_permutation(int n){

    // I have to construct a permunation 3n
    int lenght = 3 * n;

    int count = 0;

    vector<int> result(lenght);

    for(int i = 0; i < lenght;++i){

        int bucket = (lenght - count) % 3;
        // so we get the bucket with /
        result[i + bucket] = count + 1;

          count++;

    }

    for (int i = 0; i < lenght; i++) 
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}