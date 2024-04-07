#ifndef NAGYHAZI_MALOM_NAME_H
#define NAGYHAZI_MALOM_NAME_H
#include <iostream>
#include <string>

class Name{
    std::string Player_Name;
public:
    Name(std::string = "");

    std::string get_name() const;

    void set_name(std::string);

    Name& operator=(const Name&);
};

#endif //NAGYHAZI_MALOM_NAME_H
