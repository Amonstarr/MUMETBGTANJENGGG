#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct operator
{
    char username[20];
    char password[20];
    char email[20];
    char nomor_telepon[20];
    char menu[20];
} data_operator, operator_aktif;

struct customer
{
    char username[20];
    char password[20];
    char email[20];
    char nomor_telepon[20];
    char menu[20];
} data_customer, customer_aktif;

void menu_registrasi();
void registrasi_operator();
void resigtrasi_customer();
int loginoperator();
int logincustomer();


int main()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------ D'WARNET -------------------------\n");
    printf("============================================================\n");
    printf("1.Registrasi Akun\n2.Login Operator\n3.Login Customer\n4.Keluar\n");
    printf("pilih menu (1/2/3/4/5) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        menu_registrasi();
        break;

        case 2:
        loginoperator();
        break;

        case 3:
        logincustomer();
        break;

        case 4:
        printf("Exiting the program\n");
        break;

        case 5:
        printf("Maaf Pilihan Tidak Tersedia\n");
        main();
        break;
    }
    return 0;
}

void menu_registrasi()
{
    int menu;

    printf("1.Registrasi Operator\n2.Registrasi Customer\n3.Keluar\n");
    printf("pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        printf("============================================================\n");
        printf("------------------------ D'WARNET -------------------------\n");
        printf("============================================================\n");
        registrasi_operator();
        break;

    case 2:
        printf("============================================================\n");
        printf("------------------------ D'WARNET -------------------------\n");
        printf("============================================================\n");
        resigtrasi_customer;
        break;

    case 3:
        main();
        break;

    default:
        printf("Maaf Pilihan Tidak Tersedia\n");
        main();
        break;
    }
}

void registrasi_seller()
{
    printf("============================================================\n");
    printf("------------------------ D'WARNET -------------------------\n");
    printf("============================================================\n");
    FILE *akun;
    struct operator baru_operator = {0};

    akun = fopen("akun_operator.dat", "ab");

    printf("Masukkan Username : ");
    gets(baru_operator.username);
    printf("Masukkan Password : ");
    gets(baru_operator.password);
    printf("Masukkan Email : ");
    gets(baru_operator.email);
    printf("Masukkan Nomor Telepon : ");
    gets(baru_operator.nomor_telepon);

    fwrite(&baru_operator, sizeof(baru_operator), 1, akun);
    fclose(akun);

    printf("Registrasi Berhasil\n");
    system("pause");
    system("cls");
    main();
}

