void luckyFace(int ran){
  switch (ran) {
    case 0:
      matrix.clear();
      matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
      matrix.writeDisplay();
      pulseColor(255,255,0);
      //delay(1000);
      for (int8_t x=0; x>=-(6*6); x--) {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print("Lucky");
        matrix.writeDisplay();
        delay(100);
      }
      //delay(500);
      break;
   case 1:
      matrix.clear();
      matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
      matrix.writeDisplay();
      pulseColor(255,255,255);
      //delay(1000);
      for (int8_t x=0; x>=-(4*6); x--) {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print("OK!");
        matrix.writeDisplay();
        delay(100);
      }
      //delay(500);
      break;
  case 2:
      matrix.clear();
      matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
      matrix.writeDisplay();
      pulseColor(0,255,255);
      //delay(1000);
      for (int8_t x=0; x>=-(6*6); x--) {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print("Sad..");
        matrix.writeDisplay();
        delay(100);
      }
      //delay(500);
      break;
  default:
      matrix.clear();
      matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
      matrix.writeDisplay();
      //delay(1000);
      for (int8_t x=0; x>=-(15*6); x--) {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print("Lucky");
        matrix.writeDisplay();
        delay(100);
      }
  }
  
}
