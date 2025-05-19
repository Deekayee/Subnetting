#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "headers.h"

using namespace std;

void testINIT()
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
          << testLan.getIP().toString();
     cout << endl
          << "   Mask: "
          << testLan.getMask().toString();
     cout << endl
          << "   Host number: "
          << testLan.getHosts() << endl;

     subNetwork testLan2(ipInput, testIp2, 420);
     cout << "Network constructor:" << endl;
     cout << "   Network: "
          << testLan2.getIP().toString();
     cout << endl
          << "   Mask: "
          << testLan2.getMask().toString();
     cout << endl
          << "   Host number: "
          << testLan2.getHosts();
}

int main()
{
     system("cls");
     subNetwork LAN1(ip(192, 168, 0, 0), ip(255, 255, 255, 0), 14);
     ip testbit(255, 255, 0, 0);
     cout << testbit.toBitset().to_string() << endl
          << testbit.getMask() << endl;

     do
     {
          /* code */
          string str;
          ip ipLan, maskLan;
          cout << "Insert an IP: ";
          getline(cin, str);
          ipLan.fromString(str);
     
          cout << "Insert a mask: ";
          getline(cin, str);
          maskLan.fromString(str);
     
          cout << "Inser nMachines: ";
          int nmachines;
          cin >> nmachines;
          cin.ignore();
     
          subNetwork LAN2(ipLan, maskLan, nmachines);
          auto result = determineNextNet(LAN2.getIP(), LAN2.getHosts(), LAN2.getMask().getMask());
          cout << "Next ip: " << result.first.toString() << endl
               << "New mask: " << result.second.toString();
     } while (true);
     

     auto result = determineNextNet(LAN1.getIP(), LAN1.getHosts(), LAN1.getMask().getMask());
     ip newIP = result.first;
     ip newMask = result.second;
     cout << "Returned:" << endl
          << newIP.toString() << endl
          << newMask.toString() << endl;
     cout << "Expected:\n     192.168.0.16\n     255.255.255.240"; // fuck you thats why
     return 0;
}
