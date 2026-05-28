# Global Solution: Data Structures and Algorithms
 
## *Menu Principal*

O menu principal quando executa o programa no terminal mostra quatro opções.

1. *Inserir Dados*
2. *Visualizar Status*
3. *Modo Análise/Reparo*
4. *Sair*


### *Inserir Dados*
Onde vai inserir todos os dados que o resto das funções irão se basear sobre. Esses dados são:
- tempHabit (Temperatura do Interior da nave)
- tempPropulso (Temperatura do Exterior da nave)
- energia (Porcentagem de Energia da nave)
- comms (Sistema de Comunicações da nave)

Após inserir todos os dados, volta ao menu principal.

### *Visualizar Status*
Dependendo dos dados inseridos, alertas diferentes serão mostrados. Os Alertas são:
```
if tempHabit > 40
```
*"Temperatura do Habitate extremamente elevada."*
```
if tempPropulso > 300
```
*"Propulsor Superaquecido."*
```
if energia < 20
```
*"Economia de Energia."*
```
if tempHabit == 0
```
*"Falha de Comunicação."*

Após mostrar todos alertas disponíveis, volta ao menu principal.

## *Modo Análise/Reparo*
Como eu queria adicionar algo a mais além do que apenas foi pedido, adicionei um sistema onde usando as informações dadas, você pode correr por um cenário onde talvez esses dados sejam veríssimos, e o sistema tenta te ajudar a arrumar a situação.

Se a temperatura interior está muito alta, talvez tenha um fogo. Se a temperatura exterior está muito alta, talvez seja raios cósmicos do sol. No total, há *20 'finais'* diferentes para esse modo. As condições iniciais são a seguir:
```
if tempHabit > 40
if tempHabit > 70
if tempPropulso > 300
if tempPropulso > 1000
if tempHabit > 40 && tempPropulso > 300
if comms == 0
if energia < 20
if tempHabit > 70 && tempPropulso > 1000 && comms == 0 && energia < 20
if tempHabit < -200 || tempHabit > 1000 || tempPropulso > 5000 || tempPropulso < -200
```
Todas as permutações do Modo Análise estão disponíveis dentro do fluxograma.
