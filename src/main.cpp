#include "VendingMachine.hpp"
#include <iostream>
#include <vector>

int main() {

	using namespace VMCore;

	VendingMachine VM;

	float inputCash = 0;
	int prodSel = 0;

	std::cout << "Cash value" << std::endl;
	std::cin >> inputCash;

	std::cout << "Product selection" << std::endl;
	std::cin >> prodSel;

	VM.cashIncrementEvent(inputCash);

	VM.productSelectionEvent(prodSel);

	VM.cancelEvent();
}

