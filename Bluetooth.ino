int sensorValue = 0;
int outputValue = 0;
const int analogInPin = A1;  // Analog input pin that the sensor output is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
void setup() {
Serial.begin(9600);      // value output to the PWM (analog out)
 pinMode(8, OUTPUT); // put your setup code here, to run once:
 digitalWrite(8, HIGH);
 digitalWrite(12, HIGH);
 pinMode(12, OUTPUT);
 pinMode(3,OUTPUT);
}
void loop() {
 if(Serial.available()>0)
   {
      char data= Serial.read(); // reading the data received from the bluetooth module


      switch(data)
      {
        //pumps canna A
        case '1': digitalWrite(8, HIGH); digitalWrite(12,HIGH); Serial.println("PUMPS STOPED");break; // when a is pressed on the app on your smart phone
        case '2': digitalWrite(8, LOW);Serial.println("PUMP  A STARTED 30ml Dose"); delay(28450); digitalWrite(8, HIGH);  break; // when d is pressed on the app on your smart phone
        case '3': digitalWrite(8, LOW);Serial.println("PUMP  A STARTED 15ml Dose"); delay(14225); digitalWrite(8, HIGH);  break;
        case '4': digitalWrite(12, LOW);Serial.println("PUMP  B STARTED 30ml Dose"); delay(28450); digitalWrite(12, HIGH);  break; // when d is pressed on the app on your smart phone
        case '5': digitalWrite(12, LOW);Serial.println("PUMP  B STARTED 15ml Dose"); delay(14225); digitalWrite(12, HIGH);  break;

       //Probe code Analogue input delays 0.4s
        case 'p': for (int x=0; x<15;x++) {sensorValue = analogRead(analogInPin);
         //outputValue = map(sensorValue, 0, 1023, 0, 5000);
         //analogWrite(analogOutPin, outputValue);

         Serial.print("sensor = " );
         Serial.print(sensorValue);
         Serial.print("\t EC (mS) = ");
         Serial.println(analogRead(1)* 5.00 / 1024, 2);
         delay(400);
            }
        break; // when d is pressed on the app on your smart phone
        case 'h': Serial.println("--------------------------------\nHELP MENU\n--------------------------------\n1. Stop Pumps \n \n2. Start Pump Canna A 30mL dose \n3. Start Pump Canna A 15mL dose\n4. Start Pump Canna B 30mL\n5. Start Pump Canna B 15mL \np. Probe on \n--------------------------------\n");break; // when d is pressed on the app on your smart phone
        default : break;
      }
      //Serial.println(data);
   }
   delay(50);
}
