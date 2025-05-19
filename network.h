#include <array>
#include <iostream>
#include <sstream>
#include <bitset>

#define byte unsigned char
#define BITSIZE 32

using namespace std;

class ip
{
private:
    array<byte, 4> address; // byte -> unsigned char = 1 byte = 8 bits, address is made up by 4 bytes!

public:
    /*CONSTRUCTORS*/
    //-default
    //-by bytes
    //-by existing address
    //-mask constructor
    ip() : address() {}; // default constructor

    // generic constructors
    ip(byte A, byte B, byte C, byte D) : address{A, B, C, D} {}
    ip(array<byte, 4> address) : address(address) {}
    ip(string stringIp) { fromString(stringIp); }
    ip(unsigned int mask) // takes mask in /n format
    {
        int j = 0;
        for (int i = 0; i < BITSIZE; i += 4)
        {
            string bits = "";
            for (int k = 0; k < 4; ++k)
            {
                bits += (i + k < mask) ? '1' : '0'; // chatgpted, ? checks previous condition, will output first option if true, if false second option
            }
            bitset<4> bitByte(bits);
            address[j++] = static_cast<byte>(bitByte.to_ulong());
        }
    }

    /*BIT UTILITY*/
    bitset<BITSIZE> toBitset() // return bit array
    {
        string str;
        for (byte B : address)
        {
            bitset<8> bits(B);
            str += bits.to_string();
        }
        return bitset<BITSIZE>(str);
    }

    void fromBitset(bitset<BITSIZE> bits) // write address from bit array
    {
        string str;
        for (int i = 0; i < BITSIZE; i += 4)
        {
            for (int j = 0; j < 4; j++)
            {
                str += bits[i + j];
            }
            address[i / 4] = static_cast<byte>(stoi(str, nullptr, 2));
            str = "";
        }
    }

    /*GETTER AND SETTER*/
    array<byte, 4> get() { return address; }
    int getMask()   //will count number of bits if dealing with a mask
    {
        int count = 0;
        bitset<BITSIZE> bits = this->toBitset();
        for (int i = bits.size() - 1; i >= 0; --i)
        {
            if (bits[i])
                count++;
            else
                break;
        }
        return count;
    }
    void set(array<byte, 4> address)
    {
        this->address = address;
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
    void jump(int pos) // will increment ip at specific position from the BITSIZE bits
    {

        address[3 - pos / 8] += (1 << (pos % 8));
    }
};
class subNetwork
{
private:
    ip network;
    ip mask;
    unsigned int hosts;

public:
    /*CONSTRUCTORS*/
    subNetwork() : network(ip()), mask(ip()), hosts(0) {} // default constructor

    subNetwork(ip network, ip mask, int hosts)
    {
        this->network = network;
        this->mask = mask;
        this->hosts = hosts;
    }

    /*GETTERS AND SETTERS*/
    unsigned int getHosts() { return hosts; }
    ip &getIP() { return network; }
    ip &getMask() { return mask; }

    void setHosts(unsigned int n) { hosts = n; }
    void set(ip network, ip mask, int n)
    {
        this->network = network;
        this->mask = mask;
        hosts = n;
    }
};

class NETWORK
{
private:
    vector<subNetwork> LAN;

public:
    NETWORK() : LAN{subNetwork()} {};

    NETWORK(ip &address, ip &mask) : LAN{subNetwork(address, mask, 0)} {}

    subNetwork &get() { return LAN.at(0); }
    ip &getIP() { return get().getIP(); }
    ip &getMask() { return get().getMask(); }
    unsigned int getTotal() { return get().getHosts(); }

    vector<subNetwork> &getNetwork() { return LAN; }
    subNetwork &getLAN(int i)
    {
        if (i < LAN.size())
            return LAN.at(i);
    }

    void setIP(ip &address, ip &mask, int n) { get().set(address, mask, n); }
    void setTotal(unsigned int total) { get().setHosts(total); }
    void addTotal(int addTotal) { setTotal(getTotal() + addTotal); }
    void addLAN(subNetwork &newLAN)
    {
        addTotal(newLAN.getHosts());
        LAN.push_back(newLAN);
    }
};