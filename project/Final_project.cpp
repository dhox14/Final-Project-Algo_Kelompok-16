#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//deklarasi variabel penambahan layanan
const int MAX = 100;
string kode_layanan[MAX];
string nama_layanan[MAX];
int harga_layanan[MAX];
int estimasi_layanan[MAX];
bool status_layanan[MAX];
int hitung_layanan = 0;

//fungsi agar Kode Layanan dapat keluar otomatis secara berurutan
string automasiKodeLayanan(int count) {
    count += 1;

    if (count < 10) {
        return "L00" + to_string(count); // Misalnya: L001
    } else if (count < 100) {
        return "L0" + to_string(count);  // Misalnya: L010
    } else {
        return "L" + to_string(count);   // Misalnya: L100
    }
}

//menu ketika memilih Tambah Layanan pada Menu Manajemen Layanan
void tambahLayanan(){
    if (hitung_layanan >= MAX) {
        cout << "Kapasitas layanan penuh!" << endl;
        return;
    }
    // automasi kode layanan
    string kode = automasiKodeLayanan(hitung_layanan);
    kode_layanan[hitung_layanan] = kode;

    cout << "Kode Layanan: " << kode << endl; // Tampilkan kode yang dihasilkan
    cout << "Nama Layanan: ";
    cin.ignore();
    getline(cin,nama_layanan[hitung_layanan]);
    cout << "Harga per kg: ";
    cin >> harga_layanan[hitung_layanan];
    cout << "Estimasi Waktu Pengerjaan (hari): ";
    cin >> estimasi_layanan[hitung_layanan];
    cout << "Status Layanan (1 = tersedia, 0 = tidak): ";
    cin >> status_layanan[hitung_layanan];
    hitung_layanan++;
    cout << "Layanan berhasil ditambahkan!" << endl;
    cout << "================================" << endl;
}

//menu ketika memilih Lihat Layanan pada Menu Manajemen Layanan
void lihatLayanan(){
    if (hitung_layanan == 0) {
        cout << "Tidak ada layanan yang tersedia.\n";
        cout << "================================" << endl;
        return;
    }
    cout << "Daftar Layanan:" << endl;
    for (int i = 0; i < hitung_layanan; i++) {
        cout << "Kode: " << kode_layanan[i]
             << ", Nama: " << nama_layanan[i]
             << ", Harga: " << harga_layanan[i]
             << ", Estimasi: " << estimasi_layanan[i] << " hari"
             << ", Status: " << status_layanan[i] << endl;
        
    }
    cout << "================================" << endl;
}

