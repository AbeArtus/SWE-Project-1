# SWE-Project-1
Final project for the SWE class: "The fridge app"



## Requirements

**Fill with X when completed**

[X] Software product may be a web application, desktop application, or mobile application (students are encouraged to self-select one of these types based on their previous experience). The product must be built ”from scratch” and not based on a starting point of a product already in existence or for another course

[X] Source code (and, ideally, more such as configuration files) must be kept in a public-accesible GitHub.com repository. A portion of the evaluation for a grade on the project will be based on following reasonable Git and branching practices.

[X]  Some portion of the software product must involve persistent data stored on a disk or database which lasts longer than a user’s individual ”session” using the application.

[  ]  Some portion of the software product’s functionality must be packaged and accessed as a web service hosted from an Internet-accessible hosting service (of which many free services exist and can be used).

[  ]  Some portion of the software product’s functionality must be only accessible after user has authenti- cated themselves to the software product via either a custom authentication system (i.e., the software stores usernames and passwords such that the user must enter a correct pair of username and password  data) or a third-party integrated authentication system (e.g., Google account). It may be that some functionality is accessible without authentication or the software knowing the identity of the user.

[ ] The software product must have a graphical user interface (GUI) using whatever GUI framework or toolkit the group prefers

[  ] The software product development lifecycle must have some form of continuous integration and executable testing such that on commit or push to GitHub some automated actions are taken to compile / build and execute tests to ensure new changes have not broken functionality (which is tested, anyway).

## Project specifications

### Persistent Data

#### Userfile / fridge file

<p>The username, password, and fridge items are all stored in the usr file in the directory</p>

<p>
~/usr
</p>

<p>
The file name will be the username<br>
EX: username.txt
</p>

With the file format of:

<p>
[username]<br>
[password]<br>
[Ingredients]<br>
</p>

#### Recipe Files and Directory Structure

<p>
The Directory files are stored inside of the directories:
</p>

<p>
~/Recipes/Breakfast/...<br>
~/Recipes/Lunch/...<br>
~/Recipes/Dinner/...<br>
~/Recipes/Snacks/...<br>
</p>
<p>With each recipe file haveing the format of:</p>
<p>
[name of recipe]<br>
#<br>
[Serving Size]<br>
#<br>
[Description]<br>
#<br>
[Ingredients]<br>
#<br>
[Directions]<br>
</p>

