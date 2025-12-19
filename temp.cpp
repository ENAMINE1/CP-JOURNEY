// Date: 13-12-2025
// Start Time: 18:14:02
// End Time  : 18:36:52
// Time Taken: 22 minutes
// Author: Shashwat Kumar
// QUESTION LINK:
// Rating:
// Description:
// Solved:
// Learning:

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/print.h"
#include "./lib/debug.h"
#else
#define debug(...) 42
#endif
#define endl '\n'
/***************************************************Main Function**************************************************/

/*
    a - z - warp cell
    . - empty cell
    # - obstacle
    dfs in 4 directions but with extra edges
*/
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<pair<int, int>>> warp(26);
vector<vector<int>> vis;

bool check(int x, int y, vector<vector<char>> &v)
{
    return x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#' && vis[x][y] == -1;
}

bool dfs(vector<vector<char>> &v, int row, int col)
{
    if (row == n - 1 && col == m - 1)
        return true;
    debug(row, col);
    vis[row][col] = 1;
    bool ans = false;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (check(nrow, ncol, v))
        {
            ans |= dfs(v, nrow, ncol);
            if (ans)
                return true;
        }
    }
    if (v[row][col] >= 'a' && v[row][col] <= 'z')
    {
        // warping
        int idx = v[row][col] - 'a';
        for (int i = 0; i < warp[idx].size(); i++)
        {
            pair<int, int> neigh = warp[idx][i];
            if (vis[neigh.first][neigh.second] == -1)
            {
                ans |= dfs(v, neigh.first, neigh.second);
            }
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vis.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] >= 'a' && v[i][j] <= 'z')
                warp[v[i][j] - 'a'].push_back({i, j});
        }
    }
    if (dfs(v, 0, 0))
        cout << 1;
    else
        cout << -1;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
#ifdef LOCAL
        std::cerr << "Case # " << i << endl;
        std::cout << "Case #" << i << endl;
#endif
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int x,y,step;
}NODE,*PNODE;
vector<pair<int,int> > vec[26];
queue<NODE> q;
char a[1005][1005];
int dx[]={0,-1,0,1,0};
int dy[]={0,0,1,0,-1};
int dist[1005][1005];
int n,m;
int flag[1000005];
void bfs()
{
	dist[1][1]=0;
	q.push(NODE{1,1,0});
	int i,tx,ty;
	NODE tmp;
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		for(i=1;i<=4;i++)
		{
			tx=tmp.x+dx[i];
			ty=tmp.y+dy[i];
			if(tx<1||tx>n||ty<1||ty>m||dist[tx][ty]!=-1||a[tx][ty]=='#')
			{
				continue;
			}
			dist[tx][ty]=dist[tmp.x][tmp.y]+1;
			q.push(NODE{tx,ty,dist[tx][ty]});
		}
		if(a[tmp.x][tmp.y]>='a'&&a[tmp.x][tmp.y]<='z'&&flag[a[tmp.x][tmp.y]-'a']==0)
		{
			flag[a[tmp.x][tmp.y]-'a']=1;
			for(i=0;i<vec[a[tmp.x][tmp.y]-'a'].size();i++)
			{
				tx=vec[a[tmp.x][tmp.y]-'a'][i].first;
				ty=vec[a[tmp.x][tmp.y]-'a'][i].second;
				if(dist[tx][ty]!=-1)
				{
					continue;
				}
				dist[tx][ty]=dist[tmp.x][tmp.y]+1;
				q.push(NODE{tx,ty,dist[tx][ty]});
			}
		}
	}
}
int main()
{
	scanf("%d %d\n",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
		for(j=1;j<=m;j++)
		{
			if(a[i][j]>='a'&&a[i][j]<='z')
			{
				vec[a[i][j]-'a'].push_back(make_pair(i,j));
			}
		}
	}
	memset(dist,0xff,sizeof(dist));
	bfs();
	printf("%d",dist[n][m]);
	return 0;
}
