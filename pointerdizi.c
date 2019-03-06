#include <stdio.h>
#include <stdlib.h>
int main()
{
int *p,i,n=20;
p=(int *)malloc(n*sizeof(int));
if(p==NULL) exit(1);
for(i=0;i<n;i++){
	*p=i;p++;
}
p-=n;
for(i=0;i<n;i++) printf("\n%d %d",i,p[i]);
return 0;
}
