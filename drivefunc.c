#include <stdio.h>
#include <string.h>

/*int main()
{
	char st[] = "gelisim";
	char ch ='';
	char* val;
	val = strrchr(st,ch);
	printf("%c :  %s \n",ch,val);
	return (0);
}

char *F(char *str,char c)
{
	int i=0,k;
	while(str[i]!='\0'){
		if(str[i==c]) k=i;i++;
	}
	if(k==-1) return NULL;
	str+=k;
	return str;
}
*/
int main()
{
	char *str="gelisim";
	while(*str!='\0'){
		printf("%s \n",str);
		str++;
	}
	return 0;
}
