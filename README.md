# IOT-Estufa
Projeto de um protótipo para uma estufa automatizada baseada em internet das coisas utilizando placa de Arduino uno.

Este projeto consistiu na criação de um protótipo de acionamento para uma estufa de aquecimento controlado, desenvolvido com foco para secagem de placas de celulares ou outros componentes eletrônicos que foram molhados, mas também que servirá para outros fins de protótipos que se deseje manter a faixa de temperatura de -55˚C a +150˚C controlada.

O protótipo em questão tem como um dos objetivos monitorar as condições térmicas dentro da estufa por meio de um sensor de temperatura LM35 conectado ao Arduino, que exibe em um display OLED integrado ao circuito a temperatura convertida em graus Celsius proporcionando uma interface de usuário intuitiva para visualização dos dados de temperatura e valor de ajuste SET(setpoint) controlável por dois botões integrados ao circuito permitindo ao usuário aumentar ou diminuir a temperatura que se deseja manter sob controle na estufa, conforme necessário.

Após a conexão dos componentes eletrônicos, como nas imagens abaixo, procede-se à configuração do sistema. O [código do Arduino](https://github.com/erickcharlesneves/IOT-Estufa/blob/main/controlador_com_lm35.ino) é carregado no microcontrolador, definindo as instruções para leitura do sensor de temperatura, controle do display OLED e interação com os botões de ajuste. O LED vermelho, representando o aquecedor, é incorporado ao sistema, pronto para indicar quando o aquecimento está em operação caso a temperatura esteja abaixo do setpoint, de acordo com a comparação entre a temperatura medida e o setpoint ajustado.

### 1.	Sensores e Dispositivos Utilizados

●	Display OLED 0.96 i2c  
●	Chave táctil Push Button (2 unidades)  
●	LED vermelho  
●	Resistor 2.2k Ω  
●	Arduino Uno  
●	Protoboard  
●	Jumpers  
●	Sensor de temperatura LM35  

### Esquema de ligação simulado:  
![image](https://github.com/erickcharlesneves/IOT-Estufa/assets/74471156/9d7b0468-083e-4b01-aee5-20c2590f91af)  

### Montagem do protótipo:  
![image](https://github.com/erickcharlesneves/IOT-Estufa/assets/74471156/18574cc9-c9f4-4b0b-b65a-f22ed1158667)
  





