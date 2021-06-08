/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:00:00 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/09 02:44:39 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cfloat>
#include "ScalarConversion.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 2) {
        std::cout << "Usage: " << std::endl;
        std::cout << argv[0] << " \"string\"" << std::endl;
        return (EXIT_FAILURE);
    }

    try {
        ScalarConversion    scalar(argv[1]);
        scalar.asChar();
        scalar.asInt();
        scalar.asFloat();
        scalar.asDboule();
    }
    catch (ScalarConversion::SCException& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
