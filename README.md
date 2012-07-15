SmallGameEngine
===============

This small game engine, or if you look at it in more detail it's actually just a state machine, is the result of a [thread in the SFML forum](http://en.sfml-dev.org/forums/index.php?topic=8536.0), where someone pointed to a [tutorial on a state machine](http://gamedevgeek.com/tutorials/managing-game-states-in-c/) programmed in C++ and intended for the graphics [Simple DirectMedia Libraray (SDL)](http://libsdl.org/). I've taken the questions as a challenge and transformed the sourcecode to make use of the Simple and Fast Multimedia Library (SFML) instead. In addition to that I've made a few other changes regarding better C++ conventions and [RAII](https://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization).
I'm not sure if this is a project I'll make much or any changes on but I might base a small game on it just for fun.

License
===============

Although I don't own the rights on the sourcecode the engine is based on I'll release it under the zlib license anyway. For further details take a look at the [LICENSE](https://github.com/eXpl0it3r/SmallGameEngine/blob/master/LICENSE) file.

Credits
===============
A big thanks for [the tutorial](http://gamedevgeek.com/tutorials/managing-game-states-in-c/) in the first place goes out to [Anthony Lewis](http://anthonylewis.com/about/), make sure to checkout his [development blog](http://gamedevgeek.com/) and his [personal blog](http://anthonylewis.com/).
Thanks to [kurayama](http://en.sfml-dev.org/forums/index.php?action=profile;u=2646) for the suggestion on using a template based Build() function rather than the Instance() functions embedded in every state class.