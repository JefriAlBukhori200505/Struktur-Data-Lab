/*
Nama: Jefri Al Bukhori
NIM : 241401142
*/

#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) cout << " ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0) cout << endl;
    }
}

// Fungsi untuk memeriksa apakah angka 'num' valid di posisi (row, col)
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Cek baris dan kolom
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    // Cek kotak 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true; // valid jika tidak melanggar aturan
}

// Fungsi utama pemecah Sudoku (DFS + Rekursi + Backtracking)
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            // Jika menemukan sel kosong (bernilai 0)
            if (board[row][col] == 0) {

                // Coba isi angka dari 1 sampai 9
                for (int num = 1; num <= 9; num++) {

                    // Periksa apakah angka valid
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num; // isi angka sementara

                        // Lanjut ke langkah berikut (rekursi = DFS)
                        if (solveSudoku(board))
                            return true; // jika berhasil, hentikan

                        // Jika gagal → kosongkan kembali (backtracking)
                        board[row][col] = 0;
                    }
                }

                // Jika tidak ada angka yang cocok, mundur (backtrack)
                return false;
            }
        }
    }

    // Jika semua sel sudah terisi → Sudoku selesai
    return true;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}
