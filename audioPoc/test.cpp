#include <opus/opus.h>
#include <iostream>
#include <cstring> // add this line to include cstring header

#define SAMPLE_RATE 48000
#define CHANNELS 2
#define FRAME_SIZE_MS 20
#define FRAME_SIZE (SAMPLE_RATE / 1000 * FRAME_SIZE_MS)
#define BITRATE 64000

int main() {
    OpusEncoder *encoder;
    OpusDecoder *decoder;
    int error;

    encoder = opus_encoder_create(SAMPLE_RATE, CHANNELS, OPUS_APPLICATION_AUDIO, &error);
    if (error != OPUS_OK) {
        std::cerr << "Error initializing encoder: " << opus_strerror(error) << std::endl;
        return 1;
    }
    opus_encoder_ctl(encoder, OPUS_SET_BITRATE(BITRATE));
    decoder = opus_decoder_create(SAMPLE_RATE, CHANNELS, &error);
    if (error != OPUS_OK) {
        std::cerr << "Error initializing decoder: " << opus_strerror(error) << std::endl;
        return 1;
    }

    std::cout << "Recording..." << std::endl;
    short buffer[CHANNELS * FRAME_SIZE];
    std::memset(buffer, 0, sizeof(buffer));

    unsigned char compressed[1024];
    int compressed_size = opus_encode(encoder, buffer, FRAME_SIZE, compressed, sizeof(compressed));
    if (compressed_size < 0) {
        std::cerr << "Error compressing audio: " << opus_strerror(compressed_size) << std::endl;
        return 1;
    }

    short decompressed[CHANNELS * FRAME_SIZE];
    int decompressed_size = opus_decode(decoder, compressed, compressed_size, decompressed, FRAME_SIZE, 0);
    if (decompressed_size < 0) {
        std::cerr << "Error decompressing audio: " << opus_strerror(decompressed_size) << std::endl;
        return 1;
    }

    std::cout << "Playing back..." << std::endl;
    for (int i = 0; i < CHANNELS * FRAME_SIZE; i++) {
        std::cout << decompressed[i] << " ";
    }
    std::cout << std::endl;

    opus_encoder_destroy(encoder);
    opus_decoder_destroy(decoder);

    return 0;
}