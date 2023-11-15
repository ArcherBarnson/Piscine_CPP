/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:00:03 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:00:04 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data test;
    test.a = 0;
    test.b = INT_MIN;
    test.c = INT_MAX;
    Data *testptr = &test;
    uintptr_t serializedPtr;
    std::cout << "data testptr addr = " << testptr << std::endl;
    serializedPtr = Serializer::serialize(testptr);
    std::cout << "testptr serialized value = " << serializedPtr << std::endl;
    testptr = NULL;
    testptr = Serializer::deserialize(serializedPtr);
    std::cout << "deserialized ptr (back to original) addr = " << testptr << std::endl;
    return 0;
}
