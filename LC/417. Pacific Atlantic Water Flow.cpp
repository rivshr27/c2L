
#include<iomanip>
#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<set>

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

// using iiii = __int128;
 
// #if defined(__SIZEOF_INT128__)
//     using iiii = __int128;
// #else
//     #error "__int128 not supported on this platform"
// #endif


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define sortall(x) sort(all(x))
#define test() int t; cin >> t; while (t--)
#define f11 for(int i = 0; i < 1; i++)
#define f22 for(int i = 0; i < 1; i++) { for(int j = 0; j < i; j++)}
#define w22(var) int var = 0; while(var--)

const int GOODMOD = 1000000007;
const int INF = 1e9;
bool f1 = true;
bool f2 = false;
auto t0 = 0;
auto t1 = 1;
auto t2 = 2;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            atlantic[m-1][j] = true;
        }
        
        bool updated = true;
        
        while(updated) {
            updated = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (!pacific[i][j]) {
                        if (i > 0 && pacific[i-1][j] && heights[i][j] >= heights[i-1][j]) {
                            pacific[i][j] = true;
                            updated = true;
                        } else if (i < m-1 && pacific[i+1][j] && heights[i][j] >= heights[i+1][j]) {
                            pacific[i][j] = true;
                            updated = true;
                        } else if (j > 0 && pacific[i][j-1] && heights[i][j] >= heights[i][j-1]) {
                            pacific[i][j] = true;
                            updated = true;
                        } else if (j < n-1 && pacific[i][j+1] && heights[i][j] >= heights[i][j+1]) {
                            pacific[i][j] = true;
                            updated = true;
                        }
                    }
                    
                    if (!atlantic[i][j]) {
                        if (i > 0 && atlantic[i-1][j] && heights[i][j] >= heights[i-1][j]) {
                            atlantic[i][j] = true;
                            updated = true;
                        } else if (i < m-1 && atlantic[i+1][j] && heights[i][j] >= heights[i+1][j]) {
                            atlantic[i][j] = true;
                            updated = true;
                        } else if (j > 0 && atlantic[i][j-1] && heights[i][j] >= heights[i][j-1]) {
                            atlantic[i][j] = true;
                            updated = true;
                        } else if (j < n-1 && atlantic[i][j+1] && heights[i][j] >= heights[i][j+1]) {
                            atlantic[i][j] = true;
                            updated = true;
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        
        return result;
    }
};