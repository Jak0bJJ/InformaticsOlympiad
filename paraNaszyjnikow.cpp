#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int pom, pompon,t;
vector <int> odp;
bool cmp (const int &a, const int &b)
{
    return a>b;
}
void ok (vector <bool> x,int l)
{
    vector <int> p (x.size());
    p[0]=-1; t=-1;
    int n = x.size()-1;
    for (int i=1;i<=n;++i)
    {
        while (t>=0&&x[t+1]!=x[i])
            t=p[t];
        t++;
        p[i]=t;
    }
    pom=n-p[n];
    for (int i=pom;i<=n;i+=pom)
    {
        odp.push_back(i+l);
    }
    if (p[n]>0)
    {
    pompon = min (p[n],n%pom+pom);
    while (x.size()!=pompon+1)
    {
        x.pop_back();
    }
    ok(x,l+n-pompon);
    }
}
int q,n,m,x,s,suma;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    for (int qq=0;qq<q;++qq)
    {
        cin >> n >> m;
        vector <bool> tn (1);
        vector <bool> tm (1);
        vector <bool> w_n (n+1,1);
        vector <bool> w_m (m+1,1);
        vector <int> p (n+1);
        vector <int> pom (m+1);
        vector <vector <bool> > wynik_n (2,w_n);
        vector <vector <bool> > wynik_m (2,w_m);
        for (int i=1;i<=n;++i)
        {
            cin >> x;
            tn.push_back(x%2);
        }
        odp.clear();
        ok(tn,0);
        suma=0;
        sort(odp.begin(),odp.end(),cmp);
        for (int i=1;i<=n;++i)
        {
            if (odp.size()==0)
                break;
            suma+=tn[i];
            if (i==odp.back())
            {
                wynik_n[suma%2][i]=0;
                while (odp.back()<=i)
                    odp.pop_back();
            }
        }
        for (int i=1;i<=m;++i)
        {
            cin>>x;
            tm.push_back(x%2);
        }
        odp.clear();
        ok(tm,0);
        suma=0;
        sort(odp.begin(),odp.end(),cmp);
        for (int i=1;i<=m;++i)
        {
            if (odp.size()==0)
                break;
            suma+=tm[i];
            if (i==odp.back())
            {
                wynik_m[suma%2][i]=0;
                while (odp.back()<=i)
                    odp.pop_back();
            }
        }
        for (int i=min(n,m);i>=0;--i)
        {
            if (wynik_n[0][i]==1&&wynik_m[0][i]==1) {cout << i << "\n"; break;}
             if (wynik_n[1][i]==1&&wynik_m[1][i]==1) {cout << i << "\n"; break;}
        }
    }
    return 0;
}