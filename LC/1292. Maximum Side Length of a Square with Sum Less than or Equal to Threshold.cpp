#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvl = vector<vll>;
using vb = vector<bool>;
using vc = vector<char>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define sortall(x) sort(all(x))
#define test() int t; cin >> t; while (t--)

const int GOODMOD = 1000000007;
const int INF = 1e9;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int row = 1; row <= m; row++) {
            for (int col = 1; col <= n; col++) {
                // pref[row][col] = current_val + top + left - diagonal_overlap
                pref[row][col] = mat[row-1][col-1] + pref[row-1][col] + pref[row][col-1] - pref[row-1][col-1];
            }
        }

        int maxLen = 0;

        for (int row = 1; row <= m; row++) {
            for (int col = 1; col <= n; col++) {

                int currentLen = maxLen + 1;

                if (row >= currentLen && col >= currentLen) {

                    int r1 = row - currentLen + 1;
                    int c1 = col - currentLen + 1;

                    int squareSum = pref[row][col] - pref[r1-1][col] - pref[row][c1-1] + pref[r1-1][c1-1];

                    if (squareSum <= threshold) {
                        maxLen++;
                    }
                }
            }
        }

        return maxLen;
    }
};