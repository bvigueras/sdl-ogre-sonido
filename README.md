Basic sound on Ogre
===================
This is an easy example of using sound tracks as BGM and sound effects.

The main track will be playing from the beginning, every time the keys "1" or
"2" are pressed it will play a sound effect.

This code is part of the book "Curso de Experto en Desarrollo de Videojuegos"
by University of Castilla-La Mancha.

Dependencies
------------

  * SDL 1.2
  * Ogre3d 1.8
  * OIS

### Dependencies installation on Debian based system: ###

0. Basic tools:
        $ sudo apt-get install build-essential

1. SDL:

         $ sudo apt-get update
         $ sudo apt-get install libsdl1.2-dev
         $ sudo apt-get install install libsdl-image1.2-dev
         $ sudo apt-get install install libsdl-sound1.2-dev libsdl-mixer1.2-dev

2. Ogre3d 1.8:

         $ sudo apt-get libogre-1.8.0 libogre-1.8-dev ogre-1.8-doc ogre-1.8-tools 

3. OIS:

         $ sudo apt-get install libois-1.3.0 libois-dev
