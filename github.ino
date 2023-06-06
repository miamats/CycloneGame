#include <Adafruit_CircuitPlayground.h>

int count = 0;
//slide switch
const int slideSwitch = 7;
volatile bool switchFlag = 0;
bool switchState = 0;

//button
const int buttonA = 4;
volatile bool buttonFlag = 0;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

  //slide switch
  switchState = digitalRead(slideSwitch);  
  pinMode(slideSwitch,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(slideSwitch), onOff, CHANGE);

  //button
  pinMode(buttonA,INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(buttonA), pressedA, FALLING);
}

void loop() {

CircuitPlayground.setPixelColor(4, 0, 255, 0);
CircuitPlayground.setPixelColor(5, 0, 255, 0);
for (int i = 0; i < 10; i++)
  {
        CircuitPlayground.setPixelColor(i, 0, 0, 255);
        delay (1000);
        CircuitPlayground.setPixelColor(i, 0, 0, 0);
        count = i;
        Serial.println(count);
        CircuitPlayground.setPixelColor(4, 0, 255, 0);
        CircuitPlayground.setPixelColor(5, 0, 255, 0);

        //if player pressess the button
        if(buttonFlag)
          {
            CircuitPlayground.clearPixels();
            delay(1000);
            if(count == 4 || count == 5)
              {
                win(); 
                delay(5000);
              }
            else
              {
                lose();
                delay(5000);
              }      
            CircuitPlayground.clearPixels();
            delay(9000);
            buttonFlag = 0;   
          }
  }
  for (int i = 9; i >= 0; i--)
    {
        CircuitPlayground.setPixelColor(i, 0, 0, 255);
        delay (1000);
        CircuitPlayground.setPixelColor(i, 0, 0, 0);
        count = i;
        Serial.println(count);
        CircuitPlayground.setPixelColor(4, 0, 255, 0);
        CircuitPlayground.setPixelColor(5, 0, 255, 0);

        //player presses the button
        if(buttonFlag)
        {
        CircuitPlayground.clearPixels();
        delay(5000);
        if(count == 4 || count == 5)
          {
          win(); 
          delay(1000);
          }
          else
          {
          lose();
          delay(5000);
          }
          CircuitPlayground.clearPixels();
          delay(9000);      
          buttonFlag = 0;   
        }   
    } 
 
}

//win
void win()
{
  delay(1);
  CircuitPlayground.setPixelColor(0, 0, 255, 0);
  CircuitPlayground.setPixelColor(1, 0, 255, 0);
  CircuitPlayground.setPixelColor(2, 0, 255, 0);
  CircuitPlayground.setPixelColor(3, 0, 255, 0);
  CircuitPlayground.setPixelColor(4, 0, 255, 0);
  CircuitPlayground.setPixelColor(5, 0, 255, 0);
  CircuitPlayground.setPixelColor(6, 0, 255, 0);
  CircuitPlayground.setPixelColor(7, 0, 255, 0);
  CircuitPlayground.setPixelColor(8, 0, 255, 0);
  CircuitPlayground.setPixelColor(9, 0, 255, 0);
}

//lose
void lose()
{
  CircuitPlayground.setPixelColor(0, 255, 0, 0);
  CircuitPlayground.setPixelColor(1, 255, 0, 0);
  CircuitPlayground.setPixelColor(2, 255, 0, 0);
  CircuitPlayground.setPixelColor(3, 255, 0, 0);
  CircuitPlayground.setPixelColor(4, 255, 0, 0);
  CircuitPlayground.setPixelColor(5, 255, 0, 0);
  CircuitPlayground.setPixelColor(6, 255, 0, 0);
  CircuitPlayground.setPixelColor(7, 255, 0, 0);
  CircuitPlayground.setPixelColor(8, 255, 0, 0);
  CircuitPlayground.setPixelColor(9, 255, 0, 0);  
}

void pressedA()
{
  buttonFlag = 1;
}

void onOff()
{
  switchFlag = 1;
}