// 1
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <windows.h>
    #include <conio.h>

struct data {
    int id;
    char nama[30], tanggal[20], harga[30], telp[20];
}dat[15];

struct node {
    char hist[100];
    struct node *next;
};

int jum=0, tot=0, temp, oy, result, x;
char temps[100];
struct node*head = NULL;

void letak();
void Ulang_Login();
void Tampilan_Tetap();
void Mencari();

// 2

 void letak (int x, int y){
        COORD CRD;
        CRD.X=x;
        CRD.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
    }

void sama() {
          printf( "\t\t\t");
        printf("+");
         for(int i=0; i<51; i++)
        {
            printf("=");Sleep(1);
        }
        printf("+");printf("\n");
}

void kosong() {
        printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
}

void garis() {
        printf( "\t\t\t");
        printf("|");
         for(int i=0; i<51; i++)
        {
            printf("-");Sleep(1);
        }
        printf("|");printf("\n");
}

void Tampilan_Tetap() {

    printf("\n\n");
    sama();
    kosong();
//v-spasi tulisan satu
        printf( "\t\t\t");printf("|");
        for(int i=0; i<12; i++)
        {
            printf(" ");Sleep(1);
        }
        printf("\033[1;34mSelamat Datang Dalam Program\033[0m");
 //v-spasi tulisan dua
         for(int i=0; i<11; i++)
        {
            printf(" ");Sleep(1);
        } printf("|");printf("\n");
 //v-spasi tulisan satu
         printf( "\t\t\t");printf("|");
        for(int i=0; i<7; i++)
        {
            printf(" ");Sleep(1);
        }
        printf("\033[1;34m     Database Toko Klontong kami      \033[0m");
         for(int i=0; i<6; i++)
        {
            printf(" ");Sleep(1);
        } printf("|");printf("\n");

    kosong();
    garis();
    kosong();

         printf( "\t\t\t");
        for(int i=0; i<15; i++)
        {
            printf(" ");Sleep(1);
        }
//v-waktu

        printf("\033[1;32m");
        time_t mytime;
		mytime = time(NULL);
		printf(ctime(&mytime));
        printf("\033[0m");
//v-spasi dua
         printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
//v-garis penutup

    garis();
    kosong();kosong();kosong();kosong();kosong();kosong();kosong();kosong();kosong();kosong();kosong();

}

void Mencari(){
    int i, j;
    struct data temp;

    // sorting the data array by book ID in ascending order using bubble sort
    for(i=0; i<tot-1; i++){
        for(j=0; j<tot-i-1; j++){
            if(dat[j].id > dat[j+1].id){
                temp = dat[j];
                dat[j] = dat[j+1];
                dat[j+1] = temp;
            }
        }
    }
}


