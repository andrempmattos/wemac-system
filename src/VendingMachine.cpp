/**
 * \file Main vending machine class 
 * \brief It holds all the core system
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 10/27/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "../include/VendingMachine.hpp"

using namespace VMCore;

VendingMachine::VendingMachine(Interface* t_interfaceOverride) : StateMachine(ST_MAX_STATES) {

    //Log system setup
    logVendingMachine->setLevel(Log::noLog);   
    logVendingMachine->warn("(CONSTRUCTOR)VendingMachine");
    
    //Change the interface used
    m_interface = t_interfaceOverride;

    //Add the product database into the system
    productDatabase = new Product[Product::MAX_VM_SLOTS];
    std::vector<productInfo> pData(Product::MAX_VM_SLOTS);
    productDatabase->getProductDatabase(pData);    
    productDatabase->setProductDatabase(productDatabase, pData);
    //logVendingMachine->debug("Product database ready");    
} 

VendingMachine::~VendingMachine() {
    logVendingMachine->warn("(DESTRUCTOR)VendingMachine");
}

//Timer VendingMachine external event
void VendingMachine::timerEvent(void) {
    logVendingMachine->warn("(EXTERNAL_EVENT)Timer");
    
    //Given the timer event, transition to a new state based upon 
    //the current state of the state machine
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_ADVERTISING) // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Validation
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Transaction
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Deployment
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Advertising
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Confirmation
    END_TRANSITION_MAP(nullptr)
}

//Cancel VendingMachine external event
void VendingMachine::cancelEvent(void) {
    logVendingMachine->warn("(EXTERNAL_EVENT)Cancel");

    UserData user;
    user.userOutput = "Purchase canceled!";
    m_interface->setUserOutput(&user);

    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Transaction
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Deployment
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Advertising
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Confirmation
    END_TRANSITION_MAP(nullptr)
}

//Cancel VendingMachine external event
void VendingMachine::confirmationEvent(int t_productSelection) {
    logVendingMachine->warn("(EXTERNAL_EVENT)Confirmation");

    VendingMachineData* pData = new VendingMachineData();
    pData->productSelection = t_productSelection;

    m_transactionCash -= productDatabase[pData->productSelection].getValue(); 
    UserData user;
    user.userOutput = "Thank you for your preference!";
    m_interface->setUserOutput(&user);

    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Validation
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Transaction
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Deployment
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Advertising
        TRANSITION_MAP_ENTRY (ST_DEPLOYMENT)  // ST_Confirmation
    END_TRANSITION_MAP(pData)
}

//Increment VendingMachine cash external event
void VendingMachine::cashIncrementEvent(float t_inputCash) {
    logVendingMachine->warn("(EXTERNAL_EVENT)Cash increment");
    
    VendingMachineData* pData = new VendingMachineData();
    pData->cashValue = t_inputCash;

    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_TRANSACTION) // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_TRANSACTION) // ST_Transaction
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Deployment
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Advertising
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Confirmation
    END_TRANSITION_MAP(pData)
}

//Select VendingMachine product external event
void VendingMachine::productSelectionEvent(int t_productSelection) {
    logVendingMachine->warn("(EXTERNAL_EVENT)Product selection");
    
    VendingMachineData* pData = new VendingMachineData();
    pData->productSelection = t_productSelection;

    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_VALIDATION)  // ST_Transaction
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Deployment
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Advertising
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Confirmation
    END_TRANSITION_MAP(pData)

}

//State machine sits here when there is any user interaction
void VendingMachine::ST_Idle(EventData* pData) {
    logVendingMachine->warn("(STATE)Idle");
}

//Give back the current user cash 
void VendingMachine::ST_Devolution(EventData* pData) {
	logVendingMachine->warn("(STATE)Devolution");
    logVendingMachine->info(("(DEVOLUTION)" + std::to_string(m_transactionCash)));

    UserData user;
    user.userOutput = "Devolution: $" + std::to_string(m_transactionCash);
    m_interface->setUserOutput(&user);

    //TODO: Implement the physical system out(i.e. LED)
    SystemData system;
    system.systemOutput = "System out: $" + std::to_string(m_transactionCash);
    m_interface->setSystemOutput(&system);
    
    m_totalMachineCash -= m_transactionCash;
    m_transactionCash = 0;
    
    logVendingMachine->warn("(INTERNAL_EVENT)ST_Devolution to ST_Idle");
    InternalEvent(ST_IDLE);
}

//Check if the transaction is valid due to the user product selection 
void VendingMachine::ST_Validation(VendingMachineData* pData) {
    logVendingMachine->warn("(STATE)Validation");
       
    UserData user;  
    bool isEnoughCash = (m_transactionCash >= productDatabase[pData->productSelection].getValue()) ? true : false;
    bool isEnoughStock = (productDatabase[pData->productSelection].getStock() >= 1) ? true : false;

    if (isEnoughCash && isEnoughStock) {
        VendingMachineData* pDataTemp = new VendingMachineData();
        pDataTemp->productSelection = pData->productSelection; 

        logVendingMachine->info("(PRODUCT)Valid purchase of " + productDatabase[pData->productSelection].getName());
        logVendingMachine->warn("(INTERNAL_EVENT)ST_Validation to ST_Confirmation");
        InternalEvent(ST_CONFIRMATION, pDataTemp);  // Valid Event
    }
    else if (isEnoughCash && !isEnoughStock) {
        user.userOutput = "Sorry! Insufficient stock, try other product";
        m_interface->setUserOutput(&user);

        logVendingMachine->info("(PRODUCT)No item in stock");
        logVendingMachine->warn("(INTERNAL_EVENT)ST_Validation to ST_Transaction");
        VendingMachineData* pDataNull = new VendingMachineData();
        InternalEvent(ST_TRANSACTION, pDataNull);   //Invalid Event
    }
    else {
        user.userOutput = "Insufficient balance, insert more cash";
        m_interface->setUserOutput(&user);

        logVendingMachine->info("(PRODUCT)No cash for " + productDatabase[pData->productSelection].getName());
        logVendingMachine->warn("(INTERNAL_EVENT)ST_Validation to ST_Transaction");
        VendingMachineData* pDataNull = new VendingMachineData();
        InternalEvent(ST_TRANSACTION, pDataNull);   //Invalid Event
    }
}
 
//Increase the user cash due to input coins
void VendingMachine::ST_Transaction(VendingMachineData* pData) {
	logVendingMachine->warn("(STATE)Transaction");
    m_transactionCash += (pData->cashValue);
    m_totalMachineCash += (pData->cashValue);
    logVendingMachine->info(("(TRANSACTION_TOTAL_CASH) $" + std::to_string(m_transactionCash)));
    logVendingMachine->info(("(MACHINE_TOTAL_CASH) $" + std::to_string(m_totalMachineCash)));

    UserData user;
    user.userOutput = "Current cash: $" + std::to_string(m_transactionCash);
    m_interface->setUserOutput(&user);    
}

//Deploy the selected product to the user
void VendingMachine::ST_Deployment(VendingMachineData* pData) {
    logVendingMachine->warn("(STATE)Deployment");
    
    int stockTemp = productDatabase[pData->productSelection].getStock();
    productDatabase[pData->productSelection].setStock((stockTemp-1));

    logVendingMachine->warn("(PRODUCT) Deploy: " + productDatabase[pData->productSelection].getName() 
                          + " New stock: " + std::to_string(stockTemp-1));

    UserData user;
    user.userOutput = "Deploying: " + productDatabase[pData->productSelection].getName()
                        + " $" + std::to_string(productDatabase[pData->productSelection].getValue());
    m_interface->setUserOutput(&user);

    //TODO: Implement the physical system out(i.e. LED)
    SystemData system;
    system.systemOutput = "Product deployed";
    m_interface->setSystemOutput(&system);

    logVendingMachine->warn("(INTERNAL_EVENT)ST_Deployment to ST_Devolution");
    InternalEvent(ST_DEVOLUTION);
}

//Show same Advertisings
void VendingMachine::ST_Advertising(void) {
    logVendingMachine->warn("(STATE)Advertising");

    AdvertisingData advertising;
    advertising.advertisingOutput = "Propaganda $$$";
    m_interface->printAdvertising(&advertising);

    logVendingMachine->warn("(INTERNAL_EVENT)ST_Advertising to ST_Idle");
    InternalEvent(ST_IDLE);
}

//Confirmation State
void VendingMachine::ST_Confirmation(VendingMachineData* pData) {
    logVendingMachine->warn("(STATE)Confirmation");

    UserData user;
    user.userOutput = "Do you confirm the purchase? (Y/N) Item: " + productDatabase[pData->productSelection].getName()
                        + " $" + std::to_string(productDatabase[pData->productSelection].getValue());
    m_interface->setUserOutput(&user);  
}