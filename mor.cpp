#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS (vector < vector <short> > &t, vector < short > &vis , int s)
{
    queue <int> que;
    que.push(s);
    if (t[s].empty())
    {
        vis[s]=-1;
        return;
    }

    while (!que.empty())
    {
        int x = que.front();
        que.pop();
        for (int i=0;i<t[x].size();++i)
            if (vis[t[x][i]]==-1)
            {
                vis[t[x][i]]=vis[x]+1;
                que.push(t[x][i]);
            }
    }
}
int n,m,k,a,b,x;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    vector < vector <short> > t (2*(n+1));
    vector < short > do_vis (2*(n+1),-1);
    vector < vector < short > > vis (n+1,do_vis);
    for (int i=0;i<m;++i)
    {
        cin >> a >> b;
        t[a].push_back(b+n);
        t[a+n].push_back(b);
        t[b].push_back(a+n);
        t[b+n].push_back(a);
    }
    for (int i=1;i<=n;++i)
        BFS (t,vis[i],i);
    for (int i=0;i<k;++i)
    {
        cin >>a >> b>>x;
        if (x%2==0)
        {
            if (vis[a][b]>x || vis[a][b]==-1)
                cout << "NIE\n";
            else
                cout << "TAK\n";
        }
        else
        {
            if (vis[a][b+n]>x || vis[a][b+n]==-1)
                cout << "NIE\n";
            else
                cout << "TAK\n";
        }

    }
    /* cout << endl;
    for (int j=1;j<=n;++j)
    {
        for (int i=1;i<=n;++i)
        cout << vis[j][i]<<" ";
    cout << endl;
    for (int i=1+n;i<=n*2;++i)
        cout << vis[j][i] << " ";
    cout << endl << endl;
    } */

    return 0;
}
/*
24 27 0
24 23
23 20
22 21
21 20
20 17
17 16
15 16
15 18
18 19
19 21
15 14
14 13
13 12
12 1
1 2
1 3
2 4
4 5
3 5
5 7
7 8
5 6
4 6
4 9
9 10
10 11
11 6
*/