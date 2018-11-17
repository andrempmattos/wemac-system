/**
 * \file Product base class 
 * \brief It implements a commum base for the vending machine products 
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 10/28/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "../include/Product.hpp"

using namespace VMCore;

Product::Product(void) {
	logProduct->setLevel(Log::levelInfo);
	logProduct->warn("(CONSTRUCTOR)Product");
}

Product::~Product(void) {
	logProduct->warn("(DESTRUCTOR)Product");
}


int Product::getId(void) {
	return m_id;	
}

void Product::setId(ProductID t_id) {
	m_id = t_id;	
}

std::string Product::getName(void) {
	return m_name;
}

float Product::getValue(void) {
	return m_value;
}

int Product::getStock(void) {
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

void Product::getProductDatabase(std::vector<productInfo> &pData) {
	using namespace std;

	string line;
	string contentSeparator = ";";
	string data[4];
	int contentStartPos = 0;
	int contentEndPos = 0;
	int dataLength = 0;
	int j = 0;

  	ifstream products("src/../include/ProductDatabase.txt");
  	if (products.is_open()) {
  		logProduct->warn("(Database)Product database data");
		
		while(getline(products, line)) {
			for (int i = 0; i < 4; i++) {
				contentStartPos = line.find(contentSeparator, contentEndPos);
				contentEndPos = line.find(contentSeparator, contentStartPos+1);
				dataLength = contentEndPos - contentStartPos - 1;
				data[i] = line.substr(contentStartPos+1, dataLength);
				
				pData[j].name  = (i == 0) ? data[i] : pData[j].name;
				pData[j].value = (i == 1) ? stof(data[i]) : pData[j].value;
				pData[j].stock = (i == 2) ? stoi(data[i]) : pData[j].stock;
				pData[j].id  = (i == 3)   ? stoi(data[i]) : pData[j].id;
			}

			logProduct->debug("(Name )" + pData[j].name);
			logProduct->debug("(Value)" + to_string(pData[j].value));
			logProduct->debug("(Stock)" + to_string(pData[j].stock));
			logProduct->debug("(Id   )" + to_string(pData[j].id));
			j++;
			contentStartPos = 0;
			contentEndPos = 0;
		}
    	products.close();
  	}
  	else {
  		logProduct->error("(Database)Unable to open file");
  	}

}

void Product::setProductDatabase(Product* t_product, std::vector<productInfo> &pData) {
	for (int i = Product::MAX_VM_SLOTS-1; i >= 0; i--) {
		
		productInfo pDataTemp = pData.back(); 
		pData.pop_back();

		t_product[i].setName(pDataTemp.name);
		t_product[i].setValue(pDataTemp.value);
		t_product[i].setStock(pDataTemp.stock);
		t_product[i].setId((ProductID)pDataTemp.id);		
	}
}