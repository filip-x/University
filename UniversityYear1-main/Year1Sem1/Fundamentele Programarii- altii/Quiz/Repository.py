from Question import Question


class Repo:
    def __init__(self):
        self._masterList = []
        self._readFile()

    def _readFile(self):
        f = open('MasterList.txt', 'r')
        for i in f:
            if i == '':
                return
            a = i.strip()
            a = a.split(';')
            self.store(Question(a[0], a[1], a[2], a[3], a[4], a[5], a[6]))
        f.close()

    def _saveFile(self):
        f = open('MasterList.txt', 'w')
        for i in self._masterList:
            f.write(str(i))
        f.close()

    @property
    def getMasterList(self):
        return self._masterList

    def store(self, obj):
        if obj.Id in [x.Id for x in self._masterList]:
            raise ValueError('ID already exists')
        self._masterList.append(obj)
        self._saveFile()

