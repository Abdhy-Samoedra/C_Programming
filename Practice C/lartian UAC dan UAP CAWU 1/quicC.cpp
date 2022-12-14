#include <stdio.h>


int main()
{
	int cases;
	scanf("%d",&cases);
	
	int gerbong;
	int time;
	
	for(int i=0;i<cases;i++)
	{
		scanf("%d %d",&gerbong,&time);
		
		int kereta[10001]={};
		
		for(int j=0;j<gerbong;j++)
		{
			scanf("%d",&kereta[j]);
		}
		
		
		int count = 0;
		
		for (int j=0; j<gerbong-1;j++)
		{
			for (int k=0;k<gerbong-j-1;k++)
			{
				if(kereta[k] < kereta[k+1])
				{
					
				}else
				{
					int temp;
					temp = kereta[k];
					kereta[k] = kereta[k+1];
					kereta[k+1]=temp;
					count++;
				}
			}
		}
		printf("Case #%d: %d\n",i+1,count*time);
		count = 0;
		
	}
}
