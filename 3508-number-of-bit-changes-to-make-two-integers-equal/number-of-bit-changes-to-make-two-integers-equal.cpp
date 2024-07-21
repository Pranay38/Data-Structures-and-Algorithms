#include <bitset>
#include <string>
#include <algorithm>

class Solution {
public:
    int minChanges(int n, int k) {
        int count = 0;
        if (n == k) {
            return 0;
        }
        
        std::bitset<32> bits(n);
        std::string sn = bits.to_string();
        std::bitset<32> bitsu(k);
        std::string sk = bitsu.to_string();
        
        for (size_t i = 0; i < sn.length(); i++) {
            if (sn[i] == '0' && sk[i] == '1') {
                return -1;
            } else if (sn[i] == '1' && sk[i] == '0') {
                count++;
            }
        }
        
        return count;
    }
};
