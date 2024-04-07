#include "name.h"

Name::Name(std::string name) : Player_Name(name) {}

std::string Name::get_name() const {
    return Player_Name;
}

void Name::set_name(std::string name) {
    Player_Name = name;
}

Name& Name::operator=(const Name &name) {
    Player_Name = name.Player_Name;
    return *this;
}
