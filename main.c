#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

FILE *fp;
int buffer[200];

 FILE *fp = fopen("books.txt", "a");
   if (fp!= NULL){
    printf("File berhasil dibuat.\n");
   }

    fprintf(fp, "%d|%c|%d\n", barang.id, barang.nama, barang.harga);


        if(isEmpty(head)){
            struct node temp = (struct node) malloc(sizeof(struct node));
            temp->barang = barang;
            temp->next = NULL;
            head = temp;
            last = temp;
        }else{
            struct node temp = (struct node) malloc(sizeof(struct node));
            temp->barang = barang;
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }

        fclose(fp);
    }



void addData(){

}

void readData(){


}

void updateData() {

}

void deleteData() {

}

int main(){
system("color 37");
    int choice;

    do {
        system("cls");
        menuawal:
        printf("\tPilihan Menu:\n");
        printf("\t1. Tambah data baru\n");
        printf("\t2. Lihat data\n");
        printf("\t3. Ubah data\n");
        printf("\t4. Hapus data\n");
        printf("\t5. Keluar\n");
        printf("\tMasukkan pilihan Anda: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                system("cls");
                addData();
                break;

            case 2:
                system("cls");
                readData();
                break;
                goto menuawal;
            case 3:
                system("cls");
                updateData();
                break;
                goto menuawal;
            case 4:
                system("cls");
                deleteData();
                break;
            case 5:
                system("cls");
                printf("\nTerima kasih telah menggunakan program ini!\n");
                exit(0);
                break;
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 5);

    return 0;
}

