# ImplementasiLinkedList
Pengerjaan Studi Kasus SDA Linked List

Dengan Ketentuan Sebagai Berikut:

========PRAKTIKUM PENGGUNAAN SINGLE LINKED LIST========
Membuat ADT Link-List Mahasiwa (Nama, Nilai UTS SDA) dengan langkah berikut:
1) Buat ADT Link-List Mahasiswa (.h) dan (.c) dengan memodifikasi ADT Liniear linked List.
   Sebuah ADT minimal mengandung 5 fungsi utama (5 sekawan):
      -- creator/ constructor
      -- destructor  
      -- Validator
      -- Get/Set
      -- PrintObject
2) Buat List L1 dan L2 untuk menampung daftar mahasiswa
3) Isikan sejumlah elemen ke pada List L1, pastikan setiap pengisian elemen, isi List harus
   terurut Ascending menurut Nama.
4) Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut ascending berdasarkan nama
5) Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut desending berdasarkan nilai
6) Hitung Jumlah elemen (jumlah mahasiswa pada list), kemudian tampilkan
7) Copy seluruh elemen pada list L1 yang Nilainya > 70 ke List L2
8) Tampilkan Isi elemen List L2
9) Jika pada L2 ada yang namanya sama, maka nama yang sama tersebut hanya boleh
   ada 1 pada list (Nama pada List harus unik). Artinya jika ada nama yang sama, maka
   hapus datanya dari list. – data yg dihapus adalah elemen yg duplikatnya bukan yang
   pertama.
10) Tampilkan elemen List L2 yang baru
11) Hapus List L1 dan List L2

Note: a. Gunakan fungsi-fungsi pada string.h
      b. Contoh definisi list di source code:
      typedef int infotype;
      typedef struct tElmtlist *address;
      typedef struct tElmtlist {
          infotype info;
          address next;
      } Elmtlist

      //Definisi List 
      //List Kosong ===> First(L) = Nil
      //Setiap elemen dengan address P dapat diacu info(p) dan Next(p);
      //Elemen terakhir List ===> Jika addresnya Last maka Next(Last) = Nil 
      typedef struct {
          address First;
      } List
