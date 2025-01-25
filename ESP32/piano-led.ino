#include <Adafruit_NeoPixel.h>

// Pin to use to send signals to WS2812B
#define LED_PIN 5

// Number of WS2812B LEDs attached to the Arduino
#define LED_COUNT 8

// Setting up the NeoPixel library
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int notesPIN[] = {1,2,42,41,40,39,38,37,36,35,45,48,47,   5};
int notes[100] = {};
int durations[] = {2000, 500,500,500, 1000,1000};
int musicDataSent = 0;

void notesLED(int pinNumber, int duration){
  digitalWrite(pinNumber, HIGH);
  delay(duration);
  digitalWrite(pinNumber, LOW);
  delay(100);
}
void setup() {
  Serial.begin(115200);
  
  int sizeNotes = sizeof(notesPIN)/sizeof(notesPIN[0]);
  
  // setting up led pin for every note as output
  for(int i=0; i<sizeNotes; i++){
    pinMode(notesPIN[i], OUTPUT);
  }
  strip.begin();           // Initialize NeoPixel object
  strip.setBrightness(10); // Set BRIGHTNESS to about 4% (max = 255)
}

void loop() {
  // put your main code here, to run repeatedly:
  int index=0;
  while(Serial.available()){    
    int temp = Serial.read(); // receive data from python
    int currentNote, currentDuration;
    Serial.write(temp); // send data to python
    if(temp == 255){
      musicDataSent = 1;
      break;
    } else{
      if(index%2 == 0){ // even index: note
        currentNote = temp;
      } else{ // odd index: duration
        currentDuration = temp*1000;
//        currentDuration = 500;
        if (currentNote != 255) { // Process the note and duration
          if(currentNote == 60 || currentNote == 48){notesLED(notesPIN[0], currentDuration);}
          else if(currentNote == 61 || currentNote == 49){notesLED(notesPIN[1], currentDuration);}
          else if(currentNote == 62 || currentNote == 50){notesLED(notesPIN[2], currentDuration);}
          else if(currentNote == 63 || currentNote == 51){notesLED(notesPIN[3], currentDuration);}
          else if(currentNote == 64 || currentNote == 52){notesLED(notesPIN[4], currentDuration);}
          else if(currentNote == 65 || currentNote == 53){notesLED(notesPIN[5], currentDuration);}
          else if(currentNote == 66 || currentNote == 54){notesLED(notesPIN[6], currentDuration);}
          else if(currentNote == 67 || currentNote == 55){notesLED(notesPIN[7], currentDuration);}
          else if(currentNote == 68 || currentNote == 56){notesLED(notesPIN[8], currentDuration);} 
          else if(currentNote == 69 || currentNote == 57){notesLED(notesPIN[9], currentDuration);}
          else if(currentNote == 70 || currentNote == 58){notesLED(notesPIN[10], currentDuration);}
          else if(currentNote == 71 || currentNote == 59){notesLED(notesPIN[11], currentDuration);}
          else if(currentNote == 72 || currentNote == 60){notesLED(notesPIN[12], currentDuration);}
          else if(currentNote == 0){
            strip.clear(); // Set all pixel colors to 'off'
            strip.setPixelColor(0, 0, 255, 0);
            strip.setPixelColor(2, 0, 255, 0);
            strip.setPixelColor(4, 0, 255, 0);
            strip.setPixelColor(6, 0, 255, 0);
  
            strip.show();   // Send the updated pixel colors to the hardware.
            
            delay(1000); // *Wait for the duration without lighting any LED
            strip.setPixelColor(0, 0, 0, 0);
            strip.setPixelColor(2, 0, 0, 0);
            strip.setPixelColor(4, 0, 0, 0);
            strip.setPixelColor(6, 0, 0, 0);
            strip.show();  // Send the updated pixel colors to the hardware
            strip.clear(); // Set all pixel colors to 'off'
          }
          

        }
        currentNote = -1; // Reset
        currentDuration = 0; // Reset
      }
      index++;
    }
    
  }
  
  if(musicDataSent == 1){
    index = 0;
    musicDataSent = 0;
  }
}
