#include <vector>
#include <string>
#include <iostream>
using namespace std;

int simple_match(string pattern, string text) {
    for(int i=0; i<text.size() - pattern.size(); i++) {
        if(text[i] != pattern[0]) continue;
        for(int j=0; j<pattern.size(); j++) {
            if(pattern[j] != text[i+j]) break;
        }
        return i;
    }
}

int kmp(string pattern, string text) {
    int m = pattern.length(), n = text.length();
    vector<int> pi(m, 0);

    int l = 0, r = 1;

    while(r < m) {
        if(pattern[l] != pattern[r]) {
            if(l == 0) r++;
            else l = pi[l-1];
        } 

        else {
            pi[r] = l + 1;
            l++; r++;
        }
    }

    l = 0, r = 0;
    while(r < n) {
        if(pattern[l] != text[r]) {
            if(l == 0) r++;
            else l = pi[l-1];
        } else {
            l++; r++;
            if(l == m) return r - m;
        }
    }

    return -1;
}

int main() {
    string t1 = "I have an apple. These apples are good.";
    string p1 = "apple";
    
    string t2 = "1a2bccc233jkl888";
    string p2 = "3jk";

    string t3 = "aaa";
    string p3 = "a";

    cout << kmp(p1, t1) << " " << t1.substr(kmp(p1, t1), p1.size()) << endl;
    cout << kmp(p2, t2) << " " << t2.substr(kmp(p2, t2), p2.size()) << endl;
    cout << kmp(p3, t3) << " " << t3.substr(kmp(p3, t3), p3.size()) << endl;

    return 0;
}