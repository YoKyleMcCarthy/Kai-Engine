#pragma once

#include <iostream>
#include "Asset.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <Scene/SceneManager.hpp>

class Texture: public Asset {
private:
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
public:
    Texture(std::string path, std::string name, SDL_Renderer* renderer) : Asset(AssetType::Texture, path, name), renderer(renderer) {}
    void Load() override {
        surface = IMG_Load(path.c_str());
        if (surface == nullptr) {
            std::cout << "Failed to load texture: " << name << std::endl;
            return;
        } else {
            std::cout << "Loaded texture: " << name << std::endl;
        }
        texture = SDL_CreateTextureFromSurface(SceneManager::GetInstance()->getRenderer(), surface);
        if (texture == nullptr) {
            std::cout << "Failed to create texture: " << name << std::endl;
            std::cout << SDL_GetError() << std::endl;
            return;
        }
        std::cout << "Loading texture: " << name << std::endl;
    };
    void Unload() override {
        if(surface != NULL) SDL_DestroySurface(surface);
        if(texture != NULL) SDL_DestroyTexture(texture);
        std::cout << "Unloading texture: " << name << std::endl;
    }
    void Reload() override {
        Unload();
        Load();
        std::cout << "Reloading texture: " << name << std::endl;
    }
    void Destroy() override {
        Unload();
        std::cout << "Destroying texture: " << name << std::endl;
    }
    SDL_Texture* Get() {
        return texture;
    }
};