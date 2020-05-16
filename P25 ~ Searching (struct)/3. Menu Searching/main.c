#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct{
    int no, nilai;
    char nama[20];
}mhs;

void selection();
void menu();
void input();
void backup();
void tukar();
void insertion();
int sequential(mhs [], int);
int binary(mhs [], int);
void tampil();
int jml;

int main()
{
    puts("MENU SEARCHING DATA STRUCT");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
    char answer;
    mhs A[MAX], B[MAX];
    input(A);
    do{
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        puts("DATA");
        tampil(A);
        backup(A, B);
        menu(A);
        fflush(stdin);
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("Ingin input lagi ? (Y/N) : ");
        answer=getchar();
        backup(B, A);
    }while(answer == 'Y' || answer == 'y');
    return 0;
}
void backup(mhs A[], mhs B[])
{
    int i;
    for(i=0; i<jml; i++){
        B[i].no = A[i].no;
        strcpy(B[i].nama, A[i].nama);
        B[i].nilai = A[i].nilai;
    }
}
void input(mhs A[])
{
    int i;
    printf("Jumlah Mahasiswa : ");
    scanf("%d", &jml);
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for(i=0; i<jml; i++){
        printf("Mahasiswa ke-%d\n", i+1);
        printf("No : ");
        scanf("%d", &A[i].no);
        fflush(stdin);
        printf("Nama : ");
        gets(A[i].nama);
        printf("Nilai : ");
        scanf("%d", &A[i].nilai);
    }
}
void menu(mhs A[])
{
    int pilih1, pilih2, pilih3, tampung;
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("MENU");
    puts("1. Tampilkan Data");
    puts("2. Sequential Search");
    puts("3. Binary Search");
    puts("4. Keluar");
    printf("Masukkan Pilihan : ");
    scanf("%d", &pilih1);
    if(pilih1 == 1){
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        puts("TAMPILKAN DATA SECARA");
        puts("1. Unsorted");
        puts("2. Sorted");
        printf("Tentukan Pilihan : ");
        scanf("%d", &pilih2);
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        switch(pilih2){
        case 1 :
            tampil(A);
            break;
        case 2 :
            insertion(A);
            tampil(A);
            break;
        }
    }else if(pilih1 == 2 || pilih1 == 3){
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        puts("SEARCH BY : ");
        puts("1. No");
        puts("2. Nama");
        printf("Pilih Menu : ");
        scanf("%d", &pilih3);
        if(pilih1 == 2){
            tampung = sequential(A, pilih3);
        }else if(pilih1 == 3){
            tampung=binary(A, pilih3);
        }
    }else if(pilih1 == 4){
        exit(0);
    }else{
        puts("ERROR, MENU TIDAK ADA !!");
        exit(0);
    }
    if(pilih1 == 2 || pilih1 == 3){
        if(tampung == 1){
            puts("Data ditemukan");
        }else{
            puts("Data tidak ditemukan");
        }
    }
}
void insertion(mhs A[])
{
    int i=1, j, key, key3;
    char key2[20];
    while(i < jml){
        key = A[i].no;
        strcpy(key2, A[i].nama);
        key3 = A[i].nilai;
        j = i-1;
        while(A[j].no>key && j>=0){
            A[j+1].no = A[j].no;
            strcpy(A[j+1].nama, A[j].nama);
            A[j+1].nilai = A[j].nilai;
            j=j-1;
        }
        A[j+1].no = key;
        strcpy(A[j+1].nama, key2);
        A[j+1].nilai = key3;
        i=i+1;
    }
}
void selection(mhs A[])
{
    int i=0, j, key, min;
    while(i < jml){
        min = i;
        j = i+1;
        while(j < jml){
            if(strcmpi(A[j].nama, A[min].nama)<0){
                min = j;
            }
            j = j+1;
        }
        tukar(i,min,A);
        i++;
    }
}
int sequential(mhs A[], int mode)
{
    int i=0, ketemu=0, key, kondisi;
    char key2[20];
    if(mode == 1){
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("Nomor yang dicari : ");
        scanf("%d", &key);
        kondisi=(A[i].no == key);
    }else{
        fflush(stdin);
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("Nama yang dicari : ");
        gets(key2);
        kondisi = (strcmpi(A[i].nama, key2) == 0);
    }
    while(!ketemu && i<jml){
        if(kondisi){
            ketemu = 1;
        }else{
            i++;
        }if(mode == 1){
            kondisi = (A[i].no == key);
        }else{
            kondisi = (strcmpi(A[i].nama, key2) == 0);
        }
    }
    return ketemu;
}
int binary(mhs A[], int mode)
{
    int l=0, r=jml-1, key, ketemu=0, m, kondisi;
    char key2[20];
    if(mode == 1){
        insertion(A);
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("Nomor yang dicari : ");
        scanf("%d", &key);
        while(!ketemu && l<=r){
            m = (l+r)/2;
            if(key < A[m].no){
                r = m-1;
            }else if(key > A[m].no){
                l = m+1;
            }else{
                ketemu = 1;
            }
        }
    }else{
        selection(A);
        fflush(stdin);
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("Nama yang dicari : ");
        gets(key2);
        while(!ketemu && l<=r){
            m = (l+r)/2;
            if(strcmpi(key2,A[m].nama) < 0){
                r = m-1;
            }else if(strcmpi(key2,A[m].nama) > 0){
                l = m+1;
            }else{
                ketemu = 1;
            }
        }
    }
    return ketemu;
}
void tampil(mhs A[])
{
    int i;
    puts("No\tNama\tNilai");
    for(i=0; i<jml; i++){
        printf("%d\t%s\t%d\n", A[i].no, A[i].nama, A[i].nilai);
    }
}
void tukar(int i, int j, mhs A[])
{
    int temp, temp3;
    char temp2[50];
    temp = A[i].no;
    A[i].no = A[j].no;
    A[j].no = temp;
    strcpy(temp2, A[i].nama);
    strcpy(A[i].nama, A[j].nama);
    strcpy(A[j].nama, temp2);
    temp3 = A[i].nilai;
    A[i].nilai = A[j].nilai;
    A[j].nilai = temp3;
}
