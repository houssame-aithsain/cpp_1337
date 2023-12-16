/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/13 15:14:08 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<stack>
#include<vector>

void print(std::stack<int> st) {

    if (st.empty())
        return;
    int x = st.top();
    st.pop();
    print(st);
    std::cout << x << std::endl;
    st.
}

int main() {

    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    print(st);
}
