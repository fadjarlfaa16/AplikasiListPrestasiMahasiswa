#include <iostream>
#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#define info(P) P->info
#define next(P) P->next
#define choosen_ukm(P) P->choosen_ukm
#define choosen_prestasi(P) P->choosen_prestasi
#define child_ukm(P) P->child_ukm
#define child_prestasi(P) P->child_prestasi
#define first(L) L.first

using namespace std;

typedef struct elmMhstoUKM *adr_MhstoUKM;
typedef struct elmMhstoPres *adr_MhstoPrestasi;

//TIPE BENTUKAN DATA MAHASISWA
struct mahasiswa {
    string NamaMahasiswa;
    string fakultas;
    int Nim;
    double IPK;
    int TAK;
};

typedef struct elmMahasiswa *adr_mahasiswa;
typedef mahasiswa infotypeM;

struct elmMahasiswa {
    infotypeM info;
    adr_mahasiswa next;
    adr_MhstoUKM child_ukm;
    adr_MhstoPrestasi child_prestasi;
};

struct ListMahasiswa {
    adr_mahasiswa first;
};


// TIPE BENTUKAN DATA ORGANISASI
struct UKM {
    string namaUKM;
    int thn_masuk;
    string bidangUKM;
};

typedef struct elmUKM *adr_UKM;
typedef UKM infotypeU;

struct elmUKM {
    infotypeU info;
    adr_UKM next;
};

struct ListUKM {
    adr_UKM first;
};

struct Prestasi {
    string jenis_prestasi;
    string skala;
    int TAK;
};

typedef struct elmPrestasi *adr_prestasi;
typedef Prestasi infotypeP;

struct elmPrestasi {
    infotypeP info;
    adr_prestasi next;
};

struct ListPrestasi {
    adr_prestasi first;
};

struct elmMhstoUKM {
    adr_UKM choosen_ukm;
    adr_MhstoUKM next;
};

struct elmMhstoPres {
    adr_prestasi choosen_prestasi;
    adr_MhstoPrestasi next;
};


//CREATING LIST
void createListMahasiswa (ListMahasiswa &LM);
void createListUKM (ListUKM &LU);
void createListPrestasi(ListPrestasi &LP);


//CREATING ELEMENT
adr_mahasiswa createElmMahasiswa(infotypeM x_mhs);
adr_UKM createElmUKM(infotypeU x_ukm);
adr_prestasi createElmPrestasi(infotypeP x_pres);
adr_MhstoUKM createChildMhstoUKM(adr_UKM PU);
adr_MhstoPrestasi createChildMhstoPrestasi(adr_prestasi PP);

//INSERTING ELEMENT
void insertlastM(ListMahasiswa &LM, adr_mahasiswa &PM);
void insertlastU(ListUKM &LU, adr_UKM &PU);
void insertlastP(ListPrestasi &LP, adr_prestasi &PP);

//INSERTING CHILD
void addMhstoUKMChild(adr_mahasiswa &PM, adr_MhstoUKM &P_UKM);
void addMhstoPrestasiChild(adr_mahasiswa &PM, adr_MhstoPrestasi &P_Pres);

//SHOW LIST
void showMahasiswa(ListMahasiswa M);
void showUKM(ListUKM LU);
void showPrestasi(ListPrestasi LP);
void showAll(ListMahasiswa LM);

//DELETING ELEMENT
void DeletefirstM(ListMahasiswa &LM, adr_mahasiswa &PM);
void DeleteLastM(ListMahasiswa &LM, adr_mahasiswa &PM);
void DeletefirstU(ListUKM &LU, adr_UKM &PU);
void DeleteLastU(ListUKM &LU, adr_UKM &PU);
void DeletefirstP(ListPrestasi &LP, adr_prestasi &PP);
void DeleteLastP(ListPrestasi &LP, adr_prestasi &PP);

//SEARCHING ELEMENT
adr_mahasiswa searchMahasiswabyNIM(ListMahasiswa LM, int nim);
adr_UKM searchUKMbyNamaUKM(ListUKM LU,string namaUKM);
adr_prestasi searchPrestasibyJenis(ListPrestasi, string jenis_prestasi);

//ADD ELEMENT
void daftarMahasiswa(ListMahasiswa &LM, adr_mahasiswa &PM);
void daftarUKM(ListUKM &LU);
void daftarPrestasi(ListPrestasi &LP);
void addChildUKM(ListUKM LU, adr_mahasiswa &PM);
void addChildPrestasi(ListPrestasi LP, adr_mahasiswa &PM);


//REMOVE ELEMENT
void removeMahasiswa(ListMahasiswa &LM, adr_mahasiswa &Prec, adr_mahasiswa &P);
void removeUKM(ListUKM &LU, adr_UKM Prec, adr_UKM &P);
void removePrestasi(ListPrestasi &LP, adr_prestasi &Prec, adr_prestasi &P);
void removeChildUKM(adr_mahasiswa &PM, adr_MhstoUKM &P_UKM);
void removeChildPrestasi(adr_mahasiswa &PM, adr_MhstoPrestasi &P_Pres);

//ACTION
bool availableCheckerInChildUKM(adr_mahasiswa PM, string jenis);
bool availableCheckerInChildPrestasi(adr_mahasiswa PM, string jenis);

//Value
int countUKM(adr_mahasiswa PM);
int countPrestasi(adr_prestasi);

void DeleteMahasiswabyNIM(ListMahasiswa &M, int nim, adr_mahasiswa &K);
void DeleteUKMbyJenisUKM(ListUKM &LM, string jenis, adr_UKM &K);
void DeletePrestasibyJenis(ListPrestasi &LP, string jenis, adr_prestasi &K);
void mainMenu(ListMahasiswa LM, ListUKM LU, ListPrestasi LP);




#endif // TUBES_H_INCLUDED
