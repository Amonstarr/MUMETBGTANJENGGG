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
} data_operator, operatoraktif;

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
void menuoperator();
void manajemenPC();
void manajemenakun();
void tambahmenu();
void ubahstatus();
void hapus_akun_cust();
void lihat_akun_cust();
void install_sistem();
void install_game();
void install_program();
void hapus_game();
void hapus_program();



int main()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
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
        loginoperator(3);
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

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    printf("1. Registrasi Operator\n2. Registrasi Customer\n3. Keluar\n");
    printf("pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        registrasi_operator();
        break;

    case 2:
        resigtrasi_customer();
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

void registrasi_operator()
{
    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");
    FILE *akun;
    struct operator new_operator = {0};

    akun = fopen("akun_operator.dat", "ab");

    printf("Masukkan Username : ");
    gets(new_operator.username);
    printf("Masukkan Password : ");
    gets(new_operator.password);
    printf("Masukkan Email : ");
    gets(new_operator.email);
    printf("Masukkan Nomor Telepon : ");
    gets(new_operator.nomor_telepon);

    fwrite(&new_operator, sizeof(new_operator), 1, akun);
    fclose(akun);

    printf("Registrasi Berhasil\n");
    system("pause");
    system("cls");
    main();
}

int loginoperator(int attempt)
{
    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    FILE *akun_operator;
    struct operator data_operator;

    akun_operator = fopen("akun_operator.dat", "rb");

    char username[30], password[30];

    printf("Masukkan Username : ");
    gets(username);

    while (fread(&data_operator, sizeof(data_operator), 1, akun_operator)==1)
    {
        if (strcmp(data_operator.username, username)==0)
        {
            printf("Masukkan Password : ");
            gets(password);
            if (strcmp(data_operator.password, password)==0)
            {
                operatoraktif = data_operator;
                fclose(akun_operator);
                system("cls");
                attempt = -1;
                break;
            }
            else
            {
                attempt--;
            }
        }
    }
    if (attempt == -1)
    {
        menuoperator();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------- D'WARNET -------------------------\n");
        printf("============================================================\n");
        fclose(akun_operator);
        loginoperator(attempt);
    }
    else
    {
        printf("Maaf kesempatan percobaan sudah habis\n");
        system("pause");
        system("cls");
        fclose(akun_operator);
        main();
    }
}

void menuoperator()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    printf("1. Manajemen PC Customer\n2. Manajemen Akun Customer\n3. Tambah Menu Pesanan\n4. Ubah Status Pesanan Customer\n5. Log Out\n");
    printf("pilih menu (1/2/3/4/5) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        manajemenPC();
        break;

        case 2:
        manajemenakun();
        break;

        case 3:
        tambahmenu();
        break;

        case 4:
        ubahstatus();
        break;

        case 5:
        printf("Berhasil Logout\n");
        system("pause");
        system("cls");
        main();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        break;
    }
}

void manajemenakun()
{
    int menu;

    printf("====================== Manajemen Akun =====================\n");
    printf("1. Hapus Akun Customer\n2. Lihat Akun Customer\n3. Kembali");
    printf("pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");
    
    switch (menu)
    {
        case 1:
        hapus_akun_cust();
        break;

        case 2:
        lihat_akun_cust();
        break;

        case 3:
        system("pause");
        system("cls");
        menuoperator();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        break;
    }
}

void manajemenPC()
{
    int menu;

    printf("====================== Manajemen Akun =====================\n");
    printf("1. Install Windows\n2. Install Game\n3. Install Program\n4. Hapus Game\n5. Hapus Program\n6. Kembali");
    printf("pilih menu (1/2/3/4/5/6) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");
    
    switch (menu)
    {
        case 1:
        install_sistem();
        break;

        case 2:
        install_game();
        break;

        case 3:
        install_program();
        break;

        case 4:
        hapus_game();
        break;

        case 5:
        hapus_program();
        break;

        case 6:
        system("pause");
        system("cls");
        menuoperator();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        break;
    }
}
