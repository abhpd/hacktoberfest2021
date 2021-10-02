# Disabling and Enabling Wi-Fi Option Using Python
In this tutorial, we will see how we can use small and simple but interesting python scripts for enabling and disabling wi-fi option of our laptop or desktop.

## Module :
### Subprocess : 
The subprocess module present in python allows us to process the system-level scripts within the piece of python code. Subprocess module was introduced to replace many old modules/functions present in Python. This module has many methods(for example, subprocess.call(), subprocess.run(), subprocess.check_output(), subprocess.Popen() and communicate() functions) for running system level languages or scripts within python environments.

## Some important notes :
Sometimes, after running these python scripts you may get a message in your terminal. It will say that – ” Its required elevation( run as administrator).”

Let’s see how to handle this.

#### Solution 1
1. Firstly, log out from user account and log in to the administrator account.

2. Secondly, open This PC in file explorer, then right click on hard drive and open Properties.

3. Thirdly, follow the steps – Security tab-> Advanced button-> Owner tab-> Edit button.

4. Finally,  select an user as an owner ,save the changes by clicking on Apply and OK.

#### Solution 2
1. Right click the application (on which we are executing the script).

2. Then,  follow the steps – Properties-> Compatibility tab-> Run this program as an administrator.

3. Finally, save the changes by clicking on Apply and OK .
