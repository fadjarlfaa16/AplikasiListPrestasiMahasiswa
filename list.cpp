#include "header.h"
using namespace std;

//CREATE LIST
void createListMahasiswa (ListMahasiswa &LM){
    first(LM)= NULL;
};
void createListUKM (ListUKM &LU){
    first(LU)= NULL;
};
void createListPrestasi(ListPrestasi &LP){
    first(LP) = NULL;
};

//CREATE ELEMENT
adr_mahasiswa createElmMahasiswa(infotypeM x){
    adr_mahasiswa PM = new elmMahasiswa;
    info(PM)= x;
    info(PM).TAK = 0;
    child_prestasi(PM) = NULL;
    child_ukm(PM) = NULL;
    next(PM)=NULL;
    return PM;
};

adr_UKM createElmUKM(infotypeU x){
    adr_UKM PU = new elmUKM;
    info(PU) = x;
    next(PU) = NULL;
    return PU;
};

adr_prestasi createElmPrestasi(infotypeP x){
    adr_prestasi PP = new elmPrestasi;
    info(PP) = x;
    next(PP) = NULL;
    return PP;
};

adr_MhstoUKM createChildMhstoUKM(adr_UKM PU){
    adr_MhstoUKM P_UKM = new elmMhstoUKM;
    choosen_ukm(P_UKM) = PU;
    next(P_UKM) = NULL;
    return P_UKM;
};

adr_MhstoPrestasi createChildMhstoPrestasi(adr_prestasi PP){
    adr_MhstoPrestasi P_Pres = new elmMhstoPres;
    choosen_prestasi(P_Pres) = PP;
    next(P_Pres) = NULL;
    return P_Pres;
};

//CHECKING AVAILABLE FUNCTION
bool availableCheckerInChildUKM(adr_mahasiswa PM, string jenis){
    adr_MhstoUKM P_UKM = child_ukm(PM);
    while (P_UKM != NULL){
        if (info(choosen_ukm(P_UKM)).namaUKM == jenis){
            return false;
        }
        P_UKM = next(P_UKM);
    }
    return true;
};

bool availableCheckerInChildPrestasi(adr_mahasiswa PP, string jenis){
    adr_MhstoPrestasi P_Pres = child_prestasi(PP);
    while (P_Pres != NULL){
        if (info(choosen_prestasi(P_Pres)).jenis_prestasi == jenis){
            return false;
        }
        P_Pres = next(P_Pres);
    }
    return true;
};


//INSERTING ELEMENT
void insertlastM(ListMahasiswa &LM, adr_mahasiswa &PM){
    if (first(LM) == NULL){
        first(LM) = PM;
    }else {
        adr_mahasiswa Q = first(LM);
        while (next(Q)!=NULL){
            Q=next(Q);
        }
        next(Q)=PM;
    }
};

void insertlastU(ListUKM &LU, adr_UKM &PU){
    if (first(LU) == NULL){
        first(LU) = PU;
    }else {
        adr_UKM Q = first(LU);
        while (next(Q)!=NULL){
            Q=next(Q);
        }
        next(Q)=PU;
    }
};

void insertlastP(ListPrestasi &LP, adr_prestasi &PP){
    if (first(LP) == NULL){
        first(LP) = PP;
    }else {
        adr_prestasi Q = first(LP);
        while (next(Q)!=NULL){
            Q=next(Q);
        }
        next(Q)=PP;
    }
};

void addMhstoUKMChild(adr_mahasiswa &PM, adr_MhstoUKM &P_UKM){
    if (child_ukm(PM) == NULL){
        child_ukm(PM) = P_UKM;
    }else {
        adr_MhstoUKM X = child_ukm(PM);
        while(next(X) != NULL){
            X = next(X);
        }
        next(X) = P_UKM;
    }
};

void addMhstoPrestasiChild(adr_mahasiswa &PM, adr_MhstoPrestasi &P_Pres){
    if (child_prestasi(PM) == NULL){
        child_prestasi(PM) = P_Pres;
    }else {
        adr_MhstoPrestasi X = child_prestasi(PM);
        while(next(X) != NULL){
            X = next(X);
        }
        next(X) = P_Pres;
    }
};

int countUKM(adr_mahasiswa PM){
    adr_MhstoUKM P = child_ukm(PM);
    int i = 0;
    while (P!= NULL){
        i++;
        P = next(P);
    }
    return i;
};
int countPrestasi(adr_mahasiswa PM){
    adr_MhstoPrestasi P = child_prestasi(PM);
    int i = 0;
    while (P!= NULL){
        i++;
        P = next(P);
    }
    return i;
};

