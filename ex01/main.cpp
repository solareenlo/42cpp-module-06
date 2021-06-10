/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 06:59:56 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/10 18:03:30 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

static const char  ASCII[] = {
    ' ', '!', '"', '#', '$', '%', '&', '\'',
    '(', ')', '*', '+', ',', '-', '.', '/',
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', ':', ';', '<', '=', '>', '?',
    '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z', '{', '|', '}', '~'
};

static const size_t ASCII_SIZE = sizeof(ASCII) / sizeof(char);

struct  Data {
    std::string str1;
    int         n;
    std::string str2;
};

void*   serialize(void) {
    Data    *pdata = new Data();
    srand(time(NULL));

    for (size_t i = 0; i < 8; i++) {
        pdata->str1.push_back(ASCII[rand() % ASCII_SIZE]);
        pdata->str2.push_back(ASCII[rand() % ASCII_SIZE]);
    }
    pdata->n = rand() % RAND_MAX;
    return (pdata);
}

Data*   deserialize(void* raw) {
    Data*   pdata = reinterpret_cast<Data*>(raw);
    return (pdata);
}

int main() {
    void*   raw = serialize();
    Data*   pdata = deserialize(raw);

    std::cout << "str1: " << pdata->str1 << std::endl;
    std::cout << "n   : " << pdata->n << std::endl;
    std::cout << "str2: " << pdata->str2 << std::endl;
    return 0;
}
