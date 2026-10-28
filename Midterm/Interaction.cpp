#include "Interaction.h"

Interaction::Interaction(
    const std::string &initType,
    const std::string &initDate,
    const std::string &initNotes) : type(initType),
                                    date(initDate),
                                    notes(initNotes) {}