//SHOWING ELEMENT IN LIST
void showMahasiswa(ListMahasiswa LM){
    adr_mahasiswa PM = first(LM);
    cout << "Daftar List Mahasiswa" << endl;
    if (PM!=NULL){
        while (PM!=NULL){
            cout << "-------------------------------------" << endl;
            cout << "Nama: " << info(PM).NamaMahasiswa <<endl;
            cout << "FAKULTAS ASAL: " << info(PM).fakultas << endl;
            cout << "NIM: " << info(PM).Nim << endl;
            cout << "IPK: " << info(PM).IPK << endl;
            cout << "TAK: " << info(PM).TAK << endl;
            cout <<endl;
            PM=next(PM);
            cout << "-------------------------------------" << endl;
        }
    }else {
        cout << "Tidak ada List Mahasiswa" ;
    }
};

void showUKM(ListUKM LU){
    adr_UKM PU = first(LU);
    cout << "Daftar List UKM" << endl;
    if (PU!=NULL){
        while (PU!=NULL){
            cout << "-------------------------------------" << endl;
            cout << "Nama UKM: " << info(PU).namaUKM <<endl;
            cout << "Bidang UKM: " << info(PU).bidangUKM << endl;
            cout << "Tahun Berdiri: " << info(PU).thn_masuk << endl;
            cout <<endl;
            PU=next(PU);
        }
    }else {
        cout << endl;
        cout << "LIST UKM KOSONG" << endl;
        cout << endl;
    }
};

void showPrestasi(ListPrestasi LP){
    adr_prestasi PP = first(LP);
    cout << "Daftar List Prestasi" << endl;
    if (PP!=NULL){
        while (PP!=NULL){
            cout << "-------------------------------------" << endl;
            cout << "Jenis Prestasi:  " << info(PP).jenis_prestasi <<endl;
            cout << "Tingka: " << info(PP).skala << endl;
            cout << "TAK: " << info(PP).TAK << endl;
            cout <<endl;
            PP=next(PP);
        }
    }else {
        cout << endl;
        cout << "LIST PRESTASI KOSONG" << endl;
        cout << endl;
    }
};

void showAll(ListMahasiswa LM){
    adr_mahasiswa PM = first(LM);
    adr_MhstoUKM P_UKM;
    adr_MhstoPrestasi P_Pres;
    if (first(LM) != NULL){
        while (PM != NULL){
            cout << "---------------------------------------------------" << endl;
            cout << "Nama Mahasiswa: " << info(PM).NamaMahasiswa <<endl;
            cout << "FAKULTAS ASAL: " << info(PM).fakultas << endl;
            cout << "NIM: " << info(PM).Nim << endl;
            cout << "IPK: " << info(PM).IPK << endl;
            int TAK = 0;
            P_Pres = child_prestasi(PM);
            while (P_Pres != NULL){
                if (info(choosen_prestasi(P_Pres)).jenis_prestasi != "404"){
                    TAK = TAK + info(choosen_prestasi(P_Pres)).TAK;
                }
                P_Pres = next(P_Pres);
            }
            cout << "TAK: " << TAK << endl;
            cout << endl;
            cout << "DAFTAR UKM YANG DIAMBIL: " << "Total(" << countUKM(PM) << ")" << endl;
            P_UKM = child_ukm(PM);
            int i = 1;
            while (P_UKM != NULL){
                if (info(choosen_ukm(P_UKM)).namaUKM != "404" ){
                    cout << i << ". "<< info(choosen_ukm(P_UKM)).namaUKM << endl;
                    i++;
                }
                P_UKM = next(P_UKM);
            }
            cout << endl;
            cout << "DAFTAR PRESTASI YANG DIAMBIL: " << "Total(" << countPrestasi(PM) << ")" << endl;
            P_Pres = child_prestasi(PM);
            int j = 1;
            while (P_Pres != NULL){
                if (info(choosen_prestasi(P_Pres)).jenis_prestasi != "404"){
                    cout << j << ". "<< info(choosen_prestasi(P_Pres)).jenis_prestasi << endl;
                    j++;
                }
                P_Pres = next(P_Pres);
            }
            PM = next(PM);
        }
    }else {
        cout << endl;
        cout << "DATA BELUM ADA" << endl;
        cout << endl;
    }
};

void DeletefirstM(ListMahasiswa &LM, adr_mahasiswa &M){
    if (first(LM)==NULL){
        cout << "List Kosong" << endl;
    }else if (next(first(LM))==NULL){
        M = first(LM);
        first(LM)=NULL;
    }else  {
        M = first(LM);
        first(LM) = next(M);
        next(M) = NULL;
    }
};

void DeleteLastM(ListMahasiswa &LM, adr_mahasiswa &M){
    if (first(LM)==NULL){
        cout << "List Kosong" << endl;
    }else if (next(first(LM))==NULL){
        M = first(LM);
        first(LM)=NULL;
    }else  {
        adr_mahasiswa P;
        P = first(LM);
        while (next(next(P))!= NULL){
            P = next(P);
        }
        M = next(P);
        next(P)=NULL;
    }
};

void DeletefirstU(ListUKM &LU, adr_UKM &U){
    if (first(LU)==NULL){
        cout << "List Kosong" << endl;
    }else if (next(first(LU))==NULL){
        U = first(LU);
        first(LU)=NULL;
        info(U).namaUKM = "404";
    }else  {
        U = first(LU);
        first(LU) = next(U);
        next(U) = NULL;
        info(U).namaUKM = "404";
    }
};

