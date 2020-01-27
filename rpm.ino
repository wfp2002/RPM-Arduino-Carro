//#include <liquidcrystal_i2c .h="">

//#include <wire .h="">
//int pinoSensor = 0; //pino que está ligado o terminal central do LM35 (porta analogica 0)

//int valorLido = 0; //valor lido na entrada analogica

//float temperatura = 0;
//int pinoTensao = 1;
//int valorTensao = 0; //valor lido na entrada analogica
//float tensao = 0;

byte detecta = 2;
int contador = 0;

//LiquidCrystal_I2C lcd(0x38,16,2);

void setup()
{
//lcd.init();
//lcd.backlight();

Serial.begin(9600);
Serial.println("CONTA GIROS DNL");
pinMode(detecta,INPUT);
digitalWrite(detecta,HIGH);
contador = 0;
attachInterrupt(0, DETECTA, FALLING);
noInterrupts();

delay (10000);

}

void loop()
{
unsigned long tempo = millis();
while(tempo +1000 > millis())
{
interrupts();

}

contador = contador * 100 ;

//valorLido = analogRead(pinoSensor);

//temperatura = (valorLido * 0.00488); // 5V / 1023 = 0.00488 (precisão do A/D)
//temperatura = temperatura * 100;
//valorTensao = analogRead(pinoTensao);
//tensao = valorTensao * 0.00488 ;
//tensao = tensao * 4 ;

//lcd.setCursor(0, 0);
//lcd.print("V:");
//lcd.print(tensao);
//lcd.print(" ");
//lcd.setCursor(0, 1);
//lcd.print("T:");
//lcd.print(temperatura);
//lcd.print(" ");
//lcd.setCursor(8, 1);
Serial.print("RPM:");
Serial.println((contador/10)*2.8);
//lcd.print(" ");
contador = 0;
}
void DETECTA()
{
contador ++;
}
