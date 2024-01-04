def fisier(file, lineNr = 1):
    if line := file.readline():
        if lineNr % 2 == 1:
            pre = line
            for c in "! @#$%^&*\n":
                pre = pre.replace(c, "")
            print(pre)
            return len(pre) + fisier(file, lineNr + 1)
        else:
            pre = line
            for c in "! @#$%^&*\n":
                pre = pre.replace(c, "#")
            words = pre.split("#")
            w = []
            for word in words:
                if len(word) > 0:
                    w.append(word)
            print(w)
            return len(w) + fisier(file, lineNr + 1)
    return 0

print(fisier(open("text.txt", "r")))