#include "../firmware/Product.hpp"

#include <iostream>

int main() {

	using namespace VMCore;

	Product p("coke", 1.5, 20);

	std::cout << p.getName() << std::endl;
	std::cout << p.getValue() << std::endl;
	std::cout << p.getStock() << std::endl;

	p.setStock(10);
	p.setName("Sprite");

	std::cout << p.getName() << std::endl;
	std::cout << p.getValue() << std::endl;
	std::cout << p.getStock() << std::endl;
}

