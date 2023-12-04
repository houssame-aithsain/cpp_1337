/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:46 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/03 17:56:54 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverte.hpp"
#include <unistd.h>

ScalarConverte::~ScalarConverte( void ) {}

ScalarConverte::ScalarConverte( void ) {}

ScalarConverte::ScalarConverte(const ScalarConverte & other ) {

	*this = other;
}

ScalarConverte& ScalarConverte::operator=(const ScalarConverte & other) {

	(void)other;
	return (*this);
}

void ScalarConverte::charConverter(double dsNotation, char c) {

	if ((std::isprint(dsNotation) && !std::fmod(dsNotation, 1.0)) || (!dsNotation && c)) {
		if (dsNotation)
			std::cout << "'" << static_cast<char>(dsNotation) << "'" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}
	else if (!std::fmod(dsNotation, 1.0))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "imposible" << std::endl;
}

void ScalarConverte::convert(std::string value) {

	ScalarConverte s;
	char *endPtr;

	std::cout << "char: ";
	std::strtod(value.c_str(), &endPtr);
	if ((endPtr[0] && !endPtr[1] && !std::strcmp(value.c_str(), endPtr)) || !endPtr[0])
		s.charConverter(std::strtod(value.c_str(), &endPtr), endPtr[0]);
	else
		std::cout << "imposible" << std::endl;
	if (!std::strcmp(value.c_str(), endPtr) && endPtr[0] && !endPtr[1]) {
		std::cout << "int: " << static_cast<int>(endPtr[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(endPtr[0]) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(endPtr[0]) << std::endl;
	}
	else if (endPtr[0] && std::strcmp(endPtr, "f")) {
		std::cout << "int: " << "imposible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else {
		std::cout << "int: ";
		long intMaxMin = std::strtod(value.c_str(), &endPtr);
		if (intMaxMin > INT_MAX || intMaxMin < INT_MIN)
			std::cout << "imposible" << std::endl;
		else
			std::cout << static_cast<int>(std::strtod(value.c_str(), &endPtr)) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(std::strtod(value.c_str(), &endPtr)) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(std::strtod(value.c_str(), &endPtr)) << std::endl;
	}
}
