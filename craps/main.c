#include <stdio.h>
#include <stdlib.h>
#include <time.h> // rand kullanabilmek icin

int a; // 1. zar atamasý
int b; // 2. zar atamasý
char x; //bitis komutu icin
int main(void)
{
    start: //basa dondurme islemi icin
    printf("\t\tZAR OYUNUNA HOSGELDINIZ!\t\t\n\n"); //giris
    printf("   1. ATIS\n");
    printf("-------------\n");
    srand(time(NULL)); //1 ve 6 arasi random sayi gelmesi icin(srand her calýstýrdýgýmýzda farkli sayi gelmesi icin )
    a = 1 + rand() %6;  //0 dan baþlamamasý için +1 ekliyoruz.
    b = 1 + rand() %6;
    printf("1. Zar: %d\n", a);  // zar degerlerini ekranda gostermek icin
    printf("2. Zar: %d\n", b);
    const int toplam_ilk = a + b; // ilk toplami kalici deger yapiyoruz.
    printf("Puan: %d\n\n", toplam_ilk); // puani ekranda gosterir.

    if(toplam_ilk == 7 || toplam_ilk == 11) // eger 7 ya da 11 gelirse kazanir.
        printf("KAZANDIN!");

    else if(toplam_ilk == 2 || toplam_ilk == 3 || toplam_ilk == 12) // eger 2, 3 ya da 12 gelirse kaybeder.
        printf("KAYBETTIN!");
    else                                // eger farkli sayý gelirse puan olarak yazilir ve 2. atisa gecilir.
    {
        printf("   2. ATISLAR\t\n");
        printf("---------------\n");
        a = 1 + rand() %6;   //ayni zarlar tekrar atilir.
        b = 1 + rand() %6;
        int toplam_son = a + b;
        printf("Puan: %d \n", toplam_ilk);
        printf("1. Zar: %d\n", a);
        printf("2. Zar: %d\n", b);
        printf("Yeni deger: %d\n", toplam_son);

            if(toplam_son == 7) //eger 2. atista 7 gelirse kaybeder.
            {
                printf("\nKAYBETTIN!");
            }else if(toplam_son == toplam_ilk) //eger 2. atista puani(ilk atistaki zarlarin toplami) gelirse kazanir.
            {
                printf("\nKAZANDIN!");
            }else
            {
                while(toplam_son != 7 || toplam_son != toplam_ilk) //7 veya puan denk gelmedigi takdirde atislar devam eder.
                {                                                  //atislarý bir donguye sokuyoruz.
                    a = 1 + rand() %6; //zarlarin atilmaya devam etmesi gerekir.
                    b = 1 + rand() %6;
                    int toplam_son = a + b;
                    printf("Puan: %d \n", toplam_ilk);
                    printf("1. Zar: %d\n", a);
                    printf("2. Zar: %d\n", b);
                    printf("Yeni deger: %d\n", toplam_son);
                    if(toplam_son == 7) //7 geldiginde dongunun bitmesi gerekir.
                    {
                        printf("\nKAYBETTIN!\n\n");
                        break;                 //break komutuyla donguden cikilmasi saglanir.
                    }else if(toplam_son == toplam_ilk) // ya da puan geldiginde donguden cikilmasi gerekir.
                    {
                        printf("\nKAZANDIN!\n\n");
                        break;                 //yine break komutuyla donguden cikilir.
                    }else;
                }
            }
    }
    printf("TEKRAR OYNAMAK ISTER MISINIZ?\n");
    printf("EGER ISTIYORSANIZ E'YE BASINIZ!\n");
    printf("EGER ISTEMIYORSANIZ H'YE BASINIZ!\n");
    scanf("%c", &x);
    if(x == 'e' || x == 'E')
        goto start;             //oyunu 1 kez daha oynamak icin
    if(x == 'h' || x == 'H')
        return(0);     //oyunu bitirmek icin

}












