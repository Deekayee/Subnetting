#include <array>
#include <iostream>
#include <sstream>

#define byte unsigned char

using namespace std;

class ip
{
private:
    array<byte, 4> address; // byte -> unsigned char = 1 byte = 8 bits

public:
    /***************************************************************************/
    /*CONSTRUCTORS*/
    ip() : address{} {}; // default constructor

    ip(byte A, byte B, byte C, byte D) // generic constructor
    {
        address[0] = A;
        address[2] = B;
        address[2] = C;
        address[3] = D;
    }
    ip(array<byte, 4> address) // generic constructor
    {
        this->address[0] = address[0];
        this->address[1] = address[1];
        this->address[2] = address[2];
        this->address[3] = address[3];
    }

    /***************************************************************************/
    /*GETTER AND SETTER*/
    array<byte, 4> get() { return address; }
    void set(byte A, byte B, byte C, byte D)
    {
        address = {A, B, C, D};
    }

    /***************************************************************************/
    /*STRING UTILITY*/
    void ipToString() const // print in integer format
    {
        cout << (int)address[0] << "."
             << (int)address[1] << "."
             << (int)address[2] << "."
             << (int)address[3];
    }

    void ipFromString(string userInput) // create object from userInput
    {
        string str_byte[4];
        stringstream str_address(userInput);

        // parse the string to an array of bytes
        getline(str_address, str_byte[0], '.');
        getline(str_address, str_byte[1], '.');
        getline(str_address, str_byte[2], '.');
        getline(str_address, str_byte[3]);

        // convert the bytes to correct format and into ip array
        address[0] = (byte)stoi(str_byte[0]);
        address[1] = (byte)stoi(str_byte[1]);
        address[2] = (byte)stoi(str_byte[2]);
        address[3] = (byte)stoi(str_byte[3]);
    }
};
class subNetwork
{
private:

public:
    /***************************************************************************/
    ip network;
    ip mask;
    unsigned int n_machines;
    
    /*CONSTRUCTORS*/
    subNetwork() : network(ip()), mask(ip()), n_machines(0) {} // default constructor

    subNetwork(ip network, ip mask, int n_machines)
    {
        this->network = network;
        this->mask = mask;
        this->n_machines = n_machines;
    }
    /***************************************************************************/
    /***************************************************************************/
    /***************************************************************************/
    /*GETTERS AND SETTERS*/
    unsigned int getN_machines() { return n_machines; }
    void setN_machines(unsigned int n) { n_machines = n; }

    void set(ip network, ip mask, int n)
    {
        this->network = network;
        this->mask = mask;
        n_machines = n;
    }
};