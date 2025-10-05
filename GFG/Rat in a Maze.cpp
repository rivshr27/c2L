
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
   void solve(int x , int y , int n , vector<vector<int>> & maze ,string & path , set<string>& ans , vector<vector<bool>> & vis){
        if(x == n-1 && y == n-1 ) ans.insert(path);
        int delx[4] = {-1 , 1, 0 ,0 };
        int dely[4] = { 0 , 0 , -1 , 1 };
        for(int i = 0 ; i < 4 ; i++){
            
            int nx = delx[i]+x;
            int ny = dely[i]+y;
            
            if(nx >= 0 && ny >=0 && nx < n && ny < n && maze[nx][ny] && !vis[nx][ny]){
                if(i==0)path.push_back('U');
                if(i==1)path.push_back('D');
                if(i==2)path.push_back('L');
                if(i==3)path.push_back('R');
                vis[nx][ny]=true;
                solve(nx ,ny ,n  , maze ,path, ans , vis);
                vis[nx][ny]=false;
                path.pop_back();
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n =maze.size();
        set<string> res;
        vector<vector<bool>>vis(n , vector<bool>(n,false));
        string path = "";
        vis[0][0]=true;
        solve(0 ,0 ,n  , maze ,path ,  res , vis);
        vector<string> ans (res.begin(),res.end());
        return ans;
    }
};