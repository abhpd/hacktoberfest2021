# enabling wi-fi option :

import subprocess    # we have to import our subprocess module .

# we will call the run method.
# execute the program to enable wi-fi
MyWish = subprocess.run(['netsh','interface','set','interface',"wi-fi","ENABLED"])
MyWish


# disabling wi-fi option :

import subprocess   # we have to import our subprocess module .

# we will call the run method.
# we will execute the program to disable wi-fi
MyWish = subprocess.run (['netsh', 'interface', 'set', 'interface', "wi-fi", "DISABLED"])
MyWish