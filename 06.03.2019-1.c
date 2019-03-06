#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795
typedef struct _Kompleks
{
	float reel;
	float sanal;
} Kompleks;
Kompleks Eslenik(Kompleks);
float Buyukluk(Kompleks);
Kompleks Toplam(Kompleks,Kompleks);
Kompleks Fark(Kompleks,Kompleks);
Kompleks Carpim(Kompleks,Kompleks);
Kompleks Bolum(Kompleks,Kompleks);
Kompleks Kuvvet(Kompleks,int);
void Kok(Kompleks A,int n,Kompleks B[]);
void Yaz(Kompleks);
int main()
{
	Kompleks A{4,-3},C[10];
	int n=10,i;
	Kok(A,n,C);
	Yaz(A);printf(" Kompleks Sayisinin Kokleri:\n");
	for(i=0;i<n;i++)
	{
		Yaz(C[i]);printf("\n");
	}
	printf("Saglama:\n");
	for(i=0;i<n;i++) 
	{
		Yaz(Kuvvet(C[i],10));printf("\n");
		
	}
	return 0;
}
Kompleks Eslenik(Kompleks A)
{
	A.sanal=-A.sanal;
	return A;
}
float Buyukluk(Kompleks A)
{
	return sqrt(A.reel*A.reel+A.sanal*A.sanal);
}
Kompleks Toplam(Kompleks A,Kompleks B)
{
	Kompleks C;
	C.reel=A.reel+B.reel;
	C.sanal=A.sanal+B.sanal;
	return C;
}
Kompleks Fark(Kompleks A,Kompleks B)
{
	Kompleks C;
	C.reel=A.reel-B.reel;
	C.sanal=A.sanal-B.sanal;
	return C;
}
Kompleks Carpim(Kompleks A,Kompleks B)
{
	Kompleks C;
	C.reel=A.reel*B.reel-A.sanal*B.sanal;
	C.sanal=A.reel*B.sanal+A.sanal*B.reel;
	return C;
}
Kompleks Bolum(Kompleks A,Kompleks B)
{
	Kompleks C;
	if(B.reel==0 && B.sanal==0) 
	{
		printf("\nBolunemez"); exit(1);
	}
	C=Carpim(A,Eslenik(B));
	C.reel/=pow(Buyukluk(B),2);
	C.sanal/=pow(Buyukluk(B),2);
	return C;
}
Kompleks Kuvvet(Kompleks A,int n)
{
	float theta,d;
	Kompleks B;
	if(A.reel==0) theta=PI/2;
	else theta=atan(A.sanal/A.reel);
	d=Buyukluk(A);
	B.reel=pow(d,n)*cos(theta*n);
	B.sanal=pow(d,n)*sin(theta*n);
	return B;	
}
void Yaz(Kompleks A)
{
	char c;
	if(A.sanal<0) c=' ';
	else c='+';
	printf("%f%c%fi",A.reel,c,A.sanal);
	return;
}
void Kok(Kompleks A,int n,Kompleks B[])
{
	int i;
	float theta,d;
	if(A.reel==0) theta=PI/2;
	else theta=atan(A.sanal/A.reel);
	d=Buyukluk(A);
	for(i=0;i<n;i++)
	{
		B[i].reel=pow(d,1./n)*cos((2*i*PI+theta)/n);
	    B[i].sanal=pow(d,1./n)*sin((2*i*PI+theta)/n);
	}
	return;	
}
