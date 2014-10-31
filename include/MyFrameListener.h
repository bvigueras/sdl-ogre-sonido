/*********************************************************************
 * Módulo 1. Curso de Experto en Desarrollo de Videojuegos
 * Autor: David Vallejo Fernández    David.Vallejo@uclm.es
 * Autor: Carlos González Morcillo  Carlos.Gonzalez@uclm.es
 *
 *
 * You can redistribute and/or modify this file under the terms of the
 * GNU General Public License ad published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * and later version. See <http://www.gnu.org/licenses/>.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.  
 *********************************************************************/

#ifndef __MYFRAMELISTENERH__
#define __MYFRAMELISTENERH__

#include <Ogre.h>
#include <OIS/OIS.h>
#include "MyApp.h"

class MyApp;

class MyFrameListener : public Ogre::FrameListener {
private:
  MyApp* _pMyApp;

  OIS::InputManager* _inputManager;
  OIS::Keyboard* _keyboard;
  OIS::Mouse* _mouse;
  Ogre::Camera* _camera;
  Ogre::SceneNode* _node;
  Ogre::OverlayManager* _overlayManager;
  Ogre::SceneManager* _sceneManager;

  Ogre::String _shadowInfo;
  Ogre::String _materialInfo;

public:
  MyFrameListener(MyApp* myApp,
		  Ogre::RenderWindow* win, Ogre::Camera* cam, 
		  Ogre::SceneNode* node, Ogre::OverlayManager* om, 
		  Ogre::SceneManager* sm);
  ~MyFrameListener();
  bool frameStarted (const Ogre::FrameEvent& evt);  

};

#endif
