#ifndef REFLECTPADDING_H
#define REFLECTPADDING_H

#include <vector>
#include <algorithm>

// reflect padding function
std::vector<double> reflectPad(const std::vector<double>& input, size_t targetSize) {
    std::vector<double> padded(targetSize);
    size_t inputSize = input.size();
    size_t padLeft = (targetSize - inputSize) / 2;
    size_t padRight = targetSize - inputSize - padLeft;

    // reflect on left
    for (size_t i = 0; i < padLeft; ++i) {
        padded[i] = input[padLeft - i - 1];
    }

    // copy original input
    std::copy(input.begin(), input.end(), padded.begin() + padLeft);

    // reflect on right
    for (size_t i = 0; i < padRight; ++i) {
        padded[inputSize + padLeft + i] = input[inputSize - i - 1];
    }

    return padded;
}

#endif // REFLECTPADDING_H