void DeleteLastU(ListUKM &LU, adr_UKM &U){
    if (first(LU)==NULL){
        cout << "List Kosong" << endl;
    }else if (next(first(LU))==NULL){
        U = first(LU);
        first(LU)=NULL;
        info(U).namaUKM = "404";
    }else  {
        adr_UKM P;
        P = first(LU);
        while (next(next(P))!= NULL){
            P = next(P);
        }
        U = next(P);
        next(P)=NULL;
        info(U).namaUKM = "404";
    }
};

void DeletefirstP(ListPrestasi &LP, adr_prestasi &P){
    if (first(LP)==NULL){
        cout << "List Kosong" << endl;
    }else if (next(first(LP))==NULL){
        P = first(LP);
        first(LP)=NULL;
        info(P).jenis_prestasi = "404";
    }else  {
        P = first(LP);
        first(LP) = next(P);
        next(P) = NULL;
        info(P).jenis_prestasi = "404";
    }
};

void DeleteLastP(ListPrestasi &LP, adr_prestasi &P){
    if (first(LP)==NULL){
        cout << "List Kosong" << endl;
    }else if (next(first(LP))==NULL){
        P = first(LP);
        first(LP)=NULL;
        info(P).jenis_prestasi = "404";
    }else  {
        adr_prestasi Q;
        Q = first(LP);
        while (next(next(Q))!= NULL){
             Q = next(Q);
        }
        P = next(Q);
        next(Q)=NULL;
        info(P).jenis_prestasi = "404";
    }
}

//SEARCHING ELEMENT
adr_mahasiswa searchMahasiswabyNIM(ListMahasiswa LM, int nim){
    adr_mahasiswa P = first(LM);
    while (P != NULL){
        if (info(P).Nim == nim){
            return P;
        }
        P = next(P);
    }
    return NULL;
};

adr_UKM searchUKMbyNamaUKM(ListUKM LU,string namaUKM){
    adr_UKM P = first(LU);
    while (P != NULL){
        if (info(P).namaUKM == namaUKM){
            return P;
        }
        P = next(P);
    }
    return NULL;
};

adr_prestasi searchPrestasibyJenis(ListPrestasi LP, string jenis_prestasi){
    adr_prestasi PP = first(LP);
    while (PP != NULL){
        if (info(PP).jenis_prestasi == jenis_prestasi){
            return PP;
        }
        PP = next(PP);
    }
    return NULL;
};

adr_MhstoUKM SearchChildUKMbyMahasiswa(adr_mahasiswa PM, string nama){
    adr_MhstoUKM Q = child_ukm(PM);
    if (child_ukm(PM) == NULL){
        return NULL;
    }else {
        while(Q!=NULL){
            if (info(choosen_ukm(Q)).namaUKM == nama){
                return Q;
            }
            Q = next(Q);
        }
        return NULL;
    }
};

adr_MhstoPrestasi SearchChildPrestasibyMahasiswa(adr_mahasiswa PM, string nama){
    adr_MhstoPrestasi Q = child_prestasi(PM);
    if (child_prestasi(PM) == NULL){
        return NULL;
    }else {
        while(Q!=NULL){
            if (info(choosen_prestasi(Q)).jenis_prestasi == nama){
                return Q;
            }
            Q = next(Q);
        }
    }
};


