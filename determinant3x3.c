#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
int main(){
while(1){
char inpt[30];
int matris[3][3];
int i=0;

int **inpvalues = (int**)malloc(sizeof(int*)*9); // Dışarıdan değer alamak için 
for(i=0; i<9; i++){
	inpvalues[i] = (int*)malloc(sizeof(int)*10);
}
int x=0;
gets(inpt);

char *token = strtok(inpt, " "); // Alınan değeri boşluga göre bölme
while (token != NULL) { 
       	inpvalues[x]=atoi(token); // Değeri int'e çevirip diziye atama
      	token = strtok(NULL, " "); 
	x++;
}
int sat=0;
int sut=0;
x=0;
for(sat=0; sat<3; sat++){
	for(sut=0; sut<3; sut++){
	matris[sat][sut]=inpvalues[x]; //matrisi oluşturma  
	x++;
	}
}

int pipec[2]; // pipe oluşturma

if (pipe(pipec) < 0) {
        perror("pipe");
        exit(1);
}

int b=0;

pid_t pid=fork();
if (pid==0){
	b = execv("satsutsec",NULL); // satsutsec programinin çalısması

	perror("hatassss");
exit(0);

}
else{
wait(&b);

int rsayi;
read(pipec[0], &rsayi, sizeof(int));  //gelen değeri okuma

int a=0;
pid_t f=fork();
if(f==0){
	write(pipec[1], &matris, sizeof(int)*9); //pipe yazma
	write(pipec[1], &rsayi, sizeof(int));
	a=execv("kofakhesap2x2",NULL);
	perror("hata");

close(pipec[1]);

}
else{
wait(&a);
int m1g;
int m2g;
int m3g;
	read(pipec[0], &m1g, sizeof(int)); //pipe'den okuma
	read(pipec[0], &m2g, sizeof(int));
	read(pipec[0], &m3g, sizeof(int));

int katsayilar[3];
switch (rsayi){				   // katsayıları belirleme	
	case 1 :
	katsayilar[0]=matris[0][0]; 
	katsayilar[1]=matris[0][1];
	katsayilar[2]=matris[0][2];
	break;
	case 2 :
	katsayilar[0]=matris[1][0]; 
	katsayilar[1]=matris[1][1];
	katsayilar[2]=matris[1][2];
	break;
	case 3 :
	katsayilar[0]=matris[2][0]; 
	katsayilar[1]=matris[2][1];
	katsayilar[2]=matris[2][2];
	break;
	case 4 :
	katsayilar[0]=matris[0][0]; 
	katsayilar[1]=matris[1][0];
	katsayilar[2]=matris[2][0];
	break;
	case 5 :
	katsayilar[0]=matris[0][1]; 
	katsayilar[1]=matris[1][1];
	katsayilar[2]=matris[2][1];
	break;
	case 6 :
	katsayilar[0]=matris[0][2]; 
	katsayilar[1]=matris[1][2];
	katsayilar[2]=matris[2][2];
	break;
}

int sonuc;
sonuc=katsayilar[0]*m1g + katsayilar[1]*m2g + katsayilar[2]*m3g;

printf("sonuc: %d\n", sonuc);

}
}
close(pipec[1]); //pipe kapatma
close(pipec[0]);
}
return 0;


}
