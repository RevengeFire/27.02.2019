#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Nokta{
	double x;
	double y;
} Nokta;
double Mesafe(Nokta A, Nokta B){
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
Nokta Bul(Nokta A[5]){
	double d[5];
	Nokta O{0,0};
	int i;
	for(i = 0; i < 5; i++) d[i] = Mesafe(A[i], 0);
	indis = 0;
	for(i = 1; i < 5; i++)
		if(d[i] < d[indis]) indis = i;
	return A[indis];
}
int main(){
	Nokta A[5];
	int i;
	for(i = 0; i < 5; i++){
		printf("%d. Nokta : ",i);
		scanf("%lf,%lf", &A[i].x, &A[i].y);
	}
	B = Bul(A);
	printf("Orijine en yakin nokta (%lf,%lf) noktasidir", B.x, B.y);
	return 0;
}
