# SmallGameEngine

This small game engine, or if you look at it in more detail it's actually just a state machine, is the result of a [thread in the SFML forum](https://en.sfml-dev.org/forums/index.php?topic=8536.0), where someone pointed to a [tutorial on a state machine](http://gamedevgeek.com/tutorials/managing-game-states-in-c/) programmed in C++ and intended for the graphics [Simple DirectMedia Library (SDL)](https://www.libsdl.org/). I've taken the question as a challenge and transformed the source code to make use of the [Simple and Fast Multimedia Library (SFML)](https://www.sfml-dev.org/) instead. Meanwhile I've added quite a few changes to not only provide a more modern approach to C++ by using features from the new C++17 standard, as well as utilizing idioms likes [RAII](https://bromeon.ch/articles/raii.html), but also to encapsulate classes a bit better.

## License

This software is available under 2 licenses -- choose whichever you prefer.  
For further details take a look at the [LICENSE](https://github.com/eXpl0it3r/SmallGameEngine/blob/master/LICENSE) file.

- Public Domain
- MIT

## Credits

A big thanks for [the tutorial](http://gamedevgeek.com/tutorials/managing-game-states-in-c/) in the first place goes out to [Anthony Lewis](https://anthonylewis.com/about/), make sure to checkout his [development blog](http://gamedevgeek.com/) and his [personal blog](https://anthonylewis.com/).
Thanks to [kurayama](https://en.sfml-dev.org/forums/index.php?action=profile;u=2646) for the suggestion on using a template based `Build()` function rather than the `Instance()` functions embedded in every state class.