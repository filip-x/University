from ui import UI
from studentrepo import StudentRepo


def start_app():
    student = StudentRepo("studentfile.txt")
    call_ui = UI(student)
    call_ui.start()


start_app()
