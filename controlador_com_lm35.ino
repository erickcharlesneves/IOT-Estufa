#include <Wire.h> //para facilitar a comunicação I2C entre arduino

//bibliotecas Adafruit para gráficos e para controle do display OLED SSD1306
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>

//largura e altura do display OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

//instância do display OLED com as definições
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int LM35 = A0; // Define o pino que lê a saída do LM35, conectado analogicamente em A0
float temperatura; // Variável que armazenará a temperatura medida
byte set_point = 0; // Variável que armazenará o Valor set_point (ponto de ajuste) da temperatura medida

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial, 9600 bps

  // Inicializa o display OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("Erro ao iniciar o display OLED"));
    while(true);
  }

  // Limpa o buffer do display
  display.clearDisplay();
  display.display();

  pinMode(13, OUTPUT); //led
  pinMode(2, INPUT_PULLUP); //2, 3 e 4 como entradas com resistores de pull-up internos(para não usar resistor) - botões
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  // Leitura da temperatura
  temperatura = analogRead(LM35) * 5.0 / 1023 / 0.01; // Conversão para temperatura em graus Celsius (5 V tensão analogica do LM35 / 1023 (valor que exibiria no display se fosse 5V) / 0.01 referente aos 10mV que o LM35 gera por grau)

  // Limpa o buffer do display
  display.clearDisplay();

  // Configurar a exibição da temperatura no display OLED
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("TEMPERATURA: ");
  display.setCursor(70, 0);
  display.print(temperatura, 1); // Exibe temperatura com uma casa decimal
  display.print("C");

  // Exibição do valor do setpoint dos bostões no display OLED
  display.setCursor(0, 20);
  display.print("VALOR SET: ");
  display.print(set_point); // Exibe o valor de ponto de ajuste

  // Atualiza o display
  display.display();

  // Tratamento dos botões para ajustar o valor setpoint, ponto de ajuste
  if (digitalRead(2) == LOW && set_point < 150) { //btn aumentar pino 2
    set_point++;
    delay(200); // Adiciona um atraso para evitar o rebote do botão
  }
  if (digitalRead(3) == LOW && set_point > 0) {  //btn diminuir pino 3
    set_point--;
    delay(200); // Adiciona um atraso para evitar o rebote do botão
  }

  // Controle do LED vermelho (representado acionamento da estufa) com base na comparação entre a temperatura medida, e o setpoint
  if (temperatura <= set_point-1) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  delay(100); // Pequeno atraso entre as iterações do loop para estabilidade
}
