#include "Customer.h"

// Implement Constructor method
Customer::Customer(
    int initCustomerID,
    const std::string &initFirstName,
    const std::string &initLastName,
    const std::string &initOrganization,
    const std::string &initEmail,
    const std::string &initPhoneNumber,
    const std::string &initCity,
    const std::string &initState,
    const std::string &initAddress,
    const std::string &initRepresentative,
    bool initIsActive) : customer_id(initCustomerID),
                         first(initFirstName),
                         last(initLastName),
                         organization(initOrganization),
                         email(initEmail),
                         phone_number(initPhoneNumber),
                         city(initCity),
                         state(initState),
                         address(initAddress),
                         representative(initRepresentative),
                         is_active(initIsActive),
                         lifetime_customer_value(0.0) {}

// To be declared and implemented after Interaction class is written/implemented
// void Customer::addInteraction(const Interaction &_interaction);
// void Customr::viewInteraction() const;