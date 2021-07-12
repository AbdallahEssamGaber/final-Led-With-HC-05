#define red_pin 9
#define green_pin 10
#define blue_pin 11

int counter, maxNum, color_pin, action_value;
bool maxDone, next;
String maxValue, inputBytes, colorName, action;

void setup() {
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  DoneWMaxBrightness();


  if (maxDone)
  {

    ResetValues();

    if (Serial.available())
    {

      inputBytes = Serial.readString();
      for (counter = 0; counter < inputBytes.length() ; counter++)
      {
        IndentifyInputs();
      }
      Serial.println(action_value);
      Serial.println(color_pin);
    }



    analogWrite(color_pin, action_value);



  }

}



void DoneWMaxBrightness()
{
  if (!maxDone)
  {
    maxValue = Serial.readString();
    maxNum = maxValue.toInt();
  }
  if (maxNum > 1)
  {
    maxDone = true;
  }
}



void ResetValues() {
  colorName = "";
  action = "";
  next = false;
}


void IndentifyInputs()
{

  if (isSpace(inputBytes[0]))
  {
    //todo make it continue if after it is smth valid
    return;
  }
  else if (isSpace(inputBytes[counter]))
  {
    next = true;
  }

  else if (isAlpha(inputBytes[counter]))
  {
    if (!next)
    {
      colorName += (char)inputBytes[counter];
      SortColor(colorName);
    }
    else if (next)
    {
      action += (char)inputBytes[counter];
      MakeAction(action);
    }

  }

}



int SortColor(String colorName)
{

  colorName.toLowerCase();

  switch (colorName) {
    case "red":
      print("tset");
      break;

      case "red":
        print("tset");
        break;
  }

  if (colorName == "red")
  {
    color_pin = red_pin;

  } else if (colorName == "green")
  {
    color_pin = green_pin;

  } else if (colorName == "blue")
  {
    color_pin = blue_pin;

  }else   color_pin = 0;
//todo: map the value 255 max

}



int MakeAction(String action)
{

  action.toLowerCase();

  if (action == "on")
  {
    action_value = maxNum;

  } else if (action == "off")
  {
    action_value = 0;

  } else if (action == "lighter")
  {
    action_value = analogRead(color_pin) + 15;
    if (action_value >= maxNum)   { action_value = maxNum; }

  } else if (action == "dimmer")
  {
    Serial.println("y");
    action_value = analogRead(color_pin) - 15;
    if (action_value <= 0)  { action_value = 0; }

  } else   action_value = 0;



}
