// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>


using namespace std;
void countingStones(long long n, long long m, long long a);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    long long n,m,a;

    cin >> n;
    cin >> m;
    cin >> a;

    countingStones(n, m, a);
    
}

void countingStones(long long n, long long m, long long a){


    long long area = n * m;

    long long area_stone = a*a;

    long long num_stones_width  = (n + a - 1) / a; // + 1 t round up
    long long num_stones_height = (m + a - 1) / a;


    long long total_stones = num_stones_width * num_stones_height;

    cout << total_stones << '\n';


}


