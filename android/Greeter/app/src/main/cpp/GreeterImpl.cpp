//
// Created by Dmitri Hammernik on 08.05.17.
//

#include "GreeterImpl.h"

std::shared_ptr<Greeter> Greeter::create_greeter() {
    return std::make_shared<GreeterImpl>();
}

std::string GreeterImpl::welcomeFromCpp() {
    return "Hello from c++";
}
