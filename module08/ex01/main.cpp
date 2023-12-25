/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:54:54 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/25 16:48:57 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void main3( void ) {

    try {
        std::vector<unsigned int> vec;

        srand(time(NULL));
        Span sp = Span(0);
        sp.addNumber(985);
        sp.addNumber(0);
        // sp.addNumber(366);
        for (unsigned int i = 0; i < 5; i++)
            vec.push_back(rand() % 1000);
        sp.addRange(vec.begin(), vec.end());
        sp.printVec(vec);
        // sp.printVec(vec);
        // std::cout << "shortest span is: " << sp.shortestSpan() << std::endl;
        // std::cout << "longest span is: " << sp.longestSpan() << std::endl;
    }
    catch(...) {
        std::cout << "error has been detected!" << std::endl;
    }
}

void main1( void )
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest span is: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span is: " << sp.longestSpan() << std::endl;
}

void main2( void ) {

    try {
        Span s(6);
        Span cpy;
        s.addNumber(1);
        s.addNumber(116);
        s.addNumber(12645);
        s.addNumber(1255);
        s.addNumber(2);
        s.addNumber(1202);
        std::cout << s.getNumb(0) << std::endl; 
        std::cout << s.getNumb(1) << std::endl;
        std::cout << s.getNumb(2) << std::endl;
        std::cout << s.getNumb(3) << std::endl;
        std::cout << s.getNumb(4) << std::endl;
        std::cout << s.getNumb(5) << std::endl;
        cpy = s;
        std::cout << "------------------------\n";
        std::cout << cpy.getNumb(0) << std::endl; 
        std::cout << cpy.getNumb(1) << std::endl;
        std::cout << cpy.getNumb(2) << std::endl;
        std::cout << cpy.getNumb(3) << std::endl;
        std::cout << cpy.getNumb(4) << std::endl;
        std::cout << cpy.getNumb(5) << std::endl;
        std::cout << "shortest span is: " << s.shortestSpan() << std::endl;
        std::cout << "longest span is: " << s.longestSpan() << std::endl;
        Span empty;
        empty.addNumber(44);
    }
    catch(const char* str) {
        std::cout << str << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "error has been detected!" << std::endl;
    }
}

int main( void ) {
    // main1();
    // main2();
    main3();
}