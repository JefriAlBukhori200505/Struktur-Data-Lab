// Program Insertion Sort
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Insertion Sort dari terkecil hingga terbesar
    for(int i = 1; i < n; i++){
        int key = data[i];     // Simpan elemen yang akan disisipkan
        int j = i - 1;

        // Geser elemen yang lebih besar dari key ke kanan
        while(j >= 0 && data[j] > key){
            data[j + 1] = data[j];
            j--;
        }
        // Tempatkan key pada posisi yang benar
        data[j + 1] = key;
    }

    // Tampilkan hasil setelah diurutkan
    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    
    cout << endl;
    return 0;
}
