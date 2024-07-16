#ifndef FFT_H
#define FFT_H

#include <vector>
#include <complex>
#include <fftw3.h>

std::vector<std::vector<std::complex<double>>> computeFFT(const std::vector<std::vector<double>>& frames) {
    int frameSize = frames[0].size();
    std::vector<std::vector<std::complex<double>>> fftFrames(frames.size(), std::vector<std::complex<double>>(frameSize));
    fftw_plan plan = fftw_plan_dft_r2c_1d(frameSize, nullptr, nullptr, FFTW_ESTIMATE);
    std::vector<double> input(frameSize);
    std::vector<std::complex<double>> output(frameSize);

    for (size_t i = 0; i < frames.size(); ++i) {
        std::copy(frames[i].begin(), frames[i].end(), input.begin());
        fftw_execute_dft_r2c(plan, input.data(), reinterpret_cast<fftw_complex*>(output.data()));
        std::copy(output.begin(), output.end(), fftFrames[i].begin());
    }
    fftw_destroy_plan(plan);
    return fftFrames;
}

#endif 
