/*
 * MusicFloppy.cpp - Library for playing tunes with a floppydrive.
 * Created by Maximilian Wotsch, February 21, 2022.
*/
#include "Arduino.h"
#include "MusicFloppy.h"

MusicFloppy::MusicFloppy(int driveSelectPin, int directionPin, int stepPin) {
    pinMode(driveSelectPin, OUTPUT);
    _driveSelectPin = driveSelectPin;
    digitalWrite(_driveSelectPin, HIGH);

    pinMode(directionPin, OUTPUT);
    _directionPin = directionPin;
    digitalWrite(_directionPin, direction);

    pinMode(stepPin, OUTPUT);
    _stepPin = stepPin;
    digitalWrite(_stepPin, HIGH);
}

MusicFloppy::MusicFloppy() {
}

void MusicFloppy::playTone(int frequency, unsigned long durationTime) {
    int periodTimeInUs = 1000000/frequency;
    unsigned long startMillis = millis();
    digitalWrite(_driveSelectPin, LOW);
    while (millis() - startMillis < durationTime) {
        digitalWrite(_stepPin, step);
        step = !step;
        delayMicroseconds(periodTimeInUs/2);
        stepCount++;
        if (stepCount >= 160) {
            stepCount = 0;
            direction = !direction;
            digitalWrite(_directionPin, direction);
        }
    }
    digitalWrite(_driveSelectPin, HIGH);
}

void MusicFloppy::setDriveSelectPin(int driveSelectPin) {
    pinMode(driveSelectPin, OUTPUT);
    _driveSelectPin = driveSelectPin;
    digitalWrite(_driveSelectPin, HIGH);
}

void MusicFloppy::setDirectionPin(int directionPin) {
    pinMode(directionPin, OUTPUT);
    _directionPin = directionPin;
    digitalWrite(_directionPin, direction);
}

void MusicFloppy::setStepPin(int stepPin) {
    pinMode(stepPin, OUTPUT);
    _stepPin = stepPin;
    digitalWrite(_stepPin, HIGH);
}