#include <array>
#include <iostream>
#include <sstream>

#define byte unsigned char

using namespace std;

class ip
{
private:
    array<byte, 4> address; // byte -> unsigned char = 1 byte = 8 bits, address is made up by 4 bytes!

public:
    /*CONSTRUCTORS*/
    ip() : address() {}; // default constructor

    // generic constructors
    ip(byte A, byte B, byte C, byte D) : address{A, B, C, D} {}
    ip(array<byte, 4> address) : address(address) {}

    /*GETTER AND SETTER*/
    array<byte, 4> get() { return address; }
    void set(byte A, byte B, byte C, byte D)
    {
        address = {A, B, C, D};
    }

    /*STRING UTILITY*/
    string toString() const // return ip address string in xxx.xxx.xxx.xxx format
    {
        stringstream ss;
        ss << (int)address[0] << "."
           << (int)address[1] << "."
           << (int)address[2] << "."
           << (int)address[3];

        return ss.str();
    }

    void fromString(string userInput) // create object from userInput
    {
        string str_byte;
        stringstream str_address(userInput);
        int i = 0;

        while (getline(str_address, str_byte, '.') && i < 4) // parse string to address
        {
            address[i++] = static_cast<byte>(stoi(str_byte)); // explicitly cast our int to byte type
        }
        
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