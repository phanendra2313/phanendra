#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int sumofmax(int *a,int m,int t,int cnt)
{
  int i,sum=0,lmax=0,rmax=0,team,j,r,l;
  if(t == cnt)
  {
    for(i=0;i<t;i++)
    sum = sum +a[i];
    return  sum;
  }
  else
  {
  for(team=0;team<t;team++)
  {
    for(i=0;i<m;i++)
    {
      printf("al[%d]=%d\n",i,a[i]);
      if(a[i]>lmax)
       {
       l = i;
       lmax=a[i];
       }
    }
    for(j=cnt-m;j<cnt;j++)
    {
      printf("ar[%d]=%d\n",j,a[j]);
      if(a[j]>rmax)
      {
       rmax=a[j];
       r=j;
      }
    }
    
    if(lmax>rmax)
    {
      sum=sum+lmax;
      lmax=0;
      printf("lmax = %d\n",a[l]);
      memmove(a+l,a+l+1,sizeof(a+l+1));
      cnt--;
    }
    else
    {
      sum=sum+rmax;
      rmax=0;
      printf("rmax = %d\n",a[r]);
      memmove(a+r,a+r+1,sizeof(a+r+1));
      cnt--;
    }
  }
    return  sum;
}
}

main()
{
  int *a,s_cnt,m,t,i,sumscores;
  
  printf("enter no of emp:");
  scanf("%d",&s_cnt);
  a=(int*)calloc(1,s_cnt*sizeof(a[0]));
  
  printf("enter emp scores:");
  for(i=0;i<s_cnt;i++)
  {
  scanf("%d",&a[i]);
  printf("%d\n",a[i]);
  }
  
  printf("enter team nos req:");
  scanf("%d",&t);
  printf("enter grouping team:");
  scanf("%d",&m);
  
  sumscores = sumofmax(a,m,t,s_cnt);

  printf("sum=%d\n",sumscores);
}
