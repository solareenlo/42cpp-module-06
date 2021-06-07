/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:00:47 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/07 10:13:07 by tayamamo         ###   ########.fr       */
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
    static const int    base_ = 10;
    int                 type_;
    std::string         getStr() const;
    int                 getBase() const;
    bool                getIsValidNum() const;
    bool                isValidNumber(std::string const& str);
    int                 detectType(std::string const& str);
};

#endif  // EX00_SCALARCONVERSION_HPP_
