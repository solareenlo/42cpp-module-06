/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:00:00 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 14:07:41 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ScalarConversion.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 2) {
        std::cout << "Usage: " << std::endl;
        std::cout << argv[0] << " \"string\"" << std::endl;
        return (EXIT_FAILURE);
    }
    return (0);
}