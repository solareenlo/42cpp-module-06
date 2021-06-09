/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:17:58 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 12:21:11 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() {}
Base::~Base() {}

Base::Base(Base const& src) {
    this->operator=(src);
}

Base&   Base::operator=(Base const& right) {
    if (this != &right) {;}
    return (*this);
}
