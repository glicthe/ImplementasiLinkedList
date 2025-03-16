#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

// 1. Constructor: Membuat list kosong
List createList() {
    List L;
    first(L) = NULL;
    return L;
}

// 2. Destructor: Menghapus seluruh elemen list
void deleteList(List *L) {
    address P = first(*L);
    while(P != NULL) {
        address temp = P;
        P = next(P);
        free(temp);
    }
    first(*L) = NULL;
}

// 3. Validator: Memeriksa apakah list kosong
int isEmpty(List L) {
    return (first(L) == NULL);
}

// 4. Getter: Mengambil data dari node tertentu
Mahasiswa getElement(address P) {
    return info(P);
}

// 5. PrintObject: Menampilkan seluruh isi list
void printList(List L) {
    if(isEmpty(L)) {
        printf("List kosong\n");
        return;
    }
    
    address P = first(L);
    printf("%-20s | %-4s\n", "Nama", "Nilai");
    printf("---------------------|------\n");
    while(P != NULL) {
        Mahasiswa m = getElement(P);
        printf("%-20s | %-4d\n", nama(m), nilai(m));
        P = next(P);
    }
}

void tampilkanMenu() {
    clearScreen();
    printf("\n=== Link-List Mahasiwa ===\n");
    printf("1. Tambah Mahasiswa ke L1\n");
    printf("2. Tampilkan L1 (Urut Nama)\n");
    printf("3. Tampilkan L1 (Urut Nilai)\n");
    printf("4. Salin ke L2 (Nilai > 70)\n");
    printf("5. Tampilkan L2\n");
    printf("6. Hapus Duplikat di L2\n");
    printf("7. Hapus Semua List\n");
    printf("8. Keluar\n");
    printf("Pilihan: ");
}

void inputMahasiswa(List *L) {
    Mahasiswa m;
    
    printf("\nMasukkan nama mahasiswa: ");
    fgets(nama(m), MAX_NAMA, stdin);
    nama(m)[strcspn(nama(m), "\n")] = '\0';
    
    do {
        printf("Masukkan nilai UTS SDA (0-100): ");
        scanf("%d", &nilai(m));
        clearBuffer();
        if(nilai(m) < 0 || nilai(m) > 100) {
            printf("Nilai harus antara 0-100!\n");
        }
    } while(nilai(m) < 0 || nilai(m) > 100);

    insertSorted(L, m);
    printf("\nData berhasil ditambahkan!");
}

void insertSorted(List *L, Mahasiswa m) {
    address newNode = (address)malloc(sizeof(ElmtList));
    if(newNode == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    
    strcpy(nama(info(newNode)), nama(m));
    nilai(info(newNode)) = nilai(m);
    next(newNode) = NULL;

    if(isEmpty(*L)) {
        first(*L) = newNode;
    } else if(strcasecmp(nama(m), nama(info(first(*L)))) < 0) {
        next(newNode) = first(*L);
        first(*L) = newNode;
    } else {
        address curr = first(*L);
        address prev = NULL;
        
        while(curr != NULL && strcasecmp(nama(m), nama(info(curr))) >= 0) {
            prev = curr;
            curr = next(curr);
        }
        
        if(prev == NULL) {
            next(newNode) = first(*L);
            first(*L) = newNode;
        } else {
            next(newNode) = curr;
            next(prev) = newNode;
        }
    }
}

void copyHighScore(List L1, List *L2) {
    address P = first(L1);
    while(P != NULL) {
        if(nilai(info(P)) > 70) {
            insertSorted(L2, info(P));
        }
        P = next(P);
    }
}

void removeDuplicates(List *L) {
    address curr = first(*L);
    while(curr != NULL && next(curr) != NULL) {
        if(strcasecmp(nama(info(curr)), nama(info(next(curr)))) == 0) {
            address temp = next(curr);
            next(curr) = next(temp);
            free(temp);
        } else {
            curr = next(curr);
        }
    }
}

void sortByNilai(List L) {
    int count = countElements(L), i, j;
    if(count == 0) return;

    Mahasiswa *arr = (Mahasiswa*)malloc(count * sizeof(Mahasiswa));
    address P = first(L);
    
    for(i=0; i<count; i++) {
        arr[i] = info(P);
        P = next(P);
    }

    for(i=0; i<count-1; i++) {
        for(j=0; j<count-i-1; j++) {
            if(nilai(arr[j]) < nilai(arr[j+1])) {
                Mahasiswa temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("%-20s | %-4s\n", "Nama", "Nilai");
    printf("---------------------|------\n");
    for(i=0; i<count; i++) {
        printf("%-20s | %-4d\n", nama(arr[i]), nilai(arr[i]));
    }
    
    free(arr);
}

int countElements(List L) {
    int count = 0;
    address P = first(L);
    while(P != NULL) {
        count++;
        P = next(P);
    }
    return count;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void waitForEnter() {
    printf("\nTekan Enter untuk melanjutkan...");
    getchar();
}

void clearScreen() {
    system("cls");
}
