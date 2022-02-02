# Metasensor1.1
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

### Capacitive Humidity Sensor | Sensor de Umidade Capacitivo
The reading is made from the average of the readings | A leitura é feita a partir da média das leituras (behind map command | comando map por trás)
```
#include <Metasensor.h>
Metasensor var(15);
void setup() {
  Serial.begin(115200);  
  // var.setSensor_Umidade_Capacitivo();
  int res = var.getSensor_Umidade_Capacitivo(2804, 1334);
  Serial.print("O valor é: ");
  Serial.println(res);   
}
void loop() {
}
```
-----------------------------------------------
### Outras soluções que para caso os métodos acima sejam muito rudimentar é apelar para matemática, vejamos:  
Visualize dados por meio de gráficos, utilize o calculo da reta, x = ay + b.  
x = valor desejado do sensor  
y = input  
a = coef. de inclinação de reta  
b = offset que corresponde ao valor de x quando y for igual a 0  

Supondo que um sensor de umidade do solo leia valores de 1023 à 0, sendo 1023 seco e 0 molhado, valores por quais visualizamos em porcentual.  
100% seco / 1023 = 0,09774.  
Seguindo a fórmula temos:  
𝑥 = 𝑎𝑦 + 0  
Onde:  
a = 0,0977  
y = 1023  
x = 100% seco (repare que para que x seja igual a 100, b tem que ser igual a 0)  
Como o hidrometro resistivo funciona com valores indiretamente proporcional, caso tivessemos menos que 1023 com y, o módulo desse valor menos 1023 seria o valor do offset (1000 - 1023 = 23).  
Assim vemos que não temos problemas, já que no sensor ideal o offet será igual a 0.  

Diferença entre Calibração e ajuste: Segundo Dimave (2020), o ajuste é uma etapa da manutenção corretiva. Enquanto isso, a calibração faz parte da prevenção, evitando, assim, tempos de parada desnecessários.  

Tipos de calibracoes  
Calibração de ponto único: Supondo que queiramos o valor de X (da fórmula), isso será feito verificando o offset, desta forma, quando o Y=0.  
Não se esqueça que neste contexto estamos esperando linearidade por parte do sensor e a inclinação da reta, assim como esta acima.  
Exemplo: Ao calibrar um sensor ultrassônico que mede 10,3cm e 0,3cm de variação se consegue medir a distância do objeto cobaia com um paquímetro e configurar este 0,3cm de variação como offset (levando em conta que o interesante é um valor muito próximo do 10cm).  

Calibracao de dois pontos: este por sua vez trata não apenas do offset, mas inclinação da reta, ou seja, a variável multiplicadora da fórmula.  
Em gráfico pode-se ter varias inclinações da reta, além do offset negativo, positivo e zerado.  
Dessa maneira, o sensor pode ter dois ajustes, um para zero (offset) e o outro para inclinação reta (multiplicador).  
#### ATENÇÃO: Ao ajustar um parametro, o outro podera ficar desajustado, então é interessante intercalar e ir ajustando ambos até que se encontre consenso entre ambos ajustes e o que se deseja.  

1.Faça duas medições com o sensor próprio, sendo uma com valor bruto baixo (mínimo da faixa) e valor bruto alto (máximo da faixa).  
2.Faça o mesmo com um outro sensor padrão, mas chame de valor de referência baixo e alto.  
3.Cálcule:  
	* faixa bruta = valor alto bruto - valor baixo bruto  
	* faixa de referência = referência alta - referência baixo  
e então...  
	* valor corrigido = valor bruto . faixa de ref/faixa bruta + ref baixa  
	* valor bruto = valor medido do sensor  
Como pôde ver, esta equação é a mesma da anterior, porém, melhorada.  

Calibração multi ponto  
Tudo visto até o momento diz respeito aos sensores que possuem apenas retas, e não curvas.  
Então o que tem que ser feito é calcular mais pontos, mas cuiado, se tiver um comportamento muito distante da curva, estes calculos podem não ajudar.

-----------------------------------------------

### Contributing | Contribuindo
* Contributions are welcome! Please read our guide before contributing to help this project | As contribuições são bem-vindas! Por favor, leia nosso guia antes de contribuir para ajudar este projeto.
### Referências
* Todos os scripts rodando por trás da leitura do sensor de umidade do solo capacitivo tiveram como referência a matéria de Giovanni de Castro, clique <a href="https://www.robocore.net/tutoriais/leitura-umidade-solo"> AQUI </a> para acessar a matéria.
