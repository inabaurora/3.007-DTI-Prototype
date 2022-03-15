#include <Adafruit_NeoPixel.h>
#include <light_CD74HC4067.h>

//neopixel output
#define PIN 9
#define LEDS 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

//multiplexer control pins
CD74HC4067 mux(10, 11, 12, 13);  // create a new CD74HC4067 object with its four control pins

const int signal_pin = A0; // select a pin to share with the 16 channels of the CD74HC4067

//constants for power supply/resistance
const float VCC = 5.0;
const float R_DIV = 3300.0;

class Strip
{
public:
  uint8_t   effect;
  uint8_t   effects;
  uint16_t  effStep;
  unsigned long effStart;
  Adafruit_NeoPixel strip;
  Strip(uint16_t leds, uint8_t pin, uint8_t toteffects, uint16_t striptype) : strip(leds, pin, striptype) {
    effect = -1;
    effects = toteffects;
    Reset();
  }
  void Reset(){
    effStep = 0;
    effect = (effect + 1) % effects;
    effStart = millis();
  }
};

struct Loop
{
  uint8_t currentChild;
  uint8_t childs;
  bool timeBased;
  uint16_t cycles;
  uint16_t currentTime;
  Loop(uint8_t totchilds, bool timebased, uint16_t tottime) {currentTime=0;currentChild=0;childs=totchilds;timeBased=timebased;cycles=tottime;}
};

Strip strip_0(107, 8, 107, NEO_GRB + NEO_KHZ800);
struct Loop strip0loop0(1, false, 1);

void setup()
{ 
  //initialize analog input
  Serial.begin(9600);
  pinMode(signal_pin, INPUT);

  //initialize neopixel display
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'

  strip_0.strip.begin();
}

