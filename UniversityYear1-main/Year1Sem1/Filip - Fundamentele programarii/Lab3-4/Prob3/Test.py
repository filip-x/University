import functions as f

def Test_Get_Set(): #we test if the getters and setters are working good 
    exemple = f.createParticipant(1,2,3)
    assert f.Getprob1(exemple)== 1 and f.Getprob2(exemple) == 2 and f.Getprob3(exemple) == 3
    f.Setprob2(exemple,5)
    assert f.Getprob1(exemple)== 1 and f.Getprob2(exemple)== 5 and f.Getprob3(exemple) == 3

def Test_remove():
    Newlistexemple=[]
    f.add_Participant(Newlistexemple,1,2,3)
    f.remove_participants(Newlistexemple,0,0)
    assert f.Getprob1(Newlistexemple[0])==0  and f.Getprob2(Newlistexemple[0])==0 and f.Getprob3(Newlistexemple[0])==0
 
def Test_Add_Element():
    Newlistexemple=[]
    #exemple = f.createParticipant(1,2,3)
    f.add_Participant(Newlistexemple,1,2,3)
    assert f.Getprob1(Newlistexemple[0])==1  and f.Getprob2(Newlistexemple[0])==2 and f.Getprob3(Newlistexemple[0])==3

def Main_Test():
    Test_Get_Set()
    Test_remove()
    Test_Add_Element()