// include nedded MusicFloppy header file
#include <MusicFloppy.h>

/**
 * create new object of the type MusicFloppy
 * "Drivename"(driveselectPin, directionPin, stepPin);
 * 
 * driveselectPin   = IDE pin 12
 * directionPin     = IDE pin 18
 * stepPin          = IDE pin 20
 * make shure that the used drive and the µC have a Ground connection
 */
MusicFloppy myDrive(2, 3, 4);

void setup() {
    
}

void loop() {
    // play a 50 Hz tune for one second by calling "Drivename".playTune(frequencyInHz, durationTime);
    myDrive.playTone(50, 1000);
    delay(1000);
}
