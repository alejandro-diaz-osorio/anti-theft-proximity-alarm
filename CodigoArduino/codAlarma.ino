#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
// Definición de pines
#define echo 4
#define trigger 2
#define buzzer 16
#define led 5
int duration;
int distance;
// Credenciales de Internet
const char* ssid = "";
const char* password = "";
// Token Bot Telegram
const char* tokenBot = "";
// ID del chat
const char* idChat = "";
WiFiClientSecure client;
UniversalTelegramBot bot(tokenBot, client);
bool alarmaActiva = false;
bool objetoDetectado = false;
void conectarWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando al WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConexión WiFi establecida.");
}
void manejarComandos() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  for (int i = 0; i < numNewMessages; i++) {
    String text = bot.messages[i].text;

    if (text == "/apagar") {
      if (alarmaActiva) {
        alarmaActiva = false;
        noTone(buzzer);
        digitalWrite(led, LOW);  
        bot.sendMessage(idChat, "Alarma apagada.", "");
        tone(buzzer, 500, 500);  
      } else {
        bot.sendMessage(idChat, "La alarma ya está apagada.", "");
      }
    }
    if (text == "/encender") {
      if (!alarmaActiva) {
        alarmaActiva = true;
        digitalWrite(led, HIGH);  
        bot.sendMessage(idChat, "Alarma activada.", "");
        tone(buzzer, 1000, 100); 
      } else {
        bot.sendMessage(idChat, "La alarma ya está activa.", "");
      }
    }
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  conectarWiFi();
  client.setInsecure();
  Serial.println("Sistema de alarma listo.");
  bot.sendMessage(idChat, "Sistema de alarma activado y listo para comandos.", "");
}
void loop() {
  manejarComandos();
  if (!alarmaActiva) {
    noTone(buzzer);
    delay(100);
    return;
  }
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH, 30000);
  distance = (duration == 0) ? 999 : (duration * 0.0343) / 2;
  Serial.println("Distancia medida: " + String(distance) + " cm");
  // Determinar la distancia de seguridad segun su necesidad en cm
  if (distance < 110 && distance > 2) {
    if (!objetoDetectado) {
      tone(buzzer, 1000);
      String message = "🚨 *ALERTA DE INTRUSIÓN DETECTADA* 🚨\n\n"
                  "📏 Distancia medida: " + String(distance) + " cm\n"
                  "🕒 Hora: " + String(millis() / 1000) + " segundos desde el inicio\n\n"
                  "*INGRESO NO AUTORIZADO* dentro del rango de seguridad.";
      for (int i = 0; i < 3; i++) {
        bot.sendMessage(idChat, message, "");
        delay(1000);
      }
      objetoDetectado = true;  
    }
  } else {
    noTone(buzzer);
    objetoDetectado = false;  
  }
  delay(50);
}
