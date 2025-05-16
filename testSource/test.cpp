#include <iostream>
#include <vector>
#include <string>

#include "headers.h"

int main()
{
    // vector <network> LAN;
    // main_Menu(&LAN);

    /************************************************/
    //  test ip
    system("cls");

    cout << "Input reading:" << endl;
    string strIp;
    cout << "Please insert Ip address in following format 255.255.255.255" << endl;
    getline(cin, strIp);

    ip ipInput;
    ipInput.fromString(strIp);
    cout << "IP ADDRESS: "
         << ipInput.toString() << endl;

    /************************************************/
    //  testing constructors
    ip testIp;
    cout << "Ip Default Constructor: " << testIp.toString() << endl;

    byte testByte = 255;
    array<byte, 4> bArray = {255, 255, 255, 255};

    ip testIp2(testByte, testByte, 255, 255), testIp3(bArray);
    cout << "Ip Constructors: " << endl
         << "   Byte const: " << testIp2.toString() << endl
         << "   Byte array: " << testIp3.toString() << endl;

    subNetwork testLan;
    cout << "Network Default constructor:" << endl;
    cout << "   Network: "
         << testLan.network.toString();
    cout << endl
         << "   Mask: "
         << testLan.mask.toString();
    cout << endl
         << "   Host number: "
         << testLan.n_machines << endl;

    subNetwork testLan2(ipInput, testIp2, 420);
    cout << "Network constructor:" << endl;
    cout << "   Network: "
         << testLan2.network.toString();
    cout << endl
         << "   Mask: "
         << testLan2.mask.toString();
    cout << endl
         << "   Host number: "
         << testLan2.n_machines;


    return 0;
}
