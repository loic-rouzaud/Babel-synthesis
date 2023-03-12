#include <opus.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

#define SAMPLE_RATE 48000
#define CHANNELS 1
#define APPLICATION OPUS_APPLICATION_VOIP
#define BITRATE 64000
#define FRAME_SIZE 960
#define MAX_FRAME_SIZE 6 * 960

int main() {
    OpusEncoder* encoder;
    OpusDecoder* decoder;
    int error;
    encoder = opus_encoder_create(SAMPLE_RATE, CHANNELS, APPLICATION, &error);
    decoder = opus_decoder_create(SAMPLE_RATE, CHANNELS, &error);
    opus_encoder_ctl(encoder, OPUS_SET_BITRATE(BITRATE));
    opus_encoder_ctl(encoder, OPUS_SET_COMPLEXITY(10));
    opus_encoder_ctl(encoder, OPUS_SET_SIGNAL(OPUS_SIGNAL_VOICE));
    opus_encoder_ctl(encoder, OPUS_SET_PACKET_LOSS_PERC(0));
    opus_encoder_ctl(encoder, OPUS_SET_VBR(1));
    opus_encoder_ctl(encoder, OPUS_SET_VBR_CONSTRAINT(0));
    opus_encoder_ctl(encoder, OPUS_SET_FORCE_CHANNELS(OPUS_AUTO));
    opus_encoder_ctl(encoder, OPUS_SET_MAX_BANDWIDTH(OPUS_BANDWIDTH_FULLBAND));
    opus_encoder_ctl(encoder, OPUS_SET_INBAND_FEC(0));
    opus_encoder_ctl(encoder, OPUS_SET_DTX(0));
    opus_encoder_ctl(encoder, OPUS_SET_LSB_DEPTH(16));
    opus_encoder_ctl(encoder, OPUS_SET_EXPERT_FRAME_DURATION(OPUS_FRAMESIZE_20_MS));
    opus_encoder_ctl(encoder, OPUS_SET_PREDICTION_DISABLED(0));

    opus_decoder_ctl(decoder, OPUS_SET_BITRATE(BITRATE));
    opus_decoder_ctl(decoder, OPUS_SET_COMPLEXITY(10));
    opus_decoder_ctl(decoder, OPUS_SET_SIGNAL(OPUS_SIGNAL_VOICE));
    opus_decoder_ctl(decoder, OPUS_SET_PACKET_LOSS_PERC(0));
    opus_decoder_ctl(decoder, OPUS_SET_FORCE_CHANNELS(OPUS_AUTO));
    opus_decoder_ctl(decoder, OPUS_SET_MAX_BANDWIDTH(OPUS_BANDWIDTH_FULLBAND));
    opus_decoder_ctl(decoder, OPUS_SET_INBAND_FEC(0));
    opus_decoder_ctl(decoder, OPUS_SET_DTX(0));
    opus_decoder_ctl(decoder, OPUS_SET_LSB_DEPTH(16));

    std::ofstream outputFile("audio.opus", std::ios::out | std::ios::binary);
    if (!outputFile.is_open()) {
        std::cout << "Error: could not create output file." << std::endl;
        return -1;
    }

    std::cout << "Recording audio for 5 seconds..." << std::endl;
    std::vector<opus_int16> samples(SAMPLE_RATE * CHANNELS * 5);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "Encoding audio..." << std::endl;
    opus_int32 maxCompressedLength = opus_encoder_get_max_data_bytes(encoder, FRAME_SIZE);
    std::vector<unsigned char> compressed(maxCompressedLength);
    opus_int32 compressedLength = opus_encode(encoder, samples.data(), FRAME_SIZE, compressed.data(), maxCompressedLength);
     outputFile.write(reinterpret_cast<const char*>(compressed.data()), compressedLength);
    outputFile.close();

    std::cout << "Decoding audio..." << std::endl;
    std::ifstream inputFile("audio.opus", std::ios::in | std::ios::binary);
    if (!inputFile.is_open()) {
        std::cout << "Error: could not open input file." << std::endl;
        return -1;
    }
    inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);
    std::vector<unsigned char> encodedData(fileSize);
    inputFile.read(reinterpret_cast<char*>(encodedData.data()), fileSize);
    inputFile.close();

    opus_int16 decodedSamples[MAX_FRAME_SIZE];
    opus_int32 decodedLength = opus_decode(decoder, encodedData.data(), compressedLength, decodedSamples, MAX_FRAME_SIZE, 0);
    std::ofstream decodedFile("audio_decoded.pcm", std::ios::out | std::ios::binary);
    if (!decodedFile.is_open()) {
        std::cout << "Error: could not create decoded output file." << std::endl;
        return -1;
    }
    decodedFile.write(reinterpret_cast<const char*>(decodedSamples), decodedLength * sizeof(opus_int16));
    decodedFile.close();

    std::cout << "Playing back decoded audio..." << std::endl;
    // Add playback code here
    // You can use a library like PortAudio to play back the audio
    // Example code:
    /*
    PaError err;
    PaStream* stream;
    err = Pa_Initialize();
    if (err != paNoError) {
        std::cout << "Error initializing PortAudio." << std::endl;
        return -1;
    }
    err = Pa_OpenDefaultStream(&stream, 0, CHANNELS, paInt16, SAMPLE_RATE, paFramesPerBufferUnspecified, NULL, NULL);
    if (err != paNoError) {
        std::cout << "Error opening default stream." << std::endl;
        return -1;
    }
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        std::cout << "Error starting stream." << std::endl;
        return -1;
    }
    std::ifstream decodedInputFile("audio_decoded.pcm", std::ios::in | std::ios::binary);
    if (!decodedInputFile.is_open()) {
        std::cout << "Error: could not open decoded input file." << std::endl;
        return -1;
    }
    std::vector<opus_int16> decodedSamplesVector(decodedLength);
    decodedInputFile.read(reinterpret_cast<char*>(decodedSamplesVector.data()), decodedLength * sizeof(opus_int16));
    decodedInputFile.close();
    err = Pa_WriteStream(stream, decodedSamplesVector.data(), decodedLength);
    if (err != paNoError) {
        std::cout << "Error writing to stream." << std::endl;
        return -1;
    }
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        std::cout << "Error stopping stream." << std::endl;
        return -1;
    }
    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        std::cout << "Error closing stream." << std::endl;
        return -1;
    }
    Pa_Terminate();
    */

    opus_encoder_destroy(encoder);
    opus_decoder_destroy(decoder);

    return
}