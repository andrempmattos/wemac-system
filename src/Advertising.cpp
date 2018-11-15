#include "Advertising.hpp"

using namespace VMCore;

Advertising::Advertising() {

}

Advertising::~Advertising() {

}

int Advertising::getAdvertising(void) {
	return queue.cPop();
}

void Advertising::addAdvertising(int text) {
	queue.push(text);
}
