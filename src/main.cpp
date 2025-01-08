// testing GSR sensor

// #include <Arduino.h>
// const int GSR=A0;
// int sensorValue=0;
// int gsr_average=0;

// void setup(){
//   Serial.begin(9600);
// }

// void loop(){
//   long sum=0;
//   for(int i=0;i<10;i++)           // average the 10 measurements 
//       {
//       sensorValue=analogRead(GSR);
//       sum += sensorValue;
//       delay(5);
//       }
//    gsr_average = sum/10;
//    Serial.println(gsr_average);
//    delay(1000);
// } 

// testing temperature sensor TMP102

// Include the SparkFun TMP102 library.
// Click here to get the library: http://librarymanager/All#SparkFun_TMP102
// #include <Arduino.h>
// #include <Wire.h> // Used to establied serial communication on the I2C bus
// #include <SparkFunTMP102.h> // Used to send and recieve specific information from our sensor

// Connections
// VCC = 3.3V
// GND = GND
// SDA = A4
// SCL = A5
/*
const int ALERT_PIN = A3;

TMP102 sensor0;

void setup() {
  Serial.begin(115200);
  Wire.begin(); //Join I2C Bus

  pinMode(ALERT_PIN,INPUT);  // Declare alertPin as an input

  //  The TMP102 uses the default settings with the address 0x48 using Wire.

  //    Optionally, if the address jumpers are modified, or using a different I2C bus,
  //    these parameters can be changed here. E.g. sensor0.begin(0x49,Wire1)

  //    It will return true on success or false on failure to communicate. 
  if(!sensor0.begin())
  {
    Serial.println("Cannot connect to TMP102.");
    Serial.println("Is the board connected? Is the device ID correct?");
    while(1);
  }

  Serial.println("Connected to TMP102!");
  delay(100);

  // Initialize sensor0 settings
  // These settings are saved in the sensor, even if it loses power

  // set the number of consecutive faults before triggering alarm.
  // 0-3: 0:1 fault, 1:2 faults, 2:4 faults, 3:6 faults.
  sensor0.setFault(0);  // Trigger alarm immediately

  // set the polarity of the Alarm. (0:Active LOW, 1:Active HIGH).
  sensor0.setAlertPolarity(1); // Active HIGH

  // set the sensor in Comparator Mode (0) or Interrupt Mode (1).
  sensor0.setAlertMode(0); // Comparator Mode.

  // set the Conversion Rate (how quickly the sensor gets a new reading)
  //0-3: 0:0.25Hz, 1:1Hz, 2:4Hz, 3:8Hz
  sensor0.setConversionRate(2);

  //set Extended Mode.
  //0:12-bit Temperature(-55C to +128C) 1:13-bit Temperature(-55C to +150C)
  sensor0.setExtendedMode(0);

  //set T_HIGH, the upper limit to trigger the alert on
  sensor0.setHighTempF(82.0);  // set T_HIGH in F
  //sensor0.setHighTempC(29.4); // set T_HIGH in C

  //set T_LOW, the lower limit to shut turn off the alert
  sensor0.setLowTempF(81.0);  // set T_LOW in F
  //sensor0.setLowTempC(26.67); // set T_LOW in C
}

void loop()
{
  float temperature;
  boolean alertPinState, alertRegisterState;

  // Turn sensor on to start temperature measurement.
  // Current consumtion typically ~10uA.
  sensor0.wakeup();

  // read temperature data
  //temperature = sensor0.readTempF();
  temperature = sensor0.readTempC();

  // Check for Alert
  alertPinState = digitalRead(ALERT_PIN); // read the Alert from pin
  alertRegisterState = sensor0.alert();   // read the Alert from register

  // Place sensor in sleep mode to save power.
  // Current consumtion typically <0.5uA.
  sensor0.sleep();

  // Print temperature and alarm state
  Serial.print("Temperature: ");
  Serial.print(temperature);

  Serial.print("\tAlert Pin: ");
  Serial.print(alertPinState);

  Serial.print("\tAlert Register: ");
  Serial.println(alertRegisterState);

  delay(1000);  // Wait 1000ms
} */


