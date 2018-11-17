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
	std::cout << ("Keyboard map\n1:COKE | 2:MEET | 3:ETIRPS | 4:GRAPE | 5:ORANGE | 6:APPLE\n7:MATE | 8:CINNAMON" \
		"| 9:WATER | /:$0.25 | *:$0.50 | -:$1\n0:No | ,:Yes | +:Cancel | ;:Menu") << std::endl;
}

DebugInterface::~DebugInterface() {
}

void DebugInterface::getSystemInput(SystemData* pData) {
	//simulatedSensor = rand() % 40 + 1;
}

void DebugInterface::setSystemOutput(SystemData* pData) {
	std::cout << "[DEBUG_INTERFACE]" << pData->systemOutput << std::endl;
}

void DebugInterface::getUserInput(UserData* pData) {
	std::cin >> pData->userInput; 

	     if (pData->userInput == "/") pData->userInput = "0.25";
	else if (pData->userInput == "*") pData->userInput = "0.50";
	else if (pData->userInput == "-") pData->userInput = "1.00";
	else if (pData->userInput == "1") pData->userInput = "SODA_SLOT_A";
	else if (pData->userInput == "2") pData->userInput = "SODA_SLOT_B";
	else if (pData->userInput == "3") pData->userInput = "SODA_SLOT_C";
	else if (pData->userInput == "4") pData->userInput = "JUICE_SLOT_A";
	else if (pData->userInput == "5") pData->userInput = "JUICE_SLOT_B";
	else if (pData->userInput == "6") pData->userInput = "JUICE_SLOT_C";
	else if (pData->userInput == "7") pData->userInput = "TEA_SLOT_A";
	else if (pData->userInput == "8") pData->userInput = "TEA_SLOT_B";
	else if (pData->userInput == "9") pData->userInput = "WATER_SLOT";
	else if (pData->userInput == "0") pData->userInput = "no";
	else if (pData->userInput == ",") pData->userInput = "yes";
	else if (pData->userInput == "+") pData->userInput = "cancel";
	else if (pData->userInput == ";") pData->userInput = "menu";
	else ;
}

void DebugInterface::decodeUserInput(UserData* pData) {
	VendingMachine* pMachineCoreExtern = (VendingMachine*)pMachineCore;

	std::string menuKeyboardMap = ("Keyboard map\n1:COKE | 2:MEET | 3:ETIRPS | 4:GRAPE | 5:ORANGE | 6:APPLE\n7:MATE | 8:CINNAMON" \
								   "| 9:WATER | /:$0.25 | *:$0.50 | -:$1\n0:No | ,:Yes | +:Cancel | ;:Menu");

     	 if (pData->userInput == "0.25") pMachineCoreExtern->cashIncrementEvent(0.25);
	else if (pData->userInput == "0.50") pMachineCoreExtern->cashIncrementEvent(0.5);
	else if (pData->userInput == "1.00") pMachineCoreExtern->cashIncrementEvent(1);
	else if (pData->userInput == "SODA_SLOT_A") { pMachineCoreExtern->productSelectionEvent(Product::SODA_SLOT_A); m_productSelected = Product::SODA_SLOT_A; }
	else if (pData->userInput == "SODA_SLOT_B") { pMachineCoreExtern->productSelectionEvent(Product::SODA_SLOT_B); m_productSelected = Product::SODA_SLOT_B; }
	else if (pData->userInput == "SODA_SLOT_C") { pMachineCoreExtern->productSelectionEvent(Product::SODA_SLOT_C); m_productSelected = Product::SODA_SLOT_C; }
	else if (pData->userInput == "JUICE_SLOT_A") { pMachineCoreExtern->productSelectionEvent(Product::JUICE_SLOT_A); m_productSelected = Product::JUICE_SLOT_A; }
	else if (pData->userInput == "JUICE_SLOT_B") { pMachineCoreExtern->productSelectionEvent(Product::JUICE_SLOT_B); m_productSelected = Product::JUICE_SLOT_B; }
	else if (pData->userInput == "JUICE_SLOT_C") { pMachineCoreExtern->productSelectionEvent(Product::JUICE_SLOT_C); m_productSelected = Product::JUICE_SLOT_C; }
	else if (pData->userInput == "TEA_SLOT_A") { pMachineCoreExtern->productSelectionEvent(Product::TEA_SLOT_A); m_productSelected = Product::TEA_SLOT_A; }
	else if (pData->userInput == "TEA_SLOT_B") { pMachineCoreExtern->productSelectionEvent(Product::TEA_SLOT_B); m_productSelected = Product::TEA_SLOT_B; }
	else if (pData->userInput == "WATER_SLOT") { pMachineCoreExtern->productSelectionEvent(Product::WATER_SLOT); m_productSelected = Product::WATER_SLOT; }
	else if (pData->userInput == "no") pMachineCoreExtern->cancelEvent();
	else if (pData->userInput == "yes") pMachineCoreExtern->confirmationEvent(m_productSelected);
	else if (pData->userInput == "cancel") pMachineCoreExtern->cancelEvent();
	else if (pData->userInput == "menu") std::cout << menuKeyboardMap << std::endl;
	else ;

	pData->userInput = "";
}

void DebugInterface::setUserOutput(UserData* pData) {
	std::cout << "[DEBUG_INTERFACE]" << pData->userOutput << std::endl;
}

void DebugInterface::printAdvertising(AdvertisingData* pData) {
	std::cout << "[DEBUG_INTERFACE]" << pData->advertisingOutput << std::endl;
}

void DebugInterface::insertAdvertising(AdvertisingData* pData) {
	//TODO:Add a super user mode to manage advertising queue
}