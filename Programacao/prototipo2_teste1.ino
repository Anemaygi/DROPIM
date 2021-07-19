int LEDAMARELO = 8;
int LED = 9; 
int botao = 11; // botão de configuração
int pinSensor = 10; // módulo do sensor TCRT5000
int SensorAnalogico = A0; // módulo do sensor TCRT5000 / saída analógica
int qtd = 1; // Número de piscadas
int val = 500; // Configuração de proximidade do sensor
int delayed = 100; // Configuração do delay entre piscadas
int ok = 0; // Confirmação de configuração
 
void setup()
{
  pinMode(LEDAMARELO, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(pinSensor, INPUT);
  Serial.begin(9600);
  delay(1000);  
}

void config(){
// função para configurar delay entre as piscadas e proximidade do sensor

  Serial.print("Insira o valor de proximidade do sensor (padrão: 500)\n");
  Serial.print("Mínimo: 0 - Máximo = 1024\n");
  val = Serial.read(); // inserir valor de proximidade do sensor
  
  Serial.print("Insira o valor de delay (padrão: 100)\n");
  delayed = Serial.read(); // inserir valor de delay entre piscadas

  Serial.print("Quando terminar a configuração, escreva 1");
  ok = Serial.read();
  if (ok == 1){
    Serial.print("Pronto\n");
    Serial.print("Iniciando DROPIM...\n");
    }
  }
 
void loop()
{
   /*
   Testagem e debug:
   Serial.println(analogRead(SensorAnalogico));
   Serial.println(qtd);

    Configuração
    if (digitalRead(botao) == HIGH){
      digitalWrite(LEDAMARELO, HIGH); 
      config();
      digitalWrite(LEDAMARELO, LOW);
    }    
   */
    
     if (analogRead(SensorAnalogico) < val){ //
        digitalWrite(LED, HIGH); 
        digitalWrite(LEDAMARELO, HIGH); 
        qtd = qtd+1;
        
        //frases de teste
        
               if (qtd == 1){
                Serial.print("Estou com fome\n");
                }

                else if (qtd == 2){
                 Serial.print("Estou com sede\n");
                }

                else if (qtd == 3){
                 Serial.print("Preciso ir ao banheiro\n");
                }

                else if (qtd == 4){
                qtd = 0;
                }
                
        delay(delayed);      
        
  } else {
        digitalWrite(LED, LOW); 
        digitalWrite(LEDAMARELO, LOW); 
        //Debug: Serial.print("NADA DETECTADO"); 
        delay(1000); 
 } 
 
}
