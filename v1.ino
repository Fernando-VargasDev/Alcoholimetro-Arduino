//Librerías

//Librerías para la Pantalla LCD
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //Crear objeto de LCD con dirección 0x27 y 16 columnas x 2 filas

//Variables 

//Leds
const int ledPIN = 8; //Led Rojo
const int ledPIN2 = 9; //Led Verde

//Buzzer
const byte pinBuzzer = 5;
byte salida = 10;

//Sensor MQ-3
const int MQ3_pin = A0;

//Limite para activar la alarma
int valor_limite= 400;


void setup() {
  //Configuración

  Serial.begin(9600);    //iniciar puerto serie

  //Led
  pinMode(ledPIN , OUTPUT);  //definir pin como salida
  pinMode(ledPIN2 , OUTPUT);  //definir pin como salida

  //Pantalla LCD
  lcd.init(); //Inicializar el LCD
  lcd.backlight(); //Encender la luz de fondo

}

void loop() {
  //Bucle 

  //Lectura del sensor
  float valor_alcohol=analogRead(MQ3_pin); //Lee el valor del sensor MQ3
  float porcentaje(valor_alcohol/10000); //Calcula el porcentaje de alcohol detectado
  

  //Mostrar la lectura en la Pantalla LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alcohol: ");
  lcd.print(porcentaje, 2); //Muestra con 2 decimales
  lcd.print("%");

  if(valor_alcohol > valor_limite){
    digitalWrite(ledPIN , HIGH); //Encender Led Rojo
    digitalWrite(ledPIN2, LOW); //Apagar Led Verde
    analogWrite(pinBuzzer, salida); //Encender Buzzer
    lcd.setCursor(0, 1);
    lcd.print("Borracho");
  }else{
    digitalWrite(ledPIN2 , HIGH); //Encender Led Verde
    digitalWrite(ledPIN, LOW);  //Apagar Led Rojo
    analogWrite(pinBuzzer, LOW); //Apagar Buzzer
    lcd.setCursor(0, 1);
    lcd.print("No borracho");
  }

  delay(1000); //Espera un segundo

}
