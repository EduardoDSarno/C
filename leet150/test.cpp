// g++ -o test test.cpp && ./test

#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            
           unordered_set<char>result;
           size_t lenght = s.size();

           int max = 0;
           int count = 0;

           int left = 0;

           for (int right = 0 ; right < lenght; ++right){

                while (result.count(s[right])) {
                    result.erase(s[left]);
                    left++;
                }
                result.insert(s[right]);
                
                count = (right - left)  + 1;
                if(count > max) max = count;
           }
           return max;
        }
};

int main(void){
    Solution sol;
    
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;  // expected: 3
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;     // expected: 1
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;    // expected: 3
    cout << sol.lengthOfLongestSubstring("") << endl;          // expected: 0
    
    return 0;
}