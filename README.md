# 🔊 Alarma de Proximidad con Notificación por Telegram usando ESP32 y HC-SR04

Este proyecto implementa un sistema de alarma de proximidad diseñado para mejorar la seguridad en viviendas rurales, fincas u otras zonas sensibles. Utiliza un sensor ultrasónico HC-SR04 y un microcontrolador ESP32 con conexión Wi-Fi para detectar objetos cercanos y enviar notificaciones en tiempo real mediante Telegram.

<div align="center">
  <img src="/img/AlarmaAntirrobo.jpg" alt="Circuito armado" width="600"/>
</div>

## 📦 Características

- ✅ Detección de proximidad con sensor ultrasónico HC-SR04
- ✅ Activación de alerta sonora con buzzer
- ✅ Notificaciones instantáneas por Telegram
- ✅ Control remoto mediante comandos `/encender` y `/apagar`
- ✅ Interfaz desarrollada en Arduino IDE
- ✅ Manual de usuario accesible vía código QR

---

## 🧠 Fundamento Técnico

| Componente     | Descripción                                                    |
| -------------- | -------------------------------------------------------------- |
| ESP32          | Microcontrolador con Wi-Fi integrado para conexión a Telegram  |
| HC-SR04        | Sensor ultrasónico para medir distancia con precisión de ±3 mm |
| Buzzer         | Emite alerta sonora en caso de intrusión                       |
| LED (opcional) | Indica visualmente el estado del sistema                       |
| Telegram API   | Envío de alertas y recepción de comandos remotos desde el chat |

---

## 📐 Diagrama de Conexión

<p align="center">
  <img src="https://user-images.githubusercontent.com/yourdiagram.png" alt="Diagrama de bloques" width="600"/>
</p>

- **HC-SR04**:

  - VCC → 5V ESP32
  - GND → GND ESP32
  - TRIG → GPIO D2
  - ECHO → GPIO D4

- **Buzzer**:

  - Positivo → GPIO D16
  - Negativo → GND

- **LED (opcional)**:
  - Ánodo → GPIO D5
  - Cátodo → GND

---

## 📲 Integración con Telegram

1. Abre Telegram y busca el bot `BotFather`.
2. Usa el comando `/newbot` y guarda el **Token** generado.
3. Busca el bot `IDBot` y usa `/getid` para obtener tu **ID de usuario**.
4. Agrega ambos datos en el código fuente antes de compilar.

---

## 💻 Programación en Arduino IDE

- Lenguaje: C++
- Librerías necesarias: `WiFi.h`, `WiFiClientSecure.h`, `UniversalTelegramBot.h`

### Comandos disponibles:

- `/encender`: Activa la alarma (LED encendido y pitido corto)
- `/apagar`: Desactiva la alarma (LED apagado y pitido largo)

> ⚠️ Cuando el sensor detecta un objeto a menos de **110 cm**, el buzzer se activa y se envía un mensaje a Telegram con los datos de intrusión.

---

## 🧪 Resultados

- 🕵️ Precisión: ±3 mm en detección
- 📲 Tiempo de alerta: < 1 segundo
- 🔋 Bajo consumo energético
- ✅ Funcionamiento validado en maqueta de vivienda rural

---

## 📎 Recursos

- 📘 [Manual de Usuario (PDF)](https://drive.google.com/drive/folders/1rFSyHGObPx82W6xENoh6TlvTBymRzTTH?usp=sharing)
- 💾 Código fuente y guía de instalación del entorno Arduino IDE
- 📦 Archivos STL y planos de maqueta (opcional)

---

## 🏁 Contribuyentes

- A. Díaz
- S. Gerónimo
- J. Larrota
- J. Rentería

Facultad de Ingeniería – Universidad Católica de Pereira  
Programa de Ingeniería de Sistemas y Telecomunicaciones

---

## 🛠️ Requisitos

- Arduino IDE
- Placa ESP32 Dev Module
- Conexión a red Wi-Fi 2.4GHz
- Cuenta de Telegram activa

---

## ⚠️ Licencia

Este proyecto se distribuye con fines académicos y educativos. Siente la libertad de modificarlo y adaptarlo para tus necesidades personales o académicas.
