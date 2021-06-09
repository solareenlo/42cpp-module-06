/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:31:08 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 12:32:18 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "B.hpp"

B::B() {}
B::~B() {}

B::B(B const& src) {
    this->operator=(src);
}

B&  B::operator=(B const& right) {
    if (this != &right) {;}
    return (*this);
}
