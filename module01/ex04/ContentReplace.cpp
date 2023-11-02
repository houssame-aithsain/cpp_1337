/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContentReplace.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:06:09 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/24 20:20:37 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContentReplace.hpp"

void Content::SetFileContent(File &Sfile) {
    this->Cfile = &Sfile;
}

void Content::SaveNewContent(std::string FileName, std::string container) {

    std::string file = FileName + ".replace";
    std::ofstream outputFile(file);

    if (!outputFile) {
        std::cerr << "Error CREATING the file!" << std::endl;
        exit(EXIT_FAILURE);
    }
    outputFile << container;
    outputFile.close();
}

void Content::Replace(std::string FileName, std::string target, std::string rword) {

    std::string::size_type ps = 0;
    std::string buff = this->Cfile->GetBuffer();

    while ((ps = buff.find(target, ps)) != std::string::npos) {
        buff.erase(ps, target.length());
        buff.insert(ps, rword);
        ps += rword.length();
    }
    SaveNewContent(FileName, buff);
}
