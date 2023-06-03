# Morpion

Small Object Oriented Program made in C++. It only has the basics, I didn't spent much time on the UI but it actually works :)

Made with :
- Visual Studio CE 2022
- C++ 20
- SFML

## So how does it work ?

Basically the main.cpp instanciates the Game class, who hold the game loop inside its run function.

The Game Class generates and manages the window based with the parameters defined inside the WindowSettings class, which is made static. It also instanciates the PlayGround class who acts as a game Manager.

The PlayGround class is holding all the differents element of the games, such as the cursor, the circles and the cross. He gathers inputs so it can act on the elements (which is kind of a bad conception since the inputs should only trigger the cursor, but I failed to make it better). It is also called by the Playground for drawing every pieces of the game, which are smart pointers holded in a vector. Last but not least, it checks all the victory's contidions.

We have a ResourcesManager which contains cache of the different textures (inspired, if not copied from Nicolas Koenig in his Udemy's courses). I've planned to add sound effect so it is also made for this, but I didn't push it this far).

And last, we have the different elements of the game. The Elements class and its derived classes.

This project was made during a short week, and was purely intended to train myself into game developpement. Of course it is free of any kind of use.
