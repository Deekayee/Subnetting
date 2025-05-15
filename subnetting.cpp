#include <iostream>
#include <vector>
#include <string>


#include "headers.h"



int main() 
{
    // vector <network> LAN;
    // main_Menu(&LAN);
    string strIp, strMask;
    system("cls");
    cout << "Please insert Ip address in following format xxx.xxx.xxx.xxx\n";
    getline(cin, strIp);
    cout << "Please insert Ip address in following format xxx.xxx.xxx.xxx\n";
    getline(cin, strMask);

    ip ip, mask;
    ip.ipFromString(strIp);
    mask.ipFromString(strMask);

    //  input reading
    cout << "IP ADDRESS: ";
    ip.ipToString();
    cout << "\nMASK: ";
    mask.ipToString();
    //  



    
    return 0;
}
