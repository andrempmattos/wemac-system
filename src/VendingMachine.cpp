#include "VendingMachine.hpp"
#include <iostream>

using namespace VMCore;

VendingMachine::VendingMachine(Interface* t_interfaceOverride) : StateMachine(ST_MAX_STATES) {

    logVendingMachine.setLevel(Log::levelError);
    logVendingMachine.setScope("[VMCORE]");
    logVendingMachine.warn("(CONSTRUCTOR)VendingMachine");

    m_interface = t_interfaceOverride;

    productDatabase = new Product[Product::MAX_VM_SLOTS];

    std::vector<productInfo> pData(Product::MAX_VM_SLOTS);
    productDatabase->getProductDatabase(pData);
    
    productDatabase->setProductDatabase(productDatabase, pData);

    logVendingMachine.debug("Product database ready");    
} 


// Cancel VendingMachine external event
void VendingMachine::cancelEvent(void) {
    // given the cancel event, transition to a new state based upon 
    // the current state of the state machine
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Transaction
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Deployment
    END_TRANSITION_MAP(nullptr)
}

// increment VendingMachine cash external event
void VendingMachine::cashIncrementEvent(float t_inputCash) {
    VendingMachineData* pData = new VendingMachineData();
    pData->cashValue = t_inputCash;

    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_TRANSACTION) // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_TRANSACTION) // ST_Transaction
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Deployment
    END_TRANSITION_MAP(pData)
}

// set VendingMachine speed external event
void VendingMachine::productSelectionEvent(int t_productSelection) {
    VendingMachineData* pData = new VendingMachineData();
    pData->productSelection = t_productSelection;

    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_VALIDATION)  // ST_Transaction
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Deployment
    END_TRANSITION_MAP(pData)
}

// state machine sits here when VendingMachine is not running
void VendingMachine::ST_Idle(EventData* pData) {
    logVendingMachine.warn("(STATE)Idle");

    AdvertisingData advertising;
    advertising.advertisingOutput = "Propaganda $$$";
    m_interface->printAdvertising(&advertising);
}

// stop the VendingMachine 
void VendingMachine::ST_Devolution(EventData* pData) {
	logVendingMachine.warn("(STATE)Devolution");
    logVendingMachine.info(("(DEVOLUTION)" + std::to_string(m_transactionCash)));

    UserData user;
    user.userOutput = "Devolution: $" + std::to_string(m_transactionCash);
    m_interface->setUserOutput(&user);
    
    m_transactionCash = 0;
    
    InternalEvent(ST_IDLE);
}

// start the VendingMachine going
void VendingMachine::ST_Validation(VendingMachineData* pData) {
    logVendingMachine.warn("(STATE)Validation");
    
        
    UserData user;
    user.userOutput = "Do you confirm the purchase? Item: " + productDatabase[pData->productSelection].getName()
                        + " $" + std::to_string(productDatabase[pData->productSelection].getValue());
    m_interface->setUserOutput(&user);
    m_interface->getUserInput(&user);    

    bool isPurchaseValid = (m_transactionCash >= productDatabase[pData->productSelection].getValue()) ? true : false;
    bool isConfirmed = (user.userInput == "y") ? true : false;

    if (isPurchaseValid && isConfirmed) {
        VendingMachineData* pDataTemp = new VendingMachineData();
        pDataTemp->productSelection = pData->productSelection;
        m_transactionCash -= productDatabase[pData->productSelection].getValue(); 

        logVendingMachine.info(("(PRODUCT)" + productDatabase[pData->productSelection].getName() + " | Valid purchase"));

        InternalEvent(ST_DEPLOYMENT, pDataTemp);
    }
    else {
        user.userOutput = "Cancelled purchase!";
        m_interface->setUserOutput(&user);

        logVendingMachine.info(("(PRODUCT)" + productDatabase[pData->productSelection].getName() + " | Invalid purchase"));
        VendingMachineData* pDataNull = new VendingMachineData();
        InternalEvent(ST_TRANSACTION, pDataNull);
    }
}

// changes the VendingMachine speed once the VendingMachine is moving
void VendingMachine::ST_Transaction(VendingMachineData* pData) {
	logVendingMachine.warn("(STATE)Transaction");
    m_transactionCash += (pData->cashValue);
    logVendingMachine.info(("(TOTAL) $" + std::to_string(m_transactionCash)));

    UserData user;
    user.userOutput = "Current cash: $" + std::to_string(m_transactionCash);
    m_interface->setUserOutput(&user);    
}

// changes the VendingMachine speed once the VendingMachine is moving
void VendingMachine::ST_Deployment(VendingMachineData* pData) {
    logVendingMachine.warn("(STATE)Deployment");
    logVendingMachine.info(("(PRODUCT)" + productDatabase[pData->productSelection].getName() + " | Deploying"));
    
    UserData user;
    user.userOutput = "Deploying: " + productDatabase[pData->productSelection].getName()
                        + " $" + std::to_string(productDatabase[pData->productSelection].getValue());
    m_interface->setUserOutput(&user);

    SystemData system;
    system.systemOutput = "(Event)Product deployment";
    m_interface->setSystemOutput(&system);

    InternalEvent(ST_DEVOLUTION);
}