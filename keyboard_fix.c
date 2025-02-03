#include <windows.h>
#include <stdio.h>
#include <time.h>

// Structure to hold key sequence information
typedef struct
{
    UINT vkCode1;     // Virtual-key code of the first key
    UINT vkCode2;     // Virtual-key code of the second key
    double timeLimit; // Time limit in seconds for the sequence
} KeySequence;

// Define the key sequences to block
KeySequence blockedSequences[] = {
    {0x49, 0xDD, 2}, // 'i' followed by ']' within 0.5 seconds
    {0x4A, 0xDE, 2}, // 'j' followed by ''' within 0.5 seconds
    {0x38, 0xBB, 2}  // '8' followed by '=' within 0.5 seconds
    // Add more sequences here...
};

HHOOK g_hKeyboardHook;      // Global keyboard hook handle
time_t g_firstKeyPressTime; // Time of the first key press in a sequence
UINT g_firstKey;            // Virtual-key code of the first key press

// Function to check if a key sequence is blocked
BOOL IsSequenceBlocked(UINT vkCode1, UINT vkCode2)
{
    for (int i = 0; i < sizeof(blockedSequences) / sizeof(blockedSequences[0]); i++)
    {
        if (blockedSequences[i].vkCode1 == vkCode1 && blockedSequences[i].vkCode2 == vkCode2)
        {
            return TRUE;
        }
    }
    return FALSE;
}

// Keyboard hook procedure
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *)lParam;

        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
        {
            // Check for the first key in a sequence
            for (int i = 0; i < sizeof(blockedSequences) / sizeof(blockedSequences[0]); i++)
            {
                if (pkbhs->vkCode == blockedSequences[i].vkCode1)
                {
                    g_firstKeyPressTime = time(NULL);
                    g_firstKey = pkbhs->vkCode;
                    break;
                }
            }

            // Check for the second key in a sequence within the time limit
            if (g_firstKey != 0)
            {
                double elapsedTime = difftime(time(NULL), g_firstKeyPressTime);
                if (elapsedTime <= blockedSequences[0].timeLimit)
                {
                    if (IsSequenceBlocked(g_firstKey, pkbhs->vkCode))
                    {
                        printf("Blocked sequence: %d, %d\n", g_firstKey, pkbhs->vkCode);
                        g_firstKey = 0; // Reset for the next sequence check
                        return 1;       // Block the key
                    }
                }
                else
                {
                    g_firstKey = 0; // Reset if time limit exceeded
                }
            }
        }
    }

    // Pass the key to the next hook in the chain
    return CallNextHookEx(g_hKeyboardHook, nCode, wParam, lParam);
}

int main()
{
    FreeConsole();

    // Install the low-level keyboard hook
    g_hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);

    if (g_hKeyboardHook == NULL)
    {
        printf("Error installing keyboard hook!\n");
        return 1;
    }

    printf("Keyboard hook installed. Press Ctrl+C to exit.\n");

    // Keep the program running and processing messages
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unhook the keyboard hook before exiting
    UnhookWindowsHookEx(g_hKeyboardHook);

    return 0;
}