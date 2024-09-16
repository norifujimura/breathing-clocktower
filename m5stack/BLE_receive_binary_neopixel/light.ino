void setupLED(){
  strip.updateLength(ledLength);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(ledBrightness);
}

void showLED(){
  /*
  for(int i=0; i<(len-1);i++){
    int index = round(i/4);

    int w;
    w = buf[i];

    uint32_t  c = strip.Color(w,w,w,w);
    strip.setPixelColor(index, c);         //  Set pixel's color (in RAM)
  }
  */
  for(int i=0; i<ledLength ;i++){

    uint32_t  c = strip.Color(0,0,0,brightness);
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}

void showLEDBytes(){
  if(mode == "white"){
    for(int i=0; i<ledLength ;i++){

      uint32_t  c = strip.Color(0,0,0,buf[i]);
      strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
    }
  }else if(mode == "rgb"){
    for(int i=0; i<ledLength ;i++){
      int r = buf[i*3];
      int g = buf[i*3+1];
      int b = buf[i*3+2];
      //uint32_t  c = strip.Color(r,g,b,0);
      uint32_t  c = getRGBW(r,g,b);
      strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
    }
  }

  strip.show(); 
}

uint32_t getRGBW(int r,int g,int b){
  if(r<=g && r<=b){
    int w = r;
    r = 0;
    g = g-w;
    b = b-w;
    uint32_t  c = strip.Color(r,g,b,w);
    return c;
  }else if(g<=r && g<=b){
    int w = g;
    r = r-w;
    g = 0;
    b = b-w;
    uint32_t  c = strip.Color(r,g,b,w);
    return c;
  }else if(b<=r && b<=g){
    int w = r;
    r = r-w;
    g = g-w;
    b = 0;
    uint32_t  c = strip.Color(r,g,b,w);
    return c;
  }
    uint32_t  c = strip.Color(0,0,0,0);
    return c;
}



