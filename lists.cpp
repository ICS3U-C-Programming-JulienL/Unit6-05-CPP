// Copyright (c) 2023 Julien Lamoureux All rights reserved.

// Created By: Julien Lamoureux
// Date: December 20, 2023
// # This program display the average of the user's marks

#include <cstdlib>
#include <iostream>
#include <random>
#include <list>
#include <stack>

float CalcAverage(std::list <float> listOfInt) {
    // initialize the sum
    float sum = 0;

    // use a for loop when aNum is in listOfInt
    for (float aNum : listOfInt) {
        // set sum to marks aNum + sum
        sum += aNum;
    }
    // calculate average
    float average = sum / listOfInt.size();

    // return average
    return average;
}

int main() {
    // declare variables
    std::string userNum;
    float userNumFloat, average;
    int counter;

    // declare constants
    const int MAX = 100;
    const int MIN = 0;

    // declare marksList
    std::list <float> marksList;

    // tell the user what the program does
    std::cout << "This program display the average of the following marks :"
              << std::endl;

    // use a do while loop when user_mark is not -1
    do {
        // get userNum
        std::cout << "Enter your mark (press -1 to exit):";
        std::cin >> userNum;

        try {
            // convert userNum to float
            userNumFloat = std::stof(userNum);

            if (userNumFloat > 100 || userNumFloat < -1) {
                std::cout << "This mark is not between 1 and 100" << std::endl;
                marksList.pop_back();
            }
            // append marksArray to the random number
            marksList.push_back(userNumFloat);
        } catch (std::invalid_argument) {
            // if userNum can't be converted, tell them to enter a valid number
            std::cout << userNum << " is not a valid number." << std::endl;
        }
    } while (userNumFloat != -1);

    // eliminate the last element in marksList
    marksList.pop_back();

    // call the CalcAverage function
    average = CalcAverage(marksList);

    // display the average
    std::cout
    << "The average of the above random marks is "
    << average << "%" << std::endl;
}
