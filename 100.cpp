// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
// 100 - The 3n + 1 problem

#include<iostream.h>

main()
{
	long long int x,y,f,max,t;
	while((cin >> x >> y)>0)
	{
		max=0;
		cout << x << " " << y;
		if(x>y)
		{
			f=x;
			x=y;
			y=f;
		}
		for(int i=x ; i<=y ; i++)
		{
			t=1;
			f=i;
			while(f!=1)
			{
				if(f%2==0)
					f/=2;
				else
					f=3*f+1;
				t++;
			}
			if(t>max)
				max=t;
		}
		cout << " " << max << endl;
	}
	return 0;
}
