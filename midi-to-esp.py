from music21 import converter, chord
from music21 import note as note21
import serial

# Load the MIDI file
midi_file = 'output.mid'
midi_data = converter.parse(midi_file)
notes_duration = list()

# Extract and print notes/chords with MIDI numbers and durations
for element in midi_data.flat.notes:
    if isinstance(element, note21.Note):
        # print(f"Note: {element.name}, MIDI Number: {element.pitch.midi}, Start: {element.offset}, Duration: {element.quarterLength}")
        notes_duration.append(int(element.pitch.midi))
        notes_duration.append(int(element.quarterLength))
    elif isinstance(element, chord.Chord):
        midi_numbers = [n.pitch.midi for n in element.notes]
        print(f"Chord: {' '.join(n.name for n in element.notes)}, MIDI Numbers: {midi_numbers}, Start: {element.offset}, Duration: {element.quarterLength}")
notes_duration.append(255)
print(notes_duration)

ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM3'
ser.open()
 
values = bytearray(notes_duration)
ser.write(values)
 
total = 0

while total < len(values):
    print (ord(ser.read(1)))
    total=total+1
 
ser.close()