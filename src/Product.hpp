#ifndef VMCORE_PRODUCT_HPP
#define VMCORE_PRODUCT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Log.hpp"

namespace VMCore {
	struct productInfo {
		std::string name;
		float value;
		int stock;
		int id;
	};

	class Product {
		public:
			enum ProductID {
				SODA_SLOT_A = 0, SODA_SLOT_B, SODA_SLOT_C, 
				JUICE_SLOT_A, JUICE_SLOT_B, JUICE_SLOT_C,
				TEA_SLOT_A, TEA_SLOT_B, WATER_SLOT, MAX_VM_SLOTS  
			};
		
		private:
			Log logProduct;

			std::string m_name;
			float m_value;
			int m_stock;
			ProductID m_id;
			
			int getId(void);
			void setId(ProductID t_id);
		
		public:
			Product();
			Product(std::string t_name, float t_value, int t_stock, ProductID t_id) : 
					m_name(t_name), m_value(t_value), m_stock(t_stock), m_id(t_id) {}

			std::string getName();
			float getValue();
			int getStock();
			void setName(std::string t_name);
			void setValue(float t_value);
			void setStock(int t_stock);
			void getProductDatabase(std::vector<productInfo> &pData);
			void setProductDatabase(Product* t_product, std::vector<productInfo> &pData);
	};	
}

#endif