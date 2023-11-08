#pragma once

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";
const std::string CORRECT_OUTPUT_FILE_NAME = "correct_output.txt";

// Function to open input and output files
std::pair<std::ifstream, std::ofstream> openFiles() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream infile(INPUT_FILE_NAME);
    std::ofstream outfile(OUTPUT_FILE_NAME);

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Could not open the files." << std::endl;
        exit(1);
    }

    return {std::move(infile), std::move(outfile)};
}

// Function to compare the contents of two files
bool compareFiles() {
    std::ifstream f1(OUTPUT_FILE_NAME, std::ifstream::binary|std::ifstream::ate);
    std::ifstream f2(CORRECT_OUTPUT_FILE_NAME, std::ifstream::binary|std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        return false; // File problem
    }

    if (f1.tellg() != f2.tellg()) {
        return false; // Size mismatch
    }

    // Seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

// Function to print the result of file comparison
void printComparison() {
    if (compareFiles()) {
        std::cout << "[Success] The code generated the CORRECT output." << std::endl;
    } else {
        std::cout << "[Fail] The code generated the WRONG output." << std::endl;
    }
}

// Function to write output results to a file
template <typename T>
void writeOutput(std::ofstream& outfile, const std::vector<T>& results) {
    for (const auto& result : results) {
        outfile << result << '\n';
    }
}

// Function to read input from a file
template <typename T>
std::vector<T> readInput(std::ifstream& infile) {
    std::vector<T> inputs;
    T input;
    while (infile >> input) {
        inputs.push_back(input);
    }
    return inputs;
}