void loop()
{
  strips_loop();
  //algorithm

  //assign all analog readings to a variable
  
  mux.channel(0);
  int val_1 = analogRead(signal_pin);
  Serial.println("Channel "+String(0)+": "+String(val_1));
  
  mux.channel(1);
  int val_2 = analogRead(signal_pin);
  Serial.println("Channel "+String(1)+": "+String(val_2));
  
  mux.channel(2);
  int val_3 = analogRead(signal_pin);
  Serial.println("Channel "+String(2)+": "+String(val_3));
  
  mux.channel(3);
  int val_4 = analogRead(signal_pin);
  Serial.println("Channel "+String(3)+": "+String(val_4));
  
  mux.channel(4);
  int val_5 = analogRead(signal_pin);
  Serial.println("Channel "+String(4)+": "+String(val_5));
  
  mux.channel(5);
  int val_6 = analogRead(signal_pin);
  Serial.println("Channel "+String(5)+": "+String(val_6));
    
  mux.channel(6);
  int val_7 = analogRead(signal_pin);
  Serial.println("Channel "+String(6)+": "+String(val_7));
  
  mux.channel(7);
  int val_8 = analogRead(signal_pin);
  Serial.println("Channel "+String(7)+": "+String(val_8));
  
  mux.channel(8);
  int val_9 = analogRead(signal_pin);
  Serial.println("Channel "+String(8)+": "+String(val_9));
  
  mux.channel(9);
  int val_10 = analogRead(signal_pin);
  Serial.println("Channel "+String(9)+": "+String(val_10));
  
  mux.channel(10);
  int val_11 = analogRead(signal_pin);
  Serial.println("Channel "+String(10)+": "+String(val_11));
  
  mux.channel(11);
  int val_12 = analogRead(signal_pin);
  Serial.println("Channel "+String(11)+": "+String(val_12));

  //set delay
  delay(50);

  // do the work boys
  // works up to ALL POSSIBLE variable inputs!
  // assumes green seats taken up as priority
  
  if (val_1 > 30)
  {
    strip.setPixelColor(0, 255, 172, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 0, 255, 0);
    strip.setPixelColor(3, 255, 0, 0);
    strip.setPixelColor(4, 0, 255, 0);
    strip.setPixelColor(5, 0, 0, 255);
    strip.setPixelColor(6, 0, 255, 0);
    strip.setPixelColor(7, 0, 0, 255);
    strip.setPixelColor(8, 0, 0, 255);
    strip.setPixelColor(9, 0, 0, 255);
    strip.setPixelColor(10, 0, 0, 255);
    strip.setPixelColor(11, 0, 0, 255);
    strip.show();
    
    if (val_3 > 30)
    {
      strip.setPixelColor(2, 255, 172, 0);
      strip.setPixelColor(5, 255, 0, 0);
      strip.setPixelColor(8, 0, 255, 0);
      strip.show();

      if (val_5 > 30)
      {
        strip.setPixelColor(4, 255, 172, 0);
        strip.setPixelColor(7, 255, 0, 0);
        strip.setPixelColor(10, 0, 255, 0);
        strip.show();

        if (val_7 > 30)
        {
          strip.setPixelColor(6, 255, 172, 0);
          strip.setPixelColor(9, 255, 0, 0);
          strip.show();

          if (val_9 > 30)
          {
            strip.setPixelColor(8, 255, 172, 0);
            strip.setPixelColor(11, 255, 0, 0);
            strip.show();

            if (val_11 > 30)
            {
              strip.setPixelColor(10, 255, 172, 0);
              strip.show();
            }
          }

          else if (val_11 > 30)
          {
            strip.setPixelColor(10, 255, 172, 0);
            strip.setPixelColor(11, 255, 0, 0);
            strip.show();
          }
        }

        else if (val_9 > 30)
        {
          strip.setPixelColor(8, 255, 172, 0);
          strip.setPixelColor(11, 255, 0, 0);
          strip.show();

          if (val_11 > 30)
          {
            strip.setPixelColor(9, 255, 0, 0);
            strip.setPixelColor(10, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_11 > 30)
        {
          strip.setPixelColor(9, 255, 0, 0);
          strip.setPixelColor(10, 255, 172, 0);
          strip.setPixelColor(11, 255, 0, 0);
          strip.show();
        }
      }

      else if (val_7 > 30)
      {
        strip.setPixelColor(6, 255, 172, 0);
        strip.setPixelColor(7, 255, 0, 0);
        strip.setPixelColor(9, 255, 0, 0);
        strip.setPixelColor(10, 0, 255, 0);
        strip.show();

        if (val_9 > 30)
        {
          strip.setPixelColor(8, 255, 172, 0);
          strip.setPixelColor(11, 255, 0, 0);
          strip.show();

          if (val_11 > 30)
          {
            strip.setPixelColor(10, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_11 > 30)
        {
          strip.setPixelColor(10, 255, 172, 0);
          strip.setPixelColor(11, 255, 0, 0);
          strip.show();
        }
      }

      else if (val_9 > 30)
      {
        strip.setPixelColor(7, 255, 0, 0);
        strip.setPixelColor(8, 255, 172, 0);
        strip.setPixelColor(10, 0, 255, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();

        if (val_11 > 30)
        {
          strip.setPixelColor(9, 255, 0, 0);
          strip.setPixelColor(10, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_11 > 30)
      {
        strip.setPixelColor(7, 255, 0, 0);
        strip.setPixelColor(9, 255, 0, 0);
        strip.setPixelColor(10, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();
      }
    }
    
    else if (val_5 > 30)
    {
      strip.setPixelColor(2, 0, 255, 0);
      strip.setPixelColor(4, 255, 172, 0);
      strip.setPixelColor(5, 255, 0, 0);
      strip.setPixelColor(7, 255, 0, 0);
      strip.setPixelColor(8, 0, 255, 0);
      strip.setPixelColor(10, 0, 255, 0);
      strip.show();

      if (val_7 > 30)
      {
        strip.setPixelColor(6, 255, 172, 0);
        strip.setPixelColor(9, 255, 0, 0);
        strip.show();

        if (val_9 > 30)
        {
          strip.setPixelColor(8, 255, 172, 0);
          strip.setPixelColor(11, 255, 0, 0);
          strip.show();

          if (val_11 > 30)
          {
            strip.setPixelColor(10, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_11 > 30)
        {
          strip.setPixelColor(10, 255, 172, 0);
          strip.setPixelColor(11, 255, 0, 0);
          strip.show();
        }
      }

      else if (val_9 > 30)
      {
        strip.setPixelColor(8, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();

        if (val_11 > 30)
        {
          strip.setPixelColor(9, 255, 0, 0);
          strip.setPixelColor(10, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_11 > 30)
      {
        strip.setPixelColor(9, 255, 0, 0);
        strip.setPixelColor(10, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();
      }
    }
    
    else if (val_7 > 30)
    {
      strip.setPixelColor(6, 255, 172, 0);
      strip.setPixelColor(7, 255, 0, 0);
      strip.setPixelColor(8, 0, 255, 0);
      strip.setPixelColor(9, 255, 0, 0);
      strip.setPixelColor(10, 0, 255, 0);
      strip.show();

      if (val_9 > 30)
      {
        strip.setPixelColor(5, 255, 0, 0);
        strip.setPixelColor(8, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();

        if (val_11 > 30)
        {
          strip.setPixelColor(10, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_11 > 30)
      {
        strip.setPixelColor(10, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();
      }
    }

    else if (val_9 > 30)
    {
      strip.setPixelColor(5, 255, 0, 0);
      strip.setPixelColor(7, 255, 0, 0);
      strip.setPixelColor(8, 255, 172, 0);
      strip.setPixelColor(10, 0, 255, 0);
      strip.setPixelColor(11, 255, 0, 0);
      strip.show();

      if (val_11 > 30)
      {
        strip.setPixelColor(9, 255, 0, 0);
        strip.setPixelColor(10, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_11 > 30)
    {
      strip.setPixelColor(7, 255, 0, 0);
      strip.setPixelColor(8, 0, 255, 0);
      strip.setPixelColor(9, 255, 0, 0);
      strip.setPixelColor(10, 255, 172, 0);
      strip.setPixelColor(11, 255, 0, 0);
      strip.show();
    }
  }

  else if (val_2 > 30)
  {
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 255, 172, 0);
    strip.setPixelColor(2, 255, 0, 0);
    strip.setPixelColor(3, 0, 255, 0);
    strip.setPixelColor(4, 255, 0, 0);
    strip.setPixelColor(5, 0, 255, 0);
    strip.setPixelColor(6, 0, 0, 255);
    strip.setPixelColor(7, 0, 255, 0);
    strip.setPixelColor(8, 0, 0, 255);
    strip.setPixelColor(9, 0, 0, 255);
    strip.setPixelColor(10, 0, 0, 255);
    strip.setPixelColor(11, 0, 0, 255);
    strip.show();

    if (val_4 > 30)
    {
      strip.setPixelColor(3, 255, 172, 0);
      strip.setPixelColor(6, 255, 0, 0);
      strip.setPixelColor(9, 0, 255, 0);
      strip.show();

      if (val_6 > 30)
      {
        strip.setPixelColor(5, 255, 172, 0);
        strip.setPixelColor(8, 255, 0, 0);
        strip.setPixelColor(11, 0, 255, 0);
        strip.show();

        if (val_8 > 30)
        {
          strip.setPixelColor(7, 255, 172, 0);
          strip.setPixelColor(10, 255, 0, 0);
          strip.show();

          if (val_10 > 30)
          {
            strip.setPixelColor(9, 255, 172, 0);
            strip.show();

            if (val_12 > 30)
            {
              strip.setPixelColor(11, 255, 172, 0);
              strip.show();
            }
          }

          else if (val_12 > 30)
          {
            strip.setPixelColor(11, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_10 > 30)
        {
          strip.setPixelColor(9, 255, 172, 0);
          strip.setPixelColor(10, 255, 0, 0);
          strip.show();

          if (val_12 > 30)
          {
            strip.setPixelColor(11, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_12 > 30)
        {
          strip.setPixelColor(10, 255, 0, 0);
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_8 > 30)
      {
        strip.setPixelColor(7, 255, 172, 0);
        strip.setPixelColor(8, 255, 0, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.setPixelColor(11, 0, 255, 0);
        strip.show();

        if (val_10 > 30)
        {
          strip.setPixelColor(9, 255, 172, 0);
          strip.show();

          if (val_12 > 30)
          {
            strip.setPixelColor(11, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_12 > 30)
        {
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_10 > 30)
      {
        strip.setPixelColor(9, 255, 172, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.setPixelColor(11, 0, 255, 0);
        strip.show();

        if (val_12 > 30)
        {
          strip.setPixelColor(8, 255, 0, 0);
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_12 > 30)
      {
        strip.setPixelColor(8, 255, 0, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_6 > 30)
    {
      strip.setPixelColor(5, 255, 172, 0);
      strip.setPixelColor(8, 255, 0, 0);
      strip.setPixelColor(11, 0, 255, 0);
      strip.show();

      if (val_8 > 30)
      {
        strip.setPixelColor(6, 255, 0, 0);
        strip.setPixelColor(7, 255, 172, 0);
        strip.setPixelColor(9, 0, 255, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.show();

        if (val_10 > 30)
        {
          strip.setPixelColor(9, 255, 172, 0);
          strip.show();

          if (val_12 > 30)
          {
            strip.setPixelColor(11, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_12 > 30)
        {
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_10 > 30)
      { 
        strip.setPixelColor(6, 255, 0, 0);
        strip.setPixelColor(9, 255, 172, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.show();

        if (val_12 > 30)
        {
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_12 > 30)
      {
        strip.setPixelColor(9, 0, 255, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_8 > 30)
    {
      strip.setPixelColor(6, 255, 0, 0);
      strip.setPixelColor(7, 255, 172, 0);
      strip.setPixelColor(8, 255, 0, 0);
      strip.setPixelColor(9, 0, 255, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.setPixelColor(11, 0, 255, 0);
      strip.show();

      if (val_10 > 30)
      {
        strip.setPixelColor(9, 255, 172, 0);
        strip.show();

        if (val_12 > 30)
        {
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_12 > 30)
      {
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_10 > 30)
    {
      strip.setPixelColor(6, 255, 0, 0);
      strip.setPixelColor(9, 255, 172, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.setPixelColor(11, 0, 255, 0);
      strip.show();

      if (val_12 > 30)
      {
        strip.setPixelColor(8, 255, 0, 0);
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_12 > 30)
    {
      strip.setPixelColor(8, 255, 0, 0);
      strip.setPixelColor(9, 0, 255, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.setPixelColor(11, 255, 172, 0);
      strip.show();
    }
  }

  else if (val_3 > 30)
  {
    strip.setPixelColor(0, 0, 255, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 255, 172, 0);
    strip.setPixelColor(3, 0, 0, 255);
    strip.setPixelColor(4, 0, 255, 0);
    strip.setPixelColor(5, 255, 0, 0);
    strip.setPixelColor(6, 0, 0, 255);
    strip.setPixelColor(7, 0, 0, 255);
    strip.setPixelColor(8, 0, 255, 0);
    strip.setPixelColor(9, 0, 0, 255);
    strip.setPixelColor(10, 0, 0, 255);
    strip.setPixelColor(11, 0, 0, 255);
    strip.show();

    if (val_5 > 30)
    {
      strip.setPixelColor(3, 255, 0, 0);
      strip.setPixelColor(4, 255, 172, 0);
      strip.setPixelColor(6, 0, 255, 0);
      strip.setPixelColor(7, 255, 0, 0);
      strip.setPixelColor(10, 0, 255, 0);
      strip.show();

      if (val_7 > 30)
      {
        strip.setPixelColor(6, 255, 172, 0);
        strip.setPixelColor(9, 255, 0, 0);
        strip.show(); 

        if (val_9 > 30)
        {
          strip.setPixelColor(8, 255, 172, 0);
          strip.setPixelColor(11, 255, 0, 0);
          strip.show();

          if (val_11 > 30)
          {
            strip.setPixelColor(10, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_11 > 30)
        {
          strip.setPixelColor(10, 255, 172, 0);
          strip.setPixelColor(11, 255, 0, 0);
          strip.show();
        }
      }

      else if (val_9 > 30)
      {
        strip.setPixelColor(8, 255,172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();

        if (val_11 > 30)
        {
          strip.setPixelColor(9, 255, 0, 0);
          strip.setPixelColor(10, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_11 > 30)
      {
        strip.setPixelColor(9, 255, 0, 0);
        strip.setPixelColor(10, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();
      }
    }

    else if (val_7 > 30)
    {
      strip.setPixelColor(3, 255, 0, 0);
      strip.setPixelColor(6, 255, 172, 0);
      strip.setPixelColor(7, 255, 0, 0);
      strip.setPixelColor(9, 255, 0, 0);
      strip.setPixelColor(10, 0, 255, 0);
      strip.show();

      if (val_9 > 30)
      {
        strip.setPixelColor(8, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();

        if (val_11 > 30)
        {
          strip.setPixelColor(10, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_11 > 30)
      {
        strip.setPixelColor(10, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();
      }
    }

    else if (val_9 > 30)
    {
      strip.setPixelColor(6, 0, 255, 0);
      strip.setPixelColor(7, 255, 0, 0);
      strip.setPixelColor(8, 255, 172, 0);
      strip.setPixelColor(10, 0, 255, 0);
      strip.setPixelColor(11, 255, 0, 0);
      strip.show();

      if (val_11 > 30)
      {
        strip.setPixelColor(9, 255, 0, 0);
        strip.setPixelColor(10, 255, 172, 0);
        strip.show(); 
      }
    }

    else if (val_11 > 30)
    {
      strip.setPixelColor(6, 0, 255, 0);
      strip.setPixelColor(7, 255, 0, 0);
      strip.setPixelColor(9, 255, 0, 0);
      strip.setPixelColor(10, 255, 172, 0);
      strip.setPixelColor(11, 255, 0, 0);
      strip.show();
    }
  }

  else if (val_4 > 30)
  {
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 0, 255, 0);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(3, 255, 172, 0);
    strip.setPixelColor(4, 255, 0, 0);
    strip.setPixelColor(5, 0, 255, 0);
    strip.setPixelColor(6, 255, 0, 0);
    strip.setPixelColor(7, 0, 255, 0);
    strip.setPixelColor(8, 0, 0, 255);
    strip.setPixelColor(9, 0, 255, 0);
    strip.setPixelColor(10, 0, 0, 255);
    strip.setPixelColor(11, 0, 0, 255);
    strip.show();

    if (val_6 > 30)
    {
      strip.setPixelColor(2, 255, 0, 0);
      strip.setPixelColor(5, 255, 172, 0);
      strip.setPixelColor(8, 255, 0, 0);
      strip.setPixelColor(11, 0, 255, 0);
      strip.show();

      if (val_8 > 30)
      {
        strip.setPixelColor(7, 255, 172, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.show();

        if (val_10 > 30)
        {
          strip.setPixelColor(9, 255, 172, 0);
          strip.show();

          if (val_12 > 30)
          {
            strip.setPixelColor(11, 255, 172, 0);
            strip.show();
          }
        }

        else if (val_12 > 30)
        {
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_10 > 30)
      {
        strip.setPixelColor(9, 255, 172, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.setPixelColor(11, 0, 255, 0);
        strip.show();

        if (val_12 > 30)
        {
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_12 > 30)
      {
        strip.setPixelColor(8, 255, 0, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_8 > 30)
    {
      strip.setPixelColor(7, 255, 172, 0);
      strip.setPixelColor(8, 255, 0, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.setPixelColor(11, 0, 255, 0);
      strip.show();

      if (val_10 > 30)
      {
        strip.setPixelColor(9, 255, 172, 0);
        strip.show();

        if (val_12 > 30)
        {
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_12 > 30)
      {
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_10 > 30)
    {
      strip.setPixelColor(9, 255, 172, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.setPixelColor(11, 0, 255, 0);
      strip.show();

      if (val_12 > 30)
      {
        strip.setPixelColor(8, 255, 0, 0);
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_12 > 30)
    {
      strip.setPixelColor(8, 255, 0, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.setPixelColor(11, 255, 172, 0);
      strip.show();
    }
  }

  else if (val_5 > 30)
  {
    strip.setPixelColor(0, 0, 255, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 0, 255, 0);
    strip.setPixelColor(3, 255, 0, 0);
    strip.setPixelColor(4, 255, 172, 0);
    strip.setPixelColor(5, 255, 0, 0);
    strip.setPixelColor(6, 0, 255, 0);
    strip.setPixelColor(7, 255, 0, 0);
    strip.setPixelColor(8, 0, 255, 0);
    strip.setPixelColor(9, 0, 0, 255);
    strip.setPixelColor(10, 0, 255, 0);
    strip.setPixelColor(11, 0, 0, 255);
    strip.show();

    if (val_7 > 30)
    {
      strip.setPixelColor(6, 255, 172, 0);
      strip.setPixelColor(9, 255, 0, 0);
      strip.show();

      if (val_9 > 30)
      {
        strip.setPixelColor(8, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();

        if (val_11 > 30)
        {
          strip.setPixelColor(10, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_11 > 30)
      {
        strip.setPixelColor(10, 255, 172, 0);
        strip.setPixelColor(11, 255, 0, 0);
        strip.show();
      }
    }

    else if (val_9 > 30)
    {
      strip.setPixelColor(8, 255, 172, 0);
      strip.setPixelColor(11, 255, 0, 0);
      strip.show();

      if (val_11 > 30)
      {
        strip.setPixelColor(9, 255, 0, 0);
        strip.setPixelColor(10, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_11 > 30)
    {
      strip.setPixelColor(9, 255, 0, 0);
      strip.setPixelColor(10, 255, 172, 0);
      strip.setPixelColor(11, 255, 0, 0);
      strip.show();
    }
  }
  
  else if (val_6 > 30)
  {
    strip.setPixelColor(0, 0, 0, 255);
    strip.setPixelColor(1, 0, 255, 0);
    strip.setPixelColor(2, 255, 0, 0);
    strip.setPixelColor(3, 0, 255, 0);
    strip.setPixelColor(4, 255, 0, 0);
    strip.setPixelColor(5, 255, 172, 0);
    strip.setPixelColor(6, 0, 0, 255);
    strip.setPixelColor(7, 0, 255, 0);
    strip.setPixelColor(8, 255, 0, 0);
    strip.setPixelColor(9, 0, 0, 255);
    strip.setPixelColor(10, 0, 0, 255);
    strip.setPixelColor(11, 0, 255, 0);
    strip.show();

    if (val_8 > 30)
    {
      strip.setPixelColor(6, 255, 0, 0);
      strip.setPixelColor(7, 255, 172, 0);
      strip.setPixelColor(9, 0, 255, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.show();

      if (val_10 > 30)
      {
        strip.setPixelColor(9, 255, 172, 0);
        strip.show();

        if (val_12 > 30)
        {
          strip.setPixelColor(11, 255, 172, 0);
          strip.show();
        }
      }

      else if (val_12 > 30)
      {
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_10 > 30)
    {
      strip.setPixelColor(6, 255, 0, 0);
      strip.setPixelColor(9, 255, 172, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.show();

      if (val_12 > 30)
      {
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_12 > 30)
    {
      strip.setPixelColor(9, 0, 255, 0);
      strip.setPixelColor(10, 255, 0, 0);
      strip.setPixelColor(11, 255, 172, 0);
      strip.show();
    }
  }

  else if (val_7 > 30)
  {
    strip.setPixelColor(0, 0, 255, 0);
    strip.setPixelColor(1, 0, 0, 255);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(3, 255, 0, 0);
    strip.setPixelColor(4, 0, 255, 0);
    strip.setPixelColor(5, 0, 0, 255);
    strip.setPixelColor(6, 255, 172, 0);
    strip.setPixelColor(7, 255, 0, 0);
    strip.setPixelColor(8, 0, 255, 0);
    strip.setPixelColor(9, 255, 0, 0);
    strip.setPixelColor(10, 0, 255, 0);
    strip.setPixelColor(11, 0, 0, 255);
    strip.show();

    if (val_9 > 30)
    {
      strip.setPixelColor(2, 0, 255, 0);
      strip.setPixelColor(5, 255, 0, 0);
      strip.setPixelColor(8, 255, 172, 0);
      strip.setPixelColor(11, 255, 0, 0);
      strip.show();

      if (val_11 > 30)
      {
        strip.setPixelColor(10, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_11 > 30)
    {
      strip.setPixelColor(10, 255, 172, 0);
      strip.setPixelColor(11, 255, 0, 0);
      strip.show();
    }
  }

  else if (val_8 > 30)
  {
    strip.setPixelColor(0, 0, 0, 255);
    strip.setPixelColor(1, 0, 255, 0);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(3, 0, 255, 0);
    strip.setPixelColor(4, 255, 0, 0);
    strip.setPixelColor(5, 0, 255, 0);
    strip.setPixelColor(6, 255, 0, 0);
    strip.setPixelColor(7, 255, 172, 0);
    strip.setPixelColor(8, 255, 0, 0);
    strip.setPixelColor(9, 0, 255, 0);
    strip.setPixelColor(10, 255, 0, 0);
    strip.setPixelColor(11, 0, 255, 0);
    strip.show();

    if (val_10 > 30)
    {
      strip.setPixelColor(9, 255, 172, 0);
      strip.show();

      if (val_12 > 30)
      {
        strip.setPixelColor(11, 255, 172, 0);
        strip.show();
      }
    }

    else if (val_12 > 30)
    {
      strip.setPixelColor(11, 255, 172, 0);
      strip.show();
    }
  }

  else if (val_9 > 30)
  {
    strip.setPixelColor(0, 0, 0, 255);
    strip.setPixelColor(1, 0, 0, 255);
    strip.setPixelColor(2, 0, 255, 0);
    strip.setPixelColor(3, 0, 0, 255);
    strip.setPixelColor(4, 0, 255, 0);
    strip.setPixelColor(5, 255, 0, 0);
    strip.setPixelColor(6, 0, 255, 0);
    strip.setPixelColor(7, 255, 0, 0);
    strip.setPixelColor(8, 255, 172, 0);
    strip.setPixelColor(9, 0, 0, 255);
    strip.setPixelColor(10, 0, 255, 0);
    strip.setPixelColor(11, 255, 0, 0);
    strip.show();

    if (val_11 > 30)
    {
      strip.setPixelColor(9, 255, 0, 0);
      strip.setPixelColor(10, 255, 172, 0);
      strip.show();
    }
  }

  else if (val_10 > 30)
  {
    strip.setPixelColor(0, 0, 0, 255);
    strip.setPixelColor(1, 0, 0, 255);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(3, 0, 255, 0);
    strip.setPixelColor(4, 0, 0, 255);
    strip.setPixelColor(5, 0, 0, 255);
    strip.setPixelColor(6, 255, 0, 0);
    strip.setPixelColor(7, 0, 255, 0);
    strip.setPixelColor(8, 0, 0, 255);
    strip.setPixelColor(9, 255, 172, 0);
    strip.setPixelColor(10, 255, 0, 0);
    strip.setPixelColor(11, 0, 255, 0);
    strip.show();

    if (val_12 > 30)
    {
      strip.setPixelColor(5, 0, 255, 0);
      strip.setPixelColor(8, 255, 0, 0);
      strip.setPixelColor(11, 255, 172, 0);
      strip.show();
    }
  }

  else if (val_11 > 30)
  {
    strip.setPixelColor(0, 0, 0, 255);
    strip.setPixelColor(1, 0, 0, 255);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(3, 0, 0, 255);
    strip.setPixelColor(4, 0, 255, 0);
    strip.setPixelColor(5, 0, 0, 255);
    strip.setPixelColor(6, 0, 255, 0);
    strip.setPixelColor(7, 255, 0, 0);
    strip.setPixelColor(8, 0, 255, 0);
    strip.setPixelColor(9, 255, 0, 0);
    strip.setPixelColor(10, 255, 172, 0);
    strip.setPixelColor(11, 255, 0, 0);
    strip.show();
  }

  else if (val_12 > 30)
  {
    strip.setPixelColor(0, 0, 0, 255);
    strip.setPixelColor(1, 0, 0, 255);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(3, 0, 0, 255);
    strip.setPixelColor(4, 0, 0, 255);
    strip.setPixelColor(5, 0, 255, 0);
    strip.setPixelColor(6, 0, 0, 255);
    strip.setPixelColor(7, 0, 255, 0);
    strip.setPixelColor(8, 255, 0, 0);
    strip.setPixelColor(9, 0, 255, 0);
    strip.setPixelColor(10, 255, 0, 0);
    strip.setPixelColor(11, 255, 172, 0);
    strip.show();
  }

  else
  {
    strip.setPixelColor(0, 0, 0, 255);
    strip.setPixelColor(1, 0, 0, 255);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(3, 0, 0, 255);
    strip.setPixelColor(4, 0, 0, 255);
    strip.setPixelColor(5, 0, 0, 255);
    strip.setPixelColor(6, 0, 0, 255);
    strip.setPixelColor(7, 0, 0, 255);
    strip.setPixelColor(8, 0, 0, 255);
    strip.setPixelColor(9, 0, 0, 255);
    strip.setPixelColor(10, 0, 0, 255);
    strip.setPixelColor(11, 0, 0, 255);
    strip.show();
  }
}

void strips_loop() {
  if(strip0_loop0() & 0x01)
    strip_0.strip.show();
}

uint8_t strip0_loop0() {
  uint8_t ret = 0x00;
  switch(strip0loop0.currentChild) {
    case 0: 
           ret = strip0_loop0_eff0();break;
  }
  if(ret & 0x02) {
    ret &= 0xfd;
    if(strip0loop0.currentChild + 1 >= strip0loop0.childs) {
      strip0loop0.currentChild = 0;
      if(++strip0loop0.currentTime >= strip0loop0.cycles) {strip0loop0.currentTime = 0; ret |= 0x02;}
    }
    else {
      strip0loop0.currentChild++;
    }
  };
  return ret;
}

uint8_t strip0_loop0_eff0() {
    // Strip ID: 0 - Effect: Rainbow - LEDS: 107
    // Steps: 107 - Delay: 20
    // Colors: 3 (255.0.0, 0.255.0, 0.0.255)
    // Options: rainbowlen=107, toLeft=true, 
  if(millis() - strip_0.effStart < 20 * (strip_0.effStep)) return 0x00;
  float factor1, factor2;
  uint16_t ind;
  for(uint16_t j=0;j<107;j++) {
    ind = strip_0.effStep + j * 1;
    switch((int)((ind % 107) / 36)) {
      case 0: factor1 = 1.0 - ((float)(ind % 107 - 0 * 36) / 36);
              factor2 = (float)((int)(ind - 0) % 107) / 36;
              strip_0.strip.setPixelColor(j, 255 * factor1 + 0 * factor2, 0 * factor1 + 255 * factor2, 0 * factor1 + 0 * factor2);
              break;
      case 1: factor1 = 1.0 - ((float)(ind % 107 - 1 * 36) / 36);
              factor2 = (float)((int)(ind - 36) % 107) / 36;
              strip_0.strip.setPixelColor(j, 0 * factor1 + 0 * factor2, 255 * factor1 + 0 * factor2, 0 * factor1 + 255 * factor2);
              break;
      case 2: factor1 = 1.0 - ((float)(ind % 107 - 2 * 36) / 36);
              factor2 = (float)((int)(ind - 72) % 107) / 36;
              strip_0.strip.setPixelColor(j, 0 * factor1 + 255 * factor2, 0 * factor1 + 0 * factor2, 255 * factor1 + 0 * factor2);
              break;
    }
  }
  if(strip_0.effStep >= 107) {strip_0.Reset(); return 0x03; }
  else strip_0.effStep++;
  return 0x01;
}
