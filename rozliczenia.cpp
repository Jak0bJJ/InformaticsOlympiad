#include <iostream>
#include <vector>
using namespace std;
const int p = 20;
vector <long long> Tree (1<<p);
int M = 1 << (p-1);
int n,kon;
void Input (int s, int val)
{
    s+=M;
    Tree[s]=val;
    s/=2;
    while (s)
    {
        Tree[s]=Tree[s*2]+Tree[s*2+1];
        s/=2;
    }
}
void Apply (int s, int val)
{
    s+=M;
    Tree[s]+=val;
    s/=2;
    while (s)
    {
        Tree[s]=Tree[s*2]+Tree[s*2+1];
        s/=2;
    }
}
long long Get (int a, int b)
{
    a+=M;
    b+=M;
    long long Ans = Tree[a];
    if (a!=b)
        Ans += Tree[b];
    while (a/2!=b/2)
    {
        if (a%2==0) Ans+=Tree[a+1];
        if (b%2==1) Ans+=Tree[b-1];
        a/=2;
        b/=2;
    }
    return Ans;
}
void inicjuj (int m)
{
    n=m;
    kon=0;
}
void dodaj (int k)
{
    Input(kon,k);
    kon++;
    kon%=n;
}
void koryguj (int i, int k)
{
    if (kon>=i)
        Apply(kon-i,k);
    else
    {
        i-=kon;
        Apply(n-i,k);
    }
}
long long suma (int i)
{
    int a,b;
    if (kon>=i)
    {
        a=kon-i;
        b=kon-1;
        return Get(a,b);
    }
    else
    {
        long long Ans=0;
        if (kon!=0)
        {
            a=0;
            b=kon-1;
            Ans=Get(a,b);
            i-=kon;
        }
        a=n-i;
        b=n-1;
        Ans+=Get(a,b);
        return Ans;
    }
}
/*int main()
{
    int m;
    cin >> m;
    inicjuj(m);
    int x,a,b;
    while (1)
    {
        cin >> x;
        if (x==1)
        {
            cin >> a;
            dodaj(a);

        }
        else if (x==2)
        {

            cin >> a >> b;
            koryguj(a,b);
        }
        else
        {

            cin >> a;
            cout << suma(a) << endl;
        }
    }
    return 0;
} */