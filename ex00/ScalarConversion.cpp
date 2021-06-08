/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:30 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 04:24:53 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion()
    : is_valid_num_(false), str_("0"), type_(kChar), precision_(1) {
        this->val_.c_ = '\0';
}

ScalarConversion::ScalarConversion(std::string const& str)
    : str_(str), precision_(1) {
    this->is_valid_num_ = this->isValidNumber(str);
    if (!this->is_valid_num_) {
        throw ScalarConversion::SCException
            ("Error: non displayable characters can't be passed");
    }
    this->type_ = this->detectType(str);
    if (this->type_ == kChar) {
        this->val_.c_ = std::atoi(this->str_.c_str());
    } else if (this->type_ == kInt) {
        this->val_.i_ = std::atoi(str.c_str());
    } else if (this->type_ == kFloat) {
        char    *endptr;
        errno = 0;
        this->val_.f_ = std::strtof(str.c_str(), &endptr);
        if (errno)
            throw ScalarConversion::SCException("Error: out of range (float)");
        this->setPrecision(str);
    } else if (this->type_ == kDouble) {
        char    *endptr;
        errno = 0;
        this->val_.d_ = std::strtod(str.c_str(), &endptr);
        if (errno)
            throw ScalarConversion::SCException("Error: out of range (double)");
        this->setPrecision(str);
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
        throw ScalarConversion::SCException("Error: out of range (double)");
    if (*endptr && !(*endptr == 'f' && *(endptr + 1) == '\0'))
        flag = false;
    if (*endptr && str.size() == 1)
        flag = false;
    return (flag);
}

int ScalarConversion::detectType(std::string const& str) {
    if (!str.compare("-inff") || !str.compare("+inff")
            || !str.compare("inff") || !str.compare("nanf")
            || !str.compare("+nanf") || !str.compare("-nanf"))
        return (kFloat);

    if (!str.compare("-inf") || !str.compare("+inf")
            || !str.compare("inf") || !str.compare("nan")
            || !str.compare("+nan") || !str.compare("-nan"))
        return (kDouble);

    char    *endptr;
    errno = 0;
    double d = std::strtod(str.c_str(), &endptr);
    if (errno)
        throw ScalarConversion::SCException("Error: fatal");
    if (*endptr == 'f')
        return (kFloat);

    if (d > std::numeric_limits<int>::max()
            || d < std::numeric_limits<int>::min())
        return (kDouble);

    int i = std::strtol(str.c_str(), &endptr, this->base_);
    errno = 0;
    if (errno)
        throw ScalarConversion::SCException("Error: fatal");
    if (*endptr == '.' || *endptr == 'e')
        return (kDouble);

    if (i > std::numeric_limits<char>::max()
            || i < std::numeric_limits<char>::min())
        return (kInt);
    return (kChar);
}

void    ScalarConversion::asChar() {
    std::cout << "char: ";
    try {
        int type = this->getType();
        if (type == kChar) {
            if (this->val_.c_ < 32 || 126 < this->val_.c_)
                throw ScalarConversion::SCException("Non displayable");
            std::cout << "'" << this->val_.c_ << "'" << std::endl;
        } else if (type == kInt) {
            if (this->val_.i_ > std::numeric_limits<char>::max()
                    || this->val_.i_ < std::numeric_limits<char>::min())
                throw ScalarConversion::SCException("impossible");
            if (this->val_.i_ < 32 || 126 < this->val_.i_)
                throw ScalarConversion::SCException("Non displayable");
            std::cout << "'" << static_cast<char>(this->val_.i_) << "'"
                << std::endl;
        } else if (type == kFloat) {
            if (this->str_ == "nanf" || this->str_ == "+nanf"
                    || this->str_ == "-nanf")
                throw ScalarConversion::SCException("impossible");
            if (this->val_.f_ > std::numeric_limits<char>::max()
                    || this->val_.f_ < std::numeric_limits<char>::min())
                throw ScalarConversion::SCException("impossible");
            if (this->val_.f_ < 32 || 126 < this->val_.f_)
                throw ScalarConversion::SCException("Non displayable");
            std::cout << "'" << static_cast<char>(this->val_.f_) << "'"
                << std::endl;
        } else if (type == kDouble) {
            if (this->str_ == "nan" || this->str_ == "+nan"
                    || this->str_ == "-nan")
                throw ScalarConversion::SCException("impossible");
            if (this->val_.d_ > std::numeric_limits<char>::max()
                    || this->val_.d_ < std::numeric_limits<char>::min())
                throw ScalarConversion::SCException("impossible");
            if (this->val_.d_ < 32 || 126 < this->val_.d_)
                throw ScalarConversion::SCException("Non displayable");
            std::cout << "'" << static_cast<char>(this->val_.d_) << "'"
                << std::endl;
        }
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
}

void    ScalarConversion::asInt() {
    std::cout << "int: ";
    try {
        int type = this->getType();
        if (type == kChar) {
            std::cout << static_cast<int>(this->val_.c_) << std::endl;
        } else if (type == kInt) {
            std::cout << this->val_.i_ << std::endl;
        } else if (type == kFloat) {
            if (this->str_ == "nanf" || this->str_ == "+nanf"
                    || this->str_ == "-nanf")
                throw ScalarConversion::SCException("impossible");
            if (this->val_.f_ > (1 << 24) - 1)
                throw ScalarConversion::SCException("impossible");
            if (this->val_.f_ < -(1 << 24) + 1)
                throw ScalarConversion::SCException("impossible");
            std::cout << static_cast<int>(this->val_.f_) << std::endl;
        } else if (type == kDouble) {
            if (this->str_ == "nan" || this->str_ == "+nan"
                    || this->str_ == "-nan")
                throw ScalarConversion::SCException("impossible");
            if (this->val_.d_ > std::numeric_limits<int>::max())
                throw ScalarConversion::SCException("impossible");
            if (this->val_.d_ < std::numeric_limits<int>::min())
                throw ScalarConversion::SCException("impossible");
            std::cout << static_cast<int>(this->val_.d_) << std::endl;
        }
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
}

void    ScalarConversion::asFloat() {
    std::cout << std::fixed << std::setprecision(this->getPrecision());
    std::cout << "float: ";
    try {
        int type = this->getType();
        if (type == kChar) {
            std::cout << static_cast<float>(this->val_.c_) << "f" << std::endl;
        } else if (type == kInt) {
            if (this->val_.i_ > (1 << 24) - 1)
                throw ScalarConversion::SCException("impossible");
            if (this->val_.i_ < -(1 << 24) + 1)
                throw ScalarConversion::SCException("impossible");
            std::cout << static_cast<float>(this->val_.i_) << "f" << std::endl;
        } else if (type == kFloat) {
            std::cout << this->val_.f_ << "f" << std::endl;
        } else if (type == kDouble) {
            if (this->val_.d_ > std::numeric_limits<float>::max())
                throw ScalarConversion::SCException("impossible");
            if (this->val_.d_ < -std::numeric_limits<float>::max())
                throw ScalarConversion::SCException("impossible");
            if (this->val_.d_ != 0.0) {
                if (this->val_.d_ < std::numeric_limits<float>::min()
                        && this->val_.d_ > -std::numeric_limits<float>::min())
                    throw ScalarConversion::SCException("impossible");
            }
            std::cout << static_cast<float>(this->val_.d_) << "f" << std::endl;
        }
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::defaultfloat;
}

void    ScalarConversion::asDboule() {
    std::cout << std::fixed << std::setprecision(this->getPrecision());
    std::cout << "double: ";
    try {
        int type = this->getType();
        if (type == kChar) {
            std::cout << static_cast<double>(this->val_.c_) << std::endl;
        } else if (type == kInt) {
            std::cout << static_cast<double>(this->val_.i_) << std::endl;
        } else if (type == kFloat) {
            std::cout << static_cast<double>(this->val_.f_) << std::endl;
        } else if (type == kDouble) {
            std::cout << this->val_.d_ << std::endl;
        }
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::defaultfloat;
}

int         ScalarConversion::getBase() const { return (this->base_); }
std::string ScalarConversion::getStr() const { return (this->str_); }
int         ScalarConversion::getType() const { return (this->type_); }
int         ScalarConversion::getPrecision() const {
    return (this->precision_);
}

void    ScalarConversion::setPrecision(std::string const& str) {
    std::string::size_type pos_dot = str.find(".");
    if (pos_dot == std::string::npos)
        return;
    std::string::size_type pos_e = str.find("e", pos_dot + 1);
    std::string::size_type pos_f = str.find("f", pos_e + 1);
    if (pos_dot == str.size() - 1)
        return;
    if (pos_f != std::string::npos)
        if (pos_dot == str.size() - 2)
            return;
    if (pos_e == std::string::npos) {
        if (pos_f == std::string::npos)
            this->precision_ = str.size() - pos_dot - 1;
        else
            this->precision_ = str.size() - pos_dot - 2;
    } else {
        this->precision_ = pos_e - pos_dot;
        std::string tmp = str.substr(pos_e + 1, str.size() - pos_e);
        if (pos_f == std::string::npos)
            tmp = str.substr(pos_e + 1, str.size() - 1 - pos_e);
        int i = std::atoi(tmp.c_str());
        if (i < 0) {
            this->precision_ += std::abs(i) - 1;
        } else {
            this->precision_ -= std::abs(i) + 1;
            if (this->precision_ < 1)
                this->precision_ = 1;
        }
    }
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
