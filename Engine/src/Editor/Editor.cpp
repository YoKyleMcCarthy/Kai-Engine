#include "Editor.hpp"

void Editor::Init() {
    sceneManager = SceneManager::GetInstance();
    currentScene = SceneManager::GetInstance()->getCurrentScene();
}

void Editor::Update(float deltaTime) {
    float x, y;
    SDL_GetMouseState(&x, &y);
    mousePos.x = ((int)x / 32) * 32;
    mousePos.y = ((int)y / 32) * 32;

}

void Editor::Show() {
    showMouseGridOnly ? DrawMouseGrid() : Draw();
}

void Editor::Draw() {
    // Grid settings
    int gridSize = 5;  // 3x3 grid
    int cellSize = 32;

    // Calculate top-left starting point for the 3x3 grid
    int startX = mousePos.x - (cellSize * (gridSize / 2));
    int startY = mousePos.y - (cellSize * (gridSize / 2));

    // **Draw internal vertical lines (skip first & last)**
    for (int i = 1; i < gridSize; i++) {  // Skip i = 0 and i = gridSize
        int x = startX + (i * cellSize);
        SDL_SetRenderDrawColor(sceneManager->getRenderer(), 0, 0, 0, 50);  // Slight transparency
        SDL_RenderLine(sceneManager->getRenderer(), x, startY, x, startY + (gridSize * cellSize));
    }

    // **Draw internal horizontal lines (skip first & last)**
    for (int i = 1; i < gridSize; i++) {
        int y = startY + (i * cellSize);
        SDL_SetRenderDrawColor(sceneManager->getRenderer(), 0, 0, 0, 50);
        SDL_RenderLine(sceneManager->getRenderer(), startX, y, startX + (gridSize * cellSize), y);
    }
    

}

void Editor::DrawGrid() {
    // draws grid based off camera position
}

void Editor::DrawMouseGrid() {
    // Grid settings
    int gridSize = 5;  // 3x3 grid
    int cellSize = 32;

    // Calculate top-left starting point for the 3x3 grid
    int startX = mousePos.x - (cellSize * (gridSize / 2));
    int startY = mousePos.y - (cellSize * (gridSize / 2));

    // **Draw internal vertical lines (skip first & last)**
    for (int i = 1; i < gridSize; i++) {  // Skip i = 0 and i = gridSize
        int x = startX + (i * cellSize);
        SDL_SetRenderDrawColor(sceneManager->getRenderer(), 0, 0, 0, 50);  // Slight transparency
        SDL_RenderLine(sceneManager->getRenderer(), x, startY, x, startY + (gridSize * cellSize));
    }

    // **Draw internal horizontal lines (skip first & last)**
    for (int i = 1; i < gridSize; i++) {
        int y = startY + (i * cellSize);
        SDL_SetRenderDrawColor(sceneManager->getRenderer(), 0, 0, 0, 50);
        SDL_RenderLine(sceneManager->getRenderer(), startX, y, startX + (gridSize * cellSize), y);
    }
}
