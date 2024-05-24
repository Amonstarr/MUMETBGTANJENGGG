#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct operator
{
    char username[20], password[20], email[20], nomor_telepon[20], menu[20], status[20];
} data_operator, operator_aktif;

struct customer
{
    char username[20], password[20], email[20], nomor_telepon[20], menu[20], status[20];
    int saldo, harga, jumlah, pengeluaran;
} data_customer, customer_aktif;

struct pesan
{
    char nama[20];
    int harga;
} pesan;

struct game
{
    char game[20], program[20];
    int sistem;
} game;

struct installSistem {
    char namaSistem[50];
};

int main()
{
    system("cls");
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");
    printf("1. Registrasi Akun\n2. Login\n3. Keluar\n");
    printf("pilih menu (1/2/3) : "); scanf("%d", &menu);   
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        menu_registrasi();
        break;

        case 2:
        menu_login();
        break;

        case 3:
        printf("Exiting the program\n");
        break;

        default:
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
    printf("------------------------ Registrasi ------------------------\n");
    printf("============================================================\n");

    printf("1. Registrasi Operator\n2. Registrasi Customer\n3. Keluar\n");
    printf("pilih menu (1/2/3) : "); scanf("%d", &menu);
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

void menu_login()
{
    int menu;

    printf("============================================================\n");
    printf("--------------------------- Login --------------------------\n");
    printf("============================================================\n");

    printf("1. Login Operator\n2. Login Customer\n3. Kembali\n");
    printf("pilih menu (1/2/3) : "); scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        login_operator(3);
        break;

        case 2:
        login_customer(3);
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
    printf("-------------------------- Reg OP --------------------------\n");
    printf("============================================================\n");
    FILE *akun;
    struct operator data_operator = {0};

    akun = fopen("akun_operator.dat", "ab");

    printf("Masukkan Username : ");
    gets(data_operator.username);
    printf("Masukkan Password : ");
    gets(data_operator.password);
    printf("Masukkan Email : ");
    gets(data_operator.email);
    printf("Masukkan Nomor Telepon : ");
    gets(data_operator.nomor_telepon);

    fwrite(&data_operator, sizeof(data_operator), 1, akun);
    fclose(akun);

    printf("Registrasi Berhasil\n");
    system("pause");
    system("cls");
    menu_login();
}

void resigtrasi_customer()
{
    printf("============================================================\n");
    printf("------------------------- Reg Cust -------------------------\n");
    printf("============================================================\n");
    FILE *akun;
    struct customer data_customer = {0};

    akun = fopen("akun_customer.dat", "ab");

    printf("Masukkan Username : ");
    gets(data_customer.username);
    printf("Masukkan Password : ");
    gets(data_customer.password);
    printf("Masukkan Email : ");
    gets(data_customer.email);
    printf("Masukkan Nomor Telepon : ");
    gets(data_customer.nomor_telepon);

    fwrite(&data_customer, sizeof(data_customer), 1, akun);
    fclose(akun);

    printf("Registrasi Berhasil\n");
    system("pause");
    system("cls");
    menu_login();
}

int login_operator(int attempt)
{
    printf("============================================================\n");
    printf("------------------------- Login OP -------------------------\n");
    printf("============================================================\n");

    FILE *akun;
    struct operator data_operator;

    akun = fopen("akun_operator.dat", "rb");

    char username[30], password[30];

    printf("Masukkan Username : ");
    gets(username);

    while (fread(&data_operator, sizeof(data_operator), 1, akun)==1)
    {
        if (strcmp(data_operator.username, username)==0)
        {
            printf("Masukkan Password : ");
            gets(password);
            if (strcmp(data_operator.password, password)==0)
            {
                operator_aktif = data_operator;
                fclose(akun);
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
        menu_operator();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------- D'WARNET -------------------------\n");
        printf("============================================================\n");
        fclose(akun);
        login_operator(attempt);
    }
    else
    {
        printf("Maaf kesempatan percobaan sudah habis\n");
        system("pause");
        system("cls");
        fclose(akun);
        main();
    }
}

int login_customer(int attempt)
{
    printf("============================================================\n");
    printf("------------------------ Login Cust ------------------------\n");
    printf("============================================================\n");

    FILE *akun;
    struct customer data_customer;

    akun = fopen("akun_customer.dat", "rb");

    char username[30], password[30];

    printf("Masukkan Username : ");
    gets(username);

    while (fread(&data_customer, sizeof(data_customer), 1, akun)==1)
    {
        if (strcmp(data_customer.username, username) == 0)
        {
            printf("Masukkan Password : ");
            gets(password);
            if (strcmp(data_customer.password, password)==0)
            {
                customer_aktif = data_customer;
                fclose(akun);
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
        menu_customer();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------- D'WARNET -------------------------\n");
        printf("============================================================\n");
        printf("Username atau password salah. Sisa percobaan %d \n", attempt);
        fclose(akun);
        login_operator(attempt);
    }
    else
    {
        printf("Maaf kesempatan percobaan sudah habis\n");
        system("pause");
        system("cls");
        fclose(akun);
        main();
    }
}

void menu_operator()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    printf("1. Manajemen PC Customer\n2. Manajemen Akun Customer\n3. Tambah Menu Pesanan\n4. Ubah Status Pesanan Customer\n5. Log Out\n");
    printf("pilih menu (1/2/3/4/5) : "); scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        manajemen_pc();
        break;

        case 2:
        manajemen_akun();
        break;

        case 3:
        tambah_menu();
        break;

        case 4:
        ubah_status(customer_aktif.username);
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

void menu_customer()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    printf("1. Pilih game\n2. Pesan makanan/minuman\n3. Lihat status makanan\n4. informasi saldo\n5. Kembali\n");
    printf("pilih menu (1/2/3/4/5) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        pilih_game();
        break;

        case 2:
        pesan_makan();
        break;

        case 3:
        menu_lihat_status();
        break;

        case 4:
        informasi_saldo();
        break;

        case 5:
        printf("Berhasil Kembali\n");
        system("pause");
        system("cls");
        main();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        main();
        break;
    }
}

void manajemen_akun()
{
    int menu;

    printf("====================== Manajemen Akun =====================\n");
    printf("1. Hapus Akun Customer\n2. Lihat Akun Customer\n3. Kembali\n");
    printf("pilih menu (1/2/3) : "); scanf("%d", &menu);
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
        menu_operator();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        break;
    }
}

void manajemen_pc()
{
    int menu;

    printf("====================== Manajemen PC =====================\n");
    printf("1. Install Windows\n2. Install\n3. Hapus\n4. Kembali\n");
    printf("pilih menu (1/2/3/4) : "); scanf("%d", &menu); 
    getchar();
    system("cls");
    
    switch (menu)
    {
        case 1:
        install_sistem();
        break;

        case 2:
        install();
        break;

        case 3:
        hapus();
        break;

        case 4:
        system("pause");
        system("cls");
        menu_operator();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        break;
    }
}

void lihat_akun_cust()
{

    FILE *file;
    struct customer customer_aktif;

    file = fopen("akun_customer.dat", "rb");

    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("Data Akun Customer:\n");
    while (fread(&data_customer, sizeof(data_customer), 1, file) == 1)
    {
        printf("Username: %s\n", data_customer.username);
        printf("Password: %s\n", data_customer.password);
        printf("Nomor telepon : %s\n", data_customer.nomor_telepon);
        printf("Email: %s\n", data_customer.email);
        printf("\n");
    }

    fclose(file);
    system("pause");
    system("cls");
    menu_operator();
}

void hapus_akun_cust()
{
    FILE *file;
    struct operator data_customer;

    file = fopen("akun_customer.dat", "rb");
    
    if (file == 0)
    {
        printf("Gagal membuka file\n");
        return;
    }

    printf("Data akun customer\n");

    while(fread(&data_customer, sizeof(data_customer), 1, file)==1)
    {
        printf("Username: %s\n", data_customer.username);
        printf("\n");
    }

    FILE *akun;
    FILE *akun2;

    char cari[20];

    akun = fopen("akun_customer.dat", "rb");
    akun2 = fopen("akun_customer2.dat", "wb");

    printf("Masukkan Username Akun Yang Ingin Dihapus : "); gets(cari);

    while (fread(&data_customer, sizeof(data_customer), 1, akun)==1)
    {
        if(strcmp(data_customer.username, cari)!=0){
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }

        fclose(akun);
        fclose(akun2);
        remove("akun");
        rename("akun2", "akun");
        printf("data berhasil dihapus\n");
        system("pause");
        menu_operator();
    }
}

void tambah_menu()
{
    FILE *menu;
    struct pesan pesan = {0};

    int pilih;

    printf("Tambah Menu\n");
    printf("1. Makanan\n");
    printf("2. Minuman\n");
    printf("Pilih jenis yang ingin ditambahkan: ");
    scanf("%d", &pilih);
    getchar();

    if (pilih == 1) {
        menu = fopen("menu_makanan.dat", "ab+");
        printf("Masukkan Nama Makanan: ");
    } else if (pilih == 2) {
        menu = fopen("menu_minuman.dat", "ab+");
        printf("Masukkan Nama Minuman: ");
    } else {
        printf("Pilihan tidak valid.\n");
        return;
    }

    gets(pesan.nama);
    printf("Masukkan Harga: ");
    scanf("%d", &pesan.harga);
    getchar();

    fwrite(&pesan, sizeof(pesan), 1, menu);
    fclose(menu);

    printf("Penambahan %s berhasil\n", (pilih == 1) ? "makanan" : "minuman");
    system("pause");
    system("cls");
    menu_operator();
}


void informasi_saldo()
{
    int jumlah, menu, hasil = 0;
    FILE *akun;
    FILE *akun2;

    struct customer customer_aktif;

    printf("========================= Menu Saldo ========================\n");
    printf("1. Cek saldo\n2. Topup saldo\n3. Kembali\n");
    printf("Pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    system("cls");

    switch (menu)
    {
        case 1:
        akun = fopen("akun_customer.dat", "rb");
        if (akun == NULL)
        {
        printf("Gagal membuka file");
        return;
        }
        int found = 0;
        char username[50];
        printf("Masukkan username: ");
        scanf("%s", username);
        while (fread(&customer_aktif, sizeof(customer_aktif), 1, akun) == 1)
        {
        if (strcmp(username, customer_aktif.username) == 0)
        {
            printf("Saldo Anda: Rp %d\n", customer_aktif.saldo);
            found = 1; 
            break;
        }
        }
        if (!found) 
        {
            printf("User tidak ditemukan.\n");
        }
        fclose(akun);
        system("pause");
        system("cls");
        break;



        case 2:
        hasil = customer_aktif.saldo;
        akun = fopen("akun_customer.dat", "rb");
        akun = fopen("akun_customer2.dat", "wb");

        printf("========================= Top Up ========================\n");
        printf("Masukkan jumlah top up saldo : Rp  ");
        scanf("%d", &jumlah);
        hasil = data_customer.saldo + jumlah;

        while (fread(&data_customer, sizeof(data_customer), 1, akun)==1)
        {
            if (strcmp(data_customer.username, customer_aktif.username)==0)
            {
                data_customer.saldo = hasil;
            }
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }
        printf("Top Up berhasil\nSaldo sekarang : Rp %d\n", hasil);
        fclose(akun);
        fclose(akun2);
        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        system("pause");
        system("cls");
        menu_customer();
        break;

        case 3:
        fclose(akun);
        menu_customer();
        break;

        default:
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
        informasi_saldo();
        break;
    }
}



void install_sistem() 
{
    FILE *sistem;
    struct installSistem sistem_info;
    int system_installed = 0;

    sistem = fopen("sistem.dat", "rb+");
    if (sistem == NULL) {
        sistem = fopen("sistem.dat", "wb+");
        if (sistem == NULL) {
            printf("Gagal Membuka File!\n");
            return;
        }
    }
    strcpy(sistem_info.namaSistem, "Windows 99");
    struct installSistem temp_info;
    while (fread(&temp_info, sizeof(struct installSistem), 1, sistem) == 1) {
        if (strcmp(temp_info.namaSistem, sistem_info.namaSistem) == 0) {
            system_installed = 1;
            break;
        }
    }
    if (system_installed) {
        printf("Sistem sudah terinstall.\n");
    } else {

        fseek(sistem, 0, SEEK_END);
        fwrite(&sistem_info, sizeof(struct installSistem), 1, sistem);
        printf("Sistem berhasil diinstall!\n");
    }

    fclose(sistem);
    system("pause");
    system("cls");
    menu_operator();
}

void pesan_makan() 
{
    FILE *menu;
    struct pesan pesan;
    int pilih;
    int jumlah;
    int total = 0;
    int found;
    char nama_pesan[50];


    printf("Pesan Menu\n");
    printf("1. Makanan\n");
    printf("2. Minuman\n");
    printf("Pilih jenis yang ingin dipesan: ");
    scanf("%d", &pilih);
    getchar();

    if (pilih == 1) {
        tampil_menu_makanan();
        menu = fopen("menu_makanan.dat", "rb");
    } else if (pilih == 2) {
        tampil_menu_minuman();
        menu = fopen("menu_minuman.dat", "rb");
    } else {
        printf("Pilihan tidak valid.\n");
        return;
    }

    if (!menu) {
        printf("Menu tidak ditemukan.\n");
        return;
    }

    printf("Masukkan Nama %s yang ingin dipesan: ", (pilih == 1) ? "Makanan" : "Minuman");
    gets(nama_pesan);

    found = 0;
    while (fread(&pesan, sizeof(pesan), 1, menu)) {
        if (strcmp(pesan.nama, nama_pesan) == 0) {
            printf("Masukkan Jumlah: ");
            scanf("%d", &jumlah);
            getchar();
            total = pesan.harga * jumlah;
            found = 1;
            break;
        }
    }
    fclose(menu);

    if (found) {
        printf("Total harga untuk %d %s adalah: %d\n", jumlah, nama_pesan, total);
    } else {
        printf("%s tidak ditemukan di menu.\n", nama_pesan);
    }

    system("pause");
    system("cls");
    bayar(total);
}

void tampil_menu_makanan() {
    FILE *menu;
    struct pesan pesan;

    menu = fopen("menu_makanan.dat", "rb");
    if (!menu) {
        printf("Menu makanan tidak ditemukan.\n");
        return;
    }

    printf("=== Menu Makanan ===\n");
    while (fread(&pesan, sizeof(pesan), 1, menu)) {
        printf("%s - Rp %d\n", pesan.nama, pesan.harga);
    }
    fclose(menu);
}

void tampil_menu_minuman() {
    FILE *menu;
    struct pesan pesan;

    menu = fopen("menu_minuman.dat", "rb");
    if (!menu) {
        printf("Menu minuman tidak ditemukan.\n");
        return;
    }

    printf("=== Menu Minuman ===\n");
    while (fread(&pesan, sizeof(pesan), 1, menu)) {
        printf("%s - Rp %d\n", pesan.nama, pesan.harga);
    }
    fclose(menu);
}

void bayar()
{
    int harga, total;
    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    FILE *akun;
    FILE *akun2;

    akun = fopen("akun_customer.dat", "rb");
    akun2 = fopen("akun_customer2.dat", "wb");

    if (total > customer_aktif.saldo)
    {
    printf("Mohon maaf saldo anda tidak mencukupi\n");
        fclose(akun);
        fclose(akun2);
        system("pause");
        system("cls");
        menu_customer();
    }
    else
    {
        while (fread(&data_customer, sizeof(data_customer), 1, akun) == 1)
        {
            if (strcmp(customer_aktif.username, data_customer.username) == 0)
            {
                data_customer.saldo -= harga;
                data_customer.pengeluaran += harga;
                data_customer.jumlah += 1;
            }
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }
        fclose(akun);
        fclose(akun2);
        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        printf("Pembayaran Berhasil\n");
        system("pause");
        system("cls");
        menu_customer();
    }
}

void ubah_status(const char *username) 
{
    FILE *akun;
    FILE *akun2;

    char tempStatus[20];
    int menu;

    akun = fopen("akun_customer.dat", "rb");
    akun2 = fopen("akun_customer2.dat", "wb");

    printf("Pilih Status baru : \n");
    printf("1. Belum dikerjakan\n2. Sedang dikerjakan\n3. Selesai\n");
    printf("Pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();

    switch (menu) {
        case 1:
            strcpy(tempStatus, "Belum dikerjakan\n");
            break;
        case 2:
            strcpy(tempStatus, "Sedang dikerjakan\n");
            break;
        case 3:
            strcpy(tempStatus, "Selesai\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            fclose(akun);
            fclose(akun2);
            return;
    }

    while (fread(&customer_aktif, sizeof(customer_aktif), 1, akun) == 1) {
        if (strcmp(customer_aktif.username, username) == 0) {
            strcpy(customer_aktif.status, tempStatus);
        }
        fwrite(&customer_aktif, sizeof(customer_aktif), 1, akun2);
    }
    fclose(akun);
    fclose(akun2);
    remove("akun_customer.dat");
    rename("akun_customer2.dat", "akun_customer.dat");
    printf("Status pesanan berhasil diubah\n");
    system("pause");
    system("cls");
    menu_customer();
}

void lihat_status(const char *username) 
{
    FILE *akun;

    akun = fopen("akun_customer.dat", "rb");
    if (!akun) {
        printf("Error: File akun_customer.dat not found.\n");
        return;
    }

    struct customer customer_data;
    int found = 0;
    while (fread(&customer_data, sizeof(customer_data), 1, akun) == 1) {
        if (strcmp(customer_data.username, username) == 0) {
            printf("Status pesanan untuk %s: %s\n", username, customer_data.status);
            found = 1;
            break;
        }
    }
    fclose(akun);

    if (!found) {
        printf("Username %s tidak ditemukan.\n", username);
    }
}

void menu_lihat_status() 
{
    char username[50];
    printf("Masukkan username untuk melihat status pesanan: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';
    lihat_status(username);
    system("pause");
    system("cls");
    menu_operator();
}

void install()
{
    FILE *menu;
    struct game newGame = {0};

    int pilih;

    printf("Install :\n");
    printf("1. Game\n");
    printf("2. Program\n");
    printf("Pilih yang ingin diinstall: ");
    scanf("%d", &pilih);
    getchar();

    if (pilih == 1) {
        menu = fopen("game.dat", "ab+");
        printf("Masukkan Nama Game: ");
        gets(newGame.game);
    } else if (pilih == 2) {
        menu = fopen("program.dat", "ab+");
        printf("Masukkan Nama Program: ");
        gets(newGame.program);
    } else {
        printf("Pilihan tidak valid.\n");
        return;
    }

    fwrite(&pesan, sizeof(pesan), 1, menu);
    fclose(menu);

    printf("Penambahan %s berhasil\n", (pilih == 1) ? "Game" : "Program");
    system("pause");
    system("cls");
    menu_operator();
}

void pilih_game() {
    FILE *file;
    struct game newGame;
    int pilih;

    printf("\nPilih program/game:\n");
    printf("1. Game\n");
    printf("2. Program\n");
    printf("3. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &pilih);

    switch (pilih) 
    {
        case 1:
        file = fopen("game.dat", "rb");
        if (file == NULL) {
            printf("Tidak ada game yang tersedia saat ini.\n");
            return;
        }
        printf("Daftar Game:\n");
        while (fread(&newGame, sizeof(newGame), 1, file) == 1) 
        {
            printf("%s\n", newGame.game);
        }
        fclose(file);
        break;

        case 2:
        file = fopen("program.dat", "rb");
        if (file == NULL) {
            printf("Tidak ada program yang tersedia saat ini.\n");
            return;
        }
        printf("Daftar Program:\n");
        while (fread(&newGame, sizeof(newGame), 1, file) == 1) 
        {
            printf("%s\n", newGame.program);
        }
        fclose(file);
        break;

        case 3:
        printf("Terima kasih!\n");
        menu_customer();
        break;

        default:
            printf("Pilihan tidak valid.\n");
            pilih_game();
    }
}

hapus() 
{
    FILE *file;
    int pilih;
    struct game data;
    char nama[20];
    int found = 0;

        printf("\nMenu Operator:\n");
        printf("1. Hapus Game\n");
        printf("2. Hapus Program\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);
        switch (pilih) {
            case 1:
                hapus_game();
                break;
            case 2:
                hapus_program();
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

}

void hapus_game()
{
    struct game data;
    char nama[20];
    int found = 0;

    FILE *file;
    FILE *file2;

    char cari[20];

    file = fopen("game.dat", "rb");
    file2 = fopen("game2.dat", "wb");

    printf("Masukkan Nama Game Yang Ingin Dihapus : "); gets(cari);

    while (fread(&data_customer, sizeof(data_customer), 1, file)==1)
    {
        if (strcmp(data.program, nama) == 0)
        {
            fwrite(&data, sizeof(data), 1, file);
        }

        fclose(file);
        fclose(file2);
        remove("game.dat");
        rename("game2.dat", "game.dat");
        printf("Game berhasil dihapus");
        system("pause");
        menu_operator();
    }
}

void hapus_program()
{
    struct game data;
    char nama[20];
    int found = 0;

    FILE *file;
    FILE *file2;

    char cari[20];

    file = fopen("program.dat", "rb");
    file2 = fopen("program2.dat", "wb");

    printf("Masukkan Nama program Yang Ingin Dihapus : "); gets(cari);

    while (fread(&data_customer, sizeof(data_customer), 1, file)==1)
    {
        if (strcmp(data.program, nama) == 0)
        {
            fwrite(&data, sizeof(data), 1, file);
        }

        fclose(file);
        fclose(file2);
        remove("program.dat");
        rename("program2.dat", "program.dat");
        printf("program berhasil dihapus");
        system("pause");
        menu_operator();
    }
}
