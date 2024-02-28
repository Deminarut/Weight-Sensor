#include <HX711_ADC.h>
#include <Adafruit_ILI9341.h> // Include the ILI9341 library

// HX711 constructor (dout pin, sck pin)
HX711_ADC LoadCell(4, 5);
float calibrationValue = 696.0; // this value is obtained using the SparkFun_HX711_Calibration sketch

// TFT display pins and constructor (CS pin, DC pin, RST pin)
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    Serial.begin(115200);
    LoadCell.begin();
    LoadCell.start(2000); // start with tare weight compensation
    LoadCell.setCalFactor(calibrationValue); // calibration value (float)

    tft.begin(); // Initialize the TFT display
    tft.setRotation(3); // Set the rotation
    tft.fillScreen(ILI9341_BLACK); // Fill the screen with black color
    tft.setTextColor(ILI9341_WHITE); // Set the text color to white
    tft.setTextSize(2); // Set the text size
}

void loop() {
  LoadCell.update();
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Tare timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else if (LoadCell.getSignalTimeoutFlag()) {
    Serial.println("Signal timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else if (LoadCell.getSignalTimeoutFlag()) {
    Serial.println("Signal timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    float i = LoadCell.getData();
    Serial.print("Load_cell output val: ");
    Serial.println(i);
    Serial.println("Succes");

    tft.setCursor(0, 0); // Set the cursor to the top-left corner
    tft.println("Load_cell output val: "); // Print the text to the TFT display
    tft.println(i); // Print the data to the TFT display
  }
}