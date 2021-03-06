#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& v, int left, int right) {
    if (left == right) return v[left];
    
    int mid = (left + right) / 2;
    
    int ret = max(solve(v, left, mid), solve(v, mid + 1, right));
    
    int lo = mid, hi = mid + 1;
    int height = min(v[lo], v[hi]);
    
    ret = max(ret, height * 2);
    
    while(left < lo || hi < right) {
        if (hi < right && (lo == left || v[lo - 1] < v[hi + 1])) {
            ++hi;
            height = min(height, v[hi]);
        }
        else {
            --lo;
            height = min(height, v[lo]);
        }
        
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n; 
        cin >> n;
        
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        
        cout << solve(v, 0, n - 1) << '\n';
    }
}
