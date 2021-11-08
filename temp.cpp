#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct point
{
    int l;
    int h;
};
struct do_que
{
    int val;
    int ile;
};
int n,wyn,akt;
do_que x;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector <point> t (n);
    deque <do_que> que;
    for (int i=0;i<n;++i)
        cin >> t[i].l >> t[i].h;
        que.push_back({t[0].l,1});
            akt=1;
    for (int i=1;i<n;++i)
    {
            if (t[i].h>=que.front().val)
            {
                if (t[i].l<que.back().val)
                    {
                        que.push_back({t[i].l,1});
                        ++akt;
                    }

                else
                {
                    x.val=t[i].l;
                    x.ile=1;
                    ++akt;
                    while (!que.empty()&&que.back().val<=x.val)
                    {
                        x.ile+=que.back().ile;
                        que.pop_back();
                    }
                que.push_back(x);
                }
            }
            else
            {
                if (akt>wyn)
                    wyn=akt;
                while (!que.empty()&&que.front().val>t[i].h)
                {
                    akt-=que.front().ile;
                    que.pop_front();
                }
                if (que.empty())
                {
                    que.push_back({t[i].l,1});
                    akt++;
                }
                else
                {
                    --i;
                }
            }

    }
if (akt>wyn)
    wyn=akt;
    cout << wyn;
    return 0;
}