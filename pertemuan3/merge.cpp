#include <iostream>   
#include <vector>     
using namespace std;  

// Fungsi untuk menggabungkan dua subarray hasil pecahan (merge)
void merge(vector<int>& arr, int left, int mid, int right) {

    
    int n1 = mid - left + 1;   // Jumlah elemen di bagian kiri
    int n2 = right - mid;      // Jumlah elemen di bagian kanan

    // Buat dua vector sementara untuk menyimpan data kiri dan kanan
    vector<int> L(n1), R(n2);

    // Salin data dari arr ke subarray L (kiri)
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Salin data dari arr ke subarray R (kanan)
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Inisialisasi indeks awal untuk subarray kiri (i), kanan (j), dan array utama (k)
    int i = 0;   
    int j = 0;      
    int k = left;

    // Bandingkan elemen dari kedua subarray dan masukkan yang lebih kecil ke array utama
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {     // Jika elemen kiri lebih kecil atau sama
            arr[k] = L[i];      // Masukkan ke array utama
            i++;                // Geser indeks kiri
        } else {                // Jika elemen kanan lebih kecil
            arr[k] = R[j];      // Masukkan elemen kanan
            j++;                // Geser indeks kanan
        }
        k++;                    // Geser posisi pada array utama
    }

    // Jika masih ada sisa elemen di L (kiri), masukkan semuanya
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Jika masih ada sisa elemen di R (kanan), masukkan semuanya
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
   
    // Basis rekursi: jika hanya satu elemen, tidak perlu diurutkan
    if (left >= right)
        return;

    // Temukan titik tengah dari array
    int mid = left + (right - left) / 2;

    // Rekursi: urutkan bagian kiri
    mergeSort(arr, left, mid);

    // Rekursi: urutkan bagian kanan
    mergeSort(arr, mid + 1, right);
   
    // Gabungkan kedua bagian yang sudah diurutkan
    merge(arr, left, mid, right);
}

// Fungsi untuk mencetak isi array ke layar
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";   // Cetak setiap elemen dipisahkan dengan spasi
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;  
   
    vector<int> data(n);   // Buat vector dengan ukuran n
    cout << "Masukkan elemen-elemen data:\n ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];    // Input elemen satu per satu
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);      // Tampilkan array sebelum diurutkan
   
    mergeSort(data, 0, n - 1);  // Panggil fungsi merge sort untuk mengurutkan
   
    cout << "Array setelah diurutkan: ";
    printArray(data);      // Tampilkan hasil array yang sudah diurutkan
   
    return 0;  
}
