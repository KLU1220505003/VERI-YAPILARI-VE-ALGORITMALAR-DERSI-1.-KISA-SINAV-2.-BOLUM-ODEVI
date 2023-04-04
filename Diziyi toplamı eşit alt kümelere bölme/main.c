#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int sayilar[21]={0.0};
	float adet; //kullan�c�dan al�nack olan eleman sayisi
	do
	{
		printf("Kac adet sayi girmek istersiniz (max 20)\n");
		scanf("%f",&adet);
	
	}while((adet-(int)adet!=0.0)||(adet>20.0 || adet<0.0));
	
	int i,j; //sayaclar
	int toplam=0; //say�lar dizisi toplam
	
	printf("Elemanlari pozitif ve tamsayi olarak giriniz:\n");
	
	//elemanlar�n al�nmas�
	for(i=0;i<(int)adet;i++)
	{
		printf("%d. eleman: ",i+1);
		scanf("%d",&sayilar[i]);
		
		//sayinin tamsay� ve pozitif olup olmad�g�n�n kontrolu
		if((sayilar[i]-(int)sayilar[i]!=0.0) || sayilar[i]<=0)
		{
			printf("Elemanlari pozitif ve tamsayi olarak giriniz!!\n"); //uyar�
			i--;
		}
		else
		{
			toplam+=sayilar[i];
		}
		
	}
	
	
	//e�er toplam �ift ise 2 e�it kumeye b�l�nebilme olas�l��� vardir
	if(toplam%2 == 0)
	{
		//ba�tan itibaren say�lar� toplayarak b�t�n say�lar�n toplam�n�n yar�s� olmas�n� dener.
		int toplam2=0;
		
		 for (i = 0; i <(int)adet; i++)
        {
            if (toplam2 + sayilar[i] <= toplam/2)
            {
                toplam2 += sayilar[i];
            }
            else
            {
                break;
            }
        }
        	
		if(toplam2 == toplam/2)
        	printf("Bu sayilar iki esit kumeye bolunur.\n");
    	else
        	printf("Bu sayilar iki esit kumeye bolunemez.\n");
	   
	}
	else
		printf("elemanlar iki esit kumeye bolunemez.");
	
	return 0;
}