// testing MAX30102 sensor

// #include <Arduino.h>
// #include <Wire.h>
// #include "MAX30105.h"

// #include "heartRate.h"

// MAX30105 particleSensor;

// const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
// byte rates[RATE_SIZE]; //Array of heart rates
// byte rateSpot = 0;
// long lastBeat = 0; //Time at which the last beat occurred

// float beatsPerMinute;
// int beatAvg;

// void setup()
// {
//   Serial.begin(115200);
//   Serial.println("Initializing...");
//   Wire1.begin(D4, D3);
//   // Initialize sensor
//   if (!particleSensor.begin(Wire1, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
//   {
//     Serial.println("MAX30105 was not found. Please check wiring/power. ");
//     while (1);
//   }
//   Serial.println("Place your index finger on the sensor with steady pressure.");

//   particleSensor.setup(); //Configure sensor with default settings
//   particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
//   particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
// }

// void loop()
// {
//   long irValue = particleSensor.getIR();

//   if (checkForBeat(irValue) == true)
//   {
//     //We sensed a beat!
//     long delta = millis() - lastBeat;
//     lastBeat = millis();

//     beatsPerMinute = 60 / (delta / 1000.0);

//     if (beatsPerMinute < 255 && beatsPerMinute > 20)
//     {
//       rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
//       rateSpot %= RATE_SIZE; //Wrap variable

//       //Take average of readings
//       beatAvg = 0;
//       for (byte x = 0 ; x < RATE_SIZE ; x++)
//         beatAvg += rates[x];
//       beatAvg /= RATE_SIZE;
//     }
//   }

//   Serial.print("IR=");
//   Serial.print(irValue);
//   Serial.print(", BPM=");
//   Serial.print(beatsPerMinute);
//   Serial.print(", Avg BPM=");
//   Serial.print(beatAvg);

//   if (irValue < 50000)
//     Serial.print(" No finger?");

//   Serial.println();

// }

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>             // Library for WiFi connectivity
#include "ThingSpeak.h"       // Library for ThingSpeak integration
#include "SparkFunTMP102.h"   // Library for TMP102 temperature sensor
#include "MAX30105.h"         // Library for MAX30102 pulse sensor
#include "heartRate.h"        // Algorithm for detecting heartbeats

// Pins for sensors
const int GSR_PIN = A0;     // Pin for GSR sensor
const int RED_PIN = D12;    // Pin for red LED (RGB)
const int GREEN_PIN = D11;  // Pin for green LED (RGB)
const int BLUE_PIN = D10;   // Pin for blue LED (RGB)
const int BUZZER_PIN = D7;  // Pin for buzzer

// Sensor objects
TMP102 temperatureSensor;
MAX30105 pulseSensor;

// Variables for GSR
int gsrValue = 0;
int gsrAverage = 0;

// Variables for TMP102
float temperature = 0.0;

// Variables for MAX30102 (pulse)
const byte RATE_SIZE = 4;  // Buffer size for averaging heart rate
byte rates[RATE_SIZE];
byte rateSpot = 0;
long lastBeat = 0;
float beatsPerMinute;
int beatAvg = 0;

// Timers for ThingSpeak and stress detection
unsigned long lastUpdateTime = 0;
const unsigned long updateInterval = 15000; // Send data to ThingSpeak every 15 seconds
unsigned long lastStressCheck = 0;
const unsigned long stressInterval = 10000; // Check stress level every 10 seconds

// WiFi and ThingSpeak variables
const char* ssid = "DIGI-52Yb";             // WiFi network name
const char* password = "PZQxUfckhx";        // WiFi password
WiFiClient client;
unsigned long myChannelNumber = 2803845;    // ThingSpeak channel ID
const char* myWriteAPIKey = "F81C89Q93ZKZRUJ6"; // ThingSpeak API write key

// Function to provide feedback (LED and buzzer)
void stressFeedback(bool stressed) {
  if (stressed) {
    // Red LED on for stress indication
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    // Buzzer beep
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    // Green LED on for no stress
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  }
}

