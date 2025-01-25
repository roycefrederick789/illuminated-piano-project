## Beginner Friendly Piano Prototype

This is a project to build a user-friendly piano prototype. The prototype is able to read music sheet scores and guide the user in playing piano through LED lights attached to each key.

The following flowchart describes our project piano prototype.
![Piano Prototype Flowchart](flowchart/piano-prototype.png)

Description of the code:
img-to-midi.py: a code to convert music sheet scores from image file to midi format file.
midi-to-esp.py: a code to load MIDI file and transmit music note data to an esp32 that is connected to laptop.
main.py: a code that integrate img-to-midi.py and midi-to-esp.py.
piano-led.ino: a code to control LED lights on a piano based on note data send by python program.


### Acknowledgment
This project includes code from [SheetVision](https://github.com/cal-pratt/SheetVision/tree/master), which is licensed under the MIT License.
The incorporated code is used to convert music sheet scores into midi format file.