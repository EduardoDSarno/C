
#include <climits>
#include <iostream>
#include <string>


using namespace std;
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        int left = 0,right = 0,best_left = 0, min_windon = INT_MAX;
        string result = "";

        // cover both upper and lowercase
        int freqt[52]  = {0};
        int freq2[52] = {0};

        for (char c : t) 
        {
            increment_freq_array(c, freqt);
        }

        int required = 0;
        for (int i = 0; i < 52; i++)
        {
            if (freqt[i] > 0) required++;
        }
        int formed = 0;

        while(right < s.size())
        {
            int idx_r = charIndex(s[right]);
 
            if (freqt[idx_r] > 0) 
            {
                freq2[idx_r]++;
                if (freq2[idx_r] == freqt[idx_r]) formed++;
            }

            while(formed == required)
            {
                int window = right - left + 1;
                if(window < min_windon)
                {
                    min_windon = window;
                    best_left = left;
                }

                int idx_l = charIndex(s[left]);
                if(freqt[idx_l] > 0)
                {
                    if(freq2[idx_l] == freqt[idx_l]) formed--;
                    freq2[idx_l]--;
                }
                left++;
            }
           
        
            right++;
        }

        return min_windon == INT_MAX ? "" : s.substr(best_left, min_windon);
    }
    /* this is a helper to calcualte index for 52 item frequency array*/
    void increment_freq_array(char c, int *freq)
    {
        int idx = charIndex(c);
        freq[idx]++;
    }
    int charIndex(char c)
    {
        int idx;
        if ('a' <= c && c <= 'z')
        {
            idx = c - 'a';
        }
        else
        {
            idx = c - 'A' + 26;
        }
        return idx;
    }
};

int main(void)
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution solution;

    cout << solution.minWindow(s, t);
}