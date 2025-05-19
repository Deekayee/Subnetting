#include "headers.h"

using namespace std;

bool validation(string &input) // will be used to validate input, using regex
{
    regex ipv4(R"(\b(?:(?:25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})\.){3}(?:25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})\b)");
    smatch match;
    if (!regex_search(input, match, ipv4))
    {
        cout << "Invalid IPV4 address, try again." << endl;
        return false;
    }
    else
        return true;
}

int lambdaHosts();
vector<subNetwork> sortLANs(vector<subNetwork> subnets) // will take a vector of subnets, and return a sorted copy
{
    sort(subnets.begin(), subnets.end(), [](subNetwork a, subNetwork b)
         { return a.getHosts() > b.getHosts(); });
    return subnets;
}
pair<ip, ip> determineNextNet(ip initIP, int _hosts, int _mask) // using provided ip, will determine the network mask to host n machines
{
    int i = 0;                        // represents bit position, from right to left, 0-31
    int maxAllowed = BITSIZE - _mask; // represents max allowed bits for host, max 32 - /mask

    while (i < maxAllowed && i < BITSIZE - 1) // running through bits, stopping before mask and position, from 2^0-2^31
    {
        if (pow(2, ++i) >= _hosts + 2) // +2 for network and broadcast, need to account for them, and we increment before
        {
            ip newIP = initIP;
            cout << newIP.toString() << endl;
            newIP.jump(i);                  // add to the net bits
            cout << newIP.toString() << endl;

            int new_mask = BITSIZE - i; // get new number of bits for mask
            ip newMask(new_mask);
            return make_pair(newIP, newMask);
        }
    }
    cout << "Number of hosts exceed maximum capacity!" << endl;
    return make_pair(ip(),ip());
}
ip getNextNetwork(ip address, ip mask);