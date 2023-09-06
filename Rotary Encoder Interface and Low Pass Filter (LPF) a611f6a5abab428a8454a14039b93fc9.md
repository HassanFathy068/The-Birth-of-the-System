# Rotary Encoder Interface and Low Pass Filter (LPF) Design

This document describes the code and design for interfacing with a rotary encoder and implementing a software-based low pass filter (LPF).

## Rotary Encoder Interface

### Hardware Setup

- Connect the rotary encoder's A and B signal pins to the Arduino's digital pins.
- Connect the Arduino's ground pin to the ground of the rotary encoder.

### Code Explanation

The provided code demonstrates how to interface with a rotary encoder and count the number of pulses from the A and B signals. Here's an overview of the code:

- The `encoderPinA` and `encoderPinB` variables define the digital pins connected to the encoder's A and B signals.
- The `count` variable stores the pulse count.
- The `handleEncoderInterrupt` function is an interrupt service routine that gets triggered when there's a change in the state of the encoder pin A.
- Inside the `handleEncoderInterrupt` function, the current states of the encoder pins are read, and the count is updated based on the direction of rotation.

## Low Pass Filter (LPF) Design

### Design Considerations

To design the LPF, we need to determine the proper cutoff frequency (fc). Here are the specifications considered for WALL-E:

- Encoder pulses per revolution: 540
- Motorized wheel diameter: 40 cm
- Maximum speed of WALL-E: 0.5 m/s

### Calculation of Maximum Frequency

The maximum frequency (fmax) of the encoder pulses can be calculated as follows:

fmax = (maximum speed) / (encoder pulses per revolution)

= 0.5 / 540

≈ 0.000925 Hz