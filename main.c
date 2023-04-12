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
    kosong();kosong();kosong();kosong();

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
    for(int i = 0; i < tot; i++) {
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
// 7
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
}
// 8
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
void cari(){
    int oy;
    Tampilan_Tetap();
    letak(26,13);
    printf("\033[1;32m --- Pencarian Data Barang --- \033[0m");
    letak (26,15);
    printf("Masukkan Kode Barang: ");
    scanf("%d", &oy);

    int result = 0, x;
    for (x=0; x < tot; x++) {
        if (oy == dat[x].id){
            result = 1;
            break;
        }
    }

    if (result == 1){
        letak (26,17);
        printf("\033[1;32m --- Data Ditemukan --- \033[0m");
        letak (26,19);
        printf(" Tanggal input  : %s", dat[x].tanggal);
        letak (26,20);
        printf(" Nama Barang    : %s", dat[x].nama);
        letak (26,21);
        printf(" Kode Barang    : %d", dat[x].id);
        letak (26,22);
        printf(" Harga Barang   : %s", dat[x].harga);
    }
    else{
        letak (26,24);
        printf("\033[1;31m\t\t\t --- Data Tidak Ditemukan ---\033[0m");
    }

    letak (26,25);
    printf("\033[1;32m Tekan Enter Untuk Kembali ke Menu\033[0m");
    getch();
}
