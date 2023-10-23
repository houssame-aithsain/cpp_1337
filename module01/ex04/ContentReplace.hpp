/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContentReplace.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:06:13 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 23:22:16 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTENTREPLACE_HPP
#define CONTENTREPLACE_HPP

#include <iostream>
#include "FileExtract.hpp"

class Content{
    private:
        File* Cfile;
    public:
        void SetFileContent(File& Sfile);
        void Replace(std::string FileName, std::string word, std::string rword);
        void SaveNewContent(std::string FileName, std::string buff);
};

#endif /*CONTENTREPLACE_HPP*/