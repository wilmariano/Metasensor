# Metasensor1.0
Library to calibrate sensor | Biblioteca para calibrar sensor

## How does it work | Como isso funciona
Instantiate an object to library class with Analog Pin | Instancie um objeto para classe da biblioteca com pino analógico
```
Metasensor var(0);
```

Start what was instantiated to calibrate your sensor | Inicie o que foi instanciado para calibrar seu sensor
```
var.init();
```

Run the command to read your analog pin with measured value previously | Rode o comando para ler seu pino analógico com valor medido anteriormente (behind map command | comando map por trás)
```
int res = var.getDifuse_read();
Serial.println(res);
```
-----------------------------------------------
For option, you can get this value and set it manually (behind map command | comando map por trás)
```
int res2 = var.getDifuse_read_specific(1023, 500);
Serial.print("O valor é: ");
```
-----------------------------------------------
Complete code Código completo
```
#include <Metasensor.h>
Metasensor var(0);
void setup() 
{
  Serial.begin(115200);
}
void loop() {
  // var.init();
  // int res = var.getDifuse_read();
  // Serial.print("O valor é: ");
  // Serial.println(res);
  int res2 = var.getDifuse_read_specific(1023, 500);
  Serial.print("O valor é: ");
  Serial.println(res2);  
}
```
-----------------------------------------------
### Contributing | Contribuindo
* Contributions are welcome! Please read our guide before contributing to help this project | As contribuições são bem-vindas! Por favor, leia nosso guia antes de contribuir para ajudar este projeto.
