#include "stdafx.h"
#include "Inputs.h"

#include "GameManager.h"
#include "InputManager.h"
#include "EventManager.h"

#include <stdio.h>

// Input Commands Sorted Alphabetically
i32 INPUT_BLOCK_SCANNER = -1;
i32 INPUT_BLOCK_DRAG = -1;
i32 INPUT_CROUCH = -1;
i32 INPUT_DEBUG = -1;
i32 INPUT_DRAW_MODE = -1;
i32 INPUT_FLASH_LIGHT = -1;
i32 INPUT_FLY = -1;
i32 INPUT_GRID = -1;
i32 INPUT_HORIZONTAL = -1;
i32 INPUT_HUD = -1;
i32 INPUT_INVENTORY = -1;
i32 INPUT_JUMP = -1;
i32 INPUT_MARKER = -1;
i32 INPUT_MEGA_SPEED = -1;
i32 INPUT_MOUSE_LEFT = -1;
i32 INPUT_MOUSE_RIGHT = -1;
i32 INPUT_PAUSE = -1;
i32 INPUT_PHYSICS_BLOCK_UPDATES = -1;
i32 INPUT_PLANET_DRAW_MODE = -1;
i32 INPUT_PLANET_ROTATION = -1;
i32 INPUT_RELOAD_BLOCKS = -1;
i32 INPUT_RELOAD_SHADERS = -1;
i32 INPUT_RELOAD_TEXTURES = -1;
i32 INPUT_RELOAD_UI = -1;
i32 INPUT_SONAR = -1;
i32 INPUT_SCAN_WSO = -1;
i32 INPUT_SPRINT = -1;
i32 INPUT_UPDATE_FRUSTUM = -1;
i32 INPUT_VERTICAL = -1;
i32 INPUT_WATER_UPDATE = -1;
i32 INPUT_ZOOM = -1;
i32 INPUT_RANDOM_DEBUG = -1;

i32 EVENT_BUTTON_DOWN = -1;
i32 EVENT_BUTTON_UP=  -1;

void buttonListener(EventData* data) {
    InputEventData* inputData = static_cast<InputEventData*>(data);
    std::cout << inputData->key << " " << inputData->eventID << std::endl;
}

// Reduce Some Code
#define CREATE_INPUT(ID,KEY,VAR) \
    VAR = GameManager::inputManager->createAxis(#ID, KEY);

#define CREATE_INPUT_D(ID, KEY_NEG, KEY_POS, VAR) \
    VAR = GameManager::inputManager->createAxis(#ID, KEY_NEG, KEY_POS);

// Generate Input Handles
void initInputs() {
    CREATE_INPUT(Random Debug, SDLK_6, INPUT_RANDOM_DEBUG);

    // The Greatest Input In The Cosmos
    CREATE_INPUT(Pause, SDLK_ESCAPE, INPUT_PAUSE);

    // Game Information
    CREATE_INPUT(Debug, SDLK_h, INPUT_DEBUG);
    CREATE_INPUT(Inventory, SDLK_TAB, INPUT_INVENTORY);
    CREATE_INPUT(HUD, SDLK_t, INPUT_HUD);

    // Visual Aid
    CREATE_INPUT(Zoom, SDLK_RCTRL, INPUT_ZOOM);
    CREATE_INPUT(Sonar, SDLK_r, INPUT_SONAR);
    CREATE_INPUT(Flash Light, SDLK_l, INPUT_FLASH_LIGHT);

    // Refreshing Functions
    CREATE_INPUT(Reload Textures, SDLK_F4, INPUT_RELOAD_TEXTURES);
    CREATE_INPUT(Reload Blocks, SDLK_F6, INPUT_RELOAD_BLOCKS);
    CREATE_INPUT(Reload Shaders, SDLK_F11, INPUT_RELOAD_SHADERS);
    CREATE_INPUT(Reload UI, SDLK_F5, INPUT_RELOAD_UI);

    // Visual Debugging
    CREATE_INPUT(Grid Toggle, SDLK_g, INPUT_GRID);
    CREATE_INPUT(Draw Mode, SDLK_m, INPUT_DRAW_MODE);
    CREATE_INPUT(Planet Draw Mode, SDLK_j, INPUT_PLANET_DRAW_MODE);
    CREATE_INPUT(Update Frustum, SDLK_u, INPUT_UPDATE_FRUSTUM);

    // Movement
    CREATE_INPUT(Fly, SDLK_f, INPUT_FLY);
    CREATE_INPUT_D(Vertical, SDLK_w, SDLK_s, INPUT_VERTICAL);
    CREATE_INPUT_D(Horizontal, SDLK_d, SDLK_a, INPUT_HORIZONTAL);
    CREATE_INPUT(Sprint, SDLK_LSHIFT, INPUT_SPRINT);
    CREATE_INPUT(Crouch, SDLK_LCTRL, INPUT_CROUCH);
    CREATE_INPUT(Mega Speed, SDLK_LALT, INPUT_MEGA_SPEED);
    CREATE_INPUT(Jump, SDLK_SPACE, INPUT_JUMP);

    // Gameplay
    CREATE_INPUT(Marker, SDLK_c, INPUT_MARKER);
    CREATE_INPUT(Scan WSO, SDLK_LEFTBRACKET, INPUT_SCAN_WSO);

    // Physics
    CREATE_INPUT(Water Update, SDLK_n, INPUT_WATER_UPDATE);
    CREATE_INPUT(Update Physics Blocks, SDLK_p, INPUT_PHYSICS_BLOCK_UPDATES);
    CREATE_INPUT_D(Planet Rotation, SDLK_MINUS, SDLK_EQUALS, INPUT_PLANET_ROTATION);
    
    // Mouse Buttons
    CREATE_INPUT(Mouse Right, SDL_BUTTON_RIGHT, INPUT_MOUSE_RIGHT);
    CREATE_INPUT(Mouse Left, SDL_BUTTON_LEFT, INPUT_MOUSE_LEFT);
    
    // Block Utilities
    CREATE_INPUT(Block Scanner, SDLK_q, INPUT_BLOCK_SCANNER);
    CREATE_INPUT(Block Select, SDLK_b, INPUT_BLOCK_DRAG);

    EVENT_BUTTON_DOWN = GameManager::eventManager->registerEvent("Button Down");
    EVENT_BUTTON_UP = GameManager::eventManager->registerEvent("Button Up");
    GameManager::eventManager->addEventListener(EVENT_BUTTON_DOWN, buttonListener);
    GameManager::eventManager->addEventListener(EVENT_BUTTON_UP, buttonListener);
}