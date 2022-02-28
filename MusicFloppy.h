/*
 * MusicFloppy.h - Library for playing tunes with a floppydrive.
 * Created by Maximilian Wotsch, February 21, 2022.
*/
#ifndef MusicFloppy_h
#define MusicFloppy_h

#include "Arduino.h"

class MusicFloppy
{
private:
    int _driveSelectPin, _directionPin, _stepPin;
    bool direction = LOW, step = LOW;
    int stepCount = 0; // max. 160 half-steps
public:
    MusicFloppy(int driveselectPin, int directionPin, int stepPin);
    MusicFloppy();

    void playTone(int frequency, unsigned long durationTime);

    void setDriveSelectPin(int driveSelectPin);
    void setDirectionPin(int directionPin);
    void setStepPin(int stepPin);
};

#endif