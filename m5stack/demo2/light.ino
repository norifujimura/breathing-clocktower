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

void bleathSin4(int max,int deg){
  
  for(int i=0; i<ledLength;i++){

    float degrees = deg;
    float radians = degToRad(degrees);
    float ratio = sin(radians); //-1 to + 1
    float value = abs(ratio);

    uint32_t  c = strip.Color(127,127,127,127);

    if(state == "taito"){
      if(ratio<0){
        //c = getRGBW2(249,252,5,value);
        r = 249;
        g = 252;
        b = 5;
      }else{
        //c = getRGBW2(5,252,57,value);
        r = 5;
        g = 252;
        b = 57;
      }
    }else if(state == "kaito"){
      if(ratio<0){
        //c = getRGBW2(249,252,5,value);
        r = 249;
        g = 252;
        b = 5;
      }else{
        //c = getRGBW2(226,5,252,value);
        r = 226;
        g = 5;
        b = 252;
      }
    }else if(state == "maiko"){
      if(ratio<0){
        //c = getRGBW2(137,245,249,value);
        r = 137;
        g = 245;
        b = 249;
      }else{
        //c = getRGBW2(252,174,5,value);
        r = 252;
        g = 174;
        b = 5;
      }
    }else if(state == "yohko"){
      if(ratio<0){
        //c = getRGBW2(157,244,249,value);
        r = 157;
        g = 244;
        b = 249;
      }else{
        //c = getRGBW2(239,157,249,value);
        r = 239;
        g = 157;
        b = 249;
      }
    }else{
      if(ratio<0){
        //c = getRGBW2(157,244,249,value);
        r = 100;
        g = 100;
        b = 200;
      }else{
        //c = getRGBW2(239,157,249,value);
        r = 250;
        g = 100;
        b = 100;
      }
    }
    c = getRGBW2(r,g,b,value);
    //uint32_t  c = strip.Color(red,green,blue,w);
    //uint32_t  c = strip.Color(r,g,b,w);
    strip.setPixelColor(i, c);         //  Set pixel's color (in RAM)
  }
  strip.show();  
}

uint32_t getRGBW2(int r,int g,int b,float ratio){
  if(r<=g && r<=b){
    int w = r;
    r = 0;
    g = g-w;
    b = b-w;

    rw = round(r * ratio);
    gw = round(g * ratio);
    bw = round(b * ratio);
    ww = round(w * ratio/2);
    uint32_t  c = strip.Color(rw,gw,bw,ww);
    return c;
  }else if(g<=r && g<=b){
    int w = g;
    r = r-w;
    g = 0;
    b = b-w;
    rw = round(r * ratio);
    gw = round(g * ratio);
    bw = round(b * ratio);
    ww = round(w * ratio/2);
    uint32_t  c = strip.Color(rw,gw,bw,ww);
    return c;
  }else if(b<=r && b<=g){
    int w = r;
    r = r-w;
    g = g-w;
    b = 0;
    rw = round(r * ratio);
    gw = round(g * ratio);
    bw = round(b * ratio);
    ww = round(w * ratio/2);
    uint32_t  c = strip.Color(rw,gw,bw,ww);
    return c;
  }
    uint32_t  c = strip.Color(0,0,0,0);
    return c;
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