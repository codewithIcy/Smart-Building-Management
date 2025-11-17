const int fan = 2;
const int heater = 3;
bool status = true;

float temperature;

void setup() {
  Serial.begin(115200);
  pinMode(fan, OUTPUT);
  pinMode(heater, OUTPUT);

  digitalWrite(fan, LOW);
  digitalWrite(heater, LOW);
  
  Serial.println("System Ready - Auto Mode");
}

void loop() {
  if(Serial.available() > 0) {
    String command = Serial.readStringUntil(':');
    String state = Serial.readStringUntil('\n');
    

    command.trim();
    state.trim();
    
    Serial.println("Command: " + command);
    Serial.println("State: " + state);
    Serial.print("Mode: ");
    Serial.println(status ? "Auto" : "Manual");
    

    if((command == "Temperature") && (status == true)) {
      temperature = state.toFloat();
      Serial.print("Temp: ");
      Serial.println(temperature);
      
      if(temperature > 24) {
        digitalWrite(fan, HIGH);
        digitalWrite(heater, LOW);
        Serial.println("Fan ON, Heater OFF");
      }
      else if(temperature < 20) { 
        digitalWrite(fan, LOW);
        digitalWrite(heater, HIGH);
        Serial.println("Fan OFF, Heater ON");
      }
      else {
        digitalWrite(fan, LOW);
        digitalWrite(heater, LOW);
        Serial.println("Both OFF");
      }
    }
    

    if(command == "Fan") {
      status = false;
      if(state == "off") {
        digitalWrite(fan, LOW);
        Serial.println("Fan manually turned OFF");
      }
      else if(state == "on") { 
        digitalWrite(fan, HIGH);
        Serial.println("Fan manually turned ON");
      }
    }

    if(command == "Heater") {
      status = false;
      if(state == "off") {
        digitalWrite(heater, LOW);
        Serial.println("Heater manually turned OFF");
      }
      else if(state == "on") {
        digitalWrite(heater, HIGH);
        Serial.println("Heater manually turned ON");
      }
    }
    

    if(command == "Mode") {
      if(state == "Auto" || state == "auto") {
        status = true;
        Serial.println("Switched to Auto Mode");
      }
      else if(state == "Manual" || state == "manual") {
        status = false;
        Serial.println("Switched to Manual Mode");
      }
    }
  }
}