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
  for(int i=0; i<(len-1);i++){
    int index = round(i/4);

    int w;
    w = buf[i];

    uint32_t  c = strip.Color(w,w,w,w);
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}

void demo(){
  for(int i=0; i<ledLength;i++){

    int w=60;

    uint32_t  c = strip.Color(w,w,w,w);
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}

void bleathOne(int val){
  for(int i=0; i<ledLength;i++){

    int w=val;

    uint32_t  c = strip.Color(red,green,blue,w);
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}

void bleathTwo(int v,int h){
  for(int i=0; i<ledLength;i++){

    int w=v;

    uint32_t  c;
    if(i == h){
      c = strip.Color(red,green,blue,w);
    }else{
      c = strip.Color(red,green,blue,0);
    }
    
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}

void bleathSin(int max,int deg){
  
  for(int i=0; i<ledLength;i++){

    float degrees = deg+i;
    float radians = degToRad(degrees);
    float ratio = (sin(radians) + 1)/2.0;

    float value = max * ratio;

    int w= round(value);

    //uint32_t  c = strip.Color(red,green,blue,w);
    uint32_t  c = strip.Color(0,0,0,w);
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}

void bleathSin2(int max,int deg){
  
  for(int i=0; i<ledLength;i++){

    float degrees = deg;
    float radians = degToRad(degrees);
    float ratio = sin(radians);
    if(ratio<0){
      ratio = 0;
    }


    int w= round(max * ratio);
    int r= round(max * ratio);
    int g= round(max * ratio);
    int b= round(max * ratio);

    //uint32_t  c = strip.Color(red,green,blue,w);
    uint32_t  c = strip.Color(r,g,b,w);
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}

void bleathSin3(int max,int deg){
  
  for(int i=0; i<ledLength;i++){

    float degrees = deg;
    float radians = degToRad(degrees);
    float ratio = (sin(radians) +1)/2.0;
    if(ratio<0){
      ratio = 0;
    }

    int w = 0;
    int r =0;
    int g = 0;
    int b = 0;

    if(state == "red"){
      r= round(max * ratio);
    }else if(state == "green"){
      g= round(max * ratio);
    }else if(state == "blue"){
       b= round(max * ratio);
    }else if(state == "white"){
      w= round(max * ratio);
    }else if(state == "all"){
      w= round(max * ratio);
      r= round(max * ratio);
      g= round(max * ratio);
      b= round(max * ratio);
    }

    //uint32_t  c = strip.Color(red,green,blue,w);
    uint32_t  c = strip.Color(r,g,b,w);
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}