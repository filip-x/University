from ui import UI
from busrepo import BusRepo
from reporoute_code import RepoRoute_Code



# this  function reads the file settings and makes the file readable for us in code
def read_settings(file_name, save_settings):
    open_file = open(file_name, "r")
    # strips it strips the the spaces at the end of an string and at the beginning
    line = open_file.readline().strip()
    while len(line) > 0:
        # it takes the words in the seq apart and then we remove the spaces
        line_items = line.split("=")
        # first element like repository students,assignemtns or grades
        line_items[0] = line_items[0].strip()
        # the second element will  be the element in the ""
        line_items[1] = line_items[1].strip()
        # here we eliminate the "" so that we will not work with and all the things will be the same ( it's okay with or without/ it dosen't mater)
        line_items[1] = line_items[1].strip("\"")
        # it puts in the dictionary the final info/ it saves the dictionary in the final form students= ....
        save_settings[line_items[0]] = line_items[1]
        line = open_file.readline().strip()  # we read the next line
    open_file.close()


def create_dictionary():  # the creation of the dictionary
    return {}


def start_settings():
    # the dictionary will be transferd to save_settings
    save_settings = create_dictionary()
    buses = None  # at first all  3 are empty
    route_code = None
    # here me make the connection between the dictionary,file.settings and the function read)
    read_settings("settings.properties", save_settings)
    # it checks the repository if it is in memory or in files

    if save_settings["repository"] == "textfiles":
        # we assign the repositorys to the files
        buses = BusRepo(save_settings["buses"])  # we assign the repositorys to the files
        route_code = RepoRoute_Code(save_settings["route_code"])
    

    call_ui = UI(buses,route_code)   # we start the program
    call_ui.start()


start_settings()
