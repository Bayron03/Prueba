import random

decimals=100

def tFunction(s):
    i=0
    result=1
    for i in range(s):
        result*=1-i/365
        pass
    return result

def birthdayParadox(s,k):
    t=tFunction(s)
    j=0 #contadores
    n=0
    for j in range(k):
        noRepetitionFlag=True
        birthdaysList=[]
        i=0
        #print(j)
        while noRepetitionFlag and i!=s:
            i+=1
            u=random.random() #Random da un valor entre 0 y 1, redondearlo nos da un entero
            birthdaysList.append(round(364*u)+1)
            noRepetitionFlag= (len(birthdaysList) == len(set(birthdaysList)))
            #print(birthdaysList)
            pass
        if(not noRepetitionFlag):
            n+=1
    p=1-n/k # PROBABILIDAD DE QUE NO SE REPITA
    d=abs(t-p)/t
    
    print("Subjects (s):",s)
    print("Expected Probability of not repetition (t):",round(t,decimals)) #NO SÉ SI ERA LA PROB DE QUE NO PASE
    print("Cycles without repetition (n):",n)
    print("Total Cycles (k):",k)
    print("Generated probability of not repetition (p):",p)
    print("Relative Error (d):",round(d,decimals))

