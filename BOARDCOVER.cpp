#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool blockType[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}},
    {{0, 0}, {1, 0}, {1, 1}}
};

int solve(vector<string> curBoard) {
    int ret = 0;

    for (int i = 0; i < curBoard.size(); ++i) {
        for (int j = 0; j < curBoard[0].length(); ++j) {
            if (curBoard[i][j] == '#') continue;
            
             
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    
    while (c--) {
        int h, w;
        cin >> h >> w;

        vector<string> board(h);
        for (int i = 0; i < h; ++i)
            cin >> board[i];

        int ans = solve(board);

        cout << ans << '\n';
    }

}
