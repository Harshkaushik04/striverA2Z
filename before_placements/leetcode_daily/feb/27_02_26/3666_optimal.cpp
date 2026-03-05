#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int m = 0;
        
        for(char c : s) {
            if(c == '0') m++;
        }
        
        if(m == 0) return 0;
        if(m % 2 != 0 && k % 2 == 0) return -1;
        if(k == 0) return -1;
        
        int L = m, R = m;
        int P = m % 2;
        int step = 0;
        
        while(step <= n) {
            step++;
            int next_P = (P + k) % 2;
            int next_L, next_R;
            
            if (k >= L && k <= R) {
                next_L = (k % 2 == P) ? 0 : 1;
            } else if (k < L) {
                next_L = L - k;
            } else {
                next_L = k - R;
            }
            
            int peak = n - k;
            if (peak >= L && peak <= R) {
                next_R = (peak % 2 == P) ? n : n - 1;
            } else if (peak < L) {
                next_R = 2 * n - L - k;
            } else {
                next_R = R + k;
            }
            
            L = next_L;
            R = next_R;
            P = next_P;
            
            if (L == 0) return step;
        }
        
        return -1;
    }
};