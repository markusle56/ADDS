#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result;

        // for(size_t i = 1; i <= s2.size(); i++) {
        //     size_t one = s1.find(s2[i]);
        //     if (one == 0) {
        //         return result;
        //     }
        //     size_t found = s1.find(s2.substr(0, i));
        //     if (found != string::npos) {
        //         result.push_back(found);
        //     } else {
        //         return result;
        //     }
        // }
        // for (int i = 0; i < s2.size(); i++) {
        //     result.push_back(-1);
        // }
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                if(s2[j] == s1[i+j]) {
                    if (result[j] == -1) {
                        result[j] = i;
                    }
                } else {
                    break;
                }
            }
        }
        return result;
    }

   