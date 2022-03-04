// include nedded MusicFloppy header file
#include <MusicFloppy.h>

/**
 * create new object of the type MusicFloppy
 * "Drivename"(driveselectPin, directionPin, stepPin);
 * 
 * driveselectPin   = IDE pin 12
 * directionPin     = IDE pin 18
 * stepPin          = IDE pin 20
 * make sure that the used drive and the µC have a Ground connection
 */
MusicFloppy myDrive(2, 3, 4);

void setup() {
    // play a tune by calling "Drivename".playTune(frequencyInHz, durationTime);
    int durationTime = 500;
    myDrive.playTone( 82, durationTime);
    myDrive.playTone(110, durationTime);
    myDrive.playTone(146, durationTime);
    myDrive.playTone(196, durationTime);
    myDrive.playTone(246, durationTime);
    myDrive.playTone(329, durationTime);
}

void loop() {

}
