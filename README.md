# Basic example on OGRE

This is an easy example where we use several features:

* Sound tracks as BGM and sound effects.
* Basic input system.
* Illumination and shadow types.
* Diferent material types.
* Overlays for simple UI.

The main track will be playing from the beginning, every time the keys "1" or "2" are pressed the illumination type will change while playing a sound effect. Keys "7" to "0" will change the sculpture material. Keys "Q" and "E" will make the sculpture rotate and "WASD" and cursor keys will move the camera. Mouse can be use to look around.

This code is part of the book "Curso de Experto en Desarrollo de Videojuegos" by University of Castilla-La Mancha. The book and original source code can be found on its [official site]

## Dependencies

  * SDL 1.2
  * Ogre3d 1.8
  * OIS

### Dependencies installation on Debian based system:

#### Basic tools:
```sh
$ sudo apt-get install build-essential
```
#### SDL:
```sh
 $ sudo apt-get update
 $ sudo apt-get install libsdl1.2-dev
 $ sudo apt-get install install libsdl-image1.2-dev
 $ sudo apt-get install install libsdl-sound1.2-dev libsdl-mixer1.2-dev
```
#### Ogre3d 1.8:
```sh
$ sudo apt-get libogre-1.8.0 libogre-1.8-dev ogre-1.8-doc ogre-1.8-tools
```
#### OIS:
```sh
$ sudo apt-get install libois-1.3.0 libois-dev
```

License
----
GPLv3

[official site]:http://www.cursodesarrollovideojuegos.com/
