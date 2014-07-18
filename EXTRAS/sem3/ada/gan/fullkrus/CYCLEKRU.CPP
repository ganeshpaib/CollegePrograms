int z,x,y;
void cycle()
{
	for(z=1;z<k;z++)
	{
		for(i=1;i<=size;i++)
		{
			for(j=1;j<=size;j++)
			{
				if(cost[i][j]==b[z])
				{
					x=find(i);
					y=find(j);
					if(x!=y)
					{
						parent[j]=i;
						printf("%d %d\n",i,j);
					}
				}
			}
		}
	}
}