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

bool cmpr(pii p1, pii p2)
{
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    run;
    loi t;
    cin >> t;
    
    rep1(tc, t)
    {
        loi n;
        cin >> n;
        
        vector< pii > tree;
        pii pt;

        rep(i, n)
        {   //.....Pi.........Hi......
            cin >> pt.first >> pt.second;
            tree.pb(pt);
        }
        
        if(n == 1)
        {
            cout << "Case #" << tc << ": " << tree[0].second << "\n";
            continue;
        }

        loi p, h;

        sort(all(tree), cmpr);

        loi res = -1 * lim, cur = -1 * lim;
        mii mp;

        /*
        0 -> no cut
        1 -> left cut
        2 -> right cut
        */

        rep(i, n)
        {
            p = tree[i].first;
            h = tree[i].second;
            
            cur = -1 * lim;

            if(mp.find(p - h) != mp.end())
             cur = max(cur, abs(p - (mp.find(p - h) -> second)));

            if(mp.find(p) != mp.end())
            cur = max(cur, abs(p - (mp.find(p) -> second)));

            if(mp.find(p) != mp.end())
            cur = max(cur, abs(p + h - (mp.find(p) -> second)));
            
            cur = max(cur, h);

            res = max(res, cur);

            cur = lim;

            if(mp.find(p - h) != mp.end())
            cur = min(cur, mp.find(p - h) -> second);

            if(mp.find(p) != mp.end())
            cur = min(cur, mp.find(p) -> second);

            if(cur == lim) cur = p - h;
            else cur = min(cur, p - h);
            
            loi xt = mp.find(p) == mp.end() ? p : mp.find(p) -> second;

            if(mp.find(p + h) == mp.end())
            mp.insert(mkp(p + h, xt));

            else if(mp.find(p + h) -> second > xt)
            mp.find(p + h) -> second = xt;

            if(mp.find(p) == mp.end())
            mp.insert(mkp(p, cur));

            else if(mp.find(p) -> second > cur)
            mp.find(p) -> second = cur;

        }

        cout << "Case #" << tc << ": " << res << "\n";
    }

    return 0;
}