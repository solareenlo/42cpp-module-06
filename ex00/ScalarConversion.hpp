/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:00:47 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/08 06:09:15 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX00_SCALARCONVERSION_HPP_
#define EX00_SCALARCONVERSION_HPP_

#include <iostream>
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

    void    output();
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
    UniVal              val_;
    static const int    base_ = 10;
    std::string         getStr() const;
    int                 getBase() const;
    bool                getIsValidNum() const;
    bool                isValidNumber(std::string const& str);
    int                 detectType(std::string const& str);
};

#endif  // EX00_SCALARCONVERSION_HPP_