//ADD ELEMENT
void daftarMahasiswa(ListMahasiswa &LM,ListUKM LU, ListPrestasi LP){
    infotypeM x_mhs;
    adr_mahasiswa PM;
    adr_MhstoUKM P_UKM;
    adr_UKM catchUKM;
    adr_MhstoPrestasi P_Pres;
    adr_prestasi catchPrestasi;
    string selectPrestasi;
    string selectUKM;
    string pilihan;
    cout << "MASUKKAN DATA MAHASISWA" << endl;
    cout << "Nama Mahasiswa: ";
    cin >> x_mhs.NamaMahasiswa;
    cout << "Fakultas Asal: ";
    cin >> x_mhs.fakultas;
    cout << "NIM: ";
    cin >> x_mhs.Nim;
    cout << "IPK: ";
    cin >> x_mhs.IPK;
    PM = createElmMahasiswa(x_mhs);
    insertlastM(LM,PM);
    adr_mahasiswa parent = PM;
    cout << "Apakah Mahasiswa ini mengikuti UKM?(Y/N): ";
    cin >> pilihan;
    while (pilihan != "N" && pilihan != "Y"){
        cout << "MASUKKAN INPUTAN DENGAN BENAR (Y/N)" << endl;
        cout << "Apakah Mahasiswa ini mengikuti UKM?(Y/N): ";
        cin >> pilihan;
    }
    if (pilihan == "Y"){
        while (pilihan == "Y"){
            showUKM(LU);
            cout << endl;
            cout << "Pilih UKM: ";
            cin >> selectUKM;
            catchUKM = searchUKMbyNamaUKM(LU,selectUKM);
            while (catchUKM == NULL){
                cout << "TIDAK ADA UKM DENGAN NAMA TERSEBUT" << endl;
                cout << "Pilih UKM: ";
                cin >> selectUKM;
                catchUKM = searchUKMbyNamaUKM(LU, selectUKM);
            }
            if (availableCheckerInChildUKM(parent, selectUKM)){
                P_UKM = createChildMhstoUKM(catchUKM);
                addMhstoUKMChild(parent,P_UKM);
                cout << endl;
                cout << info(PM).NamaMahasiswa << " Mendaftar pada UKM " << info(catchUKM).namaUKM << "!" << endl;
                cout << endl;
                cout << "Tambah data lagi? (Y/N): ";
                cin >> pilihan;
            }else {
                cout << endl;
                cout << "MAHASISWA BERSANGKUTAN SUDAH MENDAFTAR PADA UKM INI" << endl;
                cout << endl;
                cout << "Tambah data lagi? (Y/N): ";
                cin >> pilihan;
            }
        }
    }
    cout << "Apakah Mahasiswa ini memiliki Prestasi? (Y/N): ";
    cin >> pilihan;
    if (pilihan == "Y"){
        while (pilihan == "Y"){
            showPrestasi(LP);
            cout << endl;
            cout << "Pilih Prestasi: ";
            cin >> selectPrestasi;
            catchPrestasi = searchPrestasibyJenis(LP, selectPrestasi);
            while (catchPrestasi == NULL){
                cout << "TIDAK ADA PRESTASI DENGAN JENIS TERSEBUT" << endl;
                cout << "Pilih PRESTASI: ";
                cin >> selectPrestasi;
                catchPrestasi = searchPrestasibyJenis(LP, selectPrestasi);
            }
            if (availableCheckerInChildPrestasi(parent, selectPrestasi)){
                P_Pres = createChildMhstoPrestasi(catchPrestasi);
                addMhstoPrestasiChild(parent,P_Pres);
                cout << endl;
                cout << info(PM).NamaMahasiswa << " Meraih Prestasi " << info(catchPrestasi).jenis_prestasi << "!" << endl;
                cout << endl;
                cout << "Tambah data lagi? (Y/N): ";
                cin >> pilihan;
            }else {
                cout << endl;
                cout << "MAHASISWA BERSANGKUTAN SUDAH MERAIH PRESTASI INI SEBELUMNYA" << endl;
                cout << endl;
                cout << "Tambah data lagi? (Y/N): ";
                cin >> pilihan;
            }
        }
    }
};
void daftarUKM(ListUKM &LU){
    adr_UKM PU;
    infotypeU x_ukm;
    cout << "Bidang UKM: ";
    cin >> x_ukm.bidangUKM;
    cout <<"Nama UKM: ";
    cin >> x_ukm.namaUKM;
    cout << "Tahun Masuk: ";
    cin >> x_ukm.thn_masuk;
    cout << endl;
    PU = createElmUKM(x_ukm);
    insertlastU(LU,PU);
    cout << endl;
    cout << "DATA UKM BERHASIL DITAMBAH" << endl;
    cout << endl;
};
void daftarPrestasi(ListPrestasi &LP){
    adr_prestasi PP;
    infotypeP x_pres;
    cout <<"Title Prestasi: ";
    cin >> x_pres.jenis_prestasi;
    cout << "Tingkat: ";
    cin >> x_pres.skala;
    cout << "TAK: ";
    cin >> x_pres.TAK;
    cout << endl;
    PP = createElmPrestasi(x_pres);
    insertlastP(LP,PP);
    cout << endl;
    cout << "DATA PRESTASI BERHASIL DITAMBAH" << endl;
    cout << endl;
};

void addChildUKM(ListUKM LU, adr_mahasiswa &PM){
    adr_MhstoUKM P_UKM = child_ukm(PM);
    adr_MhstoUKM newUKM;
    adr_UKM select;
    while (next(P_UKM) != NULL){
        P_UKM = next(P_UKM);
    }
    string pilih;
    showUKM(LU);
    cout << endl;
    cout << "PILIH UKM: ";
    cin >> pilih;
    if (availableCheckerInChildUKM(PM,pilih)){
        select = searchUKMbyNamaUKM(LU, pilih);
        if (select != NULL){
            newUKM = createChildMhstoUKM(select);
            next(P_UKM) = newUKM;
            cout << "DATA UPDATED" << endl;
            cout << endl;
        }else {
            cout << endl;
            cout << "INPUT TIDAK VALID" << endl;
            cout << endl;
        }
    }else {
        cout << endl;
        cout << "MAHASISWA INI SUDAH MENGIKUTI UKM INI SEBELUMNYA" << endl;
        cout << endl;
    }
};

