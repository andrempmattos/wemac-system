#ifndef VMCORE_PRODUCT_HPP
#define VMCORE_PRODUCT_HPP

#include <string>

namespace VMCore {
	class Product {
		private:
			std::string m_name;
			float m_value;
			int m_stock;
		public:
			Product(std::string t_name, float t_value, int t_stock) : m_name(t_name), m_value(t_value), m_stock(t_stock) {}
			std::string getName();
			float getValue();
			int getStock();
			void setName(std::string t_name);
			void setValue(float t_value);
			void setStock(int t_stock);
	};	
}

#endif