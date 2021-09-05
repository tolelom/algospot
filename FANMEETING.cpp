#include <bits/stdc++.h>
using namespace std;


void addTo(vector<int>& a, const vector<int>& b, int k) {

}

void subFrom(vector<int>& a, const vector<int>& b) {

}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b, a);

    if (an == 0 || bn == 0) return vector<int>();

    if (an <= 50) return multiply(a, b);
    
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, b1, 0); addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);

    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}


int hugs(const string& members, const string& fans) {
    int n = members.size(), m = fans.size();
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) a[i] = (members[i] == 'M');
    for (int i = 0; i < m; ++i) b[i] = (members[i] == 'M');

    vector<int> c = karatsuba(a, b);
    int allHugs = 0;
    for (int i = n - 1; i < m; ++i)
        if (c[i] == 0)
            ++allHugs;

    return allHugs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    while(c--) {
        string a, b;
        cin >> a >> b;

        if (a.length() > b.length()) a.swap(b);

        int ans = 0;
        for (int i = 0; i < b.length() - a.length() + 1; ++i) {
            bool flag = true;
            for (int j = 0; j < a.length(); ++j) {
                if (a[j] == 'M' && b[i + j] == 'M') {
                    flag = false;
                    break;
                }
            }

            if (flag) ans++;
        }
        cout << ans << '\n';
    }
}
