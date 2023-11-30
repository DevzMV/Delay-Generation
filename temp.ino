#include <TimerOne.h>
void Timer1_ISR(void)
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void setup() {
  Serial.begin(9600);
  pinMode (A0, INPUT);  /*LM35 pin*/ 
  pinMode(LED_BUILTIN, OUTPUT); /*LED_BULTIN=13*/

}

void loop() {
  int tempAdc;
  float temp;
  tempAdc = analogRead(A0);  /* Read Temperature */
  temp = (tempAdc* 4.88); /* Convert adc value to equivalent voltage */
  temp = (temp/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print(" Degree Celsius\n");
  if(temp>30)
  {
  Timer1.initialize(500000);// An Interrupt Every 500ms
  Timer1.attachInterrupt(Timer1_ISR);
  }
  if(temp<30)
  {
   Timer1.initialize(250000);// An Interrupt Every 250ms
  Timer1.attachInterrupt(Timer1_ISR);
  }
}
