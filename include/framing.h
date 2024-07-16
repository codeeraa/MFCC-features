#ifndef FRAMING_H
#define FRAMING_H

#include <vector>

std::vector<std::vector<double>> framing(const std::vector<double>& signal, int frameSize, int frameShift) {
    int numFrames = (signal.size() - frameSize) / frameShift + 1;
    std::vector<std::vector<double>> frames(numFrames, std::vector<double>(frameSize));
    for (int i = 0; i < numFrames; ++i) {
        for (int j = 0; j < frameSize; ++j) {
            frames[i][j] = signal[i * frameShift + j];
        }
    }
    return frames;
}
#endif 
