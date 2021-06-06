/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:00:47 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/07 02:12:13 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX00_SCALARCONVERSION_HPP_
#define EX00_SCALARCONVERSION_HPP_

#include <string>

class   ScalarConversion {
 public:
    explicit ScalarConversion(std::string const& str);
    ScalarConversion(ScalarConversion const& src);
    ~ScalarConversion();
    ScalarConversion&   operator=(ScalarConversion const& right);

    char    toChar();
    int     toInt();
    float   toFloat();
    double  toDboule();

 private:
    ScalarConversion();
    std::string const& str;
};

#endif  // EX00_SCALARCONVERSION_HPP_