void append(struct node** head_ref, char histo[]) {

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = * head_ref;

    strcpy(new_node->hist, histo);
    new_node->next = NULL;

    if(*head_ref == NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// 3

void printlist(struct node *node){
    while(node != NULL){
        printf("%s \n", node->hist);
        node = node->next;
    }
}

// 4
void tambah(){
        FILE *file = fopen("data_barang.txt", "a");
    if (file == NULL) {
    printf("\033[1;31mGagal membuka file\n\033[0m");
    return;
    }
    Tampilan_Tetap();
    letak(26,13);
    printf("\033[1;34m --- Tambah Data Buku --- \033[0m");
    letak(26,14);
    printf(" Masukan Jumlah Data Buku Yang Dimasukan : "); scanf("%d", &jum);

    for(int i = 0; i < jum; i++) {
        system("cls");
        Tampilan_Tetap();
        letak(26,13);
        printf("\033[1;34m --- Tambah Data Buku --- \033[0m");
        letak(26,14);
        printf(" Masukan Jumlah Data Buku Yang Dimasukan : %d", jum);

        letak(26,16);
        printf(" Data ke %d", i+1);
        letak(26,17);
        printf(" Tanggal       : ");
        letak(26,18);
        printf(" Nama Barang   : ");
        letak(26,19);
        printf(" Kode Barang   : ");
        letak(26,20);
        printf(" Harga         : ");

        letak(43,17);
        scanf(" %[^\n]%*c", &dat[i+tot].tanggal);
        letak(43,18);
        scanf(" %[^\n]%*c", &dat[i+tot].nama);
        letak(43,19);
        scanf(" %d", &dat[i+tot].id);
        letak(43,20);
        scanf(" %[^\n]%*c", &dat[i+tot].harga);
        // tulis data ke file
        fprintf(file, "%s %s %d %s\n", dat[i+tot].tanggal, dat[i+tot].nama, dat[i+tot].id, dat[i+tot].harga);
        }
        tot += jum;

        fclose(file);
        printf("\033[1;32m\t\t\t Data berhasil ditambahkan\n\033[0m");
        system("pause");
        system("cls");

    }


// 6

void lihat() {
    FILE *file = fopen("data_barang.txt", "r");
    if (file == NULL) {
        printf("\033[1;31mGagal membuka file\n\033[0m");
        return;
    }
    int i = 0;
    while (fscanf(file, "%s %s %d %s", dat[i].tanggal, dat[i].nama, &dat[i].id, dat[i].harga) != EOF) {
        if(i==0 || i%3==0) {
            system("cls");
            Tampilan_Tetap();
            letak(26,13);
            printf("\033[1;34m --- Daftar Data Barang --- \n\n\033[0m");
            letak(26,15);
            printf(" Data ke %d", i+1);
            letak(26,16);
            printf(" Tanggal Input           :%s", dat[i].tanggal);
            letak(26,17);
            printf(" Nama Barang             :%s", dat[i].nama);
            letak(26,18);
            printf(" Kode Barang             :%d", dat[i].id);
            letak(26,19);
            printf(" Harga Barang            :%s", dat[i].harga);
		getch();
        }else if(i==1 || i==4 || i==7 || i==10 || i==13) {
            letak(26,21);
            printf(" Data ke %d", i+1);
            letak(26,22);
            printf(" Tanggal Input           :%s", dat[i].tanggal);
            letak(26,23);
            printf(" Nama Barang             :%s", dat[i].nama);
            letak(26,24);
            printf(" Kode Barang             :%d", dat[i].id);
            letak(26,25);
            printf(" Harga Barang            :%s", dat[i].harga);
		getch();
        }else {
            letak(26,27);
            printf(" Data ke %d", i+1);
            letak(26,28);
            printf(" Tanggal Input           :%s", dat[i].tanggal);
            letak(26,29);
            printf(" Nama Barang             :%s", dat[i].nama);
            letak(26,30);
            printf(" Kode Barang             :%d", dat[i].id);
            letak(26,31);
            printf(" Harga Barang            :%s", dat[i].harga);
            getch();
        }
    }
    letak(26,35);
    printf("\033[1;32m\n\n\t\t\t Tekan Enter Untuk Kembali ke Menu\033[0m"); getch();
}// 8
// punya Ikky
void urut() {
    int temp;
    char temps[30];
    Tampilan_Tetap();
    for (int i = 0; i < tot -1; i++) {
    for (int j = 0; j < tot -i -1; j++) {
    if (dat[j].id > dat[j+1].id) {
        temp = dat[j].id;
        dat[j].id = dat[j+1].id;
        dat[j+1].id = temp;

            strcpy(temps, dat[j].nama);
            strcpy(dat[j].nama, dat[j+1].nama);
            strcpy(dat[j+1].nama, temps);

            strcpy(temps, dat[j].tanggal);
            strcpy(dat[j].tanggal, dat[j+1].tanggal);
            strcpy(dat[j+1].tanggal, temps);

            strcpy(temps, dat[j].harga);
            strcpy(dat[j].harga, dat[j+1].harga);
            strcpy(dat[j+1].harga, temps);

            strcpy(temps, dat[j].telp);
            strcpy(dat[j].telp, dat[j+1].telp);
            strcpy(dat[j+1].telp, temps);
        }
    }
}
printf("\033[1;32m\t\t\tData berhasil diurutkan berdasarkan Kode Barang\n\033[0m");
system("pause");
system("cls");
}

//11
void mencari(){
    int oy;
    Tampilan_Tetap();
    letak(26,13);
    printf("\033[1;32m --- Pencarian Data Barang --- \033[0m");
    letak (26,15);
    printf("Masukkan Kode Barang: ");
    scanf("%d", &oy);

    char filename[] = "data_barang.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\033[1;31mGagal membuka file\n\033[0m");
        return;
    }

    int result = 0, x;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s %d %s", dat[tot].tanggal, dat[tot].nama, &dat[tot].id, dat[tot].harga);
        if (oy == dat[tot].id){
            result = 1;
            break;
        }
        tot++;
    }

    fclose(file);

    if (result == 1){
        letak (26,17);
        printf("\033[1;32m --- Data Ditemukan --- \033[0m");
        letak (26,19);
        printf(" Tanggal input  : %s", dat[tot].tanggal);
        letak (26,20);
        printf(" Nama Barang    : %s", dat[tot].nama);
        letak (26,21);
        printf(" Kode Barang    : %d", dat[tot].id);
        letak (26,22);
        printf(" Harga Barang   : %s", dat[tot].harga);
    }
    else{
        letak (26,24);
        printf("\033[1;31m\t\t\t --- Data Tidak Ditemukan ---\033[0m");
    }

    letak (26,25);
    printf("\033[1;32m Tekan Enter Untuk Kembali ke Menu\033[0m");
    getch();
}

