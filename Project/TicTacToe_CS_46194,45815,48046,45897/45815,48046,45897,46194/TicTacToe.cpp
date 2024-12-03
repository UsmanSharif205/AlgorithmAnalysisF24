#include <windows.h>
#include <iostream>

using namespace std;

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int player = 1, i, choice;
char mark;
HWND hwndButtons[9]; // Store handles for the 9 buttons

int checkwin();
void updateBoard(HWND hwnd);
void resetBoard();

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int main() {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "TicTacToe";

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    HWND hwnd = CreateWindow(
        wc.lpszClassName, "Tic Tac Toe",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_CREATE:
        for (int i = 0; i < 9; i++) {
            hwndButtons[i] = CreateWindow(
                "BUTTON", "",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                50, 50, 100, 100, // Default size and position
                hwnd, (HMENU)(i + 1), (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL
            );
        }
        resetBoard(); // Initialize the board
        updateBoard(hwnd); // Update the UI
        break;

    case WM_COMMAND:
        if (HIWORD(wp) == BN_CLICKED) {
            choice = LOWORD(wp);

            if (square[choice] != '1' && square[choice] != '2' && square[choice] != '3' &&
                square[choice] != '4' && square[choice] != '5' && square[choice] != '6' &&
                square[choice] != '7' && square[choice] != '8' && square[choice] != '9') {
                return 0;
            }

            mark = (player == 1) ? 'X' : 'O';
            square[choice] = mark;
            updateBoard(hwnd);

            i = checkwin();

            if (i == 1) {
                MessageBox(hwnd, (mark == 'X') ? "Player 1 Wins!" : "Player 2 Wins!", "Game Over", MB_OK);
                resetBoard();
                updateBoard(hwnd);
            }
            else if (i == 0) {
                MessageBox(hwnd, "Game Draw!", "Game Over", MB_OK);
                resetBoard();
                updateBoard(hwnd);
            }
            else {
                player = (player % 2) ? 2 : 1;
            }
        }
        break;

    case WM_SIZE: {
        // Dynamically adjust button positions and sizes
        int width = LOWORD(lp);
        int height = HIWORD(lp);

        int buttonWidth = width / 3;
        int buttonHeight = height / 3;

        for (int i = 0; i < 9; i++) {
            int x = (i % 3) * buttonWidth;
            int y = (i / 3) * buttonHeight;

            MoveWindow(hwndButtons[i], x, y, buttonWidth, buttonHeight, TRUE);
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wp, lp);
    }

    return 0;
}

void updateBoard(HWND hwnd) {
    for (int i = 0; i < 9; i++) {
        char temp[2] = { square[i + 1], '\0' };
        SetWindowText(hwndButtons[i], temp);
    }
}

void resetBoard() {
    player = 1;
    for (int i = 1; i < 10; i++) {
        square[i] = '0' + i; // Reset square to initial numbers
    }
}

int checkwin() {
    int win[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9},
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9},
        {1, 5, 9}, {3, 5, 7}
    };

    for (int i = 0; i < 8; i++) {
        if (square[win[i][0]] == square[win[i][1]] && square[win[i][1]] == square[win[i][2]]) {
            return 1;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (square[i] != 'X' && square[i] != 'O') {
            return -1;
        }
    }

    return 0;
}


