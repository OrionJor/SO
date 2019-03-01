#Orion Jorjuan
# Algoritmo do banqueiro


# Número de processos  
P = 5
  
# Número de recursos  
R = 3
  
# Função para encontrar a necessidade de cada processo
def calculateprecisa(precisa, max, alocacao): 
  
    # Calculando a necessidade de cada P ->processo
    for i in range(P): 
        for j in range(R): 
              
           #Necessidade de instância = instância max -
           #instância alocada
            precisa[i][j] = max[i][j] - alocacao[i][j]  

#Função para encontrar o sistema está em
# estado seguro ou não

def isSafe(processes, acessivel, max, alocacao): 
    precisa = [] 
    for i in range(P): 
        l = [] 
        for j in range(R): 
            l.append(0) 
        precisa.append(l) 
          
    # Função para calcular a precisa da matrix 
    calculateprecisa(precisa, max, alocacao) 
  
    # Marcar todos os processos quando terminar
    finalizar = [0] * P 
      
    # Para armazenar a sequência segura
    safeSeq = [0] * P  
  
    # Para armazenar a sequência segura 
    trabalho = [0] * R  
    for i in range(R): 
        trabalho[i] = acessivel[i]  
  
    # Enquanto todos os processos não estão terminados
    # ou o sistema não está em estado seguro.

    count = 0
    while (count < P): 
          
        # Encontre um processo que não termine
        # e cujas necessidades podem ser satisfeitas
        # com os recursos atuais do trabalho [].
        found = False
        for p in range(P):  
          
           # Encontre um processo que não termine
        # e cujas necessidades podem ser satisfeitas
        # com os recursos atuais do trabalho [].
            if (finalizar[p] == 0):  
              
                
		# Verifique se há todos os recursos número de necessidade atual de P é menor
                # do que trabalho
                for j in range(R): 
                    if (precisa[p][j] > trabalho[j]): 
                        break
                      
                # Se todas as necessidades de p estiverem satisfeitas.
                if (j == R - 1):  
                  

		    # Adicione os recursos alocados de
                    # atual P para o disponível / trabalho
                    # recursos, isto é, os recursos
                   

                    for k in range(R):  
                        trabalho[k] += alocacao[p][k]  
  
                    # Adicione este processo a uma sequência segura.
                    safeSeq[count] = p 
                    count += 1
  
                    # Marque este p como terminado
                    finalizar[p] = 1
  
                    found = True
       
	# Se não conseguimos encontrar um próximo processo
        # em sequência segura. 
        if (found == False): 
            print("O sistema não está em estado seguro") 
            return False
          
    # If system is in safe state then  
    # safe sequence will be as below  
    print("O sistema está em estado seguro.", 
              "\nO estado seguro é: ", end = " ")

    print(*safeSeq)  
  
    return True
  
# main  função Principal
if __name__ =="__main__": 
      
    processes = [0, 1, 2, 3, 4] 
  
    # Instâncias disponíveis de recursos 
    acessivel = [3, 3, 2]  
  
    # Máximo R que pode ser alocado
    # para processos
    max = [[7, 5, 3], [3, 2, 2], 
            [9, 0, 2], [2, 2, 2], 
            [4, 3, 3]] 
  
    # Recursos alocados para processos
    alocacao = [[0, 1, 0], [2, 0, 0], 
             [3, 0, 2], [2, 1, 1], 
             [0, 0, 2]]  
  
    # Verifique se o sistema está em estado seguro ou não
    isSafe(processes, acessivel, max, alocacao)  
  
#  A saida: O sistema está em estado seguro. A sequência segura é: 1 3 4 0 2
