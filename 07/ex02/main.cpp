/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:02:49 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/20 13:54:47 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	//------------------------MORE TESTS-----------------------------------------------
	std::cout << "--------------------MORE TEST-----------------------" << std::endl;
	int i;
	Array<std::string> words(5);
	Array<int> numberz[10];
	Array<int> nnnn[10];
	
	for (i = 0; i < 10; i++)
		numberz[i] = i;
	Array< Array<int> arrayarray[10];
	for (i = 0; i < 10; i++)
		arrayarray[i] = numberz;
	words[0] = "this ";
	words[1] = "is ";
	words[2] = "a ";
	words[3] = "string ";
	words[4] = "array";
	for (int j = 0; j < 5; j++)
		std::cout << words[j];
	std::cout << std::endl;
	try {
		words[5] = "out of range bruh";
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return 0;
}
