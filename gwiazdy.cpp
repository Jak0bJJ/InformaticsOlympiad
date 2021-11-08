#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct lp
{
    int l;
    int r;
};
int n,s,best,done;
bool bul;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    vector <lp> t (n);
    vector <bool> d (n);
    vector <int> odp (1,s);
    for (int i=1;i<n;++i)
    {
        cin >> t[i].l >> t[i].r;
    }
    if (s==1)
    {
        d[1]=1;
        done=2;
    }
    else if (s==n)
    {
        done=2;
    }
    else if (t[1].l==t[1].r)
    {
        if (t[2].l>t[2].r)
            d[2]=1;
        else
            d[1]=1;
        done=3;
    }
    else if (t[1].l>t[1].r)
    {
        best=1;
        int j=2;
        while (s+j<=n&&t[j].l>t[j].r)
        {
            if (t[j].l-t[j].r<t[best].l-t[best].r)
                best=j;
            ++j;
        }
        if (s+j>n)
        {
        for (int i=1;i<j;++i)
                d[i]=1;
        done=j;
        if (t[j].l-t[j].r<t[best].l-t[best].r)
        {
            best=j;
            done++;
        }
        d[best]=0;
       // cout << j << " " << best << endl;
        }
        else
        {
            for (int i=1;i<j;++i)
                d[i]=1;
            d[j]=0;
            done=j+1;
        }
    }
    else if (t[1].l<t[1].r)
    {
        best=1;
        int j=2;
        while (s-j>0&&t[j].l<t[j].r)
        {
            if (t[j].r-t[j].l<t[best].r-t[best].l)
                best=j;
            ++j;
        }
        if (s-j==0)
        {
        done=j;
        if (t[j].r-t[j].l<t[best].r-t[best].l)
        {
            best=j;
            done++;
        }
        d[best]=1;
        }
        else
        {
            d[j]=1;
            done=j+1;
        }
    }
    for (int i=done;i<n;++i)
    {
        if (t[i].l>t[i].r)
            d[i]=1;
    }
    int p=1, k=n, pom=0;
    stack <int> stak;
    for (int i=1;i<n;++i)
    {
        if (s==p)
            p++;
        if (s==k)
            k--;
        bool bul=d[i];
        pom=1;
        while (i+1<n&&d[i]==d[i+1])
        {
            pom++;
            ++i;
        }
        if (bul==1)
        {
            while (stak.size()!=pom)
            {
                if (k!=s)
                    stak.push(k);
                --k;
            }
            while (!stak.empty())
            {
                odp.push_back(stak.top());
                stak.pop();
            }
        }
        else
        {
            while (stak.size()!=pom)
            {
                if (p!=s)
                    stak.push(p);
                ++p;
            }
            while (!stak.empty())
            {
                odp.push_back(stak.top());
                stak.pop();
            }
        }
    }
    long long wynik=0;
    for (int i=1;i<n;++i)
    {
        if (d[i]==1)
            wynik+=t[i].r;
        else
            wynik+=t[i].l;
    }
    cout << wynik << "\n";
    for (int i=0;i<odp.size();++i)
        cout << odp[i] << " ";
    return 0;
}