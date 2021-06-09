/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:12:58 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 12:17:48 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_BASE_HPP_
#define EX02_BASE_HPP_

class   Base {
 public:
    Base();
    Base(Base const& src);
    virtual ~Base();
    Base&   operator=(Base const& right);

    Base*   generate(void);
    void    identify_from_pointer(Base* p);
    void    identify_from_reference(Base& p);
};

#endif  // EX02_BASE_HPP_
