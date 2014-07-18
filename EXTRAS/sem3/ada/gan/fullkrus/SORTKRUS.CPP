int temp;
void sort()
{
	for(i=1;i<size;i++)
	{
		for(j=i+1;j<=size;j++)
		{
			if(b[i]>b[j])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
}