#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result(s2.size(),-1);
        size_t count = s1.find(s2.substr(0,1));
        if (count == string::npos) {
            return result;
        } else {
            result[0] = count;
        }
        while (count != string::npos) {
            for(int i = 1; i< s2.size(); i++) {
                if (s2[i] == s1[i+count]) {
                    if (result[i] != -1) {
                        result[i] = count;
                    }
                }
            }
            count = s1.find(s2.substr(0,1), count);
        }
        return result;
        
    }

   