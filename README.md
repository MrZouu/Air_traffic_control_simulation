# Air traffic control simulation
A program simulating a Air traffic control in 2D. 

![Language](https://img.shields.io/badge/Language-C%2B%2B-0052cf)
![Language](https://img.shields.io/badge/Allegro-02A9FF?style=logo=Allegro&logoColor=white)

***Project date : 2022***

##  Description
This simulator lets you follow the flights and airports of a number of aircraft, and confront the problems of air traffic control. 

It applies a range of graph theory algorithms to provide a solution to this task. 

<p align="center">
	<img src="images/air_traffic.jpg" width="600">
</p>

⚠️This project is the result of a common work, made for school with a deadline and I chose to leave it as it was at the time of submission

# Install
### What I used
* A compiler :
    * **[CodeBlocks](http://www.codeblocks.org/downloads/binaries/)** *(MinGW setup)*
* Allegro:
    * **[Allegro](https://github.com/MrZouu/Air_traffic_control_simulation/blob/main/allegro_4_4_3_install.zip)**
### Add Allegro
* Go to the **[Allegro file](https://github.com/MrZouu/Air_traffic_control_simulation/blob/main/allegro_4_4_3_install.zip)**
  * Extract the .zip file to -> **`\Program Files\CodeBlocks\MinGW`**
  * Press "Ok"

I had Allegro malfunctions while having the OpenCV library installed on a device

* In **Codeblocks**
  * `Compiler -> Linker settings -> Add`
  * Click on the file icon
  * Go to **`\Program Files\CodeBlocks\MinGW\bin`**
  * If the file is empty, select the "All files" option
  * Open `Alegg44.dll`

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
   
<p align="center"><b>HMI display</b></p>
   <p align="center">
	<img src="https://imgur.com/VacoAfL.png" width="600">
   </p>
   
##  User guide
**Interactions with the console**

* Select an option by writing the corresponding number

* Press enter to confirm

* Press ESC to exit HMI display

**Interactions with the mouse**

* Use the mouse to display airport information on the map

#  Credits
* [**Lorenzo**](https://github.com/MrZouu) : Co-creator of the project. 
* **Léo La Fornara** : Co-creator of the project.
