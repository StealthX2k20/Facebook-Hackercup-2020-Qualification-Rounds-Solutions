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

loi n, m;
loi dist[1000010], cost[1000010];

set <loi> best;
unordered_map<loi, loi> freq;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    run;
    loi t;
    cin >> t;
    
    rep1(tc, t)
    {
        best.clear();
	freq.clear();

        cin >> n >> m;
        
        //loi dist[n], cost[n];
	rep(i, n + 1) dist[i] = -1;

	in(cost, n);
        
	if(n == m)
	{
	  cout << "Case #" << tc << ": 0\n";
	  continue;
	}

	loi cur = 0;
	rep(i, m + 1)
	{
          dist[i] = 0;
	  if(cost[i] and i)
           best.insert(cost[i]), freq[cost[i]]++;
	 }

        rep3(i, m + 1, n - 1)
	{
	   cur++;
	   if(best.size() == 0)
	     dist[i] = -1;

	   else dist[i] = *(best.begin());
		
	   if(cost[i] and dist[i] != -1)
	   {
              best.insert(dist[i] + cost[i]);
	      freq[(dist[i] + cost[i])]++;
	   }
            
	   if(cost[cur] and dist[cur] != -1)
	   {
		if(freq[(dist[cur] + cost[cur])] == 1)
		    best.erase(best.find(dist[cur] + cost[cur])), freq[(dist[cur] + cost[cur])]--;
		        
		else freq[(dist[cur] + cost[cur])]--;
	   }
         }

	 loi res = dist[n - 1];
	 cout << "Case #" << tc << ": " << res << "\n";

    }

    return 0;
}
