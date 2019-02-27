#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

typedef struct _Kompleks{
	float reel;
	float sanal;
}Kompleks;

//Prototypes
Kompleks Eslenik(Kompleks);
float Buyukluk(Kompleks);
Kompleks Toplam(Kompleks,Kompleks);
Kompleks Fark(Kompleks,Kompleks);
Kompleks Carpim(Kompleks,Kompleks);
Kompleks Bolum(Kompleks,Kompleks);
Kompleks Kuvvet(Kompleks,int);

//Functions
Kompleks Eslenik(Kompleks A){
	A.sanal*=-1;return A;
}
float Buyukluk(Kompleks A){
	return sqrt(pow(A.reel,2) + pow(A.sanal,2));
}
Kompleks Toplam(Kompleks A,Kompleks B){
	Kompleks C;
	C.reel = A.reel + B.reel;
	C.sanal = A.sanal + B.sanal;
	return C;
}
Kompleks Fark(Kompleks A,Kompleks B){
	Kompleks C;
	C.reel = A.reel - B.reel;
	C.sanal = A.sanal - B.sanal;
	return C;
}
Kompleks Carpim(Kompleks A,Kompleks B){
	Kompleks C;
	C.reel = (A.reel*B.reel) - (A.sanal*B.sanal);
	C.sanal = (A.reel*B.sanal) + (B.reel*A.sanal);
	return C;
}
Kompleks Bolum(Kompleks A,Kompleks B){
	Kompleks C;
	C = Carpim(A,Eslenik(B));
	C.reel /= pow(Buyukluk(B),2);
	C.sanal /= pow(Buyukluk(B),2);
	return C;
}
Kompleks Kuvvet(Kompleks A,int x){
	Kompleks B;
	float d=Buyukluk(A),theta;
	if(A.reel == 0) theta = PI/2;
	else theta = atan(A.sanal/A.reel);
	B.reel = pow(d,x)*cos(theta*x);
	B.sanal = pow(d,x)*sin(theta*x);
	return B;
}
void Yaz(Kompleks A){
	char c;
	if(A.sanal<0) c = ' ';
	else c = '+';
	printf("%f%c%fi",A.reel,c,A.sanal);
	return;
}
int main(){
	Kompleks A{2,2},B{2,2},C;
	int n=2;
	C = Toplam(A,B);
	printf("(");Yaz(A);printf(") + (");Yaz(B);printf(") = ");Yaz(C);printf("\n");
	C = Fark(A,B);
	printf("(");Yaz(A);printf(") - (");Yaz(B);printf(") = ");Yaz(C);printf("\n");
	C = Carpim(A,B);
	printf("(");Yaz(A);printf(") * (");Yaz(B);printf(") = ");Yaz(C);printf("\n");
	C = Bolum(A,B);
	printf("(");Yaz(A);printf(") / (");Yaz(B);printf(") = ");Yaz(C);printf("\n");
	C = Kuvvet(A,n);
	printf("POW((");Yaz(A);printf("),%d) = (",n);Yaz(C);printf(")");
	return 0;
}
