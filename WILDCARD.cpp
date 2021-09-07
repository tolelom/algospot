#include <bits/stdc++.h>
using namespace std;

bool match(string w, string s) {
    int pos = 0;
    
    while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) {
        pos++;
    }

    if (pos == w.size())
        return pos == s.size();

    if (w[pos] == '*')
        for (int skip = 0; pos + skip <= s.size(); ++skip) {
            if (match(w.substr(pos + 1), s.substr(pos + skip)))
                return true;
        }

    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    while(c--) {
        string w;
        cin >> w;

        int n;
        cin >> n;

        while(n--) {
            string s;
            cin >> s;
            if (match(w, s)) {
                cout << s << '\n';
            }
        }
    }
}
