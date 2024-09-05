var mx,my;
var state = "init";

function setup() {
  createCanvas(320,240);
  noStroke();
  rectMode(CENTER);
  frameRate(20);
}

function draw() {
  checkBTConnection();

/*
  mx = round(mouseX-160);
  my = round(mouseY-120);
  background(230);
  fill(244, 122, 158);
  rect(mx+160, my+120, 10,10);
  */

  mx = round(mouseX);
  my = round(mouseY);
  background(230);
  fill(244, 122, 158);
  if(mx>255){
    mx = 255;
  }
  if(mx<0){
    mx = 0;
  }
  if(my>255){
    my = 255;
  }
  if(my<0){
    my = 0;
  }
  rect(mx, my, 10,10);

  sendData();
}

function sendData(){
  //myLog("sendData");
  if(monitor == null){
    monitor = document.getElementById("monitor");
  }

  monitor.innerHTML = "value to send: "+mx+":"+my;
  //sendOne(mx+160, my+120);
  if(state == "connected" || state == "ready"){
    sendOne(mx, my);
    state = "sent";
  }

  if(state == "sent"){
    receive();
  }
  
}
