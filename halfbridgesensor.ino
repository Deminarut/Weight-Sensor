#include <HX711_ADC.h>

void setup() {
  Serial.begin(115200);
  HX711_ADC LoadCell(4, 5);
  float calibrationValue = 696.0;
  LoadCell.begin();
  LoadCell.start(2000);
  LoadCell.setCalFactor(calibrationValue);
}