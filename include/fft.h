#ifndef FFT_H
#define FFT_H

#include <vector>
#include <complex>
#include <fftw3.h>
#include <algorithm>

// compute fft function
std::vector<std::vector<std::complex<double>>> computeFFT(const std::vector<std::vector<double>>& frames, size_t targetSize) {
    int frameSize = frames[0].size();
    std::vector<std::vector<std::complex<double>>> fftFrames(frames.size(), std::vector<std::complex<double>>(targetSize / 2 + 1));
    
    // fftw3 plan
    fftw_plan plan = fftw_plan_dft_r2c_1d(targetSize, nullptr, nullptr, FFTW_ESTIMATE);

    std::vector<double> input(targetSize);
    std::vector<std::complex<double>> output(targetSize / 2 + 1);

    for (size_t i = 0; i < frames.size(); ++i) {
        // reflect pad the current frame
        std::vector<double> paddedFrame = reflectPad(frames[i], targetSize);
        
        // perform fft
        fftw_execute_dft_r2c(plan, paddedFrame.data(), reinterpret_cast<fftw_complex*>(output.data()));
        std::copy(output.begin(), output.end(), fftFrames[i].begin());
    }
    
    fftw_destroy_plan(plan);
    return fftFrames;
}

#endif // FFT_H
