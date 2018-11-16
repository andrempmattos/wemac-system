/**
 * \file Advertising class 
 * \brief It implements the advertising system
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 11/06/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "../include/Advertising.hpp"

using namespace VMCore;

Advertising::Advertising() {

}

Advertising::~Advertising() {

}

std::string Advertising::getAdvertising(void) {

	if(mainQueue.getdataHead() == removedQueue.getdataHead()) {  // Delete the advertising at the main Queue if that is equal to the head of the removedQueue.
		mainQueue.dPop();
		removedQueue.dPop();
	}
	
	return mainQueue.cPop();
}

void Advertising::addAdvertising(std::string text) {
	mainQueue.push(text);
}

void Advertising::removeAdvertising(std::string advertisingID) { 
	removedQueue.push(advertisingID);			// Add in this queue the advertising that will be removed
}

