#include <stdio.h>
#include <windows.h> // türkçe karakterde kullanıyoruz
#include <stdlib.h> // radtgele iban oluşturmak için lazım
#include <time.h> // herkese aynı iban verilmemesi için kullanıcaz
#include <string.h>
#include <conio.h>

// fonksiyon bildirimi yaptım
void bakiye_guncelle(char ad[], int yeni_bakiye);
int iban_para_gonder(char gonderen[], int bakiye);
int sifre_al();

int main () {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printf("\n");
    printf("  +================================================+\n");
    printf("  |      KAHRAMANMARAŞ İSTİKLAL ÜNİVERSİTESİ       |\n");
    printf("  +================================================+\n");
    printf("  | DERS: YZM103 ALGORİTMA VE PROGRAMLAMAYA GİRİŞ  |\n");
    printf("  | DERSİN HOCASI: Dr.Öğr.Üy.İBRAHİM ARUK          |\n");
    printf("  | PROJE: Banka Uygulaması                        |\n");
    printf("  | HAZIRLAYAN: Muhammed Çağrı Güneş               |\n");
    printf("  | ÖĞRENCİ NO: 25020091012                        |\n");
    printf("  +================================================+\n");
    system("timeout /t 2 > nul"); // 2 saniye bekler


    // "Slant" Yazı Tipi kullanılmıştır
    printf("\n");
    printf("    ____              __             ___               \n");
    printf("   / __ )____ _____  / /______ _    /   |  ____  ____  \n");
    printf("  / __  / __ `/ __ \\/ //_/ __ `/   / /| | / __ \\/ __ \\ \n");
    printf(" / /_/ / /_/ / / / / ,< / /_/ /   / ___ |/ /_/ / /_/ / \n");
    printf("/_____/\\__,_/_/ /_/_/|_|\\__,_/   /_/  |_/ .___/ .___/  \n");
    printf("                                       /_/   /_/       \n");
    printf("\n");
    printf("========================================================\n");
    printf("         GÜVENLİ BANKACILIK SİSTEMİNE HOSGELDİNİZ       \n");
    printf("========================================================\n");
    system("timeout /t 2 > nul");

    int secim,sifre,bakiye=0;
    char kullanici_adi[1000],iban[30];
    int dosya_sifre,dosya_bakiye,dosyada_varmi=0;
    char dosya_ismi[1000],dosya_iban[30];
    int secim2,tutar;
    // ibanın sürekli yenilenmesi için bunu ekledik
    srand(time(0));



    while (1) {
        printf("\n");
        printf("   +=====================================+\n");
        printf("   |          İŞLEM SEÇİM EKRANI         |\n");
        printf("   +=====================================+\n");
        printf("   |                                     |\n");
        printf("   | ( 1 ) Yeni Hesap Oluştur (Kayıt Ol) |\n");
        printf("   | ( 2 ) Giriş Yap                     |\n");
        printf("   | ( 3 ) Çıkış Yap                     |\n");
        printf("   |                                     |\n");
        printf("   +-------------------------------------+\n");
        printf("    >> Seçiminiz(1/2/3):");
        scanf("%d",&secim);
        switch (secim) {
            case 1: {
                printf("\n");
                printf("  .__________________________________.\n");
                printf("  |                                  |\n");
                printf("  |  Yeni Hesap Oluştur (Kayıt Ol)   |\n");
                printf("  |                                  |\n");
                printf("  |__________________________________|\n");
                printf("  |  [+] Kullanıcı Adınız : ");
                scanf(" %s",kullanici_adi);
                printf("  |  [+] Sifreniz         : ");
                sifre = sifre_al();
                printf("\n");
                printf("  |__________________________________|\n");
                printf("\n");


                // iban belirleniyor bu kısımda sprintf kullandık oda string türünde veriyi bellege kaydediyor
                sprintf(iban,"TR%d%d%d%d",rand(),rand(),rand(),rand());
                FILE *dosya;
                dosya=fopen("kullanicilar1.txt","a");
                fprintf(dosya,"%s %d %s %d\n",kullanici_adi,sifre,iban,bakiye);
                fclose(dosya);
                break;
            }
            case 2: {
                // dosyada varmı diye kontrol ediyoruz kullanıcı
                dosyada_varmi=0;
                printf("\n");
                printf("  .__________________________________.\n");
                printf("  |                                  |\n");
                printf("  |            Giriş Yap             |\n");
                printf("  |                                  |\n");
                printf("  |__________________________________|\n");
                printf("  | { + } Kullanıcı Adınınz:  ");
                scanf("%s",kullanici_adi);
                printf("  | { + } Sifreniz         :  ");
                sifre = sifre_al();
                printf("\n");
                printf("  |                                  |\n");
                printf("  !__________________________________!\n");
                printf("\n");
                FILE *dosya;
                dosya=fopen("kullanicilar1.txt","r");
                // dosyada kontrol yapıyoruz E0F dosya sonuna gelene kadar kontrol etmemizi sağlıyor
                while(fscanf(dosya,"%s %d %s %d\n",dosya_ismi, &dosya_sifre, dosya_iban, &dosya_bakiye)!=EOF) {
                    if (strcmp(kullanici_adi,dosya_ismi)==0 && (sifre==dosya_sifre)) {
                        dosyada_varmi=1;
                        break;
                    }
                }
                fclose(dosya);
                if (dosyada_varmi == 1) {
                    while (1) {
                        printf("\n");
                        printf("  .____________________________________.\n");
                        printf("  |          GİRİŞ BAŞARILI            |\n");
                        printf("  |           HESAP ÖZETİ              |\n");
                        printf("  |____________________________________|\n");
                        printf("  |                                    |\n");

                        printf("  |  Sayın    :%s                      |\n",kullanici_adi);
                        printf("  |  Bakiyeniz:%dTL                   |\n",dosya_bakiye);
                        printf("  |  İbanınız :%s            |\n",dosya_iban);
                        printf("  |____________________________________|\n");
                        system("timeout /t 2 > nul");
                        printf("  .____________________________________.\n");
                        printf("  |                                    |\n");
                        printf("  |             İŞLEMLER               |\n");
                        printf("  |____________________________________|\n");
                        printf("  |                                    |\n");

                        printf("  | [1] >> Para Yatırma                |\n");
                        printf("  | [2] >> Para Çekme                  |\n");
                        printf("  | [3] >> EFT/Havale                  |\n");
                        printf("  | [4] >> Çıkış                       |\n");
                        printf("  |                                    |\n");
                        printf("  !____________________________________!\n");
                        printf("\n");
                        printf("  >> Seçiminiz:");
                        scanf("%d",&secim2);
                        switch (secim2) {
                            case 1: {
                                printf("\n");
                                printf("  ._____________________________________.\n");
                                printf("  |                                     |\n");
                                printf("  |          PARA YATIRMA MENÜSÜ        |\n");
                                printf("  |_____________________________________|\n");
                                printf("  |                                     |\n");

                                printf("  | [+] Yatırmak İstediğiniz Tutar : ");
                                scanf("%d",&tutar);
                                printf("  |                                    |\n");
                                printf("  !____________________________________!\n");
                                printf("\n");
                                dosya_bakiye += tutar;
                                bakiye_guncelle(kullanici_adi,dosya_bakiye);
                                printf("   >> İŞLEM BAŞARILI  ");
                                printf("\n");
                                break;

                            }
                            case 2: {
                                printf("\n");
                                printf("  .___________________________________.\n");
                                printf("  |                                   |\n");
                                printf("  |          PARA ÇEKME MENÜSÜ        |\n");
                                printf("  |___________________________________|\n");
                                printf("  |                                   |\n");

                                printf("  | [+] Çekmek İstediğiniz Tutar : ");
                                scanf("%d",&tutar);

                                printf("  |                                    |\n");
                                printf("  !____________________________________!\n");
                                printf("\n");
                                if (tutar>dosya_bakiye) {
                                    printf("\n");
                                    printf("\a");
                                    printf("  .____________________________________.\n");
                                    printf("  |                                    |\n");
                                    printf("  |    [-] Yetersiz Bakiye             |\n");
                                    printf("  !____________________________________!\n");
                                    printf("\n");

                                }
                                else {
                                    dosya_bakiye -= tutar;
                                    bakiye_guncelle(kullanici_adi, dosya_bakiye);
                                }
                                break;
                            }
                            case 3: {
                                dosya_bakiye = iban_para_gonder(kullanici_adi, dosya_bakiye);
                                break;
                            }
                            case 4: {
                                printf("\n");
                                printf("  .____________________________________.\n");
                                printf("  |                                    |\n");
                                printf("  | [-] Çıkış Yapılıyor                |\n");
                                printf("  !____________________________________!\n");
                                printf("\n");
                                system("timeout /t 2 > nul");
                                return 0;
                            }
                        }
                    }
                }
                else {
                    printf("\n");
                    printf("\a");
                    printf("  ._____________________________________.\n");
                    printf("  |                                     |\n");
                    printf("  |  [!] HATALI KULLANICI ADI VEYA      |\n");
                    printf("  |      GEÇERSİZ ŞİFRE GİRDİNİZ        |\n");
                    printf("  |                                     |\n");
                    printf("  |_____________________________________|\n");
                    printf("\n");
                    // 3 saniye bekler
                    system("timeout /t 3 > nul");
                }
                break;
            }
            case 3: {
                printf("\n");
                printf("  ._____________________________________.\n");
                printf("  |           Çıkış Yapılıyor           |\n");
                printf("  |_____________________________________|\n");
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
/* -------- BAKIYE GUNCELLEME -------- */
void bakiye_guncelle(char ad[], int yeni_bakiye) {
    char dosya_ad[50], dosya_iban[30];
    int dosya_sifre, dosya_bakiye;
    // gecici diye dosya açmamız para çekme yatırma kısmının çalışmasını saglıyor onu oraya yazıp daha sonrasında işlem tamamlandığında gerçek dosyaya aktarımı sağlanıyor
    FILE *dosya = fopen("kullanicilar1.txt", "r");
    FILE *gecici = fopen("gecici.txt", "w");

    while (fscanf(dosya, "%s %d %s %d", dosya_ad, &dosya_sifre,
                  dosya_iban, &dosya_bakiye) != EOF) {

        if (strcmp(ad, dosya_ad) == 0)
            fprintf(gecici, "%s %d %s %d\n", dosya_ad, dosya_sifre, dosya_iban, yeni_bakiye);
        else
            fprintf(gecici, "%s %d %s %d\n", dosya_ad, dosya_sifre, dosya_iban, dosya_bakiye);
                  }

    fclose(dosya);
    fclose(gecici);
    // kullanıcılar1 dosyası silinip gecici dosyanın isminin kullanıcı yapıyoruz bu sayade para güncelleme işlemimiz sıkıntısısz çalışıyor
    remove("kullanicilar1.txt");
    rename("gecici.txt", "kullanicilar1.txt");
}
/* ----------- IBAN PARA GONDERME ------------ */
int iban_para_gonder(char gonderen[], int bakiye) {

    char hedef_iban[30], ad[50], iban[30];
    int sifre, dosya_bakiye, tutar, bulundu = 0;
    printf("\n");
    printf("  .___________________________________.\n");
    printf("  |                                   |\n");
    printf("  |         EFT/HAVALE MENÜSÜ         |\n");
    printf("  !___________________________________!\n");
    printf("  |                                   |\n");

    printf("  |   [+]  IBAN:                       ");
    scanf("%s", hedef_iban);
    printf("  |   [+]  Tutar :    ");
    scanf("%d", &tutar);
    printf("  |                                   |\n");
    printf("  !___________________________________!\n");
    printf("\n");

    if (tutar > bakiye) {
        printf("\n");
        printf("\a");
        printf("  .______________________.\n");
        printf("  |   Yetersiz bakiye!   |\n");
        printf("  !______________________!\n");
        printf("\n");
        system("timeout /t 2 > nul");

        return bakiye;
    }

    FILE *dosya = fopen("kullanicilar1.txt", "r");
    FILE *gecici = fopen("gecici.txt", "w");

    while (fscanf(dosya, "%s %d %s %d", ad, &sifre, iban, &dosya_bakiye) != EOF) {

        if (strcmp(ad, gonderen) == 0)
            fprintf(gecici, "%s %d %s %d\n", ad, sifre, iban, dosya_bakiye - tutar);
        else if (strcmp(iban, hedef_iban) == 0) {
            fprintf(gecici, "%s %d %s %d\n", ad, sifre, iban, dosya_bakiye + tutar);
            bulundu = 1;
        }
        else
            fprintf(gecici, "%s %d %s %d\n", ad, sifre, iban, dosya_bakiye);
    }

    fclose(dosya);
    fclose(gecici);

    if (!bulundu) {
        printf("\n");
        printf("\a");
        printf("  ._____________________________.\n");
        printf("  |    [-] IBAN bulunamadi!    |\n");
        printf("  !_____________________________!\n");
        printf("\n");
        system("timeout /t 2 > nul");

        remove("gecici.txt");
        return bakiye;
    }

    remove("kullanicilar1.txt");
    rename("gecici.txt", "kullanicilar1.txt");

    return bakiye-tutar;
}
/*-------------ŞİFRE GİZLEME---------------*/
int sifre_al() {
    int girilenSifre = 0 ;
    int i = 0;
    char tus;

    while (1) {
        tus = _getch(); // tuşu okumak için
        // enter tuşunun ascı kodu 13
        if (tus == 13 )  {
            break;
        }
        else if (tus == 8 ) {              // Backspace tuşu
            if (i > 0) {
                i--;
                girilenSifre /=10;  // sayının son basamağını matematiksel olarak siler
                printf("\b \b");
            }
        }
        else if (tus >= '0' && tus <= '9' ) {
            girilenSifre = (girilenSifre * 10) + (tus - '0');
            printf("*");
            i++;
        }
    }
    return girilenSifre;
}