//calvin
void hapus() {
    char jawab, search[30];
    Tampilan_Tetap();
    letak(26,13);
    printf("\033[1;32m --- Hapus Data Barang --- \033[0m");
    letak(26,15);
    printf("Masukkan Kode Barang : ");
    scanf("%d", &oy);
    Mencari();
    result = 0;
    for (x = 0; x <= tot; x++) {
        if (oy == dat[x].id) {
            result = 1;
            break;
        }
    }

    if (result == 1) {
        letak(26,17);
        printf("Data Barang berikut akan dihapus :");
        letak(26,19);
        printf(" Tanggal input : %s", dat[x].tanggal);
        letak(26,20);
        printf(" Nama Barang   : %s", dat[x].nama);
        letak(26,21);
        printf(" Kode Barang   : %d", dat[x].id);
        letak(26,22);
        printf(" Harga Barang  : %s", dat[x].harga);

        printf("\n\n\t\t\t Yakin ingin menghapus data ini? (\033[1;32mY\033[0m/\033[1;31mN\033[0m) ");
        scanf(" %c", &jawab);

        if (jawab == 'Y' || jawab == 'y') {
            for (int i = x; i < tot - 1; i++) {
                dat[i] = dat[i+1];
            }
            tot--;

            // Tulis ulang seluruh data ke file setelah dihapus
            FILE *file = fopen("data_barang.txt", "w");
            for (int i = 0; i < tot; i++) {
                fprintf(file, "%s %s %d %s\n", dat[i].tanggal, dat[i].nama, dat[i].id, dat[i].harga);
            }
            fclose(file);

            printf("\033[1;32m\t\t\t Data berhasil dihapus\n\033[0m");
        }
        else {
            printf("\033[1;31m\t\t\t Data tidak jadi dihapus\n\033[0m");
        }
    }
    else {
        printf("\033[1;31m\t\t\t Data tidak ditemukan\n\033[0m");
    }

    system("pause");
    system("cls");
}


