#include "Transaction.h"

Transaction::Transaction(
    const std::string &initType,
    const std::string &initDate,
    const double initAmount) : type(initType), date(initDate), amount(initAmount) {}