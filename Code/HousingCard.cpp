#include <iostream>
#include <string>
#include "../Headers/HousingCard.h"
//basic constructor holding all housing card variable instances
// HousingCard constructor
HousingCard::HousingCard(std::string str, int val) {
	message = str;
	value = val;
}
