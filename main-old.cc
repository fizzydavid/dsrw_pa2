//by yjz
#include<bits/stdc++.h>
#include <immintrin.h>

using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
//My i/o stream
struct fastio
{
	char s[1000000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 1000000, stdin);
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


typedef unsigned int u32;
void bucket_sort(int *_a, int n)
{
	
    // sort(a, n);
    int cnt0[256] = {};
    int cnt1[256] = {};
    int cnt2[256] = {};
    int cnt3[256] = {};
    
	u32 *a = new u32[n];
    u32 *b = new u32[n];
    
    int *_a_end = _a+n;
	u32 *a_end = a+n;
	u32 *x;
	int *y;

	for (x=a, y=_a; x!=a_end; x++, y++)
    {
		*x = *y^(1<<31);
        cnt0[(*x) & 255] ++;
        cnt1[((*x)>>8) & 255] ++;
        cnt2[((*x)>>16) & 255] ++;
        cnt3[((*x)>>24) & 255] ++;
    }
    for (int i=1; i<256; i++)
    {
        cnt0[i] += cnt0[i-1];
        cnt1[i] += cnt1[i-1];
        cnt2[i] += cnt2[i-1];
        cnt3[i] += cnt3[i-1];
    }
    u32 *a_last = a+n-1, *b_last = b+n-1;
	u32 *a_threshold = a+8, *b_threshold = b+8; 
    for (x=a_last; x>=a_threshold; x-=8)
    {
        b[--cnt0[(*x) &255]] = *x;
        b[--cnt0[(*(x-1)) &255]] = *(x-1);
        b[--cnt0[(*(x-2)) &255]] = *(x-2);
        b[--cnt0[(*(x-3)) &255]] = *(x-3);
        b[--cnt0[(*(x-4)) &255]] = *(x-4);
        b[--cnt0[(*(x-5)) &255]] = *(x-5);
        b[--cnt0[(*(x-6)) &255]] = *(x-6);
        b[--cnt0[(*(x-7)) &255]] = *(x-7);
    }
	for (; x>=a; x--) b[--cnt0[(*x) &255]] = *x;

    for (x=b_last; x>=b_threshold; x-=8)
    {
        a[--cnt1[(*x)>>8 &255]] = *x;
        a[--cnt1[(*(x-1))>>8 &255]] = *(x-1);
        a[--cnt1[(*(x-2))>>8 &255]] = *(x-2);
        a[--cnt1[(*(x-3))>>8 &255]] = *(x-3);
        a[--cnt1[(*(x-4))>>8 &255]] = *(x-4);
        a[--cnt1[(*(x-5))>>8 &255]] = *(x-5);
        a[--cnt1[(*(x-6))>>8 &255]] = *(x-6);
        a[--cnt1[(*(x-7))>>8 &255]] = *(x-7);
    }
    for (; x>=b; x--) a[--cnt1[(*x)>>8 &255]] = *x;
	
	for (x=a_last; x>=a_threshold; x-=8)
    {
        b[--cnt2[(*x)>>16 &255]] = *x;
        b[--cnt2[(*(x-1))>>16 &255]] = *(x-1);
        b[--cnt2[(*(x-2))>>16 &255]] = *(x-2);
        b[--cnt2[(*(x-3))>>16 &255]] = *(x-3);
        b[--cnt2[(*(x-4))>>16 &255]] = *(x-4);
        b[--cnt2[(*(x-5))>>16 &255]] = *(x-5);
        b[--cnt2[(*(x-6))>>16 &255]] = *(x-6);
        b[--cnt2[(*(x-7))>>16 &255]] = *(x-7);
    }
	for (; x>=a; x--) b[--cnt2[(*x)>>16 &255]] = *x;

    for (x=b_last; x>=b_threshold; x-=8)
    {
        a[--cnt3[(*x)>>24 &255]] = *x;
        a[--cnt3[(*(x-1))>>24 &255]] = *(x-1);
        a[--cnt3[(*(x-2))>>24 &255]] = *(x-2);
        a[--cnt3[(*(x-3))>>24 &255]] = *(x-3);
        a[--cnt3[(*(x-4))>>24 &255]] = *(x-4);
        a[--cnt3[(*(x-5))>>24 &255]] = *(x-5);
        a[--cnt3[(*(x-6))>>24 &255]] = *(x-6);
        a[--cnt3[(*(x-7))>>24 &255]] = *(x-7);
    }
	for (; x>=b; x--) a[--cnt3[(*x)>>24 &255]] = *x;
	
	
	for (x=a, y=_a; x!=a_end; x++, y++)
    {
		*y = *x^(1<<31);
	}
	delete[] a;
	delete[] b;
}

int my_sort(int a[], int n)
{
	bucket_sort(a, n);
	return unique(a, a+n)-a;
}


const int M = 48; //maximum size for node
const int MAX_KEY_NUM = 27654321;
const int NODE_NUM = (MAX_KEY_NUM/M)*2;

const int INF = 2147483647;
const int MINF = -2147483648;

int counter;

class BTree
{
private:
	//null pointer has id 0
	class Node  //BTree node
	{
	public:
		bool is_leaf;
		short sz; //the size of the node
		int k[M], p[M+1];  //key and pointer
		int sum, cnt[M+1];
		
