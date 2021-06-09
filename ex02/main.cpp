/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:21:32 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 18:30:22 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void) {
    srand(time(NULL));
    switch (rand() % 3) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return (NULL);
}

void    identify_from_pointer(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown pointer" << std::endl;
}

void    identify_from_reference(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception& e) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception& e) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception& e) {
    }
    std::cout << "Unknown reference" << std::endl;
}

int main() {
    Base*   pbase = generate();

    std::cout << "Pointer  : ";
    identify_from_pointer(pbase);
    std::cout << "Reference: ";
    identify_from_reference(*pbase);
    delete pbase;
    return 0;
}
