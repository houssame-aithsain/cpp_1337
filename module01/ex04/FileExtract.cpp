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
        std::cerr << "Error opening the file." << std::endl;
        std::exit(20);
    }
    this->ReadFromFile(FileId);
}

void File::ReadFromFile( std::ifstream& FileId ){

    std::string line;
    bool FirstLine = true;

    while (std::getline(FileId, line)){
        if (!FirstLine)
            this->buffer += '\n';
        else
            FirstLine = false;
        this->buffer += line;
    }
    FileId.close();
}

std::string File::GetBuffer( void ){

    return (this->buffer);
}