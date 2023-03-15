#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "portaudio.h"
#include "opus/opus.h"

#define SAMPLE_RATE     (48000)
#define FRAMES_PER_BUFFER (480)
#define NUM_SECONDS     (10)
#define NUM_CHANNELS    (2)
#define OPUS_FRAME_SIZE (960) // 20ms at 48000Hz
#define MAX_FRAME_SIZE  (6*960)
#define MAX_PACKET_SIZE (3*1276) // see https://tools.ietf.org/html/rfc6716#section-3.1.1

typedef struct {
    SAMPLE *recorded_samples;
    unsigned char *encoded_data;
    SAMPLE *decoded_samples;
    int recorded_frames;
    int encoded_size;
    int decoded_frames;
    OpusEncoder *opus_encoder;
    OpusDecoder *opus_decoder;
} paUserData;

static int record_callback(const void *inputBuffer, void *userData,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *outputBuffer) {
    paUserData *data = (paUserData*)userData;
    const SAMPLE *read_samples = (const SAMPLE*)inputBuffer;
    SAMPLE *write_samples = &data->recorded_samples[data->recorded_frames * NUM_CHANNELS];
    int num_frames = framesPerBuffer;
    int num_samples = num_frames * NUM_CHANNELS;
    int num_bytes = num_samples * sizeof(SAMPLE);
    memcpy(write_samples, read_samples, num_bytes);
    data->recorded_frames += num_frames;
    return paContinue;
}

static int play_callback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData) {
    paUserData *data = (paUserData*)userData;
    SAMPLE *read_samples = &data->decoded_samples[data->decoded_frames * NUM_CHANNELS];
    SAMPLE *write_samples = (SAMPLE*)outputBuffer;
    int num_frames = framesPerBuffer;
    int num_samples = num_frames * NUM_CHANNELS;
    int num_bytes = num_samples * sizeof(SAMPLE);
    if (data->decoded_frames + num_frames > data->recorded_frames) {
        num_frames = data->recorded_frames - data->decoded_frames;
        num_samples = num_frames * NUM_CHANNELS;
        num_bytes = num_samples * sizeof(SAMPLE);
        memset(&data->decoded_samples[data->decoded_frames * NUM_CHANNELS], 0, num_bytes);
    }
    memcpy(write_samples, read_samples, num_bytes);
    data->decoded_frames += num_frames;
    return paContinue;
}

int main(void) {
    PaStreamParameters inputParameters, outputParameters;
    PaStream *stream = NULL;
    PaError err;
    paTestData data = {0};
    paUserData user_data = {0};
    int num_frames;
    unsigned char packet[MAX_PACKET_SIZE];
    int packet_size;
    int error;

    user_data.opus_encoder = opus_encoder_create(SAMPLE_RATE, NUM_CHANNELS, OPUS_APPLICATION_VOIP, &error);
    if (error != OPUS_OK) {
        fprintf(stderr, "Error creating Opus encoder: %s\n", opus_strerror(error));
        return -1;
    }
    opus_encoder_ctl(user_data.opus_encoder, OPUS_SET_BITRATE(64000));
    opus_encoder_ctl(user_data.opus_encoder, OPUS_SET_BANDWIDTH(OPUS_BANDWIDTH_FULLBAND));
    opus_encoder_ctl(user_data.opus_encoder, OPUS_SET_BANDWIDTH(OPUS_BANDWIDTH_FULLBAND))
    user_data.opus_encoder.set_vbr(True)

    err = Pa_StartStream( stream );
  if( err != paNoError ) goto error;
  printf("\n=== Now recording!! Please speak into the microphone. ===\n"); fflush(stdout);

  while( ( err = Pa_IsStreamActive( stream ) ) == 1 )
  {
      Pa_Sleep(1000);
      printf("index = %d\n", data.frameIndex ); fflush(stdout);
  }
  if( err < 0 ) goto error;

  err = Pa_CloseStream( stream );
  if( err != paNoError ) goto error;

    /* Save the data into a file */
    if (WRITE_TO_FILE)
    {
        FILE  *fid;
        fid = fopen("recorded.raw", "wb");
        if (!fid) {
            printf("Could not open file.");
            return 1;
        }
        fwrite( data.recordedSamples, NUM_CHANNELS * sizeof(SAMPLE), data.maxFrameIndex, fid );
        fclose(fid);
        printf("Wrote data to 'recorded.raw'\n");
    }

    /* Playback recorded data.  -------------------------------------------- */
    data.frameIndex = 0;

    outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */
    if (outputParameters.device == paNoDevice) {
        fprintf(stderr,"Error: No default output device.\n");
        goto error;
    }
    outputParameters.channelCount = NUM_CHANNELS;
    outputParameters.sampleFormat =  PA_SAMPLE_TYPE;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    printf("\n=== Now playing back. ===\n"); fflush(stdout);
    err = Pa_OpenStream(
              &stream,
              NULL, /* no input */
              &outputParameters,
              SAMPLE_RATE,
              FRAMES_PER_BUFFER,
              paClipOff,      /* we won't output out of range samples so don't bother clipping them */
              playCallback,
              &data );
    if( err != paNoError ) goto error;

    if( stream )
    {
        err = Pa_StartStream( stream );
        if( err != paNoError ) goto error;

        printf("Waiting for playback to finish.\n"); fflush(stdout);

        while( ( err = Pa_IsStreamActive( stream ) ) == 1 ) Pa_Sleep(100);
        if( err < 0 ) goto error;

        err = Pa_CloseStream( stream );
        if( err != paNoError ) goto error;

        printf("Done.\n"); fflush(stdout);
    }

    /* Clean up. */
    Pa_Terminate();
    if( data.recordedSamples )       /* Sure it is NULL or valid. */
    {
        free( data.recordedSamples );
    }
    return err;
}