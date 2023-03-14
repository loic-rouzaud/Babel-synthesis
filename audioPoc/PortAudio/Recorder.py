#!/usr/bin/env python3
import sounddevice as sd
import numpy as np

# Load the raw audio file
raw_audio_file = 'recorded.raw'
with open(raw_audio_file, 'rb') as f:
    raw_audio = np.frombuffer(f.read(), dtype=np.float32)

# Play the audio back
sd.play(raw_audio, samplerate=38000)
sd.wait()