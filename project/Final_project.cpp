#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

#include "utility/include/Const.h"

using namespace std;
using namespace Const;

// deklarasi variabel penambahan layanan
const int MAX = 100;
const int MAX_HISTORY = 15;
string kode_layanan[MAX];
string nama_layanan[MAX];
int harga_layanan[MAX];
int estimasi_layanan[MAX];
int hitung_layanan = 0;

// fungsi agar Kode Layanan dapat keluar otomatis secara berurutan
string automasiKodeLayanan(int count)
{
  count += 1;

  if (count < 10)
  {
    return "L00" + to_string(count); // Misalnya: L001
  }
  else if (count < 100)
  {
    return "L0" + to_string(count); // Misalnya: L010
  }
  else
  {
    return "L" + to_string(count); // Misalnya: L100
  }
}

// Check Tahun Kabisat
bool checkTahunKabisat(int tahun)
{
  return (tahun % 4 == 0 && (tahun % 100 != 0 || tahun % 400 == 0));
}

// fungsi Validasi tanggal
bool validasiTanggalInput(int hari, int bulan, int tahun)
{
  if (bulan < 1 || bulan > 12)
  {
    return false;
  }

  int hariDalamBulan[] = {31, (checkTahunKabisat(tahun) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (hari < 1 || hari > hariDalamBulan[bulan - 1])
  {
    return false;
  }

  return true;
}

bool validasiJamMenit(int jam, int menit)
{
  if (jam < 0 || jam > 23)
  {
    return false;
  }

  if (menit < 0 || menit > 59)
  {
    return false;
  }

  return true;
}

// menu ketika memilih Tambah Layanan pada Menu Manajemen Layanan
void tambahLayanan()
{
  if (hitung_layanan >= MAX)
  {
    cout << "Kapasitas layanan penuh!" << endl;
    return;
  }
  // automasi kode layanan
  string kode = automasiKodeLayanan(hitung_layanan);
  kode_layanan[hitung_layanan] = kode;

  cout << "Kode Layanan: " << kode << endl; // Tampilkan kode yang dihasilkan

  // Validasi Nama Layanan agar tidak bisa hanya input spasi/input kosong
  string nama;
  bool validInput = false;

  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer once before the loop

  while (!validInput)
  {
    cout << "Nama Layanan: ";
    getline(cin, nama);

    // Check if input is empty or contains only spaces
    bool isOnlySpaces = true;
    for (size_t i = 0; i < nama.length(); ++i)
    {
      if (!isspace(nama[i]))
      {
        isOnlySpaces = false;
        break;
      }
    }

    if (nama.empty() || isOnlySpaces)
    {
      cout << "Masukkan input yang valid" << endl;
    }
    else
    {
      validInput = true;
      nama_layanan[hitung_layanan] = nama;
    }
  }

  // code sebelum diubah
  // cout << "Nama Layanan: ";
  // cin.ignore();
  // getline(cin,nama_layanan[hitung_layanan]);

  cout << "Harga per kg: ";
  cin >> harga_layanan[hitung_layanan];
  cout << "Estimasi Waktu Pengerjaan (hari): ";
  cin >> estimasi_layanan[hitung_layanan];
  hitung_layanan++;
  cout << "Layanan berhasil ditambahkan!" << endl;
  cout << dividerEqual << endl;
}

// menu ketika memilih Lihat Layanan pada Menu Manajemen Layanan
void lihatLayanan()
{
  if (hitung_layanan == 0)
  {
    cout << "Tidak ada layanan yang tersedia.\n";
    cout << dividerEqual << endl;
    return;
  }
  cout << "Daftar Layanan:" << endl;
  for (int i = 0; i < hitung_layanan; i++)
  {
    cout << "Kode: " << kode_layanan[i]
         << ", Nama: " << nama_layanan[i]
         << ", Harga: " << harga_layanan[i]
         << ", Estimasi: " << estimasi_layanan[i] << " hari" << endl;
  }
  cout << dividerEqual << endl;
}

// menu ketika memilih Ubah Layanan pada Menu Manajemen Layanan
void ubahLayanan()
{
  if (hitung_layanan == 0)
  {
    cout << "Tidak ada layanan yang tersedia untuk diubah." << endl;
    cout << dividerEqual << endl;
    return;
  }

  cout << "Masukkan kode layanan yang ingin diubah: ";
  cout << dividerHyphen << endl;
  string kode;
  cin >> kode;

  // Cari layanan berdasarkan kode
  int index = -1;
  for (int i = 0; i < hitung_layanan; i++)
  {
    if (kode_layanan[i] == kode)
    {
      index = i;
      break;
    }
  }

  if (index == -1)
  {
    cout << "Layanan dengan kode " << kode << " tidak ditemukan." << endl;
    cout << dividerEqual << endl;
    return;
  }

  cout << "Detail layanan saat ini:" << endl;
  cout << "Kode: " << kode_layanan[index]
       << ", Nama: " << nama_layanan[index]
       << ", Harga: " << harga_layanan[index]
       << ", Estimasi: " << estimasi_layanan[index] << " hari" << endl;
  cout << dividerHyphen << endl;

  // Menu ubah layanan
  while (true)
  {
    cout << "Apa yang ingin diubah?" << endl;
    cout << "1. Nama Layanan" << endl;
    cout << "2. Harga Per Kg" << endl;
    cout << "3. Estimasi Waktu Pengerjaan" << endl;
    cout << "4. Status Layanan" << endl;
    cout << "5. Selesai" << endl;
    cout << "Pilih opsi: ";
    int opsi;
    cin >> opsi;
    cout << dividerHyphen << endl;

    if (opsi == 5)
    {
      break;
    }
    switch (opsi)
    {
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
      cout << "Masukkan estimasi waktu pengerjaan baru (hari): ";
      cin >> estimasi_layanan[index];
      cout << "Estimasi waktu berhasil diubah!" << endl;
      break;
    default:
      cout << "Pilihan tidak valid!" << endl;
    }
  }
}

void hapusLayanan()
{
  if (hitung_layanan == 0)
  {
    cout << "Tidak ada layanan yang tersedia untuk dihapus." << endl;
    cout << dividerEqual << endl;
    return;
  }

  cout << "Masukkan kode layanan yang ingin dihapus: ";
  string kode;
  cin >> kode;

  // Cari indeks layanan yang akan dihapus
  int index = -1;
  for (int i = 0; i < hitung_layanan; i++)
  {
    if (kode_layanan[i] == kode)
    {
      index = i;
      break;
    }
  }

  if (index == -1)
  {
    cout << "Layanan dengan kode " << kode << " tidak ditemukan." << endl;
    cout << dividerEqual << endl;
    return;
  }

  // Geser data ke kiri untuk menghapus elemen
  for (int i = index; i < hitung_layanan - 1; i++)
  {
    kode_layanan[i] = kode_layanan[i + 1];
    nama_layanan[i] = nama_layanan[i + 1];
    harga_layanan[i] = harga_layanan[i + 1];
    estimasi_layanan[i] = estimasi_layanan[i + 1];
  }

  // Kurangi jumlah layanan
  hitung_layanan--;

  // Perbarui kode layanan agar tetap berurutan
  for (int i = 0; i < hitung_layanan; i++)
  {
    kode_layanan[i] = automasiKodeLayanan(i);
  }

  cout << "Layanan berhasil dihapus dan kode layanan diperbarui." << endl;
  cout << dividerEqual << endl;
}

// Fungsi untuk menghitung rata-rata waktu pengerjaan per jenis layanan
void hitungRataRataWaktuPengerjaan()
{
  if (hitung_layanan == 0)
  {
    cout << "Tidak ada layanan yang tersedia untuk menghitung rata-rata." << endl;
    cout << "================================" << endl;
    return;
  }

  // Menggunakan map untuk menyimpan total waktu dan jumlah layanan per jenis
  map<string, pair<int, int>> waktuPengerjaan; // <Nama Layanan, <Total Waktu, Jumlah Layanan>>

  for (int i = 0; i < hitung_layanan; i++)
  {
    waktuPengerjaan[nama_layanan[i]].first += estimasi_layanan[i]; // Total waktu
    waktuPengerjaan[nama_layanan[i]].second += 1;                  // Jumlah layanan
  }

  cout << "Rata-rata Waktu Pengerjaan per Jenis Layanan:" << endl;
  for (const auto &entry : waktuPengerjaan)
  {
    string namaLayanan = entry.first;
    int totalWaktu = entry.second.first;
    int jumlahLayanan = entry.second.second;
    double rataRata = static_cast<double>(totalWaktu) / jumlahLayanan;

    cout << "Jenis Layanan: " << namaLayanan
         << ", Rata-rata Waktu Pengerjaan: " << rataRata << " hari" << endl;
  }
  cout << "================================" << endl;
}

// menu ketika memilih Manajemen Layanan pada Menu Admin
void manajemenLayanan()
{
  while (true)
  {
    cout << "Manajemen Layanan" << endl;
    cout << dividerHyphen << endl;
    cout << "1. Tambah Layanan" << endl;
    cout << "2. Lihat Layanan" << endl;
    cout << "3. Ubah Layanan" << endl;
    cout << "4. Hapus Layanan" << endl;
    cout << "5. Hitung rata-rata waktu pengerjaan" << endl;
    cout << "6. Kembali" << endl;
    cout << dividerHyphen << endl;
    cout << "Pilih Aksi: ";
    int layanan_action;
    cin >> layanan_action;
    cout << dividerEqual << endl;

    if (layanan_action == 6)
    {
      break;
    }

    if (layanan_action == 1)
    {
      tambahLayanan();
    }
    else if (layanan_action == 2)
    {
      lihatLayanan();
    }
    else if (layanan_action == 3)
    {
      ubahLayanan();
    }
    else if (layanan_action == 4)
    { // Panggil fungsi hapus layanan
      hapusLayanan();
    }
    else if (layanan_action == 5)
    { // Panggil fungsi hapus layanan
      hitungRataRataWaktuPengerjaan();
    }
    else
    {
      cout << "Pilihan tidak valid!" << endl;
    }
  }
}

// deklarasi variabel penambahan pesanan
string kode_pesanan[MAX];
string tanggal_masuk[MAX];
string jenis_layanan[MAX];
int berat_cucian[MAX];
string status_pesanan[MAX];
int hitung_pesanan = 0;

string history_status[MAX][MAX_HISTORY];
string tanggal_status[MAX][MAX_HISTORY];

int cariPesananBerdasarkanKode(string kode)
{
  for (int i = 0; i < hitung_pesanan; i++)
  {
    if (kode_pesanan[i] == kode)
    {
      return i;
    }
  }
  return -1;
  // identifikasi bila tidak ditemukan;
}

string automasiKodePesanan(int count)
{
  count += 1;

  if (count < 10)
  {
    return "NP00" + to_string(count); // Misalnya: L001
  }
  else if (count < 100)
  {
    return "NP0" + to_string(count); // Misalnya: L010
  }
  else
  {
    return "NP" + to_string(count); // Misalnya: L100
  }
}

bool updateHistoryStatus(int i, string status_baru, string tanggaldiperbarui)
{
  int j = 0;

  while (j < MAX_HISTORY && history_status[i][j] != "")
  {
    j++;
  }

  if (j < MAX_HISTORY)
  {
    history_status[i][j] = status_baru;
    tanggal_status[i][j] = tanggaldiperbarui;
  }
  else
  {
    for (int k = 1; k < MAX_HISTORY; k++)
    {
      history_status[i][k - 1] = history_status[i][k];
      tanggal_status[i][k - 1] = tanggal_status[i][k];
    }

    history_status[i][MAX_HISTORY - 1] = status_baru;
    tanggal_status[i][MAX_HISTORY - 1] = tanggaldiperbarui;
  }

  return true;
}

// automasi daftar layanan yang tersedia untuk dipilih
void memilihJenisLayanan()
{
  int pilihan;
  while (true)
  {
    cout << "Jenis Layanan Tersedia:" << endl;
    for (int i = 0; i < hitung_layanan; i++)
    {
      cout << i + 1 << ". " << nama_layanan[i] << endl;
    }
    cout << "Pilih Jenis Layanan (1-" << hitung_layanan << "): ";
    cin >> pilihan;
    cout << dividerHyphen << endl;
    if (pilihan >= 1 && pilihan <= hitung_layanan)
    {
      jenis_layanan[hitung_pesanan] = nama_layanan[pilihan - 1];
      break;
    }
    else
    {
      cout << "Pilihan tidak valid, silakan coba lagi." << endl;
      cout << dividerHyphen << endl;
    }
  }
}

void filterBeratCucian()
{
  while (true)
  {
    cout << "Berat Cucian (kg): ";
    cin >> berat_cucian[hitung_pesanan];
    if (berat_cucian[hitung_pesanan] > 0)
    {
      break;
    }
    cout << "Berat cucian harus berupa angka positif. Silakan coba lagi." << endl;
    cout << dividerHyphen << endl;
  }
}

void memilihStatusPesanan(int i, string tanggal)
{
  int pilihan;
  while (true)
  {
    cout << "Daftar Status Pesanan: " << endl;
    cout << "1. Diterima" << endl;
    cout << "2. Dikerjakan" << endl;
    cout << "3. Selesai" << endl;
    cout << "4. Diambil " << endl;
    cout << "Pilih Status Pesanan: ";
    cin >> pilihan;
    cout << dividerHyphen << endl;
    if (pilihan == 1)
    {
      status_pesanan[hitung_pesanan] = "Diterima";
      updateHistoryStatus(i, "Diterima", tanggal);
      break;
    }
    else if (pilihan == 2)
    {
      status_pesanan[hitung_pesanan] = "Dikerjakan";
      updateHistoryStatus(i, "Dikerjakan", tanggal);
      break;
    }
    else if (pilihan == 3)
    {
      status_pesanan[hitung_pesanan] = "Selesai";
      updateHistoryStatus(i, "Selesai", tanggal);
      break;
    }
    else if (pilihan == 4)
    {
      status_pesanan[hitung_pesanan] = "Diambil";
      updateHistoryStatus(i, "Diambil", tanggal);
      break;
    }
    else
    {
      cout << "Pilihan tidak valid, silakan coba lagi." << endl;
      cout << dividerHyphen << endl;
    }
  }
}

// Fungsi baru untuk validasi kode unik
bool isKodePesananUnik(const string &kode)
{
  // Cek apakah kode sudah ada dalam daftar
  for (int i = 0; i < hitung_pesanan; i++)
  {
    if (kode_pesanan[i] == kode)
    {
      return false; // Kode ditemukan, berarti tidak unik
    }
  }
  return true; // Kode tidak ditemukan, berarti unik
}

// menu ketika memilih Tambah Pesanan pada Menu Manajemen Pesanan
void tambahPesanan()
{
  if (hitung_pesanan >= MAX)
  {
    cout << "Pesanan anda sudah penuh!" << endl;
    return;
  }

  string kode;
  do
  {
    // Generate kode baru hingga menemukan kode unik
    kode = automasiKodePesanan(hitung_pesanan);
  } while (!isKodePesananUnik(kode)); // <-- Ditambahkan validasi dengan fungsi isKodePesananUnik

  kode_pesanan[hitung_pesanan] = kode;

  if (hitung_layanan == 0)
  {
    cout << "Jenis Layanan Belum Diinput" << endl;
    cout << dividerEqual << endl;
    return;
  }
  cout << "Nomor Pesanan: " << kode << endl;

  char delimiter;

  int hari, bulan, tahun;
  do
  {
    cout << "Tanggal Masuk (Tanggal/Bulan/Tahun): ";
    cin >> hari >> delimiter >> bulan >> delimiter >> tahun;

    if (!validasiTanggalInput(hari, bulan, tahun))
    {
      cout << "Tanggal tidak valid! Silakan coba lagi." << endl;
      cin.ignore();
    }
  } while (!validasiTanggalInput(hari, bulan, tahun));
  string tanggal = to_string(hari) + '/' + to_string(bulan) + '/' + to_string(tahun);
  tanggal_masuk[hitung_pesanan] = tanggal;

  memilihJenisLayanan(); //
  filterBeratCucian();
  memilihStatusPesanan(hitung_pesanan, tanggal);
  hitung_pesanan++;
  cout << "Pesanan berhasil ditambahkan!" << endl;
  cout << dividerEqual << endl;
}

// menu untuk melihat semua pesanan
void semuaPesanan()
{
  cout << "Daftar Pesanan:" << endl;
  for (int i = 0; i < hitung_pesanan; i++)
  {
    cout << "Kode: " << kode_pesanan[i]
         << ", Tanggal Masuk: " << tanggal_masuk[i]
         << ", Jenis Layanan: " << jenis_layanan[i]
         << ", Berat Cucian: " << berat_cucian[i] << " kg"
         << ", Status Pesanan: " << status_pesanan[i] << endl;
  }
  cout << dividerEqual << endl;
  return;
}

void tampilkanPesananBerdasarkanStatus(const string &status)
{
  bool found = false; // Indikator jika ada data ditemukan
  for (int i = 0; i < hitung_pesanan; i++)
  {
    if (status_pesanan[i] == status)
    {
      cout << "Kode: " << kode_pesanan[i]
           << ", Tanggal Masuk: " << tanggal_masuk[i]
           << ", Jenis Layanan: " << jenis_layanan[i]
           << ", Berat Cucian: " << berat_cucian[i] << " kg"
           << ", Status Pesanan: " << status_pesanan[i] << endl;
      found = true; // Tandai bahwa ada data ditemukan
    }
  }
  if (!found)
  {
    cout << "Tidak ada pesanan dengan status " << status << "." << endl;
  }
  cout << dividerEqual << endl;
}

// menu untuk melihat pesanan perstatus
void pesananPerStatus()
{
  int pilih;
  cout << "Daftar Status Pesanan: " << endl;
  cout << "1. Diterima" << endl;
  cout << "2. Dikerjakan" << endl;
  cout << "3. Selesai" << endl;
  cout << "4. Diambil " << endl;
  cout << "Pilih Status Pesanan: ";
  cin >> pilih;
  cout << dividerHyphen << endl;

  switch (pilih)
  {
  case 1:
    tampilkanPesananBerdasarkanStatus("Diterima");
    break;
  case 2:
    tampilkanPesananBerdasarkanStatus("Dikerjakan");
    break;
  case 3:
    tampilkanPesananBerdasarkanStatus("Selesai");
    break;
  case 4:
    tampilkanPesananBerdasarkanStatus("Diambil");
    break;
  default:
    cout << "Pilihan tidak valid." << endl;
    cout << dividerEqual << endl;
  }
}

// menu ketika memilih Lihat Pesanan pada Menu Manajemen Pesanan
void lihatPesanan()
{
  while (true)
  {
    cout << "1. Semua Pesanan" << endl;
    cout << "2. Pesanan PerStatus" << endl;
    cout << "3. Kembali" << endl;
    cout << dividerHyphen << endl;
    cout << "Pilih Opsi: ";
    int opsi;
    cin >> opsi;
    cout << dividerHyphen << endl;

    if (opsi == 3)
    {
      break;
    }

    if (opsi == 1)
    {
      semuaPesanan();
    }
    else if (opsi == 2)
    {
      pesananPerStatus();
    }
    else
    {
      cout << "Opsi Tidak Valid" << endl;
      cout << dividerHyphen << endl;
    }
  }
}

// menu ketika memilih Manajemen Pesanan pada Menu Admin
void manajemenPesanan()
{
  while (true)
  {
    cout << "Manajemen Pesanan" << endl;
    cout << dividerHyphen << endl;
    cout << "1. Tambah Pesanan" << endl;
    cout << "2. Lihat Pesanan" << endl;
    cout << "3. Kembali" << endl;
    cout << dividerHyphen << endl;
    cout << "Pilih Aksi: ";
    int pesanan_action;
    cin >> pesanan_action;
    cout << dividerEqual << endl;

    if (pesanan_action == 3)
    {
      break;
    }

    if (pesanan_action == 1)
    {
      tambahPesanan();
    }

    else if (pesanan_action == 2)
    {
      if (hitung_pesanan == 0)
      {
        cout << "Tidak ada layanan yang tersedia.\n";
        cout << dividerEqual << endl;
      }
      else
      {
        lihatPesanan();
      }
    }
  }
}

void lihatHistoryStatus(string kode_pesanan_input)
{
  int index = cariPesananBerdasarkanKode(kode_pesanan_input);
  if (index == -1)
  {
    cout << "Pesanan dengan kode " << kode_pesanan_input << " tidak ditemukan!" << endl;
    cout << dividerEqual << endl;
  }
  else
  {
    cout << "History status pesanan " << kode_pesanan_input << ":" << endl;
    for (int j = 0; j < MAX_HISTORY; j++)
    {
      if (history_status[index][j] != "")
      {
        cout << history_status[index][j] << " - " << tanggal_status[index][j] << endl;
      }
    }
    cout << dividerEqual << endl;
  }
}

void ubahStatusPesanan()
{
  if (hitung_pesanan == 0)
  {
    cout << "Tidak ada status pesanan yang tersedia untuk diubah." << endl;
    cout << dividerEqual << endl;
    return;
  }

  cout << "Masukkan kode Pesanan yang statusnya ingin diubah: " << endl;
  cout << dividerHyphen << endl;
  string kode;
  cin >> kode;
  cout << dividerHyphen << endl;
  char delimiter;

  int hari, bulan, tahun;

  int index = cariPesananBerdasarkanKode(kode);

  tanggal_masuk[hitung_pesanan] = to_string(hari) + '/' + to_string(bulan) + '/' + to_string(tahun);
  cout << dividerHyphen << endl;

  if (index == -1)
  {
    cout << "Pesanan dengan kode " << kode << " tidak ditemukan." << endl;
    cout << dividerEqual << endl;
    return;
  }
  cout
      << "Detail Pesanan saat ini:" << endl;
  cout << "Kode: " << kode_pesanan[index]
       << ", Tanggal Masuk: " << tanggal_masuk[index]
       << ", Jenis Layanan: " << jenis_layanan[index]
       << ", Berat Cucian: " << berat_cucian[index] << " kg"
       << ", Status Pesanan: " << status_pesanan[index] << endl;
  cout << dividerHyphen << endl;

  // Validasi pengurutan status pesanan
  string current_status = status_pesanan[index];

  if (current_status == "Diambil")
  {
    cout << "Pesanan sudah diambil dan tidak dapat dilakukan perubahan." << endl;
    cout << dividerEqual << endl;
    return;
  }

  int opsi;
  cout << "Perbarui Status Pesanan: " << endl;

  do
  {
    cout << "Tanggal Ubah Status (Tanggal/Bulan/Tahun): ";
    cin >> hari >> delimiter >> bulan >> delimiter >> tahun;

    if (!validasiTanggalInput(hari, bulan, tahun))
    {
      cout << "Tanggal tidak valid! Silakan coba lagi." << endl;
      cin.ignore();
    }
  } while (!validasiTanggalInput(hari, bulan, tahun));

  string tanggalUpdate = to_string(hari) + '/' + to_string(bulan) + '/' + to_string(tahun);

  switch (current_status[0])
  {         // Using first character for switch
  case 'D': // "Diterima"
    if (current_status == "Diterima")
    {
      cout << "2. Dikerjakan" << endl;
      cout << "Pilih opsi: ";
      cin >> opsi;
      cout << dividerHyphen << endl;

      switch (opsi)
      {
      case 2:
        status_pesanan[index] = "Dikerjakan";

        updateHistoryStatus(index, "Dikerjakan", tanggalUpdate);

        cout
            << "Status pesanan berhasil diperbarui menjadi 'Dikerjakan'!" << endl;
        break;
      default:
        cout << "Opsi tidak valid! Status hanya dapat diubah ke 'Dikerjakan'." << endl;
      }
    }
    else
    { // "Dikerjakan"
      cout << "3. Selesai" << endl;
      cout << "Pilih opsi: ";
      cin >> opsi;
      cout << dividerHyphen << endl;

      switch (opsi)
      {
      case 3:
        status_pesanan[index] = "Selesai";
        updateHistoryStatus(index, "Selesai", tanggalUpdate);
        cout << "Status pesanan berhasil diperbarui menjadi 'Selesai'!" << endl;
        break;
      default:
        cout << "Opsi tidak valid! Status hanya dapat diubah ke 'Selesai'." << endl;
      }
    }
    break;

  case 'S': // "Selesai"
    cout << "4. Diambil" << endl;
    cout << "Pilih opsi: ";
    cin >> opsi;
    cout << dividerHyphen << endl;

    switch (opsi)
    {
    case 4:
      status_pesanan[index] = "Diambil";
      updateHistoryStatus(index, "Diambil", tanggalUpdate);
      cout << "Status pesanan berhasil diperbarui menjadi 'Diambil'!" << endl;
      break;
    default:
      cout << "Opsi tidak valid! Status hanya dapat diubah ke 'Diambil'." << endl;
    }
    break;

  default:
    cout << "Status tidak valid!" << endl;
  }

  cout << dividerEqual << endl;
}

void menuLihatHistoryStatus()
{
  cout << "Masukkan kode pesanan untuk melihat history status: ";
  string kode;
  cin >> kode;
  lihatHistoryStatus(kode);
  return;
}

// menu ketika memilih Manajemen Proses pada Menu Admin
void manajemenProses()
{
  while (true)
  {
    cout << "Manajemen Proses" << endl;
    cout << dividerHyphen << endl;
    cout << "1. Ubah Status Pesanan" << endl;
    cout << "2. Lihat History Status Pesanan" << endl;
    cout << "3. Kembali" << endl;
    cout << dividerHyphen << endl;
    cout << "Pilih Aksi: ";
    int proses_action;
    cin >> proses_action;
    cout << dividerEqual << endl;

    if (proses_action == 3)
    {
      break;
    }
    if (proses_action == 2)
    {
      menuLihatHistoryStatus();
    }
    if (proses_action == 1)
    {
      ubahStatusPesanan();
    }
  }
}

// Deklarasi variabel manajemen pendapatan
double total_pendapatan[MAX];
string tanggal_pendapatan[MAX];
int hitung_pendapatan = 0;

// Fungsi untuk manajemen pendapatan berdasarkan periode tertentu
void hitungPendapatanPerHari()
{
  if (hitung_pesanan == 0)
  {
    cout << "Tidak ada pesanan untuk dihitung.\n";
    cout << dividerEqual << endl;
    return;
  }

  cout << "Masukkan tanggal (Tanggal/Bulan/Tahun): ";
  string tanggal;
  cin.ignore();
  getline(cin, tanggal);

  double pendapatan = 0;
  bool pesananDitemukan = false;

  // Iterasi seluruh pesanan
  for (int i = 0; i < hitung_pesanan; i++)
  {
    if (tanggal_masuk[i] == tanggal &&
        (status_pesanan[i] == "Selesai" || status_pesanan[i] == "Diambil"))
    {

      // Menemukan harga layanan pada pesananan
      for (int j = 0; j < hitung_layanan; j++)
      {
        if (jenis_layanan[i] == nama_layanan[j])
        {
          pendapatan += harga_layanan[j] * berat_cucian[i];
          pesananDitemukan = true;
          break;
        }
      }
    }
  }

  if (pesananDitemukan)
  {
    // Mengumpulkan data per tanggal
    tanggal_pendapatan[hitung_pendapatan] = tanggal;
    total_pendapatan[hitung_pendapatan] = pendapatan;
    hitung_pendapatan++;

    cout << "Total pendapatan untuk tanggal " << tanggal << ": Rp. " << pendapatan << endl;
  }
  else
  {
    cout << "Tidak ada pesanan selesai atau diambil untuk tanggal tersebut.\n";
  }
  cout << dividerEqual << endl;
}

// Fungsi untuk menghitung pendapatan per bulan
void hitungPendapatanPerBulan()
{
  if (hitung_pesanan == 0)
  {
    cout << "Tidak ada pesanan untuk dihitung.\n";
    cout << dividerEqual << endl;
    return;
  }

  cout << "Masukkan bulan dan tahun (Bulan/Tahun): " << endl;
  string bulanTahun;
  cin.ignore();
  getline(cin, bulanTahun);

  double pendapatan = 0;
  bool pesananDitemukan = false;

  // Iterasi seluruh pesanan
  for (int i = 0; i < hitung_pesanan; i++)
  {
    // Mengekstrak bulan dan tahun dari variabel tanggal_masuk
    string orderBulanTahun = tanggal_masuk[i].substr(3);

    if (orderBulanTahun == bulanTahun &&
        (status_pesanan[i] == "Selesai" || status_pesanan[i] == "Diambil"))
    {

      // Mencari harga pelayanan untuk pesanan
      for (int j = 0; j < hitung_layanan; j++)
      {
        if (jenis_layanan[i] == nama_layanan[j])
        {
          pendapatan += harga_layanan[j] * berat_cucian[i];
          pesananDitemukan = true;
          break;
        }
      }
    }
  }

  if (pesananDitemukan)
  {
    cout << "Total pendapatan untuk bulan " << bulanTahun << ": Rp. " << pendapatan << endl;
  }
  else
  {
    cout << "Tidak ada pesanan selesai atau diambil untuk bulan tersebut.\n";
  }
  cout << dividerEqual << endl;
}

// Menu manajemen pendapatan
void manajemenPendapatan()
{
  while (true)
  {
    cout << "Manajemen Pendapatan" << endl;
    cout << dividerHyphen << endl;
    cout << "1. Hitung Pendapatan per Hari" << endl;
    cout << "2. Hitung Pendapatan per Bulan" << endl;
    cout << "3. Kembali" << endl;
    cout << dividerHyphen << endl;
    cout << "Pilih Aksi: ";
    int pendapatan_action;
    cin >> pendapatan_action;
    cout << dividerEqual << endl;

    if (pendapatan_action == 3)
    {
      break;
    }

    switch (pendapatan_action)
    {
    case 1:
      hitungPendapatanPerHari();
      break;
    case 2:
      hitungPendapatanPerBulan();
      break;
    default:
      cout << "Pilihan tidak valid!\n";
      cout << dividerEqual << endl;
    }
  }
}

// menu ketika memilih Admin pada Menu Utama
void menuAdmin()
{

  while (true)
  {
    cout << "Anda masuk sebagai Admin" << endl;
    cout << dividerHyphen << endl;
    cout << "1. Manajemen Layanan" << endl;
    cout << "2. Manajemen Pesanan" << endl;
    cout << "3. Manajemen Proses" << endl;
    cout << "4. Manajemen Pendapatan" << endl; // New option
    cout << "5. Logout" << endl;               // Moved to option 5
    cout << dividerHyphen << endl;
    cout << "Pilih Menu: ";
    int admin_menu;
    cin >> admin_menu;
    cout << dividerEqual << endl;

    if (admin_menu == 5)
    { // Changed from 4 to 5
      cout << "Anda telah logout." << endl;
      break;
    }

    if (admin_menu == 1)
    {
      manajemenLayanan();
    }

    else if (admin_menu == 2)
    {
      manajemenPesanan();
    }

    else if (admin_menu == 3)
    {
      manajemenProses();
    }

    else if (admin_menu == 4)
    {
      manajemenPendapatan();
    }
  }
}

void antrianPekerjaan()
{
  cout << "Daftar Antrian Pesanan yang perlu dikerjakan:" << endl;
  for (int i = 0; i < hitung_pesanan; i++)
  {
    if (status_pesanan[i] == "Diterima")
    {
      cout << "Kode: " << kode_pesanan[i]
           << ", Estimasi: " << estimasi_layanan[i] << " hari" << endl; // <-- Tampilkan estimasi waktu pengerjaan
    }
  }
  cout << dividerEqual << endl;
  return;
}

void detailPesananYangPerluDikerjakan()
{
  cout << "Detail Pesanan yang perlu dikerjakan:" << endl;
  for (int i = 0; i < hitung_pesanan; i++)
  {
    if (status_pesanan[i] == "Diterima")
    {
      cout << "Kode: " << kode_pesanan[i]
           << ", Tanggal Masuk: " << tanggal_masuk[i]
           << ", Jenis Layanan: " << jenis_layanan[i]
           << ", Berat Cucian: " << berat_cucian[i] << " kg"
           << ", Estimasi: " << estimasi_layanan[i] << " hari" // <-- Tampilkan estimasi waktu pengerjaan
           << ", Status Pesanan: " << status_pesanan[i] << endl;
    }
  }
  cout << dividerEqual << endl;
  return;
}

// menu ketika memilih Manajemen Pekerjaan pada Menu Staff
void ManajemenPekerjaan()
{
  while (true)
  {
    cout << "Manajemen Pekerjaan" << endl;
    cout << dividerHyphen << endl;
    cout << "1. Lihat Antrian Hari Ini" << endl;
    cout << "2. Lihat Detail Pesanan" << endl;
    cout << "3. Kembali" << endl;
    cout << dividerHyphen << endl;
    cout << "Pilih Aksi: ";
    int pekerjaan_action;
    cin >> pekerjaan_action;
    cout << dividerEqual << endl;

    if (pekerjaan_action == 3)
    {
      break;
    }

    if (pekerjaan_action == 1)
    {
      antrianPekerjaan();
    }

    else if (pekerjaan_action == 2)
    {
      detailPesananYangPerluDikerjakan();
    }
    else
    {
      cout << "Opsi tidak valid" << endl;
      cout << dividerHyphen << endl;
    }
  }
}

// menu untuk mencetak nota
void cetakNota()
{
  if (hitung_pesanan == 0)
  {
    cout << "Tidak ada pesanan" << endl;
    cout << dividerEqual << endl;
    return;
  }

  cout << "Masukkan kode pesanan untuk pencetakan Nota: " << endl;
  string kode;
  cin >> kode;
  cout << dividerHyphen << endl;
  // Cari pesanan berdasarkan kode

  int index = cariPesananBerdasarkanKode(kode);

  // int index = -1;
  // for (int i = 0; i < hitung_pesanan; i++)
  // {
  //   if (kode_pesanan[i] == kode)
  //   {
  //     index = i;
  //     break;
  //   }
  // }

  if (index == -1)
  {
    cout << "Pesanan dengan kode " << kode << " tidak ditemukan." << endl;
    cout << dividerEqual << endl;
    return;
  }
  if (status_pesanan[index] == "Selesai")
  {
    // Tampilkan informasi nota
    cout << dividerEqual << endl;
    cout << "Nota Pesanan" << endl;
    cout << dividerEqual << endl;
    cout << "Kode Pesanan      : " << kode_pesanan[index] << endl;
    cout << "Tanggal Masuk     : " << tanggal_masuk[index] << endl;
    cout << "Jenis Layanan     : " << jenis_layanan[index] << endl;
    cout << "Berat Cucian      : " << berat_cucian[index] << " kg" << endl;

    // Cari harga per kg berdasarkan jenis layanan
    for (int i = 0; i < hitung_layanan; i++)
    {
      if (jenis_layanan[index] == nama_layanan[i])
      {
        cout << "Harga per kg      : Rp. " << harga_layanan[i] << endl;
        cout << "Total Harga       : Rp. " << harga_layanan[i] * berat_cucian[index] << endl;
        break;
      }
    }
    cout << dividerEqual << endl;
  }
  else if (status_pesanan[index] == "Diambil")
  {
    cout << "Pesanan sudah diambil" << endl;
    cout << dividerEqual << endl;
  }
  else
  {
    cout << "Pesanan belum siap" << endl;
    cout << dividerEqual << endl;
  }
}

void mencariPesananBerdasarkanNomor()
{
  if (hitung_pesanan == 0)
  {
    cout << "Tidak ada pesanan" << endl;
    cout << dividerEqual << endl;
    return;
  }

  cout << "Masukkan kode pesanan: " << endl;
  string kode;
  cin >> kode;
  cout << dividerHyphen << endl;

  // Cari pesanan berdasarkan kode
  int index = cariPesananBerdasarkanKode(kode);

  if (index == -1)
  {
    cout << "Pesanan dengan kode " << kode << " tidak ditemukan." << endl;
    cout << dividerEqual << endl;
    return;
  }

  cout << "Pesanan dengan kode " << kode_pesanan[index] << ":" << endl;
  cout << ", Tanggal Masuk: " << tanggal_masuk[index] << endl;
  cout << ", Jenis Layanan: " << jenis_layanan[index] << endl;
  cout << ", Berat Cucian: " << berat_cucian[index] << " kg" << endl;
  cout << ", Status Pesanan: " << status_pesanan[index] << endl;
  cout << dividerEqual << endl;
}

// menu ketika memilih Pencatatan Pesanan pada Menu Staff
void pencatatanPesanan()
{
  while (true)
  {
    cout << "Pencatatan Pesanan" << endl;
    cout << dividerHyphen << endl;
    cout << "1. Tambah Pesanan" << endl;
    cout << "2. Cetak Nota" << endl;
    cout << "3. Cari Pesanan" << endl;
    cout << "4. Kembali" << endl;
    cout << dividerHyphen << endl;
    cout << "Pilih Aksi: ";
    int pencatatan_action;
    cin >> pencatatan_action;
    cout << dividerEqual << endl;

    if (pencatatan_action == 4)
    {
      break;
    }

    if (pencatatan_action == 1)
    {
      tambahPesanan();
    }

    else if (pencatatan_action == 2)
    {
      cetakNota();
    }

    else if (pencatatan_action == 3)
    {
      mencariPesananBerdasarkanNomor();
    }
  }
}

// Fungsi untuk menampilkan notifikasi pesanan mendekati batas waktu pengerjaan
void notifikasiPesananMendekatiTenggat()
{
  bool adaNotifikasi = false;
  cout << "========================================" << endl;
  cout << "[NOTIFIKASI] Pesanan Mendekati Tenggat Waktu!" << endl;
  cout << "========================================" << endl;

  for (int i = 0; i < hitung_pesanan; i++)
  {
    // Cek status dan estimasi waktu pengerjaan
    if (status_pesanan[i] == "Dikerjakan" && estimasi_layanan[i] == 1)
    {
      cout << "Kode: " << kode_pesanan[i]
           << ", Jenis Layanan: " << jenis_layanan[i]
           << ", Estimasi: " << estimasi_layanan[i] << " hari" << endl;
      adaNotifikasi = true;
    }
  }

  if (!adaNotifikasi)
  {
    cout << "Tidak ada pesanan mendekati tenggat waktu." << endl;
  }
  cout << "----------------------------------------" << endl;
}

// menu ketika memilih Staff pada Menu Utama
void menuStaff()
{
  // Tampilkan notifikasi saat login sebagai Staff
  notifikasiPesananMendekatiTenggat();

  while (true)
  {
    cout << "Anda masuk sebagai Staff" << endl;
    cout << dividerHyphen << endl;
    cout << "1. Manajemen Pekerjaan" << endl;
    cout << "2. Pencatatan" << endl;
    cout << "3. Logout" << endl;
    cout << dividerHyphen << endl;
    cout << "Pilih Menu: ";
    int staff_menu;
    cin >> staff_menu;
    cout << dividerEqual << endl;

    if (staff_menu == 3)
    {
      cout << "Anda telah logout." << endl;
      break;
    }

    if (staff_menu == 1)
    {
      ManajemenPekerjaan();
    }

    else if (staff_menu == 2)
    {
      pencatatanPesanan();
    }
  }
}

// Menu Utama
int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  while (true)
  {

    // Cout Menu Start
    cout << welcomeMessage << endl;
    cout << dividerEqual << endl;

    for (int i = 0; i < MENULENGTH; i++)
    {
      cout << roleMessage[i] << endl;
    }

    cout << dividerHyphen << endl;
    cout << "Pilih peran anda: " << endl;
    // Cout Menu End

    int role;
    cin >> role;
    cout << dividerEqual << endl;

    if (role == 3)
    {
      cout << "Terima Kasih Telah Menggunakan Sistem Laundry";
      break;
    }

    if (role == 1)
    {
      menuAdmin();
    }
    else if (role == 2)
    {
      menuStaff();
    }
    else
    {
      cout << "Nomor Tidak Valid, Silahkan Pilih No 1, 2 atau 3" << endl;
      cout << dividerEqual << endl;
    }
  }
}
