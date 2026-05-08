#pragma once
#ifndef TRANSLATIONEXCEPTIONHEADER
#define TRANSLATIONEXCEPTIONHEADER
#endif
#include <exception>
#include <string>
class TranslationException : public std::exception {
    private:
        std::string message;

    public:
        TranslationException(const std::string& msg)
            : message(msg) {}

        const char* what() const noexcept override {
            return message.c_str();
        }
};