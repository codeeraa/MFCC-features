#ifndef PRE_EMPHASIS_H
#define PRE_EMPHASIS_H

#include <vector>

// pre-emphasis step
std::vector<double> preEmphasis(const std::vector<double>& signal, double alpha = 0.97) {
    std::vector<double> emphasized_signal(signal.size());
    emphasized_signal[0] = signal[0];  
    for (size_t i = 1; i < signal.size(); ++i) {
        emphasized_signal[i] = signal[i] - alpha * signal[i - 1];
    }
    return emphasized_signal;
}

#endif 
