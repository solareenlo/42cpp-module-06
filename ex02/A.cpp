/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:26:28 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 12:27:45 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "A.hpp"

A::A() {}
A::~A() {}

A::A(A const& src) {
    this->operator=(src);
}

A&  A::operator=(A const& right) {
    if (this != &right) {;}
    return (*this);
}
