#include <iostream>
#include <vector>
#include <cmath>
#include "pre_emphasis.h"
#include "framing.h"
#include "hamming_window.h"
#include "fft.h"
#include "mel_filter.h"
#include "dct.h"

int main() {
    // generate dummy data
    int sampleRate = 25000;
    int duration = 1; // in seconds
    std::vector<double> samples(sampleRate * duration);
    double frequency = 240.0; 

    for (int i = 0; i < samples.size(); ++i) {
        samples[i] = std::sin(2.0 * M_PI * frequency * i / sampleRate);
    }

    // mfcc parameter
    double preEmphasisAlpha = 0.97;
    int frameSize = 625; // 25 ms per frame
    int frameShift = 250; // hop length (hop every 10 ms)
    int numFilters = 40; // number of mel filter
    int numCoeffs = 13;// number of mfcc standard for many speech processing
    double fmin = 80.0; //lowest frequency to be included
    double fmax = 7600.0; //set below the Nyquist frequency 

    // pre emphasis
    auto emphasizedSignal = preEmphasis(samples, preEmphasisAlpha);

    // framing
    auto frames = framing(emphasizedSignal, frameSize, frameShift);

    // windowing
    auto windowedFrames = hammingWindow(frames);

    // FFT
    auto fftFrames = computeFFT(windowedFrames);

    // mel filter bank
    auto melSpectrogram = melFilterBank(fftFrames, sampleRate, numFilters, fmin, fmax);

    // DCT
    auto mfccs = computeDCT(melSpectrogram, numCoeffs);

    // print mfcc
    for (const auto& mfcc : mfccs) {
        for (auto coeff : mfcc) {
            std::cout << coeff << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
