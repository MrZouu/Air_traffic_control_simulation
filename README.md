# Air traffic control simulation
A program simulating a Air traffic control in 2D. 

![Language](https://img.shields.io/badge/Language-C%2B%2B-0052cf)
![Language](https://img.shields.io/badge/Allegro-02A9FF?style=logo=Allegro&logoColor=white)

##  Description
This simulator allows you to follow the flights and ground stations of a number of aircraft and to 
to confront the problems of air traffic control. It will put into practice some algorithms of 
graph theory in order to bring a solution to this task.


⚠️This project is the result of a common work, made for school with a deadline and I chose to leave it as it was at the time of submission

# Install
### What I used
* A compiler :
    * **[CodeBlocks](http://www.codeblocks.org/downloads/binaries/)** *(MinGW setup)*
* Allegro:
    * **[Allegro](https://github.com/MrZouu/Saboteur/blob/main/allegro_4_4_3_install.zip)**
### Add Allegro
* With **[allegro_4_4_3_install.zip](https://github.com/MrZouu/Saboteur/blob/main/allegro_4_4_3_install.zip)**
  * Extract the .zip file to -> **\Program Files\CodeBlocks\MinGW**
  * Press "Ok"
* In **Codeblocks**
  * Compiler -> Linker settings -> Add
  * Click on the file icon
  * Go to **\Program Files\CodeBlocks\MinGW\bin**
  * If the file is empty, select the "All files" option
  * Open Alegg44.dll

# Features
## Main Menu
* The menu is a console interface with
   * **Liste des aeroports** - List of airports
   * **Liste des trajets (Liste d'adjacence)** - All connections between airports
   * **Liste des avions** - Different types of aircraft and their characteristics
   * **Liste des aeroports IHM** - List of airports with Allegro
   * **Effectuer un trajet** - Routes to go from one airport to another
   * **Crise mondiale energetique** - Shows the minimum distance to travel to all airports
   * **Trajet avec IHM** - All connections between airports with Allegro
   * **Quitter** - Leave
   
   #### HMI display :
   <p align="center">
	<img src="https://imgur.com/VacoAfL.png" width="800">
   </p>
   
##  User guide
* Interactions with the console

Select an option by writing the corresponding number

Press enter to confirm

Press ESC to exit HMI display

* Interactions with the mouse

Use the mouse to display airport information on the map

#  Credits
* [**MrZouu**](https://github.com/MrZouu) : Co-creator of the project. 
* **Léo La Fornara** : Co-creator of the project.