//14 calvin 6
void edit() {
    char stemp[30], search[30], temps[100];
    int jaw = 0;
    Tampilan_Tetap();
    letak(26, 13);
    printf("\033[1;32m --- Ubah Data Barang ---\033[0m");
    letak(26, 15);
    printf("Masukkan Kode Barang : ");
    scanf("%d", &oy);

    Mencari();

    result = 0;
    for (x = 0; x <= tot; x++) {
        if (oy == dat[x].id) {
            result = 1;
            break;
        }
    }

    if (result == 1) {
        letak(26, 17);
        printf("Data Barang berikut akan Diubah :");
        letak(26, 19);
        printf(" Tanggal input       : %s", dat[x].tanggal);
        letak(26, 20);
        printf(" Nama Barang         : %s", dat[x].nama);
        letak(26, 21);
        printf(" Kode Barang         : %d", dat[x].id);
        letak(26, 22);
        printf(" Harga Barang        : %s", dat[x].harga);

        letak(26, 24);
        printf("Pilih Data yang akan diganti");
        letak(26, 26);
        printf("1. Tanggal input");
        letak(26, 27);
        printf("2. Nama Barang");
        letak(26, 28);
        printf("3. Kode barang");
        letak(26, 29);
        printf("4. Harga Barang");
        letak(26, 30);
        printf("5. Selesai / Batal");
        letak(26, 32);
        printf("Pilihan : ");
        scanf("%d", &jaw);

        switch (jaw) {
            case 1:
                letak(26, 35);
                printf("Masukkan Tanggal input baru : ");
                scanf(" %[^\n]%*c", &stemp);
                strcpy(dat[x].tanggal, stemp);
                break;
            case 2:
                letak(26, 35);
                printf("Masukkan Nama Barang baru : ");
                scanf(" %[^\n]%*c", &stemp);
                strcpy(dat[x].nama, stemp);
                break;
            case 3:
                letak(26, 35);
                printf("Masukkan Kode barang baru : ");
                scanf("%d", &temp);
                dat[x].id = temp;
                break;
            case 4:
                letak(26, 35);
                printf("Masukkan Harga Barang baru : ");
                scanf(" %[^\n]%*c", &stemp);
                            strcpy(dat[x].harga, stemp);
            break;
        case 5:
            return;
        default:
            letak(26, 35);
            printf("\033[1;31mInput tidak valid, silakan coba lagi!\033[0m");
            break;
    }

    FILE *fp = fopen("data_barang.txt", "w");
    if (fp == NULL) {
        printf("\033[1;31mGagal membuka file\n\033[0m");
        return;
    }

    for (int i = 0; i < tot; i++) {
        fprintf(fp, "%s %s %d %s\n", dat[i].tanggal, dat[i].nama, dat[i].id, dat[i].harga);
    }

    fclose(fp);

    printf("\033[1;32mData berhasil diubah!\n\033[0m");
    system("pause");
} else {
    letak(26, 17);
    printf("\033[1;31mData tidak ditemukan!\n\033[0m");
    system("pause");
}
system("cls");
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
     int pilihan;
    char a=170,b=219, str[]="54321";;
    printf("\n\n\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\tLoading...");
    printf("\n\n");
    printf( "\t\t\t\t\t");

    for (int i=0; i<= 25; i++)
    {
          printf("\033[1;32m>\033[0m");
        Sleep(100);
    }
    printf ("\n\n\t\t\t\t\t\033[1;32m'\033[0mPRESS ANY BUTTON TO \033[1;32mLOGIN'\033[0m ");
    system ("pause>0");

    char nama[10], psw[8];
    int ulang = 0;
    system ("cls");

    for(int i=0; i<1; i++)
    {
        sama();
        printf("\n");
        printf( "\t\t\t");printf("|");
        for(int i=0; i<7; i++)
        {
            printf(" ");Sleep(1);
        }
        printf("\033[1;34m     Login ke Toko Klontong KAMI      \033[0m");
         for(int i=0; i<6; i++)
        {
            printf(" ");Sleep(1);
        } printf("|");printf("\n");
        printf("\n");
        sama();
        printf("\n\n");

}

   char user[5]="tugas",pass[8]="kematian",word[8],name[5];
    int i,j,k,l,p,input,cek,nilai,salah;
    p=0;
    salah=0;
    awal:

    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t");
    printf("\033[1;34m--- SELAMAT DATANG! ---\n\033[0m");
    printf("\n\t\t\t\t\t");
    printf("USERNAME  : ");
    printf("\033[1;32m");
    scanf("%s",&name);
    cek=0;
    for(i=0;i<5;i++){
        if(name[i]==user[i]){
            cek=cek+1;
        }else{
            cek=0;
        }
    }
    printf("\033[0m");
    printf("\n\t\t\t\t\t");
    printf("PASSWORD  : ");
    for(i=0;i<8;i++){
        input=getch();
        if(input==13){
            goto cek;
        }else{
            word[i]=input;
            printf("\033[1;32m*\033[0m");
        }
    }
    nilai=0;
    for(i=0;i<8;i++){
        if(pass[i]==word[i]){
            nilai=nilai+1;
        }else{
            nilai=0;
        }
    }
    getch();
    cek:
    if(cek==5&&nilai==8){
        printf("\n\n\t\t\t\t  ");
        printf("\033[1;32mSelamat datang di Tugas Kematian\033[0m");
        printf("\n\n\t\t\t\t       ");
        printf("\033[1;32mKlik ENTER untuk lanjut\033[0m");
        getch();
        system("cls");
        goto muka;
    }else{
        if(cek==5){
            printf("\n\n\t\t\t\t\t   ");
            printf("\033[1;31mPassword salah\033[0m");
            goto bawah;
        }else if(nilai==8){
            printf("\n\n\t\t\t\t\t   ");
            printf("\033[1;31mUsername salah\033[0m");
            goto bawah;
        }else{
            printf("\n\n\t\t\t\t     ");
            printf("\033[1;31mUsername dan Password salah\033[0m");
            goto bawah;
        }
    }
    bawah:
    salah=salah+1;
    if(salah==3){
        printf("\n\n\t\t  ");
        printf("\033[1;31mAnda telah salah menginput username dan password sebanyak 3 kali\n\033[0m");
        printf("\033[1;31m\n\t\t\t\t\tAnda akan keluar dalam \033[0m");
        for( i =1 ; i<= 5; i++ ) {
            letak(51, 20);
            printf("%c", str[p++]);
            Sleep(1000);
            if(p == strlen(str))
            p = 0;
        }
        system("cls");
        return 0;
    }else{
        printf("\n\n\t\t\t\t     ");
        printf("\033[1;32mKlik ENTER untuk mengulangi\033[0m");
        printf("\n\n\t\t\t\t  ");
        printf("\033[1;31mAnda memiliki %d kesempatan lagi!\033[0m",3-salah);
        getch();
        goto awal;
    }

    muka:

        do {
        system ("cls");
        Tampilan_Tetap();
        letak (26,13);
        printf("1. Tambah Data Barang");
        letak (26,14);
        printf("2. Lihat Data Barang");
        letak (26,15);
        printf("3. Urutkan Data Barang");
        letak (26,16);
        printf("4. Pencarian Data Barang");
        letak (26,17);
        printf("5. Hapus Data Barang");
        letak (26,18);
        printf("6. Ubah Data Barang");
        letak (26,19);
        printf("\033[1;31m7. Exit\033[0m");
        letak (26,21);
        printf("\033[1;34mMasukkan Pilihan Anda : \033[0m"); scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: system ("cls");
                    tambah();
                    break;
            case 2: system ("cls");
                    lihat();
                    break;
            case 3: system ("cls");
                    urut();
                    break;
            case 4: system ("cls");
                    mencari();
                    break;
            case 5: system ("cls");
                    hapus();
                    break;
            case 6: system ("cls");
                    edit();
                    break;
            case 7: return 0;
            default: letak(6,21); printf("\033[1;34mPilihan Tidak Tersedia\033[0m");getch();
        }
    } while(pilihan != 7);

}
