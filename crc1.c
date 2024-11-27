#include<stdio.h>

int main()
{
	int d[10],i,j,k,len,divlen;
	int m1[20],rem1[10];

    printf("\n\rAt the receiver end\n");

    printf("\nEnter the length of the divisor: ");
    scanf("%d", &divlen);

    printf("\nEnter the divisor: ");
    for (i = 0; i < divlen; i++) 
    {
        scanf("%d", &d[i]);
    }
    // Input the length of the original data
    printf("\nEnter the length of the original data (without CRC): ");
    scanf("%d", &len);

	printf("\nEnter the complete data + CRC received: ");
	for(i=0;i<len+(divlen-1);i++)
	{
	 scanf("%d",&m1[i]);
	}

      for(i=0;i<len;i++)
	{
	 if(m1[i]==1)
	 {
	  for(j=0;j<divlen;j++)
	  {
	   if(m1[i+j]==d[j])
	    rem1[j]=0;
	   else
	    rem1[j]=1;
	  }
	for(k=0;k<divlen;k++)
	{
	 m1[i+k]=rem1[k];
	}
	}
	else
	{
	  for(k=0;k<divlen;k++)
	  {
	   rem1[k]=m1[i+k];
	  }
	}
	}
	
	printf("\n");
	printf("\nCRC = ");
	j=0;
	for(i=1;i<divlen;i++)
	{
	 printf("%d",rem1[i]);
	 j=j+rem1[i];
	}

	if(j==0)
	  printf("\nThere is no error\n");
	else
	  printf("\nThere is error\n");

	return(1);
}
