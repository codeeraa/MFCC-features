#ifndef HAMMING_WINDOW_H
#define HAMMING_WINDOW_H

#include <vector>
#include <cmath>

#define M_PI           3.14159265358979323846  /* pi */

// function to apply hamming window to frames
std::vector<std::vector<double>> hammingWindow(const std::vector<std::vector<double>>& frames) {
    int frameSize = frames[0].size();
    std::vector<double> window(frameSize);

    // window coefficients
    double alpha = 0.54;
    double beta = 1.0 - alpha;
    double normalizationFactor = 2 * M_PI / (frameSize - 1);
    for (int i = 0; i < frameSize; ++i) {
        window[i] = alpha - beta * cos(i * normalizationFactor);
    }

    // apply the Hamming window to each frame
    std::vector<std::vector<double>> windowedFrames(frames.size(), std::vector<double>(frameSize));
    for (size_t i = 0; i < frames.size(); ++i) {
        for (int j = 0; j < frameSize; ++j) {
            windowedFrames[i][j] = frames[i][j] * window[j];
        }
    }

    return windowedFrames;
}

#endif // HAMMING_WINDOW_H
