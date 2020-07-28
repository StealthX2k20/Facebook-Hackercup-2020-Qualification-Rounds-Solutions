#include<bits/stdc++.h>
using namespace std;
#define loi long long
#define lod long double
#define doubel double
#define pb push_back
#define run ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define lim 5000000000000000000
#define in(ar, n) for(loi i = 0; i < n; i++) cin >> ar[i];
#define out(ar, n) for (loi i = 0; i < n; i++) cout << ar[i] << " "; cout << "\n";
#define rep(i, n) for(loi i = 0; i < n; i++)
#define rep1(i, n) for(loi i = 1; i <= n; i++)
#define rev(i, n) for(loi i = n - 1; ~i; i--)
#define rep3(i, l, r) for(loi i = l; i <= r; i++)
#define rev3(i, r, l) for(loi i = r; i >= l; i--)
#define rep4(i, r, l) for(loi i = r; i >= l; i--)
#define all(x) x.begin(), x.end ()
#define mkp make_pair
#define vii vector<loi>
#define mii map<loi, loi>
#define sii set<loi>
#define pii pair<loi, loi>
#define mxdepth 23 // FOR LCA til N = 1e6
#define mxn 2000001

void dfs(loi vert, loi vis[], vii graph[], vii &path)
{
    path.pb(vert);
    vis[vert] = 1;
    rep(i, graph[vert].size())
     if(vis[graph[vert][i]] == 0)
       dfs(graph[vert][i], vis, graph, path);
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    run;
    int t;
    cin >> t;

    for(loi tc = 1; tc <= t; tc++)
    {
        loi n;
        cin >> n;
        
        string inc, outg;
        cin >> inc;
        cin >> outg;

        vii graph[n];

        rep(i, n)
        {
            if(i == 0)
            {
              if(outg[i] == 'Y')
              {
                  if(inc[i + 1] == 'Y')
                    graph[i].pb(i + 1);
              }
            }

            else if(i == n - 1)
            {
               if(outg[i] == 'Y')
               {
                   if(inc[i - 1] == 'Y')
                   graph[i].pb(i - 1);
               }
            }

            else
            {
                if(outg[i] == 'Y')
                {
                    if(inc[i - 1] == 'Y')
                      graph[i].pb(i - 1);

                    if(inc[i + 1] == 'Y')
                      graph[i].pb(i + 1);
                }
            }
        }

        char res[n][n];

        rep(i, n)
          rep(j, n)
             res[i][j] = 'N';

        
        cout << "Case #" << tc << ":\n";

        vii reachable;
        loi vis[n];

        rep(i, n)
        {
           reachable.clear();
           memset(vis, 0, sizeof(vis));
           dfs(i, vis, graph, reachable);

           rep(j, reachable.size())
            res[i][reachable[j]] = 'Y';

           res[i][i] = 'Y';
        }

        rep(i, n)
        {
            rep(j, n)
            cout << res[i][j];

            cout << "\n";
        }
    }

    return 0;
}