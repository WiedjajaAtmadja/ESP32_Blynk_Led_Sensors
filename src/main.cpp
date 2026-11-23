/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL6nWBqfn6T"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "VF-T3uNo88MVY__MNbBNSZoexclthtHf"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define PIN_LED_RED 2
#define PIN_LED_GREEN 0

#define BLYNK_LED_RED V0
#define BLYNK_LED_GREEN V1

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(BLYNK_LED_RED)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  Serial.printf("V0 value is: %d\r\n", value);
  digitalWrite(PIN_LED_RED, value);
}

BLYNK_WRITE(BLYNK_LED_GREEN)
{
  // Set incoming value from pin V1 to a variable
  int value = param.asInt();
  Serial.printf("V1 value is: %d\r\n", value);
  digitalWrite(PIN_LED_GREEN, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Request the latest state from the server
  Blynk.syncVirtual(BLYNK_LED_RED);
  Blynk.syncVirtual(BLYNK_LED_GREEN);
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
}

void setup()
{
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  digitalWrite(PIN_LED_RED, LOW);
  digitalWrite(PIN_LED_GREEN, LOW);
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}
