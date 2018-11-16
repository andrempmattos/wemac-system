/**
 * \file Computer-oriented interface class 
 * \brief It implements a console/keyboard interface system
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 11/06/2017
 * 
 * \defgroup Computer Debug Interface
 */

#include "../include/DebugInterface.hpp"

using namespace VMCore;

DebugInterface::DebugInterface() {
}

DebugInterface::~DebugInterface() {
}

void DebugInterface::getSystemInput(SystemData* pData) {
	//TODO:Get a simulated sensor/pin data
}

void DebugInterface::setSystemOutput(SystemData* pData) {
	std::cout << "[VIRTUAL](INTERFACE)" << pData->systemOutput << std::endl;
	//TODO:Set a actuator/pin value
}

void DebugInterface::getUserInput(UserData* pData) {
	std::cin >> pData->userInput; 

	     if (pData->userInput == "/") pData->userInput = "0.25";
	else if (pData->userInput == "*") pData->userInput = "0.50";
	else if (pData->userInput == "-") pData->userInput = "1.00";
	else if (pData->userInput == "1") pData->userInput = "0"; //SODA_SLOT_A
	else if (pData->userInput == "2") pData->userInput = "1"; //SODA_SLOT_B
	else if (pData->userInput == "3") pData->userInput = "2"; //SODA_SLOT_C
	else if (pData->userInput == "4") pData->userInput = "3"; //JUICE_SLOT_A
	else if (pData->userInput == "5") pData->userInput = "4"; //JUICE_SLOT_B
	else if (pData->userInput == "6") pData->userInput = "5"; //JUICE_SLOT_C
	else if (pData->userInput == "7") pData->userInput = "6"; //TEA_SLOT_A
	else if (pData->userInput == "8") pData->userInput = "7"; //TEA_SLOT_B
	else if (pData->userInput == "9") pData->userInput = "8"; //WATER_SLOT
	else if (pData->userInput == "0") pData->userInput = "n";
	else if (pData->userInput == ",") pData->userInput = "y";
	else if (pData->userInput == "+") pData->userInput = "cancel";
	else if (pData->userInput == ";") pData->userInput = "menu";
	else if (pData->userInput == "t") pData->userInput = "timer";
	else ;
}

void DebugInterface::setUserOutput(UserData* pData) {
	std::cout << "[VIRTUAL](INTERFACE)" << pData->userOutput << std::endl;
}

void DebugInterface::printAdvertising(AdvertisingData* pData) {
	std::cout << "[VIRTUAL](INTERFACE)" << pData->advertisingOutput << std::endl;
}

void DebugInterface::insertAdvertising(AdvertisingData* pData) {
	//TODO:Add a super user mode to manage advertising queue
}