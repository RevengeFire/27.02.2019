#include <stdio.h>
#include <iostream>
#include <stdlib.h>
int F(char *x)
{
	if(*x=='\0') return 0;
	return 1+F(x+1);
}
void copy(char *str1, char *str2){
	int i=0;
	while(*str2!='\0'){
		str1[i]=*str2; str2++;i++;
	}
	return;
}
void birlestir(char *str1,char *str2){
	int i=0,k;
	while(str1[i]!='\0') i++;
	while(str2[k]!='\0') str1[k+i]=str2[k++];
		str1[i+k]='\0';
		return;
	
}
int bul(char *str,char c)
{
	int k=0;
	while(str[k]!='\0')
		if(str[k++]==c) return k-1;
		return -1;
}
int main()
{
	char *str1,*str2,c;
	int n=20,k;
	str1=(char *)malloc(n*sizeof(char));
	if(str1==NULL) {printf("Bellek Hatasi:"); exit(1);}
	str2=(char *)malloc(n*sizeof(char));
	if(str2==NULL) {printf("Bellek Hatasi:"); exit(1);}
	printf("1.string:");
	gets(str1);
	printf("Karakter:");
//	std::cin >> c;
	scanf("%c",&c);
	k=bul(str1,c);
	if(k!=-1) printf("%c karakteri %s icerisinde %d. pozisyondadir",c,str1,k);
	if(k==-1) printf("%c karakteri %s icerisinde %d. yoktur!",c,str1,k);
	free(str1);free(str2);
	return 0;
}
