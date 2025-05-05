#pragma once

#include <string>

class Class{
public:
    Class(const std::string&);

    Class(Class&&);

    std::string& get();

    void set(const std::string&);

private:
    std::string wrapped;
};
