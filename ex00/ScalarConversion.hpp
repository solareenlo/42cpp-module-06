/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:00:47 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 03:12:27 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX00_SCALARCONVERSION_HPP_
#define EX00_SCALARCONVERSION_HPP_

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cerrno>

enum : int {
  kChar,
  kInt,
  kFloat,
  kDouble,
};

union   UniVal  {
    char    c_;
    int     i_;
    float   f_;
    double  d_;
};

class   ScalarConversion {
 public:
    explicit ScalarConversion(std::string const& str);
    ScalarConversion(ScalarConversion const& src);
    ~ScalarConversion();
    ScalarConversion&   operator=(ScalarConversion const& right);

    void    asChar();
    void    asInt();
    void    asFloat();
    void    asDboule();

    class   SCException : public std::exception {
     public:
        explicit SCException(std::string msg);
        SCException(SCException const& src);
        ~SCException() throw();
        SCException&    operator=(SCException const& right);
        char const* what() const throw();

     private:
        SCException();
        std::string message_;
        std::string getMessage() const;
    };

 private:
    ScalarConversion();
    bool                is_valid_num_;
    std::string const   str_;
    int                 type_;
    union UniVal        val_;
    int                 precision_;
    static const int    base_ = 10;
    int                 getBase() const;
    std::string         getStr() const;
    int                 getType() const;
    int                 getPrecision() const;
    void                setPrecision(std::string const& str);
    bool                isValidNumber(std::string const& str);
    int                 detectType(std::string const& str);
};

#endif  // EX00_SCALARCONVERSION_HPP_
