#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct{
    int no, nilai;
    char nama[20];
}mahasiswa;

void input();
void sequential_search(mahasiswa []);
void insertion_s();
void tampil();
int jml;

int main()
{
    puts("~~ SEQUENTIAL UNSORTED ~~");
    int tampung;
    mahasiswa A[MAX];
    input(A);
    puts("BEFORE SORT");
    tampil(A);
    insertion_s(A);
    puts("AFTER SORT");
    tampil(A);
    if(tampung == 1){
        puts("Data %d ADA dalam daftar");
    }else{
        puts("Data %d TIDAK ADA dalam daftar");
    }
    return 0;
}
void input(mahasiswa A[])
{
    int i;
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Masukkan jumlah mahasiswa : ");
    scanf("%d", &jml);
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for(i=0; i<jml; i++){
        printf("Mahasiswa ke %d\n", i+1);
        printf("No : ");
        scanf("%d", &A[i].no);
        fflush(stdin);
        printf("Nama : ");
        gets(A[i].nama);
        fflush(stdin);
        printf("Nilai : ");
        scanf("%d", &A[i].nilai);
        fflush(stdin);
        puts("");
    }
}
void insertion_s(mahasiswa A[])
{
    int i=1, j, key, key3;
    char key2[20];
    while(i < jml){
        key = A[i].no;
        strcpy(key2, A[i].nama);
        key3 = A[i].nilai;
        j = i-1;
        while(A[j].no > key && j>=0){
            A[j+1].no = A[j].no;
            strcpy(A[j+1].nama, A[j].nama);
            A[j+1].nilai = A[j].nilai;
            j = j-1;
        }
        A[j+1].no = key;
        strcpy(A[j+1].nama, key2);
        A[j+1].nilai = key3;
        i = i+1;
    }
}
void sequential_search(mahasiswa A[])
{
    int i=0, ketemu=0, key;
    printf("Data yang ingin dicari : ");
    scanf("%d", &key);
    while(!ketemu && i<jml){
        if(A[i].no == key){
            ketemu = 1;
        }else{
            i++;
        }
    }
    return ketemu;
}
void tampil(mahasiswa A[])
{
    int i;
    puts("No\tNama\tNilai");
    for(i=0; i<jml; i++){
        printf("%d\t%s\t%d", A[i].no, A[i].nama, A[i].nilai);
        puts("");
    }
}
