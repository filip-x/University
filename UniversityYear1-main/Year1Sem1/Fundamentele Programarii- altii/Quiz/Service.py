from Question import Question
import random


class Service:
    def __init__(self, repo):
        self._repo = repo

    def startQuiz(self, element):
        if len(element) > 2:
            raise ValueError('Invalid command')
        file = element[1]
        f = open(file, 'r')
        questions = []
        for i in f:
            a = i.strip()
            a = a.split(';')
            r = ''
            r += 'Q: ' + a[1] + '\n'
            r += 'A1: ' + a[2] + ' A2: ' + a[3] + ' A3: ' + a[4] + '\n'
            questions.append((r, a[5], a[6]))
        return questions

    def storeQuestion(self, element):
        if len(element) != 8:
            raise ValueError('Invalid command')
        if element[6] not in [element[3], element[4], element[5]]:
            raise ValueError('Invalid correct answer')
        if element[7] not in ['easy', 'medium', 'hard']:
            raise ValueError('Invalid difficulty')
        if element[3] == element[4] or element[4] == element[5] or element[3] == element[5]:
            raise ValueError('Need different answers')
        q = Question(element[1], element[2], element[3], element[4], element[5], element[6], element[7])
        self._repo.store(q)

    def createQuiz(self, element):
        candidates = []
        nr = 0
        if not element[2].isdigit():
            raise ValueError('Invalid number of questions')
        if element[1] not in ['easy', 'medium', 'hard']:
            raise ValueError('Invalid difficulty')
        element[2] = int(element[2])
        for i in self._repo.getMasterList:
            if i.Difficulty == element[1]:
                nr += 1
                candidates.append(i)
                if nr == element[2] // 2:
                    break
        if len(candidates) < element[2] // 2:
            raise ValueError('There are not enough ' + element[1] + ' questions')
        remaining = []
        for elem in self._repo.getMasterList:
            if elem not in candidates:
                remaining.append(elem)
        if len(remaining) < element[2] - len(candidates):
            raise ValueError('Not enough questions in list')
        for i in range(nr, element[2]):
            a = random.choice(remaining)
            candidates.append(a)
            remaining.remove(a)
        d = {'easy': 1, 'medium': 2, 'hard': 3}
        candidates = sorted(candidates, key=lambda x: d[x.Difficulty])
        f = open(element[3], 'w')
        for i in candidates:
            f.write(str(i))
        f.close()

    def __str__(self):
        return str(self._repo)

