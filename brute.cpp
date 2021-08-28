//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
		return c!=EOF;
	}
}_buff;
ll getnum()
{
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}

set<int> v;
void Insert(int x)
{
    v.insert(x);
}
int Query(int l, int r)
{
    int cnt = 0;
    for (auto x : v) cnt += l<=x&&x<r;
    return cnt;
}
int n;
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
	{
        char s[10];
        int x, y;
        scanf("%s%d%d", s, &x, &y);
		if (s[0]=='i')
		{
			Insert(x);
			//debug(root);
			//puts("");
		}
		else
		{
			putnum(Query(x, y));
			putchar('\n');
		}
	}
	return 0;
}