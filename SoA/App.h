#pragma once

#ifndef App_h_
#define App_h_

#include <Vorb/MainGame.h>

class DevScreen;
class InitScreen;
class LoadScreen;
class MainMenuScreen;
class GamePlayScreen;
class MeshManager;
class TexturePackLoader;
class SpaceSystem;
class StarSystemScreen;
class IOManager;

class App : public MainGame {
public:
    virtual ~App();

    virtual void addScreens();
    virtual void onInit();
    virtual void onExit();

    // Accessible Pointers To Screens
    InitScreen* scrInit = nullptr;
    LoadScreen* scrLoad = nullptr;
    MainMenuScreen* scrMainMenu = nullptr;
    GamePlayScreen* scrGamePlay = nullptr;
    StarSystemScreen* scrStarSystem = nullptr;

    SpaceSystem* spaceSystem = nullptr; ///< Space ECS
    DevScreen* scrDev = nullptr;
    std::vector<IGameScreen*> scrTests;
    IOManager* saveFileIom = nullptr;

    // TODO(Ben): This can go somewhere else v v v
    MeshManager* meshManager = nullptr; ///< Stores chunk, terrain, particle, and physics block meshes
};

#endif // App_h_