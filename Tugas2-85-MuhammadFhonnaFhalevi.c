#include <stdio.h>
#include <stdlib.h>

void daftar_menu(), belanja();
typedef struct a{
    int harga1;
}menu;

int main(){
    int menu1;

    do{
        printf("\n========================================\n");
        printf("Selamat datang di Toko Pangan Lampineung \n");
        printf("========================================\n");
        printf("1. Daftar menu\n");
        printf("2. Belanja\n");
        printf("3. Keluar\n\n");
    do {
        printf("Pilihan Anda : ");
        scanf("%d", &menu1);         
        if (menu1 > 3 || menu1 < 1){
            printf("Maaf input Anda tidak sesuai !\n");
        }
    }
    while (menu1 > 3 || menu1 < 1);

    switch (menu1){

            case 1:
                daftar_menu();
                continue;
                
            case 2:
                belanja();
                continue;

            case 3:
                exit (1);

            default:
                printf("Maaf, input anda tidak sesuai!");
                break;
        }
    }while(menu1 >= 1 && menu1 <= 3);
}
void daftar_menu(){
    int i;
    char enter;
    int harga2[6]={0,160000,15000,40000,14000,8000};
    menu pangan[6];
    for (i = 0; i <6 ; i++){
     pangan[i].harga1 = harga2[i];
    }
    printf("+----+---------------------+---------------+\n");
    printf("| No |        Menu         |     Harga     |\n");
    printf("+----+---------------------+---------------+\n");
    printf("|  1 |  Beras              |Rp. %d     |\n", pangan[1].harga1);
    printf("|  2 |  Minyak goreng      |Rp. %d      |\n", pangan[2].harga1);
    printf("|  3 |  Telur              |Rp. %d      |\n", pangan[3].harga1);
    printf("|  4 |  Gula               |Rp. %d      |\n", pangan[4].harga1);
    printf("|  5 |  Garam              |Rp. %d       |\n", pangan[5].harga1);
    printf("+----+---------------------+---------------+\n\n");
    
    printf("Tekan Enter untuk lanjut...");
    scanf("%c",&enter);
    getchar();
}

void belanja() {
    int harga2[6] = {0,160000,15000,40000,14000,8000};
    int b, c, harga, total = 0, uang, uangtmbh;
    char enter2;
    char ulang[]={'y','t'};

    do {
        do {
            printf("Input nomor menu : ");
            scanf("%x", &b);
            if (b < 1 || b > 5){
                printf("Maaf, input anda tidak sesuai!\n");
            }
        }while (b < 1 || b > 5);

        if (b >= 1 || b <= 5){
                printf("Input banyak menu yang diinginkan : ");
                scanf("%d", &c);
                harga = c * harga2[b];
                total += harga;

        }
        do {
            printf("apakah Anda ingin belanja lagi (y/t)? : ");
            scanf("%s", ulang);
            getchar();

            if ((*ulang != 'y' ) && (*ulang !='t'))
                printf("Maaf, input anda tidak sesuai!\n");

        } while ((*ulang != 'y' ) && (*ulang !='t'));
    } while (*ulang=='y');

    printf("\nTotal belanjaan : Rp. %d \n", total);
    printf("Masukkan uang Anda : Rp. ");
    scanf("%d", &uang);
    if(total <= uang){
        printf("Kembalian Anda : Rp. %d\n", uang-total);
    }
    else if(total > uang){
        printf("Uang anda tidak cukup : Rp. %d\n", total-uang);
        printf("Masukkan uang tambahan : Rp. ");
        scanf("%d", &uangtmbh);
        uang = uang + uangtmbh;
        printf("Kembalian Anda : Rp. %d\n\n", uang-total);
    }
    printf("-------------------------------\n");
    printf("Terima kasih sudah berbelanja!\n\n");
    printf("Tekan Enter untuk lanjut...");
    scanf("%c",&enter2);
    getchar();
}
