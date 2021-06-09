/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:34:08 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 12:35:14 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "C.hpp"

C::C() {}
C::~C() {}

C::C(C const& src) {
    this->operator=(src);
}

C&  C::operator=(C const& right) {
    if (this != &right) {;}
    return (*this);
}
