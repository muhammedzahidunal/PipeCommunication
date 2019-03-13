#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int main(){

int sat=0;
int sut=0;

int gmatris[3][3];
int gsayi;
read(3, &gmatris, sizeof(int)*9); // pipe okuma
read(3, &gsayi, sizeof(int));

for(sat=0; sat<3; sat++){
	for(sut=0; sut<3; sut++){
	printf("%2d", gmatris[sat][sut]); // okunan matrisi yazdirma 
	}
	puts("");
}

printf("random sayı: %d\n",gsayi);

int m1[2][2];				//kofaktör hesaplama için oluşan matrisler
int m2[2][2];
int m3[2][2];

if (gsayi==1){
m1[0][0]=gmatris[1][1];
m1[0][1]=gmatris[1][2];
m1[1][0]=gmatris[2][1];
m1[1][1]=gmatris[2][2];

m2[0][0]=gmatris[1][0];
m2[0][1]=gmatris[1][2];
m2[1][0]=gmatris[2][0];
m2[1][1]=gmatris[2][2];

m3[0][0]=gmatris[1][0];
m3[0][1]=gmatris[1][1];
m3[1][0]=gmatris[2][0];
m3[1][1]=gmatris[2][1];	
}
else if(gsayi==2){
m1[0][0]=gmatris[0][1];
m1[0][1]=gmatris[0][2];
m1[1][0]=gmatris[2][1];
m1[1][1]=gmatris[2][2];

m2[0][0]=gmatris[0][0];
m2[0][1]=gmatris[0][2];
m2[1][0]=gmatris[2][0];
m2[1][1]=gmatris[2][2];

m3[0][0]=gmatris[0][0];
m3[0][1]=gmatris[0][1];
m3[1][0]=gmatris[2][0];
m3[1][1]=gmatris[2][1];	
}
else if(gsayi==3){
m1[0][0]=gmatris[0][1];
m1[0][1]=gmatris[0][2];
m1[1][0]=gmatris[1][1];
m1[1][1]=gmatris[1][2];

m2[0][0]=gmatris[0][0];
m2[0][1]=gmatris[0][2];
m2[1][0]=gmatris[1][0];
m2[1][1]=gmatris[1][2];

m3[0][0]=gmatris[0][0];
m3[0][1]=gmatris[0][1];
m3[1][0]=gmatris[1][0];
m3[1][1]=gmatris[1][1];	
}
else if(gsayi==4){
m1[0][0]=gmatris[1][1];
m1[0][1]=gmatris[1][2];
m1[1][0]=gmatris[2][1];
m1[1][1]=gmatris[2][2];

m2[0][0]=gmatris[0][1];
m2[0][1]=gmatris[0][2];
m2[1][0]=gmatris[2][1];
m2[1][1]=gmatris[2][2];

m3[0][0]=gmatris[0][1];
m3[0][1]=gmatris[0][2];
m3[1][0]=gmatris[1][1];
m3[1][1]=gmatris[1][2];
}
else if(gsayi==5){
m1[0][0]=gmatris[1][0];
m1[0][1]=gmatris[1][2];
m1[1][0]=gmatris[2][0];
m1[1][1]=gmatris[2][2];

m2[0][0]=gmatris[0][0];
m2[0][1]=gmatris[0][2];
m2[1][0]=gmatris[2][0];
m2[1][1]=gmatris[2][2];

m3[0][0]=gmatris[0][0];
m3[0][1]=gmatris[0][2];
m3[1][0]=gmatris[1][0];
m3[1][1]=gmatris[1][2];
}
else if(gsayi==6){
m1[0][0]=gmatris[1][0];
m1[0][1]=gmatris[1][1];
m1[1][0]=gmatris[2][0];
m1[1][1]=gmatris[2][1];

m2[0][0]=gmatris[0][0];
m2[0][1]=gmatris[0][1];
m2[1][0]=gmatris[2][0];
m2[1][1]=gmatris[2][1];	

m3[0][0]=gmatris[0][0];
m3[0][1]=gmatris[0][1];
m3[1][0]=gmatris[1][0];
m3[1][1]=gmatris[1][1];	
}


int po = 1;
int u = 0;
u =gsayi;
if(gsayi>3){			// pow işlemi
if(gsayi%2 ==1){
po = 1 ;
}
if(gsayi%2 == 0 ){
po = -1;
}
}
else{
if(gsayi%2 ==1){
po = -1 ;
}
if(gsayi%2 == 0 ){
po = 1;
}
}


int m1value=po*-1*(m1[0][0]*m1[1][1] - m1[0][1]*m1[1][0]); //kofaktör işlemi
int m2value= po*(m2[0][0]*m2[1][1] - m2[0][1]*m2[1][0]);
int m3value= po*-1*(m3[0][0]*m3[1][1] - m3[0][1]*m3[1][0]);

write(4, &m1value , sizeof(int)); //pipe'a yazma 
write(4, &m2value , sizeof(int));
write(4, &m3value , sizeof(int));


return 0;
}
