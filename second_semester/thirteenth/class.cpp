#include <utility>

#include "class.hpp"

Class::Class(const std::string& s): wrapped(s) {}

Class::Class(Class&& c) {
        wrapped = std::move(c.wrapped);
    }

std::string& Class::get() {
    return wrapped;
}

void Class::set(const std::string& s) {
    wrapped.s = s;
}
