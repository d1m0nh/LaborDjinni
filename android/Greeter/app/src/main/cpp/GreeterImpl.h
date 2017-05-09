//
// Created by Dmitri Hammernik on 08.05.17.
//

#ifndef GREETER_GREETERIMPL_H
#define GREETER_GREETERIMPL_H

#include <greeter.hpp>

using namespace libgreeter;

class GreeterImpl : public Greeter {
public:
    virtual std::string welcomeFromCpp() override;
};


#endif //GREETER_GREETERIMPL_H
