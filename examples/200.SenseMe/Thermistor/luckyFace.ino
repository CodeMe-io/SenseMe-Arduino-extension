void luckyFace(int ran){
  switch (ran) {
    case 0:
      matrix.clear();
      matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
      matrix.writeDisplay();
      //delay(500);
      break;
   case 1:
      matrix.clear();
      matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
      matrix.writeDisplay();
      //delay(500);
      break;
  case 2:
      matrix.clear();
      matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
      matrix.writeDisplay();
      //delay(500);
      break;
  default:
      matrix.clear();
      matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
      matrix.writeDisplay();
  }
  
}
