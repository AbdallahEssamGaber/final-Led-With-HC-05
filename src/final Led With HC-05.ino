#define red_pin 9
#define green_pin 10
#define blue_pin 11
#define maxNum 255

int color_pin, action_value, changeValue = 80;
String inputBytes;

void setup() {
        pinMode(red_pin, OUTPUT);
        pinMode(green_pin, OUTPUT);
        pinMode(blue_pin, OUTPUT);
        Serial.begin(9600);
}

void loop() {



        if (Serial.available())
        {

                inputBytes = Serial.readString();
                if (inputBytes == "red" || inputBytes == "red on" || inputBytes == "red full" || inputBytes == "Red" || inputBytes == "Red on" || inputBytes == "Red full")
                {
                        color_pin = red_pin;
                        action_value = maxNum;


                } else if (inputBytes == "lighter red" || inputBytes == "Lighter red" || inputBytes == "more red" || inputBytes == "More red")
                {
                        color_pin = red_pin;
                        action_value = action_value + changeValue;
                        if(action_value >= maxNum) action_value = maxNum;


                } else if (inputBytes == "dimmer red" || inputBytes == "Dimmer red" || inputBytes == "Red dimmer" || inputBytes == "Red less" || inputBytes == "red less")
                {
                        Serial.println("dimmer red");

                        color_pin = red_pin;
                        action_value = action_value - changeValue;
                        if(action_value <= 0) action_value = 0;


                } else if (inputBytes == "red off" || inputBytes == "Red off")
                {
                        Serial.println("off");

                        color_pin = red_pin;
                        action_value = 0;


                } else if (inputBytes == "blue" || inputBytes == "blue on" || inputBytes == "blue full" || inputBytes == "Blue" || inputBytes == "Blue on" || inputBytes == "Blue full")
                {
                        color_pin = blue_pin;
                        action_value = maxNum;


                } else if (inputBytes == "lighter blue" || inputBytes == "Lighter blue" || inputBytes == "more blue" || inputBytes == "More blue")
                {
                        color_pin = blue_pin;
                        action_value = action_value + changeValue;
                        if(action_value >= maxNum) action_value = maxNum;


                } else if (inputBytes == "dimmer blue" || inputBytes == "Dimmer blue" || inputBytes == "Blue dimmer" || inputBytes == "Blue less" || inputBytes == "blue less")
                {
                        color_pin = blue_pin;
                        action_value = action_value - changeValue;
                        if(action_value <= 0) action_value = 0;


                } else if (inputBytes == "blue off" || inputBytes == "Blue off")
                {
                        color_pin = blue_pin;
                        action_value = 0;

                }else if (inputBytes == "green" || inputBytes == "green on" || inputBytes == "green full" || inputBytes == "Green" || inputBytes == "Green on" || inputBytes == "Green full")
                {
                        color_pin = green_pin;
                        action_value = maxNum;

                } else if (inputBytes == "lighter green" || inputBytes == "Lighter green" || inputBytes == "more green" || inputBytes == "More green")
                {
                        color_pin = green_pin;
                        action_value = action_value + changeValue;
                        if(action_value >= maxNum) action_value = maxNum;

                } else if (inputBytes == "dimmer green" || inputBytes == "Dimmer green" || inputBytes == "Green dimmer" || inputBytes == "Green less" || inputBytes == "green less")
                {
                        color_pin = green_pin;
                        action_value = action_value - changeValue;
                        if(action_value <= 0) action_value = 0;

                } else if (inputBytes == "green off" || inputBytes == "Green off")
                {
                        color_pin = green_pin;
                        action_value = 0;

                }else if (inputBytes == "all" || inputBytes == "All" || inputBytes == "on all" || inputBytes == "On all" ||  inputBytes == "all on" ||  inputBytes == "All on")
                {
                        action_value = maxNum;
                        analogWrite(blue_pin, action_value);
                        analogWrite(green_pin, action_value);
                        analogWrite(red_pin, action_value);

                } else if (inputBytes == "off all" || inputBytes == "Off all" ||  inputBytes == "all off" ||  inputBytes == "All off")
                {
                        action_value = 0;
                        analogWrite(blue_pin, action_value);
                        analogWrite(green_pin, action_value);
                        analogWrite(red_pin, action_value);

                } else if (inputBytes == "brighter" || inputBytes == "Brighter" || inputBytes == "more" || inputBytes == "More" || inputBytes == "Lighter" || inputBytes == "lighter")
                {
                        action_value = action_value + changeValue;
                        if(action_value >= maxNum) action_value = maxNum;

                }else if (inputBytes == "dimmer" || inputBytes == "Dimmer" || inputBytes == "less" || inputBytes == "Less")
                {

                        action_value = action_value - changeValue;
                        if(action_value <= 0) action_value = 0;

                }else if (inputBytes == "off" || inputBytes == "Off")
                {
                        action_value = 0;
                }else if (inputBytes == "full" || inputBytes == "Full" || inputBytes == "full brightness" || inputBytes == "Full brightness")
                {
                        action_value = maxNum;
                }
                Serial.println(action_value);
                analogWrite(color_pin, action_value);




        }



}
