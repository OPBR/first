#include<stdio.h>
#include<string.h>

int fa[50000],eat[50000],eaten[50000];

int mfind(int a)
{
	if (fa[a] != a)
		fa[a] = mfind(fa[a]);
	return fa[a];

}

int mmerge(int a,int b)
{
	if (!a)
		return b;
	if (!b)
		return a;
	return (fa[mfind(a)] = mfind(b));

}

int findeat(int a)
{
	int ra = mfind(a);
	int tmp = eat[ra];
	if (!tmp)
		return tmp;
	int rf = mfind(tmp);
	eat[ra] = rf;
	return rf;

}

int findeaten(int a)
{
	int ra = mfind(a);
	int tmp = eaten[ra];
	if (!tmp)
		return tmp;
	int rf = mfind(tmp);

	eaten[ra] = rf;
	return rf;

}

int main(void)
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	for (i = 0; i <= n; i++){
		fa[i] = i;
	}

	memset(eat,0,sizeof(eat));
	memset(eaten,0,sizeof(eaten));

	int a,b,c;
	int ans = 0;
	while(k--){
		scanf("%d %d %d",&a,&b,&c);
		if (b > n || c > n || b <= 0 || c <= 0){
			ans++;
			continue;
		}

		int rb = mfind(b);
		int rc = mfind(c);
		int eb = findeat(rb);
		int ec = findeat(rc);
		int etb = findeaten(rb);
		int etc = findeaten(rc);

		if (a == 1){
			if (eb == rc || ec == rb || etc == rb || etb == rc){
				ans++;
				continue;
			}
			fa[rb] = rc;
			eat[rc] = mmerge(eb,ec);
			eaten[rc] = mmerge(etb,etc);
			if (ec){
				eaten[ec] = rc;
				eat[ec] = eaten[rc];
			}
			if (etc){
				eat[etc] = rc;
				eaten[etc] = eat[rc];
			}

		}

		else{
			if (rb == rc || ec == rb || etb == rc){
				ans++;
				continue;
			}
			eat[rb] = mmerge(eb,rc);
			eaten[rc] = mmerge(etc,rb);
			eat[rc] = eaten[rb] = mmerge(etb,ec);
			int d = eat[rc];
			if (d){
				eat[d] = rb;
				eaten[d] = rc;
			}
		}

	}
	
	printf("ans = %d\n",ans);
	return 0;
}
