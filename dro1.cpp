#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
bool edit=0; //polecam tak robic na wszystkie dodatkowe couty jesli nie robisz
stack <int> stak;
void DFS (vector < vector <int> > &g,vector <int> &vis,int s) //pierwszy DFS ktory robi post-order do SSS (ze stackiem fajnie sie robi)
{
    vis[s]=1;
    for (int i=0;i<g[s].size();++i)
        if (vis[g[s][i]]==0)
            DFS(g,vis,g[s][i]);
    stak.push(s);
}
void SSS (vector < vector <int> > &g,vector <int> &vis,vector < vector <int> > &sss, int s) //drugi DFS bo wole tak niz w jednym pakowac ify
{
    vis[s]=1;
    sss.back().push_back(s); //wrzucasz do aktualnej spojnej
    for (int i=0;i<g[s].size();++i)
        if (vis[g[s][i]]==0)
            SSS(g,vis,sss,g[s][i]);
}
int n,m,a,b;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    vector < vector <int> > g (n+1); //graf
    vector < vector <int> > t (n+1); //transponowany
    vector < vector <int> > sss;    // tu beda spojne
    vector <int> w; //to jest potrzebne zeby powiekszac vector
    for (int i=0;i<m;++i)
        {
            cin >> a >> b;
            g[a].push_back(b);
            t[b].push_back(a);
        }
    vector <int> vis (n+1); //visited
    for (int i=1;i<=n;++i) //pierwszy DFS
        if (vis[i]==0)
            DFS(g,vis,i);
    for (int i=1;i<=n;++i)
        vis[i]=0;
    while (!stak.empty()) //drugi DFS
    {
        if (vis[stak.top()]==0)
        {
            sss.push_back(w); //dodajemy nowa spojna
            SSS(t,vis,sss,stak.top()); //DFS znajdzie wszystkie punkty w tej spojnej
        }
        stak.pop();
    }
    if (edit)
    {
    for (int i=0;i<sss.size();++i)
    {
        cout << endl;
        for (int j=0;j<sss[i].size();++j)
            cout << sss[i][j] << " ";
    }
    cout << endl;
    }
    //tu zaczyna sie robienie dagu koncza sie spojne xD
    vector <int> do_ktorej (n+1); //pomocniczy vector mowiacy dla danego punktu w ktorej spojnej sie znajduje
    for (int i=0;i<sss.size();++i)
    {
        for (int j=0;j<sss[i].size();++j)
            do_ktorej[sss[i][j]]=i; //wypelniamy go
    }
    int k= sss.size();
    vector < vector <int> > dag (k); //tu mamy nasza nowa liste sasiadow
    vector < vector <int> > trans (k); //nawet to kurwa potrzebuje
    vector <int> pom (k); //a tu mam stopien wejscia (mozna tez zrobic transponowany ale nie potrzebuje)
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<g[i].size();++j)
            if (do_ktorej[i]!=do_ktorej[g[i][j]]) //jesli droga nie prowadzi do tej samej spojnej to przepisujemy ja
            {
                dag[do_ktorej[i]].push_back(do_ktorej[g[i][j]]); //ze spojnej do ktorej nalezy i do spojnej do ktorej nalezy jego sasiad
                trans[do_ktorej[g[i][j]]].push_back(do_ktorej[i]);
                pom[do_ktorej[g[i][j]]]++; //stopien wejscia tego sasiada zwiekszam
            }
    }
    if (edit)
    {
    for (int i=0;i<dag.size();++i)
    {
        cout << endl << i <<":  ";
        for (int j=0;j<dag[i].size();++j)
            cout << dag[i][j] << " ";
        cout << endl;
    }
    }
    //po 80 linijkach zaczynamy zadanko <3
    queue <int> que;
    vector <int> topo;
    for (int i=0;i<k;++i)
        if (pom[i]==0)
            que.push(i);
    while (!que.empty())
    {
        int x=que.front();
        que.pop();
        topo.push_back(x);
        for (int i=0;i<dag[x].size();++i)
        {
            pom[dag[x][i]]--;
            if (pom[dag[x][i]]==0)
                que.push(dag[x][i]);
        }
    }
    if (edit)
    for (int i=0;i<k;++i)
    {
        cout << topo[i] << " ";
    }
    vector <int> p (k);
    for (int i=0;i<k;++i)
        p[topo[i]]=i;
    vector <int> r (k,k);
    for (int i=0;i<k;++i)
    {
        for (int j=0;j<dag[i].size();++j)
        {
            if (p[dag[i][j]]<r[i])
                r[i]=p[dag[i][j]];
        }

    }
    if (edit)
    {
        cout << endl;
         for (int i=0;i<k;++i)
            cout << r[i]<< " ";
           cout << endl;
    }

    vector <int> odp (k,1);
    int low=1;
    for (int i=0;i<k;++i)
    {
        low=max(low,i+1);
        for (int j=low;j<r[i];++j)
            odp[j]=0;
        if (low<r[i])
        low=r[i];
    }
    for (int i=0;i<k;++i)
        r[i]=-1;
    for (int i=k-1;i>=0;--i)
    {
        for (int j=0;j<trans[i].size();++j)
        {
            if (p[trans[i][j]]>r[i])
                r[i]=p[trans[i][j]];
        }
    }
    low=k-2;
    for (int i=k-1;i>=0;--i)
    {
        low=min(low,i-1);
        for (int j=low;j>r[i];--j)
            odp[j]=0;
        if (low>r[i])
        low=r[i];
    }
      if (edit)
    {
        cout << endl;
         for (int i=0;i<k;++i)
            cout << r[i]<< " ";
           cout << endl;
    }
    vector <int> wynik;
    for (int i=0;i<k;++i)
    {
        if (odp[i]==1)
            for (int j=0;j<sss[i].size();++j)
                wynik.push_back(sss[i][j]);
    }
    sort(wynik.begin(),wynik.end());
    cout << wynik.size() << endl;
    for (int i=0;i<wynik.size();++i)
        cout << wynik[i] << " ";
    return 0;
}
/*
9 10
1 2
2 3
3 1
4 5
5 6
6 7
7 8
8 4
1 9
9 6
*/