//menu ketika memilih Ubah Layanan pada Menu Manajemen Layanan
void ubahLayanan(){
    
    if (hitung_layanan == 0) {
        cout << "Tidak ada layanan yang tersedia untuk diubah." << endl;
        cout << "================================" << endl;
        return;
    }

    cout << "Masukkan kode layanan yang ingin diubah: ";
    cout << "--------------------------------" << endl;
    string kode;
    cin >> kode;

    // Cari layanan berdasarkan kode
    int index = -1;
    for (int i = 0; i < hitung_layanan; i++) {
        if (kode_layanan[i] == kode) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Layanan dengan kode " << kode << " tidak ditemukan." << endl;
        cout << "================================" << endl;
        return;
    }

    cout << "Detail layanan saat ini:" << endl;
    cout << "Kode: " << kode_layanan[index]
         << ", Nama: " << nama_layanan[index]
         << ", Harga: " << harga_layanan[index]
         << ", Estimasi: " << estimasi_layanan[index] << " hari"
         << ", Status: " << status_layanan[index] << endl;
    cout << "--------------------------------" << endl;

    // Menu ubah layanan
    while (true) {
        cout << "Apa yang ingin diubah?" << endl;
        cout << "1. Nama Layanan" << endl;
        cout << "2. Harga Per Kg" << endl;
        cout << "3. Estimasi Waktu Pengerjaan" << endl;
        cout << "4. Status Layanan" << endl;
        cout << "5. Selesai" << endl;
        cout << "Pilih opsi: ";
        int opsi;
        cin >> opsi;
        cout << "--------------------------------" << endl;

        if (opsi == 5) {
            break;
        } 
        switch (opsi) {
            case 1:
                cout << "Masukkan nama baru: ";
                cin.ignore();
                getline(cin, nama_layanan[index]);
                cout << "Nama layanan berhasil diubah!" << endl;
                break;
            case 2:
                cout << "Masukkan harga baru per kg: ";
                cin >> harga_layanan[index];
                cout << "Harga layanan berhasil diubah!" << endl;
                break;
            case 3:
                cout << "Masukkan estimasi waktu pengerjaan baru (jam): ";
                cin >> estimasi_layanan[index];
                cout << "Estimasi waktu berhasil diubah!" << endl;
                break;
            case 4:
                cout << "Masukkan status baru (1 = tersedia, 0 = tidak): ";
                cin >> status_layanan[index];
                cout << "Status layanan berhasil diubah!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

}

//menu ketika memilih Manajemen Layanan pada Menu Admin
void manajemenLayanan(){
    while (true)
    {   cout << "Manajemen Layanan" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Tambah Layanan" << endl;
        cout << "2. Lihat Layanan" << endl;
        cout << "3. Ubah Layanan" << endl;
        cout << "4. Kembali" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih Aksi: ";
        int layanan_action;
        cin >> layanan_action;
        cout << "================================" << endl;

        if(layanan_action == 4){
            break;
        }

        if(layanan_action == 1){
            tambahLayanan();                
        }

        else if(layanan_action == 2){
            lihatLayanan();
                
        }

        else if(layanan_action == 3){
            ubahLayanan();
        }
    }
}

//deklarasi variabel penambahan layanan
string kode_pesanan[MAX];
string tanggal_masuk[MAX];
string jenis_layanan[MAX];
int berat_cucian[MAX];
string jenis_pakaian[MAX];
string deadline_pengerjaan[MAX];
string status_pesanan[MAX];
int hitung_pesanan = 0;

string automasiKodePesanan(int count){
    count += 1;

    if (count < 10) {
        return "NP00" + to_string(count); // Misalnya: L001
    } else if (count < 100) {
        return "NP0" + to_string(count);  // Misalnya: L010
    } else {
        return "NP" + to_string(count);   // Misalnya: L100
    }
}

//menu ketika memilih Tambah Pesanan pada Menu Manajemen Pesanan
void tambahPesanan(){
    if(hitung_pesanan >= MAX){
        cout << "Pesanan anda sudah penuh!" << endl;
        return;
    }
    string kode = automasiKodePesanan(hitung_pesanan);
    kode_pesanan[hitung_pesanan] = kode;

    cout << "Nomor Pesanan: " << kode << endl;
    cout << "Tanggal Masuk: ";
    cin.ignore();
    getline(cin, tanggal_masuk[hitung_pesanan]);
    cout << "Jenis Layanan: ";
    cin.ignore();
    getline(cin, jenis_layanan[hitung_pesanan]);
    cout << "Berat Cucian: ";
    cin >> berat_cucian[hitung_pesanan];
    cout << "Jenis Pakaian: ";
    cin >> jenis_pakaian[hitung_pesanan];
    cout << "Deadline Pengerjaan: ";
    cin.ignore();
    getline(cin, deadline_pengerjaan[hitung_pesanan]);
    cout << "Status Pesanan: ";
    cin >> status_pesanan[hitung_pesanan];
    hitung_pesanan++;
    cout << "Pesanan berhasil ditambahkan!" << endl;
    cout << "================================" << endl;
    
}

void semuaPesanan(){
    cout << "Daftar Layanan:" << endl;
    for (int i = 0; i < hitung_pesanan; i++) {
        cout << "Kode: " << kode_pesanan[i]
             << ", Tanggal Masuk: " << tanggal_masuk[i]
             << ", Jenis Layanan: " << jenis_layanan[i]
             << ", Berat Cucian: " << berat_cucian[i] << " kg"
             << ", Jenis Pakaian: " << jenis_pakaian[i]
             << ", Deadline Pengerjaan: " << deadline_pengerjaan[i]
             << ", Status Pesanan: " << status_pesanan[i] << endl;
        
    }
    cout << "================================" << endl;

}

//menu ketika memilih Lihat Pesanan pada Menu Manajemen Pesanan
void lihatPesanan(){
    while (true)
    {   cout << "1. Semua Pesanan" << endl;
        cout << "2. Pesanan PerStatus" << endl;
        cout << "3. Pesanan Yang Mendekati Deadline" << endl;
        cout << "4. Kembali" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih Opsi: ";
        int opsi;
        cin >> opsi;

        if(opsi == 4){
            break;
        }

        if(opsi == 1){
            semuaPesanan();
        }
        else if(opsi == 2){
        }
    }
    
}

// menu ketika memilih Manajemen Pesanan pada Menu Admin
void manajemenPesanan(){
    while (true)
    {   cout << "Manajemen Pesanan" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Lihat Pesanan" << endl;
        cout << "3. Kembali" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih Aksi: ";
        int pesanan_action;
        cin >> pesanan_action;
        cout << "================================" << endl;

        if (pesanan_action == 3){
                    break;
        }

        if(pesanan_action == 1){
            tambahPesanan();
                    
        }

        else if(pesanan_action == 2){
            if (hitung_pesanan == 0) {
                cout << "Tidak ada layanan yang tersedia.\n";
                cout << "================================" << endl;
            }else{
                lihatPesanan();
            }
                    
        }
    }
}

//menu ketika memilih Manajemen Proses pada Menu Admin
void manajemenProses(){
    while (true)
    {   cout << "Manajemen Proses" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Ubah Status Pesanan" << endl;
        cout << "2. Kembali" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih Aksi: ";
        int proses_action;
        cin >> proses_action;
        cout << "================================" << endl;

        if (proses_action == 2)
        {
            break;
        } 
        if (proses_action == 1){
            cout << "Masukkan nomor pesanan yang ingin diubah statusnya: ";
            int no_pesanan;
            cin >> no_pesanan;
        }                       
    }
}

//menu ketika memilih Admin pada Menu Utama
void menuAdmin(){
    while (true)
    {   cout << "Anda masuk sebagai Admin" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Manajemen Layanan" << endl;
        cout << "2. Manajemen Pesanan" << endl;
        cout << "3. Manajemen Proses" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih Menu: ";
        int admin_menu;
        cin >> admin_menu;
        cout << "================================" << endl;

        if(admin_menu == 4){
            break;
        }

        if(admin_menu == 1){
            manajemenLayanan();
        }
                    
        else if(admin_menu == 2){
            manajemenPesanan();                
        }

        else if(admin_menu == 3){
            manajemenProses();
        }
    }
}

//menu ketika memilih Manajemen Pekerjaan pada Menu Staff
void ManajemenPekerjaan(){
    while(true)
    {   cout << "Manajemen Pekerjaan" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Lihat Antrian Hari Ini" << endl;
        cout << "2. Lihat Detail Pesanan" << endl;
        cout << "3. Lihat Estimasi Penyelesaian" << endl;
        cout << "4. Kembali" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih Aksi: ";
        int pekerjaan_action;
        cin >> pekerjaan_action;
        cout << "================================" << endl;

        if(pekerjaan_action == 4){
            break;
        }

        if(pekerjaan_action == 1){

        }

        else if(pekerjaan_action == 2){

        }

        else if(pekerjaan_action == 3){

        }
    }
}

//menu ketika memilih Pencatatan Pesanan pada Menu Staff
void pencatatanPesanan(){
    while(true)
    {   cout << "Pencatatan Pesanan" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Cetak Nota" << endl;
        cout << "3. Cari Pesanan" << endl;
        cout << "4. Kembali" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih Aksi: ";
        int pencatatan_action;
        cin >> pencatatan_action;
        cout << "================================" << endl;

        if(pencatatan_action == 4){
            break;
        }

        if(pencatatan_action == 1){
            tambahPesanan();
        }

        else if(pencatatan_action == 2){

        }

        else if(pencatatan_action == 3){
                            
        }
    }
}

//menu ketika memilih Staff pada Menu Utama
void menuStaff(){
    while (true)
    {   cout << "Anda masuk sebagai Staff" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Manajemen Pekerjaan" << endl;
        cout << "2. Pencatatan" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih Menu: ";
        int staff_menu;
        cin >> staff_menu;
        cout << "================================" << endl;

        if(staff_menu == 3){
            break;
        }

        if(staff_menu == 1){
            ManajemenPekerjaan();
        }

        else if(staff_menu == 2){
            pencatatanPesanan();
        }
    }
}

//Menu Utama
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    while (true)
    {   cout << "Selamat Datang di Sistem Laundry" << endl;
        cout << "================================" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Keluar" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih peran anda: ";
        int role;
        cin >> role;
        cout << "================================" << endl;

        if(role == 3){
            cout << "Terima Kasih Telah Menggunakan Sistem Laundry";
            break;
        }

        if(role == 1){
            menuAdmin();
        }
        else if (role == 2){
            menuStaff();                    
        }
        else{
            cout << "Nomor Tidak Valid, Silahkan Pilih No 1, 2 atau 3" << endl;
            cout << "================================" << endl;
        }        
    }
}
