/**
 * \file Main file 
 * \brief It instantiates the vending machine system and the platform-oriented interfaces 
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 10/28/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "VendingMachine.hpp"
#include "DebugInterface.hpp"
#include "../include/ProjectIncludes.hpp"

//Debug main file version (first project checkpoint/assigment).
int main() {
	using namespace VMCore;

	Interface* interfaceOverride = new DebugInterface();
	VendingMachine VM(interfaceOverride);

	//This code section will be integrated to the interface class in a different implementation. 
	UserData* user = new UserData();
	user->userOutput = ("Keyboard map\n1:COKE | 2:MEET | 3:ETIRPS | 4:GRAPE | 5:ORANGE | 6:APPLE\n7:MATE | 8:CINNAMON" \
						"| 9:WATER | /:$0.25 | *:$0.50 | -:$1\n0:No | ,:Yes | +:Cancel | ;:Menu");
	interfaceOverride->setUserOutput(user);

	//Continuously ask for user input interaction. 
	while(true) {
		interfaceOverride->getUserInput(user);
		
			 if (user->userInput == "0.25") VM.cashIncrementEvent(0.25);
		else if (user->userInput == "0.50") VM.cashIncrementEvent(0.5);
		else if (user->userInput == "1.00") VM.cashIncrementEvent(1);
		else if (user->userInput == "0") VM.productSelectionEvent(Product::SODA_SLOT_A);
		else if (user->userInput == "1") VM.productSelectionEvent(Product::SODA_SLOT_B);
		else if (user->userInput == "2") VM.productSelectionEvent(Product::SODA_SLOT_C);
		else if (user->userInput == "3") VM.productSelectionEvent(Product::JUICE_SLOT_A);
		else if (user->userInput == "4") VM.productSelectionEvent(Product::JUICE_SLOT_B);
		else if (user->userInput == "5") VM.productSelectionEvent(Product::JUICE_SLOT_C);
		else if (user->userInput == "6") VM.productSelectionEvent(Product::TEA_SLOT_A);
		else if (user->userInput == "7") VM.productSelectionEvent(Product::TEA_SLOT_B);
		else if (user->userInput == "8") VM.productSelectionEvent(Product::WATER_SLOT);
		else if (user->userInput == "cancel") VM.cancelEvent();
		else if (user->userInput == "menu") interfaceOverride->setUserOutput(user);
		else ;
	}

	delete user;
	delete interfaceOverride
}