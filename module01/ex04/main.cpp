/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 23:21:13 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileExtract.hpp"
#include "ContentReplace.hpp"

int main(int ac, char **av){

    File file;
    Content content;
    if (ac != 4){
        std::cout << "USAGE: name file s1 s2" << std::endl;
        return (1);
    }
    file.OpenFile(av[1]);
    content.SetFileContent(file);
    content.Replace(av[1], av[2], av[3]);
}
