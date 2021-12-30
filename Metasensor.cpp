#include "Metasensor.h"
Metasensor::Metasensor(int input) {
  this->input = input;
  init();
}
void Metasensor::init() {
  pinMode(input, INPUT);
  setCalibrate_bool();
}
void Metasensor::setCalibrate_bool() {
  delay(10000);
  Serial.print("0% value for what you are measuring will be...");
  x = analogRead(input);
  Serial.println(x);
  delay(10000);
  Serial.print("100% value for what you are measuring will be...");
  y = analogRead(input);
  Serial.println(y);
  Serial.println("If using MAP command, use X and Y values as reference.");
}
int Metasensor::getDifuse_read() {
  delay(10000);
  input = analogRead(input);
  Serial.println(input);
  output = map(input, y,x, 100, 0);
  Serial.print("Sensor get caught: ");
  Serial.print(output);
  Serial.println("%");
}
int Metasensor::getDifuse_read_specific(int a, int b) {
  input = analogRead(input);
  Serial.println(input);
  int output_specific = map(input, b,a, 100, 0);
  return output_specific;
}

void Metasensor::setSensor_Umidade_Capacitivo() {
  delay(10000);
  Serial.println("                  ---*****---                  ");
  Serial.println("Calibrando Sensor de Umidade de Solo Capacitivo");
  Serial.println("Deixe o sensor seco, até o fim da leitura");
  Serial.println("Coletando media de leituras do sensor...");
  Serial.println("");
  //Declaracao da variavel que armazena as leituras do sensor
  int leitura_sensor = 0;
  //Declaracao da variavel que armazena a quantidade de amostras que serao coletadas
  const int NUMERO_AMOSTRAS = 100; 
  //Altere a variavel acima com a quantidade de amostras que deseja coletar para o calculo da media
  //Declaracao da variavel que armazena a soma das leituras
  long somatoria = 0;

  //Realiza a leitura do sensor de acordo com a variavel "NUMERO_AMOSTRAS"
  for(int i = 1; i <= NUMERO_AMOSTRAS; i++){
    leitura_sensor = analogRead(input); //Le o sensor
    somatoria = somatoria + leitura_sensor; //Soma a variavel "somatoria" a leitura atual do sensor com seu valor anterior
    float tensao = leitura_sensor*(5.0/1023); //Converte a leitura para tensao para referencia
    Serial.print("Amostra ");
    Serial.print(i);
    Serial.print("  |  ");
    Serial.print("Leitura: ");
    Serial.print(leitura_sensor);
    Serial.print("  |  ");
    Serial.print("Tensao: ");
    Serial.println(tensao);
    delay(1000);
  }
  //Calcula a media das leituras utilizando a variavel "somatoria" e a variavel "NUMERO_AMOSTRAS"
  int media_seco = somatoria / NUMERO_AMOSTRAS;
  Serial.println("");
  Serial.print("Media obtida para o sensor seco: ");
  Serial.println(media_seco);

  Serial.println("Submeta o sensor a um copo de água até a linha divisória do circuito");
  Serial.println("Respeite a linha para não danificar o sensor!!");
  delay(10000);
  //Declaracao da variavel que armazena as leituras do sensor
  leitura_sensor = 0;
  //Declaracao da variavel que armazena a soma das leituras
  somatoria = 0;

  Serial.println("Coletando media de leituras do sensor...");
  Serial.println("");
  //Realiza a leitura do sensor de acordo com a variavel "NUMERO_AMOSTRAS"
  for(int i = 1; i <= NUMERO_AMOSTRAS; i++){
    leitura_sensor = analogRead(input); //Le o sensor
    somatoria = somatoria + leitura_sensor; //Soma a variavel "somatoria" a leitura atual do sensor com seu valor anterior
    float tensao = leitura_sensor*(5.0/1023); //Converte a leitura para tensao para referencia
    Serial.print("Amostra ");
    Serial.print(i);
    Serial.print("  |  ");
    Serial.print("Leitura: ");
    Serial.print(leitura_sensor);
    Serial.print("  |  ");
    Serial.print("Tensao: ");
    Serial.println(tensao);
    delay(1000);
  }
  //Calcula a media das leituras utilizando a variavel "somatoria" e a variavel "NUMERO_AMOSTRAS"
  int media_molhado = somatoria / NUMERO_AMOSTRAS;
  Serial.println("");
  Serial.print("Media obtida para o sensor molhado: ");
  Serial.println(media_molhado);

  Serial.println("");
  Serial.print("Media obtida para o sensor seco: ");
  Serial.println(media_seco);
  Serial.print("Media obtida para o sensor molhado: ");
  Serial.println(media_molhado);
}

int Metasensor::getSensor_Umidade_Capacitivo(int a, int b) {
  //Declaracao da variavel que armazena as leituras do sensor
  int leitura_sensor = 0;
  //Declaracao da variavel que armazena a quantidade de amostras que serao coletadas
  const int NUMERO_AMOSTRAS = 60; 
  //Altere a variavel acima com a quantidade de amostras que deseja coletar para o calculo da media
  //Declaracao da variavel que armazena a soma das leituras
  long somatoria = 0;
  for(int i = 1; i <= NUMERO_AMOSTRAS; i++){
    leitura_sensor = analogRead(input); //Le o sensor
    somatoria = somatoria + leitura_sensor; //Soma a variavel "somatoria" a leitura atual do sensor com seu valor anterior
    float tensao = leitura_sensor*(5.0/1023); //Converte a leitura para tensao para referencia
    Serial.print("Amostra ");
    Serial.print(i);
    Serial.print("  |  ");
    Serial.print("Leitura: ");
    Serial.print(leitura_sensor);
    Serial.print("  |  ");
    Serial.print("Tensao: ");
    Serial.println(tensao);
    delay(500);
  }
  //Calcula a media das leituras utilizando a variavel "somatoria" e a variavel "NUMERO_AMOSTRAS"
  int media = somatoria / NUMERO_AMOSTRAS;
  int leitura_sensor_final = map(media, b, a, 100, 0);
  if(leitura_sensor_final>100){
    leitura_sensor_final = 100;
  }else if(leitura_sensor_final<0){
    leitura_sensor_final = 0;
  }else{
    leitura_sensor_final = leitura_sensor_final;
  }
  return leitura_sensor_final;
}