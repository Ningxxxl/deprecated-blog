#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 505;
const int INF = 0x3f3f3f3f;

struct node
{
    int v, len, cost;

    node(int v = 0, int len = 0, int cost = 0) : v(v), len(len), cost(cost) {}

    bool operator<(const node &a) const
    {
        if (len > a.len)
            return 1;
        else if (len == a.len && cost < a.cost)
            return 1;
        return 0;
    }
};

vector<node> G[maxn];

bool vis[maxn];
int dis[maxn];
int val[maxn];
int co[maxn];
int pre[maxn];
int pathnum[maxn];

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        G[i].clear();
        vis[i] = false;
        val[i] = INF;
        dis[i] = INF;
        pre[i] = i;
        pathnum[i] = 1;
    }
}

void dijkstra(int s, int e)
{
    priority_queue<node> q;
    q.push(node(s, 0, 0));
    dis[s] = 0;
    val[s] = 0;
    while (!q.empty())
    {
        node now = q.top();
        q.pop();
        int v = now.v;
        if (vis[v])
            continue;
        vis[v] = true;
        for (int i = 0; i < G[v].size(); i++)
        {
            int vt = G[v][i].v;
            int len = G[v][i].len;
            int cost = G[v][i].cost;
            if (!vis[vt] && dis[vt] >= dis[v] + len)
            {
                if (dis[vt] > dis[v] + len)
                    pathnum[vt] = pathnum[v];
                else if (dis[vt] == dis[v] + len)
                    pathnum[vt] += pathnum[v];
                if (dis[vt] > dis[v] + len || (dis[vt] == dis[v] + len && val[vt] < val[v] + cost))
                {
                    dis[vt] = dis[v] + len;
                    val[vt] = val[v] + cost;
                    pre[vt] = v;
                    q.push(node(vt, dis[vt], val[vt]));
                }
            }
        }
    }
    val[e] += co[e];
    cout << pathnum[e] << " " << val[e] << endl;
}

void print(int x, int s)
{
    if (x == s)
        return;
    print(pre[x], s);
    cout << " " << x;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++)
        cin >> co[i];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(node(b, c, co[a]));
        G[b].push_back(node(a, c, co[b]));
    }
    dijkstra(s, d);
    cout << s;
    print(d, s);
    cout << endl;
}