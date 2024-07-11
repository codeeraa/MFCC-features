#ifndef HAMMING_WINDOW_H
#define HAMMING_WINDOW_H

#include <vector>
#include <cmath>

//windowing with hamming method
std::vector<double> hammingWindow(const std::vector<double>&frame) {
    std::vector<double> windowed_frame(frame.size());
    for (size_t i = 0; i < frame.size(); ++i) {
        windowed_frame[i] = frame[i] * (0.54 - 0.46 * std::cos(2 * M_PI * i / (frame.size() - 1)));
    }
    return windowed_frame;
}
#endif 
