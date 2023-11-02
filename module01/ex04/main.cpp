/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/25 11:34:04 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileExtract.hpp"
#include "ContentReplace.hpp"

int main(int ac, char **av){

    File file;
    Content content;

    if (ac != 4){
        std::cout << "USAGE: sed fileName s1 s2" << std::endl;
        return (EXIT_FAILURE);
    }
    file.OpenFile(av[1]);
    content.SetFileContent(file);
    content.Replace(av[1], av[2], av[3]);
}