		Node()
		{
			is_leaf = false;
			sum = sz = 0;
		}
		void init_root(const int &lp, const int &lp_sum, const int &key, const int &rp, const int &rp_sum)
		{
			p[0] = lp;
			cnt[0] = lp_sum;
			k[0] = key;
			p[1] = rp;
			cnt[1] = rp_sum;
			sz = 1;
			sum = lp_sum+rp_sum;	
		}
		void insert_key(const int &key)
		{
			int i;
			for (i=sz-1; i>=0; i--)
			{
				if (k[i]>=key) k[i+1] = k[i];
				else break;
			}
			k[i+1] = key;
			sz++, sum++;
		}
		void insert_key(const int &key, const int &pos)
		{
			for (int i=sz-1; i>=pos; i--)
			{
				k[i+1] = k[i];
			}
			k[pos] = key;
			sz++, sum++;
		}
		void init_and_insert_key(int k_from[], const int &key, const int &pos)
		{
			memcpy(k, k_from, pos<<2);
			k[pos] = key;
			memcpy(k+pos+1, k_from+pos, (sz-pos)<<2);
			sz++, sum++;
		}
		void insert_split(const int &pos, const int &key, const int &pt, const int &pt_sum)
		{
			for (int i=sz; i>pos; i--)
			{
				k[i] = k[i-1];
				p[i+1] = p[i];
				cnt[i+1] = cnt[i];
			}
			k[pos] = key, p[pos+1] = pt;
			cnt[pos] -= pt_sum, cnt[pos+1] = pt_sum;
			sz++;
		}
		
		bool is_full() const {return sz==M;}
		int find_pos(const int &key) const
		{
			const int *it, *end = k+sz;
			for (it=k; it!=end && (*it)<key; ++it);
			return it-k;
		}
		int find_pos_from(const int &key, int pos) const   //to be deleted
		{
			const int *it, *end = k+sz;
			for (it=k+pos; it!=end && (*it)<key; ++it);
			return it-k;
		}
		int get_cntsum(const int &l, const int &r) const
		{
			int ret = 0;
			for (int i=l; i<=r; i++) ret += cnt[i];
			return ret;
		}
	}a[NODE_NUM];

	int root;  //the root id
	int tot;   //total number of nodes

	int sp_key;
	void split_inner(int x)
	{
		int y = ++tot;
		int val = a[x].k[M>>1];
		a[x].sz = M>>1;
		a[y].sz = (M>>1)-1;
		memcpy(a[y].k, a[x].k+(M>>1)+1, (a[y].sz)<<2);
		memcpy(a[y].p, a[x].p+(M>>1)+1, (a[y].sz+1)<<2);
		memcpy(a[y].cnt, a[x].cnt+(M>>1)+1, (a[y].sz+1)<<2);
		int sum = a[x].get_cntsum((M>>1)+1, M);
		a[x].sum -= sum;
		a[y].sum = sum;
		sp_key = val;
	}
	void split_leaf(int x, int key, int pos)
	{	
		int y = ++tot;
		int mid_key = a[x].k[M>>1];
		a[y].is_leaf = true;
		if (key<mid_key)
		{
			a[y].sz = a[y].sum = M>>1;
			memcpy(a[y].k, a[x].k+(M>>1), (a[y].sz)<<2);
			
			a[x].sz = a[x].sum = M>>1;
			a[x].insert_key(key, pos);
		}
		else
		{
			a[y].sz = a[y].sum = M>>1;
			a[y].init_and_insert_key(a[x].k+(M>>1), key, pos-(M>>1));

			a[x].sz = a[x].sum = M>>1;
		}
		sp_key = mid_key;
	}

	int insert(int x, int key)
	{
		Node &cur = a[x];
		int pos = cur.find_pos(key);
		if (pos<cur.sz&&cur.k[pos]==key) return -1;
		if (!a[x].is_leaf)
		{
			int return_code = insert(cur.p[pos], key);
			if (return_code==-1) return -1;
			cur.sum++;
			cur.cnt[pos]++;
			if (return_code==1)
			{
				cur.insert_split(pos, sp_key, tot, a[tot].sum);
				if (cur.is_full())
				{
					split_inner(x);
					return 1;
				}
			}
		}
		else
		{
			if (cur.is_full())
			{
				split_leaf(x, key, pos);
				return 1;
			}
			else
			{
				cur.insert_key(key);
			}
		}
		return 0;
	}
	
