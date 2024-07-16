#ifndef PRE_EMPHASIS_H
#define PRE_EMPHASIS_H

#include <vector>

std::vector<double> preEmphasis(const std::vector<double>& signal, double alpha) {
    std::vector<double> emphasizedSignal(signal.size());
    emphasizedSignal[0] = signal[0];
    for (size_t i = 1; i < signal.size(); ++i) {
        emphasizedSignal[i] = signal[i] - alpha * signal[i - 1];
    }
    return emphasizedSignal;
}

#endif
