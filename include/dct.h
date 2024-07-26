#ifndef DCT_H
#define DCT_H

#include <vector>
#include <cmath>
#define M_PI 3.14159265358979323846

std::vector<std::vector<double>> applyDCT(const std::vector<std::vector<double>>& melSpectrogram, int n_mfcc, int dct_type) {
    int numFrames = melSpectrogram.size();
    int numMelFilters = melSpectrogram[0].size();
    
    std::vector<std::vector<double>> dctCoefficients(numFrames, std::vector<double>(n_mfcc, 0.0));
    double factor = (dct_type == 2) ? 2.0 : 1.0;
    
    for (int i = 0; i < numFrames; ++i) {
        for (int k = 0; k < n_mfcc; ++k) {
            double sum = 0.0;
            for (int n = 0; n < numMelFilters; ++n) {
                sum += melSpectrogram[i][n] * std::cos(M_PI / numMelFilters * (n + 0.5) * k);
            }
            dctCoefficients[i][k] = factor * sum;
        }
    }
    
    return dctCoefficients;
}

#endif // DCT_H
