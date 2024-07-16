#ifndef DCT_H
#define DCT_H

#include <vector>
#include <cmath>
#include <Eigen/Dense>

std::vector<std::vector<double>> computeDCT(const std::vector<std::vector<double>>& melSpectrogram, int numCoeffs) {
    int numFrames = melSpectrogram.size();
    int numFilters = melSpectrogram[0].size();
    Eigen::MatrixXd dctMatrix(numCoeffs, numFilters);

    std::vector<std::vector<double>> mfccs(numFrames, std::vector<double>(numCoeffs));
    for (int i = 0; i < numFrames; ++i) {
        Eigen::VectorXd melSpectrum = Eigen::VectorXd::Map(&melSpectrogram[i][0], numFilters);
        Eigen::VectorXd mfcc = dctMatrix * melSpectrum;
        for (int j = 0; j < numCoeffs; ++j) {
            mfccs[i][j] = mfcc[j];
        }
    }
    return mfccs;
}

#endif 