void addChildPrestasi(ListPrestasi LP, adr_mahasiswa &PM){
    adr_MhstoPrestasi P_Pres = child_prestasi(PM);
    adr_MhstoPrestasi newPres;
    adr_prestasi select;
    while (next(P_Pres) != NULL){
        P_Pres = next(P_Pres);
    }
    string pilih;
    showPrestasi(LP);
    cout << endl;
    cout << "PILIH PRESTASI: ";
    cin >> pilih;
    if (availableCheckerInChildPrestasi(PM,pilih)){
        select = searchPrestasibyJenis(LP, pilih);
        if (select != NULL){
            newPres = createChildMhstoPrestasi(select);
            next(P_Pres) = newPres;
            cout << "DATA UPDATED" << endl;
            cout << endl;
        }else {
            cout << endl;
            cout << "INPUT TIDAK VALID" << endl;
            cout << endl;
        }
    }else {
        cout << endl;
        cout << "MAHASISWA INI SUDAH MERAIH PRESTASI INI SEBELUMNYA" << endl;
        cout << endl;
    }
};


void DeleteMahasiswabyNIM(ListMahasiswa &LM, int nim, adr_mahasiswa &K){
    adr_mahasiswa Q;
    adr_mahasiswa P;
    P = searchMahasiswabyNIM(LM,nim);
    adr_mahasiswa Prec;
    Prec = first(LM);
    if (first(LM)!= NULL){
        while (next(Prec)!= NULL){
            Prec = next(Prec);
        }
        if (first(LM)==P){
            DeletefirstM(LM, K);
        }else if (Prec == P){
            DeleteLastM(LM,K);
        }else {
            K = first(LM);
            while (K != NULL && info(K).Nim != nim){
                Q = K;
                K = next(K);
            }
            next(Q) = next(K);
            next(K) = NULL;
        }
    }else {
        cout << endl;
        cout << "------------------------ DATA BELUM ADA ------------------------" << endl;
        cout << endl;
    }
};

void DeleteUKMbyJenisUKM(ListUKM &LU, string jenis, adr_UKM &K){
    adr_UKM Q;
    adr_UKM P;
    P = searchUKMbyNamaUKM(LU,jenis);
    adr_UKM Prec;
    Prec = first(LU);
    if (first(LU) != NULL){
        while (next(Prec)!= NULL){
            Prec = next(Prec);
        }
        if (first(LU) == P){
            DeletefirstU(LU, K);
        }else if (Prec == P){
            DeleteLastU(LU,K);
        }else {
            K = first(LU);
            while (K != NULL && info(K).namaUKM != jenis){
                Q = K;
                K = next(K);
            }
            next(Q) = next(K);
            next(K) = NULL;
            info(K).namaUKM = "404";
        }
    }else {
        cout << endl;
        cout << "------------------------ DATA BELUM ADA ------------------------" << endl;
        cout << endl;
    }
};

void DeletePrestasibyJenis(ListPrestasi &LP, string jenis, adr_prestasi &K){
    adr_prestasi Q;
    adr_prestasi P;
    P = searchPrestasibyJenis(LP,jenis);
    adr_prestasi Prec;
    Prec = first(LP);
    if (first(LP) != NULL){
        while (next(Prec)!= NULL){
            Prec = next(Prec);
        }
        if (first(LP)==P){
            DeletefirstP(LP, K);
        }else if (Prec == P){
            DeleteLastP(LP,K);
        }else {
            K = first(LP);
            while (K != NULL && info(K).jenis_prestasi != jenis){
                Q = K;
                K = next(K);
            }
            next(Q) = next(K);
            next(K) = NULL;
            info(K).jenis_prestasi = "404";
        }
    }else {
        cout << endl;
        cout << "------------------------ DATA BELUM ADA ------------------------" << endl;
        cout << endl;
    }
};

