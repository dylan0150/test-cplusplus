SDL_Event e;

void pollEvents() {
  while ( SDL_PollEvent( &e ) != 0 ) {
    switch ( e.type ) {

      case SDL_WINDOWEVENT:
        switch( e.window.event ) {
          case SDL_WINDOWEVENT_SHOWN: SDL_Log("Window %d shown", e.window.windowID ); break;
          case SDL_WINDOWEVENT_HIDDEN: SDL_Log("Window %d hidden", e.window.windowID ); break;
          case SDL_WINDOWEVENT_EXPOSED: SDL_Log("Window %d exposed", e.window.windowID ); break;
          case SDL_WINDOWEVENT_RESIZED: SDL_Log("Window %d resized to %d,%d", e.window.windowID, e.window.data1, e.window.data2); break;
          case SDL_WINDOWEVENT_SIZE_CHANGED: SDL_Log("Window %d size change to to %d,%d", e.window.windowID, e.window.data1, e.window.data2); break;
          case SDL_WINDOWEVENT_RESTORED: SDL_Log("Window %d minimized", e.window.windowID ); break;
          case SDL_WINDOWEVENT_ENTER: SDL_Log("Window %d maximized", e.window.windowID ); break;
          case SDL_WINDOWEVENT_LEAVE: SDL_Log("Window %d maximized", e.window.windowID ); break;
          case SDL_WINDOWEVENT_FOCUS_GAINED: SDL_Log("Window %d maximized", e.window.windowID ); break;
          case SDL_WINDOWEVENT_FOCUS_LOST: SDL_Log("Window %d maximized", e.window.windowID ); break;
          case SDL_WINDOWEVENT_CLOSE: SDL_Log("Window %d maximized", e.window.windowID ); break;
          case SDL_WINDOWEVENT_TAKE_FOCUS: SDL_Log("Window %d maximized", e.window.windowID ); break;
          case SDL_WINDOWEVENT_HIT_TEST: SDL_Log("Window %d maximized", e.window.windowID ); break;
          default: SDL_Log("Unknown window event %d - %d,%d", e.window.windowID, e.window.data1, e.window.data2 );
        }
      break;

      case SDL_KEYDOWN:
        switch ( e.key.keysym.sym ) {
          default: SDL_Log( "Window %d, key code %d, sym %d down, repeat %d", e.key.windowID, e.key.keysym.sym, e.key.keysym.scancode, e.key.repeat );
        }
      break;

      case SDL_KEYUP:
        switch ( e.key.keysym.sym ) {
          default: SDL_Log( "Window %d, key code %d, sym %d up, repeat %d", e.key.windowID, e.key.keysym.sym, e.key.keysym.scancode, e.key.repeat );
        }
      break;

      case SDL_TEXTEDITING: SDL_Log("Event %d", SDL_TEXTEDITING );
        SDL_Log("Window %d, text editted %d, %d characters from %d", e.edit.windowID, e.edit.text, e.edit.start, e.edit.length)
      break;

      case SDL_TEXTINPUT: SDL_Log("Event %d", SDL_TEXTINPUT );
        SDL_Log("Window %d, text input %d", e.edit.windowID, e.edit.text)
      break;

      case SDL_MOUSEMOTION: SDL_Log("Event %d", SDL_MOUSEMOTION ); break;
      case SDL_MOUSEBUTTONDOWN: SDL_Log("Event %d", SDL_MOUSEBUTTONDOWN ); break;
      case SDL_MOUSEBUTTONUP: SDL_Log("Event %d", SDL_MOUSEBUTTONUP ); break;
      case SDL_MOUSEWHEEL: SDL_Log("Event %d", SDL_MOUSEWHEEL ); break;
      case SDL_JOYAXISMOTION: SDL_Log("Event %d", SDL_JOYAXISMOTION ); break;
      case SDL_JOYBALLMOTION: SDL_Log("Event %d", SDL_JOYBALLMOTION ); break;
      case SDL_JOYHATMOTION: SDL_Log("Event %d", SDL_JOYHATMOTION ); break;
      case SDL_JOYBUTTONDOWN: SDL_Log("Event %d", SDL_JOYBUTTONDOWN ); break;
      case SDL_JOYBUTTONUP: SDL_Log("Event %d", SDL_JOYBUTTONUP ); break;
      case SDL_JOYDEVICEADDED: SDL_Log("Event %d", SDL_JOYDEVICEADDED ); break;
      case SDL_JOYDEVICEREMOVED: SDL_Log("Event %d", SDL_JOYDEVICEREMOVED ); break;
      case SDL_CONTROLLERAXISMOTION: SDL_Log("Event %d", SDL_CONTROLLERAXISMOTION ); break;
      case SDL_CONTROLLERBUTTONDOWN: SDL_Log("Event %d", SDL_CONTROLLERBUTTONDOWN ); break;
      case SDL_CONTROLLERBUTTONUP: SDL_Log("Event %d", SDL_CONTROLLERBUTTONUP ); break;
      case SDL_CONTROLLERDEVICEADDED: SDL_Log("Event %d", SDL_CONTROLLERDEVICEADDED ); break;
      case SDL_CONTROLLERDEVICEREMOVED: SDL_Log("Event %d", SDL_CONTROLLERDEVICEREMOVED ); break;
      case SDL_CONTROLLERDEVICEREMAPPED: SDL_Log("Event %d", SDL_CONTROLLERDEVICEREMAPPED ); break;
      case SDL_AUDIODEVICEADDED: SDL_Log("Event %d", SDL_AUDIODEVICEADDED ); break;

      case SDL_QUIT: SDL_Log("Event %d", SDL_QUIT );
        quit = true;
      break;

      case SDL_SYSWMEVENT: SDL_Log("Event %d", SDL_SYSWMEVENT ); break;
      case SDL_FINGERMOTION: SDL_Log("Event %d", SDL_FINGERMOTION ); break;
      case SDL_FINGERDOWN: SDL_Log("Event %d", SDL_FINGERDOWN ); break;
      case SDL_FINGERUP: SDL_Log("Event %d", SDL_FINGERUP ); break;
      case SDL_MULTIGESTURE: SDL_Log("Event %d", SDL_MULTIGESTURE ); break;
      case SDL_DOLLARGESTURE: SDL_Log("Event %d", SDL_DOLLARGESTURE ); break;
      case SDL_DOLLARRECORD: SDL_Log("Event %d", SDL_DOLLARRECORD ); break;
      case SDL_DROPFILE: SDL_Log("Event %d", SDL_DROPFILE ); break;
      case SDL_DROPTEXT: SDL_Log("Event %d", SDL_DROPTEXT ); break;
      case SDL_DROPBEGIN: SDL_Log("Event %d", SDL_DROPBEGIN ); break;
      case SDL_DROPCOMPLETE: SDL_Log("Event %d", SDL_DROPCOMPLETE ); break;
      default: SDL_Log("Unknown event %d", e ); break;
    }
  }
}
