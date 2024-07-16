#ifndef HAMMING_WINDOW_H
#define HAMMING_WINDOW_H

#include <vector>
#include <cmath>

std::vector<std::vector<double>> hammingWindow(const std::vector<std::vector<double>>& frames) {
    int frameSize = frames[0].size();
    std::vector<double> window(frameSize);
    for (int i = 0; i < frameSize; ++i) {
        window[i] = 0.54 - 0.46 * cos(2 * M_PI * i / (frameSize - 1));
    }
    std::vector<std::vector<double>> windowedFrames(frames.size(), std::vector<double>(frameSize));
    for (size_t i = 0; i < frames.size(); ++i) {
        for (int j = 0; j < frameSize; ++j) {
            windowedFrames[i][j] = frames[i][j] * window[j];
        }
    }
    return windowedFrames;
}

#endif 
