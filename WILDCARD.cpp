#include <bits/stdc++.h>
using namespace std;

priority_queue<string, vector<string>, greater<string>> pq;
int cashe[101][101];
string W, S;

bool match(int w, int s) {
    int& ret = cashe[w][s];
    if (ret != -1) return ret;

    while(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) {
        ++w, ++s;
    }

    if (w == W.size())
        return ret = (s == S.size());

    if (W[w] == '*')
        for (int skip = 0; s + skip <= S.size(); ++skip) {
            if (match(w + 1, s + skip))
                return ret = 1;
        }

    return ret = 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    while(c--) {
        cin >> W;

        int n; cin >> n;

        while(n--) {
            cin >> S;

            memset(cashe, -1, sizeof(cashe));
            if (match(0, 0) == 1)
                pq.push(S);
        }
    }

    while(!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}
