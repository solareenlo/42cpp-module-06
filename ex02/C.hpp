/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:32:50 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 12:34:01 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_C_HPP_
#define EX02_C_HPP_

#include "Base.hpp"

class   C : public Base {
    C();
    C(C const& src);
    ~C();
    C&  operator=(C const& right);
};

#endif  // EX02_C_HPP_
