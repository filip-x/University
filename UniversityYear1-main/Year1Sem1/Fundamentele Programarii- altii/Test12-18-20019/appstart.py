from ui import UI
from driverrepo import DriverRepo
from orderrepo import OrderRepo


def start_app():
    driver = DriverRepo("driverfile.txt")
    order = OrderRepo("orderfile.txt")
    call_ui = UI(driver,order)
    call_ui.start()


start_app()
