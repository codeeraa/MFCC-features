#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "hamming_window.h"
#include "pre_emphasis.h"


//using the sndfile library to generate vector data of audiofile
std::vector<double> readAudioFile(const std::string& filename, int& sample_rate) {
    SF_INFO sf_info;
    SNDFILE* sndfile = sf_open(filename.c_str(), SFM_READ, &sf_info);
    if (!sndfile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    sample_rate = sf_info.samplerate;
    std::vector<double> audio_data(sf_info.frames * sf_info.channels);
    sf_readf_double(sndfile, audio_data.data(), sf_info.frames);
    sf_close(sndfile);

    return audio_data;
}

// windowing step using hamming window formula
std::vector<std::vector<double>> frameSignal(const std::vector<double>& signal, int frame_length, int frame_step) {
    std::vector<std::vector<double>> frames;
    int num_frames = 1 + (signal.size() - frame_length) / frame_step;
    for (int i = 0; i < num_frames; ++i) {
        std::vector<double> frame(signal.begin() + i * frame_step, signal.begin() + i * frame_step + frame_length);
        frames.push_back(applyHammingWindow(frame));  // applying hamming window to each frame
    }
    return frames;
}

int main() {
    int sample_rate;
    //load audio file
    std::string filename = "audio_file.wav";
    std::vector<double> audio_signal = readAudioFile(filename, sample_rate);

    if (audio_signal.empty()) {
        std::cerr << "Failed to read audio data" << std::endl;
        return 1;
    }

    // pre-emphasis
    std::vector<double> emphasized_signal = preEmphasis(audio_signal);

    // framing
    int frame_length = 625; // 25 ms
    int frame_step = 250; // 10 ms hop size for overlap

    auto frames = frameSignal(emphasized_signal, frame_length, frame_step);

    for (const auto& frame : frames) {
        for (double sample : frame) {
            std::cout << sample << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
