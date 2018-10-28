#ifndef VMCORE_PRODUCT_HPP
#define VMCORE_PRODUCT_HPP

namespace VMCore {
	class Product {
		private:
			string m_name;
			float m_value;
			int m_stock;
		public:
			Product(string t_name, float t_value, int t_stock) : m_name(t_name), m_value(t_value), m_stock(t_stock) {}
			string getName();
			float getValue();
			int getStock();
	};	
}

#endif