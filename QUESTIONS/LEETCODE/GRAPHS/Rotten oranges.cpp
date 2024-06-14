// Date: 14-06-2024
// Start Time: 21:20:50
// End Time  : 21:52:00
// Time Taken: 32 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https : // leetcode.com/problems/rotting-oranges/description/
// Rating: Easy
// Description: Find the largest distance of a cell from mulitple sources
// Solved: Yes
// Learning: Nothing

#define endl '\n'
queue<pair<int, int>> q;
vector<vector<int>> dist;
int dirx[] = {1, 0, -1, 0};
int diry[] = {0, 1, 0, -1};
int n, m;

bool check(int x, int y, vector<vector<int>> &g)
{
    return (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != 0);
}

void bfs(vector<vector<int>> &g)
{
    while (!q.empty())
    {
        auto [x, y] = q.front();
        // cout<<x<<" "<<y<<"->"<<dist[x][y+1]<<endl;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (check(x + dirx[i], y + diry[i], g))
            {
                // i the cell is reachable
                if (dist[x + dirx[i]][y + diry[i]] > dist[x][y] + 1)
                {
                    dist[x + dirx[i]][y + diry[i]] = dist[x][y] + 1;
                    q.push({x + dirx[i], y + diry[i]});
                }
            }
        }
    }
}

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &g)
    {
        // run a multisource bfs and keep marking the oranges that rot to 2
        n = g.size();
        m = g[0].size();

        dist.clear();
        dist.resize(n, vector<int>(m, 1e9));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 2)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        bfs(g);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] != 0)
                {
                    if (dist[i][j] == 1e9)
                    {
                        return -1;
                    }
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        return max(ans, 0);
    }
};