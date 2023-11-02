/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileExtract.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:16:39 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 20:17:44 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileExtract.hpp"

void File::OpenFile( std::string FileName ){

    std::ifstream FileId(FileName);

    if (!FileId) {
        std::cerr << "Error OPENING the file!" << std::endl;
        std::exit(20);
    }
    this->ReadFromFile(FileId);
}

void File::ReadFromFile( std::ifstream& FileId ){

    std::string line;

    while (std::getline(FileId, line, '\0')){
        this->buffer += line;
    }
    FileId.close();
}

std::string File::GetBuffer( void ){

    return (this->buffer);
}