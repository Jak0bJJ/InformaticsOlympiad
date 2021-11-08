//Jakub Jakubowski
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
    int x;
    int y;
};


short get_quadrant (point p)
{
    if (p.x > 0 && p.y > 0)
        return 1;
    else if (p.x == 0 && p.y > 0)
        return 2;
    else if(p.x < 0 && p.y > 0)
        return 3;
    else if (p.x < 0 && p.y == 0)
        return 4;
    else if(p.x < 0 && p.y < 0)
        return 5;
    else if (p.x == 0 && p.y < 0)
        return 6;
    else if (p.x > 0 && p.y < 0)
        return 7;
    else
        return 0;
}

bool comp (point A, point B)
{
    short q_A = get_quadrant(A);
    short q_B = get_quadrant(B);

    if (q_A != q_B)
        return (q_A < q_B);
    if (A.y*B.x != B.y*A.x)
        return (A.y*B.x < B.y*A.x);
    else
        return (A.x*A.x + A.y*A.y < B.x*B.x + B.y*B.y);

}
long long naj,akt;
int i,n,j;
int main()
{
    vector <long long> wsp(2,0);
    cin >> n;
    vector <point> punkt(n);
    for (int i=0; i<n; ++i)
        {cin >> punkt[i].x >> punkt[i].y;
        if (punkt[i].x==0&&punkt[i].y==0)
        {
            --n;
            --i;
            punkt.pop_back();
        }
        }
    sort(punkt.begin(),punkt.end(),comp);
        wsp[0]=punkt[0].x;
        wsp[1]=punkt[0].y;
        naj = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);
        i=1;
    while (i<n)
    {
       if((((wsp[0]-punkt[j].x)*(wsp[0]-punkt[j].x))+((wsp[1]-punkt[j].y)*(wsp[1]-punkt[j].y)))>(((wsp[0]+punkt[i].x)*(wsp[0]+punkt[i].x))+((wsp[1]+punkt[i].y)*(wsp[1]+punkt[i].y)))&&j<n)
        {
            wsp[0]-=punkt[j].x;
            wsp[1]-=punkt[j].y;
            ++j;
        akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);
            if (akt>naj)
                naj=akt;
        }
        else
        {
            wsp[0]+=punkt[i].x;
            wsp[1]+=punkt[i].y;
            ++i;
      /*     if (((wsp[0]*wsp[0])+(wsp[1]*wsp[1]))<(punkt[i].x*punkt[i].x)+(punkt[i].y*punkt[i].y))
            {
                wsp[0]=punkt[i].x;
                wsp[1]=punkt[i].y;
            } */
            akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);
            if (akt>naj)
                naj=akt;

        }
    }
    i=0;
    while (j<n)
       {
           if (i>=j)
           {
              wsp[0]-=punkt[j].x;
            wsp[1]-=punkt[j].y;
            ++j;
            akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);

            if (akt>naj)
                naj=akt;
           }
          if((((wsp[0]-punkt[j].x)*(wsp[0]-punkt[j].x))+((wsp[1]-punkt[j].y)*(wsp[1]-punkt[j].y)))>(((wsp[0]+punkt[i].x)*(wsp[0]+punkt[i].x))+((wsp[1]+punkt[i].y)*(wsp[1]+punkt[i].y)))&&j<n)
        {
            wsp[0]-=punkt[j].x;
            wsp[1]-=punkt[j].y;
            ++j;
            akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);

            if (akt>naj)
                naj=akt;

        }
        else
        {
            wsp[0]+=punkt[i].x;
            wsp[1]+=punkt[i].y;
         /*  if (((wsp[0]*wsp[0])+(wsp[1]*wsp[1]))<(punkt[i].x*punkt[i].x)+(punkt[i].y*punkt[i].y))
            {
                wsp[0]=punkt[i].x;
                wsp[1]=punkt[i].y;
            } */
            akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);

            if (akt>naj)
                naj=akt;
                ++i;
        }
       }
 //*
 wsp[0]=punkt[n-1].x;
    wsp[1]=punkt[n-1].y;
       j=n-1;
       i=n-2;
     while(i>=0)
    {
        if((((wsp[0]-punkt[j].x)*(wsp[0]-punkt[j].x))+((wsp[1]-punkt[j].y)*(wsp[1]-punkt[j].y)))>(((wsp[0]+punkt[i].x)*(wsp[0]+punkt[i].x))+((wsp[1]+punkt[i].y)*(wsp[1]+punkt[i].y)))&&j>=0)
        {
            wsp[0]-=punkt[j].x;
            wsp[1]-=punkt[j].y;
            --j;
        akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);
            if (akt>naj)
                naj=akt;
        }
        else
        {
            wsp[0]+=punkt[i].x;
            wsp[1]+=punkt[i].y;
            --i;
            akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);
            if (akt>naj)
                naj=akt;

        }
    }

    i=n-1;

    while (j>=0)
       {
           if (i<=j)
           {
              wsp[0]-=punkt[j].x;
            wsp[1]-=punkt[j].y;
            --j;
           akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);

            if (akt>naj)
                naj=akt;
           }
          if((((wsp[0]-punkt[j].x)*(wsp[0]-punkt[j].x))+((wsp[1]-punkt[j].y)*(wsp[1]-punkt[j].y)))>(((wsp[0]+punkt[i].x)*(wsp[0]+punkt[i].x))+((wsp[1]+punkt[i].y)*(wsp[1]+punkt[i].y)))&&j>=0)
        {
            wsp[0]-=punkt[j].x;
            wsp[1]-=punkt[j].y;
            --j;
            akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);

            if (akt>naj)
                naj=akt;

        }
        else
        {
            wsp[0]+=punkt[i].x;
            wsp[1]+=punkt[i].y;
            --i;
            akt = (wsp[0]*wsp[0])+(wsp[1]*wsp[1]);

            if (akt>naj)
                naj=akt;
        }
       }//*/
    cout <<naj;
    return 0;
}
