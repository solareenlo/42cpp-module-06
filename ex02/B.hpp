/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:29:30 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 12:41:11 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_B_HPP_
#define EX02_B_HPP_

#include "Base.hpp"

class   B : public Base {
 public:
    B();
    B(B const& src);
    ~B();
    B&  operator=(B const& right);
};

#endif  // EX02_B_HPP_
