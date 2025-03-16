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
3) Buat List L1 dan L2 untuk menampung daftar mahasiswa
4) Isikan sejumlah elemen ke pada List L1, pastikan setiap pengisian elemen, isi List harus
   terurut Ascending menurut Nama.
5) Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut ascending berdasarkan nama
6) Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut desending berdasarkan nilai
7) Hitung Jumlah elemen (jumlah mahasiswa pada list), kemudian tampilkan
8) Copy seluruh elemen pada list L1 yang Nilainya > 70 ke List L2
9) Tampilkan Isi elemen List L2
10) Jika pada L2 ada yang namanya sama, maka nama yang sama tersebut hanya boleh
   ada 1 pada list (Nama pada List harus unik). Artinya jika ada nama yang sama, maka
   hapus datanya dari list. – data yg dihapus adalah elemen yg duplikatnya bukan yang
   pertama.
11) Tampilkan elemen List L2 yang baru
12) Hapus List L1 dan List L2

Note: 
1) Gunakan fungsi-fungsi pada string.h
2) Contoh definisi list di source code:

Contoh:
       
      typedef int infotype;
      typedef struct tElmtlist *address;
      typedef struct tElmtlist {
          infotype info;
          address next;
      } Elmtlist

      // Definisi List 
      // List Kosong ===> First(L) = Nil
      // Setiap elemen dengan address P dapat diacu info(p) dan Next(p);
      // Elemen terakhir List ===> Jika addresnya Last maka Next(Last) = Nil 
      typedef struct {
          address First;
      } List
