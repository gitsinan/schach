#pragma once
#include <exception>
#include <string>
class IllegalMoveException : public std::exception {
    private:
        std::string message;

    public:
        IllegalMoveException(const std::string& msg)
            : message(msg) {}

        const char* what() const noexcept override {
            return message.c_str();
        }
};