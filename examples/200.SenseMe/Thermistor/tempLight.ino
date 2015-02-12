void tempLight() {
    // Get the temperature
    //
    float t = SenseMeThermistor.temperature(CELSIUS);
    
    // Print the temperature
    Serial.print("Temp is: ");
    Serial.println(t);
    
    delay(1000);
    
    // Choose the next point in RGB space by temperature - this is a 
    // linear scale that maps from pure blue for the coldest to pure
    // red for the hottest, with intermediate temperatures
    // represented by the appropriate mixture of blue and red.
    //
    // We constrain the temperature so that the lowest temperature we
    // represent is TBLUE and the highest is TRED. MAX_BRIGHTNESS is
    // the maximum we can set an LED channel to.
    //
    
    matrix.setTextSize(1);
    matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
    matrix.setTextColor(LED_ON);
    for (int8_t x=0; x>=-40; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(t);
    matrix.print("C");
    matrix.writeDisplay();
    delay(100);
  }
}
