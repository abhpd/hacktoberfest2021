The website is targeted at solving the issue which many faculties face during online classes which is the attendance for the respective session. It is intended to  ensure that the student really attend the meeting and not just leave the meeting with passive video on.

You can also refer:
* https://dev.to/scottydocs/how-to-write-a-kickass-readme-5af9
* https://blog.bitsrc.io/how-to-write-beautiful-and-meaningful-readme-md-for-your-next-project-897045e3f991?gi=fb7d021f516d

You can include things like:
* short description
* features
* libraries needed
* how it works
* how to run it etc


## TODO
* REST API
    * Add all tables
        * Come up with a way to handle attendance storage (hour wise, or minute wise, etc)
    * Have APIs to create, read, update and delete
        * student
        * faculty
        * class
        * attendance
    * Add result processing to show aggregate attendance for
        * student
        * class
    * Generate sample data
    * Improve security through JWT and test it
    * Replace name with ID
    * Test all APIs
* Facial Recognition
    * Research about facial recognition in python
    * Add facial recognition module
    
## RUN INSTRUCTIONS
* To run app 

    ` python app.py `
* Execute all command in venv 
* Database run command

     `python db_setup.py` 
     
 * To run server from anywhere 
 
       `python -m http.server`             
     
            
