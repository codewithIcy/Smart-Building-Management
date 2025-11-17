const int fan = 2;
const int heater = 3;

float temperature;

void setup() {
  Serial.begin(115200);
  pinMode(fan, OUTPUT);
  pinMode(heater, OUTPUT);
}

void loop() {
 if(Serial.available()){
  String command = Serial.readStringUntil(':');
  Serial.println("Command: " + command);
  String state = Serial.readStringUntil('\n');
  Serial.println("State: " + state);

  if(command=="Temperature"){
    temperature = state.toFloat();
    Serial.println(temperature);
      if(temperature>24){
        digitalWrite(fan, 1);
        digitalWrite(heater, 0);
      }
      else if(state == "off"){
        digitalWrite(fan, 0);
        digitalWrite(heater, 0);
      }
      else{
        digitalWrite(fan, 0);
        digitalWrite(heater, 1);
      }
    }
    if(command=="Fan"){
      if(state=="off"){
        digitalWrite(fan, 0);
      }
      if(state=="on"){
        digitalWrite(fan, 1);
      }
    }
    if(command == "Heat"){
      if(state=="off"){
        digitalWrite(heater, 0);
      }
      if(state=="on"){
        digitalWrite(heater, 1);
      }
    }
  }
}
