from ui import UI
from humanrepo import HumanRepo


def start_app():
    human = HumanRepo("humanfile.txt")
    call_ui = UI(human)
    call_ui.start()

start_app()


