/*********************************************************************
 * Módulo 2. Curso de Experto en Desarrollo de Videojuegos
 * Autor: Carlos González Morcillo     Carlos.Gonzalez@uclm.es
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
#include "MyFrameListener.h"

MyFrameListener::MyFrameListener(MyApp* myApp,
				 Ogre::RenderWindow* win, 
				 Ogre::Camera* cam, 
				 Ogre::SceneNode *node, 
				 Ogre::OverlayManager *om,
				 Ogre::SceneManager* sm) {
  OIS::ParamList param;
  size_t windowHandle;  std::ostringstream wHandleStr;

  _pMyApp = myApp;
  _camera = cam;  _node = node; _overlayManager = om;
  _sceneManager = sm;

  _shadowInfo = "STENCIL_MODULATIVE";
  _materialInfo = "Material";
  
  win->getCustomAttribute("WINDOW", &windowHandle);
  wHandleStr << windowHandle;
  param.insert(std::make_pair("WINDOW", wHandleStr.str()));
  
  _inputManager = OIS::InputManager::createInputSystem(param);
  _keyboard = static_cast<OIS::Keyboard*>
    (_inputManager->createInputObject(OIS::OISKeyboard, false));
  _mouse = static_cast<OIS::Mouse*>
    (_inputManager->createInputObject(OIS::OISMouse, false));
}

MyFrameListener::~MyFrameListener() {
  _inputManager->destroyInputObject(_keyboard);
  _inputManager->destroyInputObject(_mouse);
  OIS::InputManager::destroyInputSystem(_inputManager);
}

bool MyFrameListener::frameStarted(const Ogre::FrameEvent& evt) {
  Ogre::Vector3 vt(0,0,0);     Ogre::Real tSpeed = 20.0;  
  Ogre::Real r = 0;
  Ogre::Real deltaT = evt.timeSinceLastFrame;
  int fps = 1.0 / deltaT;

  _keyboard->capture();
  if(_keyboard->isKeyDown(OIS::KC_ESCAPE)) return false;
  if(_keyboard->isKeyDown(OIS::KC_UP))    vt+=Ogre::Vector3(0,0,-1);
  if(_keyboard->isKeyDown(OIS::KC_DOWN))  vt+=Ogre::Vector3(0,0,1);
  if(_keyboard->isKeyDown(OIS::KC_LEFT))  vt+=Ogre::Vector3(-1,0,0);
  if(_keyboard->isKeyDown(OIS::KC_RIGHT)) vt+=Ogre::Vector3(1,0,0);
  if(_keyboard->isKeyDown(OIS::KC_W))   vt+=Ogre::Vector3(0,0,-1);
  if(_keyboard->isKeyDown(OIS::KC_S))   vt+=Ogre::Vector3(0,0,1);
  if(_keyboard->isKeyDown(OIS::KC_A))   vt+=Ogre::Vector3(-1,0,0);
  if(_keyboard->isKeyDown(OIS::KC_D))   vt+=Ogre::Vector3(1,0,0);

  if(_keyboard->isKeyDown(OIS::KC_1)) {
    _sceneManager->setShadowTechnique(Ogre::SHADOWTYPE_TEXTURE_MODULATIVE);
    _shadowInfo = "TEXTURE_MODULATIVE";
    _pMyApp->getSoundFXPtr()->play();
  }

  if(_keyboard->isKeyDown(OIS::KC_2)) {
    _sceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
    _shadowInfo = "STENCIL_MODULATIVE";
    _pMyApp->getSoundFXPtr()->play();
  }

  Ogre::Entity *ent = static_cast <Ogre::Entity *> (_node->getAttachedObject("Neptuno"));
  if(_keyboard->isKeyDown(OIS::KC_7)) {
    ent->setMaterialName("Material");  
    _materialInfo = "MaterialBase";
  }
  if(_keyboard->isKeyDown(OIS::KC_8)) {
    ent->setMaterialName("MaterialAO");  
    _materialInfo = "MaterialAO";
  }
  if(_keyboard->isKeyDown(OIS::KC_9)) {
    ent->setMaterialName("MaterialTex");  
    _materialInfo = "MaterialTex";
  }
  if(_keyboard->isKeyDown(OIS::KC_0)) {
    ent->setMaterialName("MaterialAOTex");
    _materialInfo = "MaterialAOTex";
  }  
  
  _camera->moveRelative(vt * deltaT * tSpeed);
  if (_camera->getPosition().length() < 10.0) {
    _camera->moveRelative(-vt * deltaT * tSpeed);
  }


  if(_keyboard->isKeyDown(OIS::KC_E)) r+=180;
  if(_keyboard->isKeyDown(OIS::KC_Q)) r-=180;
  _node->yaw(Ogre::Degree(r * deltaT));
  
  _mouse->capture();
  float rotx = _mouse->getMouseState().X.rel * deltaT * -1;
  float roty = _mouse->getMouseState().Y.rel * deltaT * -1;
  _camera->yaw(Ogre::Radian(rotx));
  _camera->pitch(Ogre::Radian(roty));

  Ogre::OverlayElement *oe;
  oe = _overlayManager->getOverlayElement("fpsInfo");
  oe->setCaption(Ogre::StringConverter::toString(fps));

  oe = _overlayManager->getOverlayElement("shadowInfo");
  oe->setCaption(_shadowInfo);

  oe = _overlayManager->getOverlayElement("materialInfo");
  oe->setCaption(_materialInfo);


  return true;
}
