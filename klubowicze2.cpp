#include <iostream>
#include <vector>
using namespace std;
struct ab
{
    int a;
    int b;
};
void odej (vector <vector <int> > &pom)
{
    for (int x=0;x<2;++x)
    for (int i=0;i<pom[x].size();++i)
        if (pom[x][i]>0)
        pom[x][i]--;
}
int minim (vector <vector <int> > &pom)
{
    int mini=2000001;
    for (int x=0;x<2;++x)
    for (int i=0;i<pom[x].size();++i)
        if (pom[x][i]>0)
            if (pom[x][i]<mini)
        mini=pom[x][i];
    if (mini==2000001)
        return 0;
    return mini;
}
bool sgn (int n)
{
    if (n>0)
        return 1;
    else if (n==0)
        return 0;
    return -1;
}
void zamien (int n, vector <bool> &t)
{
    int j=0;
    while (n)
    {
        t[j]=n%2;
        n/=2;
        ++j;
    }
}
bool czy_dziala (vector <ab> &zer, vector <ab> &jed)
{
    for (int i=0;i<zer.size();++i)
        if (sgn(zer[i].a)!=sgn(zer[i].b)||sgn(jed[i].a)!=sgn(jed[i].b))
            return 0;
    return 1;
}
int n,m,x,_k=0;
unsigned long long wynik;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >>m;
   vector <bool> zapis_bin (n);
   vector < vector <bool > > t (m,zapis_bin);
   vector <int> z (n);
   vector <vector <int> > pom (2,z);
   vector <ab> zera (n);
   vector <ab> jeden (n);
   int sum_a=0,sum_b=0;
    for (int i=0;i<m;++i)
    {
        cin >> x;
        zamien(x,t[i]);
    }
    int p=0,k=0;
    for (int j=0;j<n;++j)
    {
        pom[t[0][j]][j]=1;
        if (t[0][j]==0)
            zera[j].a++;
        else
            jeden[j].a++;
    }
    for (int i=1;i<m;i++)
       {
           for (int j=0;j<n;++j)
           {
               if (t[i][j]==0)
                zera[j].b++;
            else
                jeden[j].b++;
           }
       }
       for (int j=0;j<n;++j)
    {
        sum_a+=sgn(zera[j].a);
         sum_a+=sgn(jeden[j].a);
         sum_b+=sgn(zera[j].b);
         sum_b+=sgn(jeden[j].b);
    }
       while (p<m)
       {
         if (czy_dziala(zera,jeden)==1)
           {
                wynik+=min(minim(pom),m-p);
            }
        if ((k+1)%m==p)
            {
                if (p+1==m)
                    break;
               for (int i=0;i<n;++i)
               {
                   if (t[p][i]==0)
                   {
                       zera[i].a--;
                       if (zera[i].a==0)
                        sum_a--;
                       if (zera[i].b==0)
                        sum_b++;
                       zera[i].b++;
                   }
                   else
                   {
                      jeden[i].a--;
                       if (jeden[i].a==0)
                        sum_a--;
                       if (jeden[i].b==0)
                        sum_b++;
                       jeden[i].b++;
                   }
               }
               odej(pom);
               p++;
               continue;
            }
           if (sum_a<=sum_b||p==k)
           {
               k++;
               _k++;
               k%=m;
               for (int i=0;i<n;++i)
               {
                   pom[t[k][i]][i]=_k-p+1;
                   if (t[k][i]==0)
                   {
                       zera[i].b--;
                       if (zera[i].b==0)
                        sum_b--;
                       if (zera[i].a==0)
                        sum_a++;
                       zera[i].a++;
                   }
                   else
                   {
                      jeden[i].b--;
                       if (jeden[i].b==0)
                        sum_b--;
                       if (jeden[i].a==0)
                        sum_a++;
                       jeden[i].a++;
                   }
               }
           }
           else
           {
                if (p+1==m)
                    break;
               for (int i=0;i<n;++i)
               {
                   if (t[p][i]==0)
                   {
                       zera[i].a--;
                       if (zera[i].a==0)
                        sum_a--;
                       if (zera[i].b==0)
                        sum_b++;
                       zera[i].b++;
                   }
                   else
                   {
                      jeden[i].a--;
                       if (jeden[i].a==0)
                        sum_a--;
                       if (jeden[i].b==0)
                        sum_b++;
                       jeden[i].b++;
                   }
               }
                odej(pom);
               p++;
           }
       }
       cout << wynik/2;
    return 0;
}