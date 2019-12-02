#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// The DC motor connected to M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
// The DC motor connected to M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);
#include <FastLED.h>
#define LED_PIN 5
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 30
#define BRIGHTNESS random(100)
#define FRAMES_PER_SECOND 60
bool gReverseDirection = false;
CRGB leds[NUM_LEDS];
void setup() {
// delay(3000); // sanity delay
FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(
TypicalLEDStrip );
FastLED.setBrightness( BRIGHTNESS );
Serial.begin(19200);
AFMS.begin();
leftMotor->setSpeed(150);
rightMotor->setSpeed(150);
Serial.println("Startup");
}
void forward() {
Serial.print("Moving forward...");
leftMotor->run(FORWARD);
rightMotor->run(FORWARD);
// This takes one second to run
for (int i = 0; i < 60; i++) {
Fire2012(); // run simulation frame
FastLED.show(); // display this frame
FastLED.delay(500 / FRAMES_PER_SECOND);
}
for (int j = 0; j < NUM_LEDS; j++) {
leds[j] = 0;
}
FastLED.show();
leftMotor->run(RELEASE);
rightMotor->run(RELEASE);
Serial.println("Stopped");
}
void backward() {
Serial.print("Moving backward...");
leftMotor->run(BACKWARD);
rightMotor->run(BACKWARD);
// This takes one second to run
for (int i = 0; i < 60; i++) {
Fire2012(); // run simulation frame
FastLED.show(); // display this frame
FastLED.delay(500 / FRAMES_PER_SECOND);
}
for (int j = 0; j < NUM_LEDS; j++) {
leds[j] = 0;
}
// void keyPressed() {
// Serial.print("Pressed:");
// Serial.println();
// }
FastLED.show();
leftMotor->run(RELEASE);
rightMotor->run(RELEASE);
Serial.println("Stopped");
}
void right() {
Serial.print("Turning...");
leftMotor->run(BACKWARD);
rightMotor->run(FORWARD);
// This takes one second to run
for (int i = 0; i < 60; i++) {
Fire2012(); // run simulation frame
FastLED.show(); // display this frame
FastLED.delay(500 / FRAMES_PER_SECOND);
}
for (int j = 0; j < NUM_LEDS; j++) {
leds[j] = 0;
}
// void keyPressed() {
// Serial.print("Pressed:");
// Serial.println();
// }
FastLED.show();
leftMotor->run(RELEASE);
rightMotor->run(RELEASE);
Serial.println("Stopped");
}
void left() {
Serial.print("Turning...");
leftMotor->run(FORWARD);
rightMotor->run(BACKWARD);
// This takes one second to run
for (int i = 0; i < 60; i++) {
Fire2012(); // run simulation frame
FastLED.show(); // display this frame
FastLED.delay(500 / FRAMES_PER_SECOND);
}
for (int j = 0; j < NUM_LEDS; j++) {
leds[j] = 0;
}
// void keyPressed() {
// Serial.print("Pressed:");
// Serial.println();
// }
FastLED.show();
leftMotor->run(RELEASE);
rightMotor->run(RELEASE);
Serial.println("Stopped");
}
void loop()
{
// Add entropy to random number generator; we use a lot of it.
// random16_add_entropy( random());
char c = Serial.read();
if (c == 'b') {
forward();
FastLED.show();
}
if (c == 'f') {
backward();
}
if (c == 'r') {
right();
}
if (c == 'l') {
left();
}
// // This takes one second to run
// for (int i = 0; i < 60; i++) {
// Fire2012(); // run simulation frame
// FastLED.show(); // display this frame
// FastLED.delay(500 / FRAMES_PER_SECOND);
// }
// for (int j = 0; j < NUM_LEDS; j++) {
// leds[j] = 0;
// }
// // void keyPressed() {
// // Serial.print("Pressed:");
// // Serial.println();
// // }
// FastLED.show();
}
