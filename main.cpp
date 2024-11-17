#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    ListMahasiswa LM;
    ListUKM LU;
    ListPrestasi LP;
    infotypeM x_mhs;
    infotypeU x_ukm;
    infotypeP x_pres;
    adr_mahasiswa PM;
    adr_UKM PU;
    adr_prestasi PP;
    int n_mhs, n_ukm, n_prestasi;

    createListMahasiswa(LM);
    createListUKM(LU);
    createListPrestasi(LP);

    cout << "----------------------- Selamat Datang Di Aplikasi Data Mahasiswa-Prestasi-Organisasi -----------------------" << endl;
    cout << endl;
    cout << "SILAHKAN MASUKKAN DATA AWAL!!!" << endl;
    cout << endl;
    cout << "LIST UNIT KEGIATAN MAHASISWA (UKM)" << endl;
    cout << "Berapa data yang diinginkan?: ";
    cin >> n_ukm;
    cout << endl;
    for (int i = 0; i<n_ukm; i++){
        cout << "Data UKM ke- "<<i+1<<":"<<endl;
        cout << "Bidang UKM: ";
        cin >> x_ukm.bidangUKM;
        cout <<"Nama UKM: ";
        cin >> x_ukm.namaUKM;
        cout << "Tahun Masuk: ";
        cin >> x_ukm.thn_masuk;
        cout << endl;
        PU = createElmUKM(x_ukm);
        insertlastU(LU,PU);
    }
    cout << endl;
    cout << "------------ DATA UKM BERHASIL DI-INPUT ------------" << endl;
    cout << endl;

    cout << "LIST PRESTASI YANG DIRAIH MAHASISWA TELKOM UNIVERSITY" << endl;
    cout << "Berapa data yang diinginkan?: ";
    cin >> n_prestasi;
    for (int i = 0; i<n_prestasi; i++){
        cout << "Data UKM ke- "<< i+1<<":"<<endl;
        cout <<"Title Prestasi: ";
        cin >> x_pres.jenis_prestasi;
        cout << "Tingkat: ";
        cin >> x_pres.skala;
        cout << "TAK: ";
        cin >> x_pres.TAK;
        cout << endl;
        PP = createElmPrestasi(x_pres);
        insertlastP(LP,PP);
    }
    cout << endl;
    cout << "------------ DATA PRESTASI BERHASIL DI-INPUT ------------" << endl;
    cout << endl;
    showPrestasi(LP);
    cout << endl;
    cout << endl;
    mainMenu(LM,LU,LP);
    return 0;
}
