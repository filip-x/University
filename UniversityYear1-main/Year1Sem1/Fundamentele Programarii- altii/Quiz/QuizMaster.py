from Repository import Repo
from Service import Service


class UI:
    def __init__(self, service):
        self._service = service

    def parseCommand(self, command):
        command = command.strip()
        command = command.split(';')
        aux = command[0]
        command.remove(command[0])
        aux = aux.split(' ')
        if aux[0] == 'add':
            command.insert(0, aux[0])
            command.insert(1, aux[1])
        if aux[0] == 'create':
            command = aux
        if aux[0] == 'start':
            command = aux
        return command

    def addQuestion(self, command):
        self._service.storeQuestion(command)

    def createQuiz(self, command):
        self._service.createQuiz(command)

    def startQuiz(self, command):
        quiz = self._service.startQuiz(command)
        correct = 0
        diff = ['easy', 'medium', 'hard']
        for i in quiz:
            print(i[0])
            answer = input('Your answer: ')
            if answer == i[1]:
                correct += diff.index(i[2]) + 1
        print('You have scored a total of: ' + str(correct))

    def start(self):
        while True:
            command = input('Command: ')
            command = self.parseCommand(command)
            d = {'add': self.addQuestion, 'create': self.createQuiz, 'start': self.startQuiz, 'exit': 0}
            if len(command) == 0:
                print('Invalid command')
                continue
            if command[0] in d:
                if command[0] == 'exit':
                    return
                else:
                    try:
                        d[command[0]](command)
                    except ValueError as err:
                        print(err)
                    except Exception as error:
                        print(error)
            else:
                print('Invalid command')


r = Repo()
s = Service(r)
u = UI(s)
u.start()