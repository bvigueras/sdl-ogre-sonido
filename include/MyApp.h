/*********************************************************************
 * Módulo 1. Curso de Experto en Desarrollo de Videojuegos
 * Autor: David Vallejo Fernández    David.Vallejo@uclm.es
 * Autor: Carlos González Morcillo  Carlos.Gonzalez@uclm.es
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

#ifndef __MYAPPH__
#define __MYAPPH__

#include <Ogre.h>
#include "MyFrameListener.h"
#include "TrackManager.h"
#include "SoundFXManager.h"

class MyFrameListener;

class MyApp {
  
private:
  Ogre::SceneManager* _sceneManager;
  Ogre::Root* _root;
  MyFrameListener* _framelistener;
  Ogre::OverlayManager* _overlayManager;

  // Manejadores del sonido.
  TrackManager* _pTrackManager;
  SoundFXManager* _pSoundFXManager;
  TrackPtr _mainTrack;
  SoundFXPtr _simpleEffect;
  
public:
  MyApp();
  ~MyApp();  
  int start ();
  bool initSDL ();
  void loadResources ();
  void createScene ();
  void createOverlay ();

  TrackPtr getTrackPtr () { return _mainTrack; }
  SoundFXPtr getSoundFXPtr () { return _simpleEffect; }
};

#endif