	int query(int x, int l, int r)
	{
		Node &cur = a[x];
		if (l==MINF&&r==INF) return cur.sum;
		if (a[x].is_leaf)
		{
			int pl = cur.find_pos(l);
			int pr = cur.find_pos_from(r, pl);
			return pr-pl;
		}
		else
		{
			int pl = l==MINF ? -1 : cur.find_pos(l);
			int pr = r==INF ? cur.sz+1 : cur.find_pos_from(r, max(0, pl));
			int ret = cur.get_cntsum(pl+1, pr-1);
			if (pl==pr) ret = query(cur.p[pl], l, r);
			else
			{
				if (l!=MINF) ret += query(cur.p[pl], l, INF);
				if (r!=INF) ret += query(cur.p[pr], MINF, r);
			}
			return ret;
		}
	}

	
	int init_arr[MAX_KEY_NUM], init_n;
	bool init;
	ll max_size[10], min_size[10];
	void load(int x, int arr[], int n, int lv)
	{
		Node &cur = a[x];
		if (lv==0)
		{
			cur.is_leaf = true;
			cur.sz = cur.sum = n;
			memcpy(cur.k, arr, n<<2);
		}
		else
		{
			cur.is_leaf = false;
			int sz = M-1;
			for (int i=M-1; i>=1; i--)
			{
				if ((n+i-1)/i>=min_size[lv-1])
				{
					sz = i-1;
					break;
				}
			}
			cur.sz = sz;
			cur.sum = n;
			int block_sz = n/(sz+1)+1;
			for (int i=0, j=0; i<=sz; i++)
			{
				if (i==n%(sz+1)) block_sz--;
				cur.p[i] = ++tot;
				cur.cnt[i] = block_sz;
				load(tot, arr+j, block_sz, lv-1);
				j += block_sz;
				if (i<sz) cur.k[i] = arr[j];
				else assert(j==n);
			}
		}
	}
	void bulkload()
	{
		cerr<<"bulkload:"<<init_n<<endl;

		max_size[0] = M;
		min_size[0] = M>>1;
		for (int i=1; i<10; i++)
		{
			max_size[i] = max_size[i-1] * M;
			min_size[i] = min_size[i-1] * (M>>1);
		}
		init_n = my_sort(init_arr, init_n);
		int lv = 0;
		while (max_size[lv] < init_n) lv++;
		load(root, init_arr, init_n, lv);
	}
public:
	BTree()
	{
		init = true;
		init_n = 0;
		root = tot = 1;
		a[root].is_leaf = true;
	}
	void Insert(int key)
	{
		if (init)
		{
			init_arr[init_n++] = key;
		}
		else
		{
			if (insert(root, key)==1)
			{
				int x = root, y = tot;
				root = ++tot;
				a[root].init_root(x, a[x].sum, sp_key, y, a[y].sum);
			}
		}
	}
	int Query(int lvalue, int rvalue)
	{
		if (lvalue>=rvalue) return 0;
		
		if (init)
		{
			bulkload();
			init = false;
		}
		return query(root, lvalue, rvalue);
	}
	
	/*
	void debug(int x)
	{
		if (a[x].is_leaf)
		{
		cerr<<"x="<<x<<" : ";	for (int i=0; i<a[x].sz; i++) cerr<<a[x].k[i]<<" "; cerr<<endl;
		}
		int sum = 0;
		for (int i=0; i<=a[x].sz; i++)
		{
			if (a[x].p[i])
			{
				if (a[x].cnt[i]!=a[a[x].p[i]].sum) cerr<<"!!!x="<<x<<" i="<<i<<" p[i]="<<a[x].p[i]<<" a[x].cnt[i]="<<a[x].cnt[i]<<" sum="<<a[a[x].p[i]].sum<<endl;
				assert(a[x].cnt[i]==a[a[x].p[i]].sum);
				sum += a[x].cnt[i];
				debug(a[x].p[i]);
			}
		}
		if (a[x].is_leaf) assert(a[x].sum==a[x].sz);
		else assert(sum==a[x].sum);
	}*/

}T;

int n;
int main()
{
    n = getnum();
	for (int i=1; i<=n; i++)
	{
		char op = getreal();
		if (op=='i')
		{
			int key = getnum();
			int dummy = getnum();
			T.Insert(key);
		}
		else
		{
			int lvalue = getnum();
			int rvalue = getnum();
			putnum(T.Query(lvalue, rvalue));
			putchar('\n');
		}
	}
	cerr<<"counter="<<counter<<endl;
	return 0;
}