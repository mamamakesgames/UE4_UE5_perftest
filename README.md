# UE4_UE5_perftest

This is a simple test project for comparing performance between UE4 and UE5. It consists of two levels, one completely empty and the other having a directional light, a navigable ground plane, and spawning 1,500 C++ based teapot characters on level start. A primitive UMG widget swaps between these levels.

On my system, I'm seeing a performance difference where UE4 is about **70% faster** than UE5. To compare for yourself, clone the project, open and build in UE4. Then open it again in UE5, converting a copy, and build there. Or, to just test the results on your own system, please check out the [Releases](https://github.com/mamamakesgames/UE4_UE5_perftest/releases). Thanks!

Kimberly Blais (kim@mamamakesgames.com)<br>
https://tiktok.com/@MamaMakesGames<br>
https://instagram.com/MamaMakesGames<br>
https://twitter.com/MamaMakesGames
