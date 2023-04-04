#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>




int main(int argc, char *argv[]) {
	
	printf("Bir matristeki en zayif K adet satirin bulunmasi\n\n");
	
	float boy,en; //int yapmad�m �unku girilen say�n�n tamsay� olup olmad�g�n� ancak b�yle kontrol edebildim.
	
	//matris i�in boy ve en bilgisinin al�nmas�
	printf("Matris icin buyukluk belirleyiniz\n");
	do
	{
		printf("Matris boyunu tam sayi ve pozitif olarak olarak giriniz (max 20, min 2):\n");
		scanf("%f",&boy);
	}while((1!= boy /(int) boy) || (boy>20.0 || boy<2.0) );
	
		do
	{
		printf("Matris enini tam sayi ve pozitif olarak olarak giriniz (max 20, min 3):\n");
		scanf("%f",&en);
	}while((1!= en /(int) en) || (en>20.0 || en<3.0));
	
	
	int rastgeleSayi; //her sat�r i�in en soldaki sivilin rastgele se�ilece�i yer
	int dizi[(int)boy][(int)en]; //istenilen matrisin olusturulmas�
	int i,j; //Sayaclar
	
	//t�m diziye 1 lerin atanmas�
	for(i=0;i<boy;i++)
	{
		for(j=0;j<en;j++)
		{
			dizi[i][j]=1;
		}
	}
	
	
	//her sat�r i�in rastgele bir yere 0 koyulmas�
	srand(time(NULL));
	for(i=0;i<boy;i++)
	{
		do
		{
			rastgeleSayi=rand()%10;
		}while(rastgeleSayi>=en || rastgeleSayi<0);
		
		dizi[i][rastgeleSayi]=0;
		
		//belirlenen yerden sa�a do�ru 0 lar�n yerle�tirilmesi
		for(j=rastgeleSayi;j<en;j++)
		{
			dizi[i][j]=0;
		}
	}
	
	//tablonun bast�r�lmas�
	printf("\nMatrisimiz:\n\n");
	for(i=0;i<boy;i++)
	{
		printf("%d. satir  ",i+1);
		for(j=0;j<en;j++)
		{
			printf("%d  ",dizi[i][j]);
		}
		printf("\n");
	}
	
	int sivilSayac[(int)boy]; 
	int sayac=0;
	
	//her sat�rdaki sivillerin say�m�
	for(i=0;i<boy;i++)
	{
		sayac=0;
		for(j=0;j<en;j++)
		{
			if(dizi[i][j]==0)
			{
				sayac++;
			}
		}
		sivilSayac[i]=sayac; //her sat�rdaki sivil say�s�n� daha sonra s�ralamak i�in dizide tutuyorum
	}
	
	
	printf("\n");
	//sivillerin askerlerden �ok veya e�it oldu�u yerlerin bulunmas�
	int satirsayisi=0;
	for(i=0;i<boy;i++)
	{
		if(sivilSayac[i]>=(en-sivilSayac[i]))
		{
			printf("%d. ",i+1);
			satirsayisi++;
		}
		
	}
	printf("satir/satirlar zayif satirlardir. Toplam %d satir.",satirsayisi);
	
	return 0;
}


