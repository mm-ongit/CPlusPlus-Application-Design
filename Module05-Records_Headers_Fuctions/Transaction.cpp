#include "Transaction.h"

Transaction::Transaction(
    const double initAmount,
    const std::string &initType) : amount(initAmount),
                                   type(initType) {}