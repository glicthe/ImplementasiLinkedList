#ifndef LIST_H
#define LIST_H
#define MAX_NAMA 50

typedef struct {
    char nama[MAX_NAMA];
    int nilaiUTS;
} Mahasiswa;

typedef struct tElmtList *address;
typedef struct tElmtList {
    Mahasiswa info;
    address next;
} ElmtList;

typedef struct {
    address First;
} List;

/*========== 5 FUNGSI UTAMA ==========*/
List createList();                   // Constructor
void deleteList(List *L);            // Destructor
int isEmpty(List L);                 // Validator
Mahasiswa getElement(address P);     // Getter
void printList(List L);              // PrintObject

/*========== FUNGSI TAMBAHAN ==========*/
void insertSorted(List *L, Mahasiswa m);
void copyHighScore(List L1, List *L2);
void removeDuplicates(List *L);
void sortByNilai(List L);
int countElements(List L);
void clearBuffer();
void waitForEnter();
void clearScreen();

/* FUNGSI AKSESOR */
#define info(P) (P)->info
#define nama(I) (I).nama
#define nilai(I) (I).nilaiUTS
#define next(P) (P)->next
#define first(L) (L).First

#endif
