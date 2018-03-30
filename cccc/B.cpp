#include <iostream>
using namespace std;

const int maxn = 105;

int f1[maxn];
int f2[maxn];
int rel[maxn][maxn];

int getf1(int a)
{
    return f1[a] == a ? a : f1[a] = getf1(f1[a]);
}
int getf2(int a)
{
    return f2[a] == a ? a : f2[a] = getf2(f2[a]);
}

void merge1(int a, int b)
{
    int fa = getf1(a);
    int fb = getf1(b);
    if(fa != fb)
        f1[fa] = fb;
}
void merge2(int a, int b)
{
    int fa = getf2(a);
    int fb = getf2(b);
    if(fa != fb)
        f2[fa] = fb;
}

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++)
        f1[i] = f2[i] = i;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        rel[a][b] = c;
        rel[b][a] = c;
        if(c == 1)
            merge1(a, b);
        else if(c == -1)
            merge2(a, b);
    }
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        bool x = getf1(a) == getf1(b);  //共同朋友
        bool y = getf2(a) == getf2(b);  //共同敌人
        if(rel[a][b] == 1) cout << "No problem" << endl; 
        else if(rel[a][b] == 0) cout << "OK" << endl; 
        else if(!x && rel[a][b] == -1) cout << "No way" << endl;
        else cout << "OK but..." << endl;
    }
}