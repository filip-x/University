def sleepIn(weekday, vacation):
    '''Function decides whether we are sleeping in
        input:
            weekday - True if it is a weekday
            vacation - True if we are on a vacation
        output:
            True if we are sleeping in
        exception:
            -
    '''
    return vacation or not weekday
 
weekday = input('Is it a weekday?(yes/no)')
 
if weekday == 'yes':
    weekday = True
else:
    weekday = False
   
vacation = input('Is it a vacation?(yes/no)')
vacation = (vacation == 'yes')
 
print(sleepIn(weekday, vacation))