// Sensor and WiFi setup
void setup() {
  Serial.begin(115200);
  Serial.println("Initializing system...");

  // Configure pins for RGB LED and buzzer
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GSR_PIN, INPUT);

  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize ThingSpeak
  ThingSpeak.begin(client);

  // Initialize TMP102 sensor
  Wire.begin();
  if (!temperatureSensor.begin()) {
    Serial.println("TMP102 not found! Check connections.");
    while (1); // Stop if TMP102 is not detected
  }
  temperatureSensor.setConversionRate(2);   // Set conversion rate to 4 Hz
  temperatureSensor.setExtendedMode(0);     // Disable extended mode
  Serial.println("TMP102 initialized.");

  // Initialize MAX30102 sensor
  Wire1.begin(D4, D3); // Specify pins for I2C
  if (!pulseSensor.begin(Wire1, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 not found! Check connections.");
    while (1); // Stop if MAX30102 is not detected
  }
  pulseSensor.setup();
  pulseSensor.setPulseAmplitudeRed(0x1F);   // Adjust red LED intensity
  pulseSensor.setPulseAmplitudeGreen(0);    // Disable green LED
  Serial.println("MAX30102 initialized.");
}

// Function to read GSR sensor
void readGSR() {
  long gsrSum = 0;
  for (int i = 0; i < 10; i++) {
    gsrSum += analogRead(GSR_PIN);
    delay(5); // Short delay between readings
  }
  gsrAverage = gsrSum / 10; // Calculate the average
  Serial.print("GSR: ");
  Serial.println(gsrAverage);
}

// Function to read temperature from TMP102
void readTemperature() {
  temperatureSensor.wakeup();
  temperature = temperatureSensor.readTempC(); // Read temperature in Celsius
  temperatureSensor.sleep();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}

// Function to read pulse from MAX30102
void readPulse() {
  long irValue = pulseSensor.getIR(); // Read infrared value
  if (checkForBeat(irValue)) {
    // Calculate BPM (Beats Per Minute)
    long delta = millis() - lastBeat;
    lastBeat = millis();
    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute > 20 && beatsPerMinute < 255) {
      rates[rateSpot++] = (byte)beatsPerMinute;
      rateSpot %= RATE_SIZE; // Wrap around buffer

      beatAvg = 0;
      for (byte x = 0; x < RATE_SIZE; x++) {
        beatAvg += rates[x];
      }
      beatAvg /= RATE_SIZE; // Calculate average BPM
    }
  }
  Serial.print("Pulse BPM: ");
  Serial.print(beatsPerMinute);
  Serial.print(", Average BPM: ");
  Serial.println(beatAvg);
}

// Function to determine stress level
void determineStress() {
  Serial.println("Determining stress level...");
  bool isStressed = false;

  // Conditions for stress detection
  if (gsrAverage < 1700 || temperature > 27.5 || beatAvg > 90) {
    isStressed = true;
    stressFeedback(true); // Stress feedback
    Serial.println("Conclusion: You are stressed.");
  } else {
    stressFeedback(false); // No stress feedback
    Serial.println("Conclusion: You are not stressed.");
  }
}

// Function to send data to ThingSpeak
void sendDataToThingSpeak() {
  ThingSpeak.setField(1, temperature);  // Set temperature data
  ThingSpeak.setField(2, gsrAverage);  // Set GSR data
  ThingSpeak.setField(3, beatAvg);     // Set pulse data

  int responseCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (responseCode == 200) {
    Serial.println("Data successfully sent to ThingSpeak.");
  } else {
    Serial.print("Error sending data: ");
    Serial.println(responseCode);
  }
}

// Main loop
void loop() {
  // Read sensors
  readGSR();
  readTemperature();
  readPulse();

  // Determine stress level every 10 seconds
  unsigned long currentMillis = millis();
  if (currentMillis - lastStressCheck >= stressInterval) {
    lastStressCheck = currentMillis;
    determineStress();
  }

  // Send data to ThingSpeak every 15 seconds
  if (currentMillis - lastUpdateTime >= updateInterval) {
    lastUpdateTime = currentMillis;
    sendDataToThingSpeak();
  }

  delay(1000); // Short delay for stability
}






