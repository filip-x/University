class Question:
    def __init__(self, qid, askedQuestion, answer1, answer2, answer3, correctAnswer, difficulty):
        if not qid.isdigit():
            raise ValueError('Invalid ID')
        self._id = int(qid)
        self._askedQuestion = askedQuestion
        self._answer1 = answer1
        self._answer2 = answer2
        self._answer3 = answer3
        self._correctAnswer = correctAnswer
        self._difficulty = difficulty

    @property
    def Id(self):
        return self._id

    @property
    def Difficulty(self):
        return self._difficulty

    def __repr__(self):
        return str(self)

    def __str__(self):
        return str(self._id) + ';' + self._askedQuestion + ';' + self._answer1 + ';' + self._answer2 + ';' + self._answer3 + ';' + self._correctAnswer + ';' + self._difficulty + '\n'
