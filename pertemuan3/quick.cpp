#include <iostream>
using namespace std;

// fungsi untuk menukar dua buah elemen
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// fungsi untuk memilih pivot
int partition(int arr[], int low, int high){
    int pivot = arr[low];   // pilih elemen pertama sebagai pivot
    int i = low;            // penunjuk kiri
    int j = high;           // penunjuk kanan

    while(true){
        // geser i ke kanan selama elemen <= pivot
        while(i <= high && arr [i] <= pivot)
            i++;

        // geser j ke kiri selama elemen > pivot
        while(j >= low && arr[j] > pivot)
            j--;

        // jika i melewati j, keluar dari perulangan
        if(i > j){
            break;
        }
        swap(arr[i], arr[j]);   // tukar elemen yang salah posisi
    }

    // letakkan pivot di posisi yang benar
    swap(arr[low], arr[j]);
    return j;   // kembalikan posisi akhir pivot
}

// fungsi rekursif
void quickSort(int arr[], int low, int high){
    if(low < high){
        int PivotIndex = partition(arr, low, high);  // dapatkan posisi pivot

        //panggil quickSort
        quickSort(arr, low, PivotIndex - 1);   // urutkan bagian kiri pivot
        quickSort(arr, PivotIndex + 1, high);  // urutkan bagian kanan pivot
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Panggil fungsi Quick Sort untuk mengurutkan data
    quickSort(data, 0, n - 1);

    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
