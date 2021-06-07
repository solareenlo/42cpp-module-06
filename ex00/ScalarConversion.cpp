/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:30 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/07 14:14:14 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion()
    : is_valid_num_(false), str_(""), type_(0) {}

ScalarConversion::ScalarConversion(std::string const& str) : str_(str) {
    this->is_valid_num_ = this->isValidNumber(str);
    if (!this->is_valid_num_) {
        throw ScalarConversion::SCException
            ("Error: non displayable characters can't be passed");
    }
}

ScalarConversion::~ScalarConversion() {}

ScalarConversion::ScalarConversion(ScalarConversion const& src) {
    this->operator=(src);
}

ScalarConversion&
ScalarConversion::operator=(ScalarConversion const& right) {
    if (this != &right) {
        this->is_valid_num_ = right.is_valid_num_;
    }
    return (*this);
}

bool    ScalarConversion::isValidNumber(std::string const& str) {
    bool    flag = true;
    char    *endptr;
    errno = 0;
    double d = std::strtod(str.c_str(), &endptr);
    (void)d;
    if (errno)
        flag = false;
    if (*endptr && !(*endptr == 'f' && *(endptr + 1) == '\0'))
        flag = false;
    return (flag);
}

int ScalarConversion::detectType(std::string const& str) {
    if (!str.compare("-inff"))
        this->type_ = kFloat;
    return (0);
}

void    ScalarConversion::output() {
}

void    ScalarConversion::asChar() {
    std::cout << "char: ";
    try {
        if (!this->getIsValidNum())
            throw ScalarConversion::SCException("impossible");
        int i = std::atoi(this->str_.c_str());
        if (i < 32 || 126 < i)
            throw ScalarConversion::SCException("Non displayable");
        std::cout << "'" << (static_cast<char>(std::atoi(this->str_.c_str())))
            << "'" << std::endl;
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
}

void    ScalarConversion::asInt() {
    std::cout << "int: ";
    try {
        char    *endptr;
        errno = 0;
        int64_t l = std::strtol(this->str_.c_str(), &endptr, this->getBase());
        if (!this->getIsValidNum() || errno
                || l > std::numeric_limits<int>::max()
                || l < std::numeric_limits<int>::min()) {
            throw ScalarConversion::SCException("impossible");
        }
        std::cout << static_cast<int>(l) << std::endl;
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
}

void    ScalarConversion::asFloat() {
    std::cout << "float: ";
    try {
        char    *endptr;
        errno = 0;
        float f = std::strtol(this->str_.c_str(), &endptr, this->getBase());
        if (errno || !this->getIsValidNum()) {
            throw ScalarConversion::SCException("impossible");
            throw ScalarConversion::SCException("impossible");
        }
        std::cout << static_cast<float>(f) << std::endl;
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
}

void    ScalarConversion::asDboule() {
    std::cout << "double: ";
    try {
        char    *endptr;
        errno = 0;
        double  d = std::strtod(this->str_.c_str(), &endptr);
        if (errno || !this->getIsValidNum()) {
            throw ScalarConversion::SCException("impossible");
        }
        std::cout << d << std::endl;
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
}

std::string ScalarConversion::getStr() const { return (this->str_); }
int         ScalarConversion::getBase() const { return (this->base_); }

bool    ScalarConversion::getIsValidNum() const {
    return (this->is_valid_num_);
}

ScalarConversion::SCException::SCException()
    : std::exception(), message_("error") {}

ScalarConversion::SCException::SCException(std::string msg)
    : std::exception(), message_(msg) {}

ScalarConversion::SCException::SCException(SCException const& src) {
    this->operator=(src);
}

ScalarConversion::SCException&
ScalarConversion::SCException::operator
=(ScalarConversion::SCException const& right) {
    if (this != &right)
        this->message_ = right.getMessage();
    return (*this);
}

ScalarConversion::SCException::~SCException() throw() {}

char const* ScalarConversion::SCException::what() const throw() {
    return (this->message_.c_str());
}

std::string ScalarConversion::SCException::getMessage() const {
    return (this->message_);
}