void removeChildUKM(adr_mahasiswa &PM, adr_MhstoUKM &P_UKM){
    adr_MhstoUKM Prec;
    string jenis;
    cout << "DATA MAHASISWA" << endl;
    cout << "NAMA: " << info(PM).NamaMahasiswa << endl;
    cout << "NIM: " << info(PM).Nim << endl;
    cout << "FAKULTAS ASAL: " << info(PM).fakultas << endl;
    cout << "IPK: " << info(PM).IPK << endl;
    cout << "UKM YANG DIAMBIL: " << endl;
    int i = 1;
    P_UKM = child_ukm(PM);
    while (P_UKM != NULL){
        if (info(choosen_ukm(P_UKM)).namaUKM != "404" ){
            cout << i << ". "<< info(choosen_ukm(P_UKM)).namaUKM << endl;
            i++;
        }
        P_UKM = next(P_UKM);
    }
    cout << "Pilih UKM yang ingin dihapus: ";
    cin >> jenis;
    P_UKM = child_ukm(PM);
    adr_MhstoUKM cek = SearchChildUKMbyMahasiswa(PM, jenis);
    if (cek != NULL){
        if (cek == child_ukm(PM)){
            child_ukm(PM) = next(cek);
            next(cek) = NULL;
        }else {
            while (next(P_UKM) != cek){
                P_UKM = next(P_UKM);
            }
            if (next(cek) != NULL){
                next(P_UKM) = next(cek);
                next(cek) = NULL;
            }else {
                next(P_UKM) = NULL;
                cek = NULL;
            }
        }
        cout <<endl;
        cout << "DATA UPDATED" << endl;
        cout << endl;
    }else {
        cout << "INPUT TIDAK VALID" << endl;
    }
};
void removeChildPrestasi(adr_mahasiswa &PM, adr_MhstoPrestasi &P_Pres){
    adr_MhstoPrestasi Prec;
    string jenis;
    cout << "DATA MAHASISWA" << endl;
    cout << "NAMA: " << info(PM).NamaMahasiswa << endl;
    cout << "NIM: " << info(PM).Nim << endl;
    cout << "FAKULTAS ASAL: " << info(PM).fakultas << endl;
    cout << "IPK: " << info(PM).IPK << endl;
    cout << "PRESTASI YANG DIRAIH: " << endl;
    int i = 1;
    P_Pres = child_prestasi(PM);
    while (P_Pres != NULL){
        if (info(choosen_prestasi(P_Pres)).jenis_prestasi != "404" ){
            cout << i << ". "<< info(choosen_prestasi(P_Pres)).jenis_prestasi << endl;
            i++;
        }
        P_Pres = next(P_Pres);
    }
    cout << "Pilih Prestasi yang ingin dihapus: ";
    cin >> jenis;
    P_Pres = child_prestasi(PM);
    adr_MhstoPrestasi cek = SearchChildPrestasibyMahasiswa(PM, jenis);
    if (cek != NULL){
        if (cek == child_prestasi(PM)){
            child_prestasi(PM) = next(cek);
            next(cek) = NULL;
        }else {
            while (next(P_Pres) != cek){
                P_Pres = next(P_Pres);
            }
            if (next(cek) != NULL){
                next(P_Pres) = next(cek);
                next(cek) = NULL;
            }else {
                next(P_Pres) = NULL;
                cek = NULL;
            }
        }
        cout <<endl;
        cout << "DATA UPDATED" << endl;
        cout << endl;
    }else {
        cout << "INPUT TIDAK VALID" << endl;
    }
};

