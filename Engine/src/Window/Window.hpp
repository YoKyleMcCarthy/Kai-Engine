//
//  Window.hpp
//  2DGame
//
//  Created by Kyle McCarthy on 2/3/2025.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <iostream>
#include <SDL3/SDL.h>
#include <Math/Vec2.hpp>

class Window {
private:
    SDL_Window* window;
    std::string title;
public:
    Vec2<float> windowSize;
    bool isOpen = false;
public:
    Window(std::string title, Vec2<float> size): title(title) {
        windowSize = size;
        window = SDL_CreateWindow(title.c_str(), size.x, size.y, SDL_WINDOW_RESIZABLE);
        if(window == NULL) {
            std::cout << "[Window-Error]--> " << SDL_GetError() << std::endl;
        } else {
            isOpen = true;
        }
    }
    
    void resize() {
        int win_w, win_h;
        SDL_GetWindowSize(window, &win_w, &win_h);
        windowSize.x = win_w;
        windowSize.y = win_h;
    }
    
    void Close() { isOpen = false; }
    
    SDL_Window* Get() {
        return window;
    }
    
    ~Window() {
        SDL_DestroyWindow(window);
    }
};

#endif /* Window_hpp */
