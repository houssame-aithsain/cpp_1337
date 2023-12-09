/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:17:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/08 19:13:43 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void function(T value) {

    std::cout << value << std::endl;
}

int main() {

  int iarr[5] = {1, 2, 3, 4, 5};
  char sarr[3] = {'c', 'o', 'm'};
  double darr[6] = {1.2, 2.3, 3.5, 4.5, 5.6, 6.7};
  std::cout << "int:" << std::endl;
  iter(iarr, 5, function<int>);
  std::cout << "str:" << std::endl;
  iter(sarr, 3, function<char>);
  std::cout << "double:" << std::endl;
  iter(darr, 6, function<double>);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }

