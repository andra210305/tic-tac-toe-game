#include <iostream>

using namespace std;

// Fungsi untuk menampilkan papan permainan
void displayBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Fungsi untuk mengecek apakah ada pemenang
char checkWinner(char board[3][3]) {
    // Cek baris dan kolom
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0]; // Pemenang pada baris i
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i]; // Pemenang pada kolom i
        }
    }

    // Cek diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0]; // Pemenang pada diagonal utama
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2]; // Pemenang pada diagonal kedua
    }

    return ' '; // Tidak ada pemenang
}

// Fungsi untuk mengecek apakah papan sudah penuh
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // Masih ada ruang kosong
            }
        }
    }
    return true; // Papan sudah penuh
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    int row, col;

    do {
        // Menampilkan papan
        displayBoard(board);

        // Meminta input baris dan kolom dari pemain
        cout << "Player " << currentPlayer << ", SILAHKAN MASUKKAN ANGKA (MISAL 0 1): ";
        cin >> row >> col;

        // Memeriksa apakah langkah valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Menyimpan langkah pemain pada papan
            board[row][col] = currentPlayer;

            // Memeriksa apakah ada pemenang
            char winner = checkWinner(board);
            if (winner != ' ') {
                displayBoard(board);
                cout << "Player " << winner << " wins!" << endl;
                break;
            }

            // Memeriksa apakah papan sudah penuh (seri)
            if (isBoardFull(board)) {
                displayBoard(board);
                cout << "It's a tie!" << endl;
                break;
            }

            // Ganti giliran pemain
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }

    } while (true);

    return 0;
}