void mainMenu(ListMahasiswa LM, ListUKM LU, ListPrestasi LP){
    int pilihan;
    cout << endl;
    cout << endl;
    cout << "------------ MAIN MENU -------------" << endl;
    cout << endl;
    cout << "1. Add Data" << endl;
    cout << "2. Delete Data" << endl;
    cout << "3. Show All Data" << endl;
    cout << "4. Search Data" << endl;
    cout << "99. Exit Application" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    if (pilihan == 1){
        cout << endl;
        cout << "1. Data Mahasiswa" << endl;
        cout << "2. Data Unit Kegiatan Mahasiswa (UKM)" << endl;
        cout << "3. Data Prestasi" << endl;
        cout << "4. Relasi UKM Mahasiswa" << endl;
        cout << "5. Relasi Prestasi Mahasiswa" << endl;
        cout << "99. Back to Main Menu" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            daftarMahasiswa(LM,LU,LP);
            mainMenu(LM,LU,LP);
        }else if (pilihan == 2){
            daftarUKM(LU);
            mainMenu(LM,LU,LP);
        }else if (pilihan == 3){
            daftarPrestasi(LP);
            mainMenu(LM,LU,LP);
        }else if (pilihan == 4){
            int selectMhs;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> selectMhs;
            adr_mahasiswa select;
            select = searchMahasiswabyNIM(LM,selectMhs);
            addChildUKM(LU,select);
            mainMenu(LM,LU,LP);
        }else if (pilihan == 5){
            int selectMhs;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> selectMhs;
            adr_mahasiswa select;
            select = searchMahasiswabyNIM(LM,selectMhs);
            addChildPrestasi(LP,select);
            mainMenu(LM,LU,LP);
        }else if (pilihan == 99){
            mainMenu(LM,LU,LP);
        }else {
            cout << endl;
            cout << "Lakukan Input dengan benar" << endl;
            mainMenu(LM,LU,LP);
        }
    }else if (pilihan == 2){
        cout << endl;
        cout << "1. Delete Data Mahasiswa" << endl;
        cout << "2. Delete Data UKM" << endl;
        cout << "3. Delete Data Prestasi" << endl;
        cout << "4. Delete Relasi UKM Mahasiswa" << endl;
        cout << "5. Delete Relasi Prestasi Mahasiswa" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            cout << endl;
            showMahasiswa(LM);
            int select;
            cout << "Data Mana yang ingin dihapus? (Masukkan NIM untuk menghapus)" << endl;
            cout << "Pilihan: ";
            cin >> select;
            adr_mahasiswa hapus;
            DeleteMahasiswabyNIM(LM,select,hapus);
            cout << endl;
            cout << "DATA MAHASISWA UPDATED" << endl;
            cout << endl;
            mainMenu(LM,LU,LP);
        }else if (pilihan == 2){
            cout << endl;
            showUKM(LU);
            string select;
            cout << "Data Mana yang ingin dihapus? (Masukkan Nama UKM untuk menghapus)" << endl;
            cout << "Pilihan: ";
            cin >> select;
            adr_UKM hapus;
            adr_UKM cari = searchUKMbyNamaUKM(LU,select);
            if (cari != NULL){
                DeleteUKMbyJenisUKM(LU,select,hapus);
                cout << endl;
                cout << "DATA UKM UPDATED" << endl;
                cout << endl;
                mainMenu(LM,LU,LP);
            }else {
                cout << endl;
                cout << "INPUT TIDAK VALID" << endl;
                cout << endl;
                mainMenu(LM,LU,LP);
            }
        }else if (pilihan == 3){
            showPrestasi(LP);
            string select;
            cout << "Data Mana yang ingin dihapus? (Masukkan Nama Prestasi untuk menghapus)" << endl;
            cout << "Pilihan: ";
            cin >> select;
            adr_prestasi hapus;
            adr_prestasi cari = searchPrestasibyJenis(LP, select);
            if (cari != NULL){
                DeletePrestasibyJenis(LP,select,hapus);
                cout << endl;
                cout << "DATA PRESTASI UPDATED" << endl;
                cout << endl;
                mainMenu(LM,LU,LP);
            }else {
                cout << endl;
                cout << "INPUT TIDAK VALID" << endl;
                cout << endl;
                mainMenu(LM,LU,LP);
            }
        }else if (pilihan == 4){
            int selectMhs;
            cout << endl;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> selectMhs;
            cout << endl;
            cout << endl;
            adr_mahasiswa select;
            adr_MhstoUKM out;
            select = searchMahasiswabyNIM(LM,selectMhs);

            removeChildUKM(select, out);
            mainMenu(LM,LU,LP);
        }else if (pilihan == 5){
            int selectMhs;
            cout << endl;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> selectMhs;
            cout << endl;
            cout << endl;
            adr_mahasiswa select;
            adr_MhstoPrestasi out;
            select = searchMahasiswabyNIM(LM,selectMhs);
            removeChildPrestasi(select, out);
            mainMenu(LM,LU,LP);
        }else {
            cout << "INPUT TIDAK VALID" << endl;
            mainMenu(LM,LU,LP);
        }
    }else if (pilihan == 3){
        cout << endl;
        cout << "1. Show Data Mahasiswa" << endl;
        cout << "2. Show Data UKM" << endl;
        cout << "3. Show Data Prestasi" << endl;
        cout << "99. Back to Main Menu" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            cout << "DATA MAHASISWA" << endl;
            cout << endl;
            showAll(LM);
            cout << "---------------------------------------------------" << endl;
            mainMenu(LM,LU,LP);
        }else if (pilihan == 2){
            cout << endl;
            showUKM(LU);
            mainMenu(LM,LU,LP);
        }else if (pilihan == 3){
            cout << endl;
            showPrestasi(LP);
            mainMenu(LM,LU,LP);
        }else if (pilihan == 99){
            mainMenu(LM,LU,LP);
        }else {
            cout << endl;
            cout << "PILIHAN TIDAK VALID" << endl;
            cout << endl;
        }
    }else if (pilihan == 4){
        cout << "1. Search Mahasiswa" << endl;
        cout << "2. Search UKM" << endl;
        cout << "3. Search Prestasi" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            int NIM;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> NIM;
            adr_mahasiswa inspect = searchMahasiswabyNIM(LM,NIM);
            if (inspect == NULL){
                cout << endl;
                cout << "DATA TIDAK ADA" << endl;
                cout << endl;
                mainMenu(LM,LU,LP);
            }else {
                cout << endl;
                cout << "                DETAIL DATA MAHASISWA" << endl;
                cout << "---------------------------------------------------" << endl;
                cout << "NAMA: " << info(inspect).NamaMahasiswa << endl;
                cout << "NIM: " << info(inspect).Nim << endl;
                cout << "FAKULTAS ASAL: " << info(inspect).fakultas << endl;
                cout << "IPK: " << info(inspect).IPK << endl;
                int TAK = 0;
                int nChildUKM = 0;
                int nChildPrestasi = 0;
                adr_MhstoPrestasi P_Pres = child_prestasi(inspect);
                while (P_Pres != NULL){
                    if (info(choosen_prestasi(P_Pres)).jenis_prestasi != "404"){
                        TAK = TAK + info(choosen_prestasi(P_Pres)).TAK;
                        nChildPrestasi = nChildPrestasi + 1;
                    }
                    P_Pres = next(P_Pres);
                }
                cout << "Jumlah TAK: " << TAK << endl;
                adr_MhstoUKM P_UKM = child_ukm(inspect);
                while (P_UKM != NULL){
                    if (info(choosen_ukm(P_UKM)).namaUKM != "404"){
                        nChildUKM = nChildUKM + 1;
                    }
                    P_UKM = next(P_UKM);
                }
                cout << "JUMLAH UKM: " << nChildUKM << endl;
                int i = 1;
                P_UKM = child_ukm(inspect);
                while (P_UKM != NULL){
                    if (info(choosen_ukm(P_UKM)).namaUKM != "404" ){
                        cout << i << ". "<< info(choosen_ukm(P_UKM)).namaUKM << endl;
                        i++;
                    }
                    P_UKM = next(P_UKM);
                }
                cout << "JUMLAH PRESTASI: " << nChildPrestasi << endl;
                int j = 1;
                P_Pres = child_prestasi(inspect);
                while (P_Pres != NULL){
                    if (info(choosen_prestasi(P_Pres)).jenis_prestasi != "404"){
                        cout << j << ". "<< info(choosen_prestasi(P_Pres)).jenis_prestasi << endl;
                        j++;
                    }
                    P_Pres = next(P_Pres);
                }
                cout << "---------------------------------------------------" << endl;
                mainMenu(LM,LU,LP);
            }
        }else if (pilihan == 2){
            string selectUKM;
            cout << "Masukkan Nama UKM: ";
            cin >> selectUKM;
            adr_UKM select = searchUKMbyNamaUKM(LU, selectUKM);
            if (select != NULL){
                cout << endl;
                cout << "UKM DATA FOUNDED!" << endl;
                cout << "-------------------------------------" << endl;
                cout << "Nama UKM: " << info(select).namaUKM <<endl;
                cout << "Bidang UKM: " << info(select).bidangUKM << endl;
                cout << "Tahun Berdiri: " << info(select).thn_masuk << endl;
                cout << "-------------------------------------" << endl;
                cout << "DAFTAR MAHASISWA YANG MENGAMBIL UKM INI: " << endl;

                int banyak = 0;
                adr_mahasiswa mhs = first(LM);
                adr_MhstoUKM mhsU;
                int o = 1;
                while (mhs != NULL){
                    mhsU = child_ukm(mhs);
                    while (mhsU != NULL){
                        if (info(select).namaUKM == info(choosen_ukm(mhsU)).namaUKM){
                            cout << o << ". "<<   info(mhs).Nim << " | " << info(mhs).NamaMahasiswa << " | " << info(mhs).fakultas << endl;
                            o++;
                        }
                        mhsU = next(mhsU);
                    }
                    mhs = next(mhs);
                }
                if (o == 1){
                    cout << "BELUM ADA MMAHASISWA YANG MENDAFTAR PADA UKM INI!" << endl;
                }
                cout << endl;
            }else {
                cout << endl;
                cout << "INPUT TIDAK VALID" << endl;
                cout << endl;
            }
            mainMenu(LM,LU,LP);
        }else if (pilihan == 3){
            string selectPrestasi;
            cout << "Masukkan Jenis Prestasi: ";
            cin >> selectPrestasi;
            adr_prestasi select = searchPrestasibyJenis(LP, selectPrestasi);
            if (select != NULL){
                cout << endl;
                cout << "PRESTASI DATA FOUNDED!" << endl;
                cout << "-------------------------------------" << endl;
                cout << "Jenis Prestasi:  " << info(select).jenis_prestasi <<endl;
                cout << "Tingkat: " << info(select).skala << endl;
                cout << "TAK: " << info(select).TAK << endl;
                cout << endl;
                cout << "DAFTAR MAHASISWA YANG MENGAMBIL UKM INI: " << endl;
                int banyak = 0;
                adr_mahasiswa mhs = first(LM);
                adr_MhstoPrestasi mhsP;
                int o = 1;
                while (mhs != NULL){
                    mhsP = child_prestasi(mhs);
                    while (mhsP != NULL){
                        if (info(select).jenis_prestasi == info(choosen_prestasi(mhsP)).jenis_prestasi){
                            cout << o << ". "<<   info(mhs).Nim << " | " << info(mhs).NamaMahasiswa  << " | " << info(mhs).fakultas << endl;
                            o++;
                        }
                        mhsP = next(mhsP);
                    }
                    mhs = next(mhs);
                }
                if (o == 1){
                    cout << "BELUM ADA MMAHASISWA YANG MERAIH PRESTASI INI!" << endl;
                }
                cout << endl;
            }else {
                cout << endl;
                cout << "INPUT TIDAK VALID" << endl;
                cout << endl;
            }
            mainMenu(LM,LU,LP);
        }else {
            cout << endl;
            cout << "PILIHAN TIDAK VALID";
            cout << endl;
        }
    }else if (pilihan == 99){
        cout << endl;
        cout << " TERIMAKASIH SUDAH MENGGUNAKAN APLIKASI DATA MAHASISWA TELKOM UNIVERSITY SEDERHANA" << endl;
        cout << "                                 CREATED BY                                       " << endl;
        cout << "                   MUHAMMAD FADJAR AL FARISYI (1303223168)                        " << endl;
    }else {
        cout << "PILIHAN TIDAK VALID" << endl;
        mainMenu(LM,LU,LP);
    }
};
