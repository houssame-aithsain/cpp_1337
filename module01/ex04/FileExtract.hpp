/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileExtract.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:15 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 20:19:04 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEEXTRACT_HPP
#define FILEEXTRACT_HPP

#include <iostream>
#include <fstream>
#include <string>

class File{
    private:
        std::string buffer;
        void ReadFromFile(std::ifstream& FileId);
    public:
        void OpenFile( std::string FileName );
        std::string GetBuffer( void );
};

#endif /*FILEEXTRACT_HPP*/