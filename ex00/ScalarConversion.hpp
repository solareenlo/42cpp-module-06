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

 private:
    ScalarConversion();
    std::string const   str_;
    static const int    base_ = 10;
    std::string         getStr() const;
    int                 getBase() const;

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
};

#endif  // EX00_SCALARCONVERSION_HPP_
