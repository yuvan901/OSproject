#include<stdio.h>
int sorting() 
{
	
}
int main()
{
    int cpu_use[20],a[20],arr[20],bt[20],p[20],pri[20],n,i,base=60,j,wait[20],tat[20],total=0,pos,temp,avg_wait,avg_tat;
   printf("Enter Total Number of Process:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        arr[i]=0*rand() % 10;
        cpu_use[i]=1+rand()%50;
        p[i]=i+1;           
    }
     printf("\nProcess\t    Burst Time    \tArrival Time\tRecent CPU Usage");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],arr[i],cpu_use[i]);
    }
     printf("\n\n Priority For the Processes");
    for(j=0;j<n;j++)
    {
    	pri[j]=(cpu_use[j]/2)+base;
    	printf("\nP[%d] %d",j+1,pri[j]);
	}
	int x=1;
	while(x!=n)
{int w;
	
		printf("\n\n\t\t%d EXECUTION",x);
	
		 for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pri[j]<pri[pos])
                pos=j;
        }
 
        temp=pri[i];
        pri[i]=pri[pos];
        pri[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        
        
    }
    wait[0]=0;

    for(i=1;i<n;i++)

    {

        wait[i]=0;

        for(j=0;j<i;j++)

            wait[i]+=bt[j];

 

        total+=wait[i];

    }

 

    avg_wait=total/n;
    total=0;

 

    printf("\n\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time\t Priority");

    for(i=0;i<n;i++)

    {

        tat[i]=bt[i]+wait[i];

        total+=tat[i];

        printf("\n\nP[%d]\t\t  %d\t\t    %d\t\t\t%d\t\t   %d",p[i],bt[i],wait[i],tat[i],pri[i]);

    }

 

    avg_tat=total/n;

    printf("\n\nAverage Waiting Time=%d",avg_wait);

    printf("\n\nAverage Turnaround Time=%d\n",avg_tat);
a[0]=0;
for(i=1;i<=n;i++)
{
	a[i]=tat[i-1];

}

 printf("\n\nNew Recent CPU Usage");
 
 for(i=0;i<n;i++)
 {
 	cpu_use[i]=a[i+1]-a[i];
 	printf("\nP[%d] %d",i+1,cpu_use[i]);
 }
   printf("\n NEW Priority For the Processes");
    for(j=0;j<n;j++)
    {
    	pri[j]=(cpu_use[j]/2)+base;
    	printf("\nP[%d] %d",j+1,pri[j]);
	}
	x=x+1;
}
    return 0;
}
