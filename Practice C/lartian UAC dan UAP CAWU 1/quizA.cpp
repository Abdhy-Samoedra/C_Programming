#include <stdio.h>

int main()
{
	int cases;
	scanf("%d",&cases);
	
	for(int i=0;i<cases;i++)
	{
		int size;
		scanf("%d",&size);
		
		int arr[size];
		
		for (int j=0;j<size;j++)
		{
			scanf("%d",&arr[j]); 		
		}	
		
		long long int batas;
		scanf("%lld",&batas);
		
		int hasil1 = 0;
		int hasil2 = 0;
		
		for(int j=size;j>0;j--)
		{
			for(int k=size;k>0;k--)
			{
				hasil1= 0;
				if(j+k-1 < size)
				{
					for(int l =k;l>=1;l--)
					{
						hasil1 += arr[j+k-l] *l;
						
						if(hasil1<= batas&& hasil2<=hasil1)
						{
							hasil2 = hasil1;
						}	
					}	
				}				
			}
		}
		printf("Case #%d: %d",i+1,hasil2);
	}	
}
