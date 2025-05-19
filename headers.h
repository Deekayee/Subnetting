#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include <regex>
#include <math.h>
#include "network.h"



void main_Menu();



bool validation(string& input); // will be used to validate input, using regex
vector <subNetwork> sortLANs(NETWORK);  // will take a NETWORK, and return a sorted copy
pair<ip, ip> determineNextNet(ip initIP, int _hosts, int _mask);