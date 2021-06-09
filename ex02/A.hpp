/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:24:47 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 12:41:02 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_A_HPP_
#define EX02_A_HPP_

#include "Base.hpp"

class   A : public Base {
 public:
    A();
    A(A const& src);
    ~A();
    A&  operator=(A const& right);
};

#endif  // EX02_A_HPP_
