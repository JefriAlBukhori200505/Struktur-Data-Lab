// Program Selection Sort
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Selection Sort dari terbesar hingga terkecil
    for (int i = 0; i < n - 1; i++) {
        
        int maxIndex = i;  // asumsikan elemen ke-i adalah yang terbesar
        for (int j = i + 1; j < n; j++) {  // cari elemen terbesar di sisa array
            if (data[j] > data[maxIndex]) {
                maxIndex = j;  // simpan indeks elemen terbesar
            }
        }

        // tukar elemen terbesar dengan posisi ke-i
        int temp = data[i];
        data[i] = data[maxIndex];
        data[maxIndex] = temp;
    }

    // tampilkan hasil akhir setelah diurutkan
    cout << "Data setelah diurutkan dari terbesar hingga terkecil:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
