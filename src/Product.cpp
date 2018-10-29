#include "Product.hpp"

using namespace VMCore;

std::string Product::getName() {
	return m_name;
}

float Product::getValue() {
	return m_value;
}

int Product::getStock() {
	return m_stock;
}

void Product::setName(std::string t_name) {
	m_name = t_name;
}

void Product::setValue(float t_value) {
	m_value = t_value;
}

void Product::setStock(int t_stock) {
	m_stock = t_stock;
}