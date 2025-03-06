#pragma once

#include <iostream>
#include <map>
#include "Asset.hpp"
#include "Texture.hpp"
class AssetManager {
private:
    static AssetManager* instance;
    AssetManager();
public:
    static AssetManager* GetInstance();
    std::map<std::string, Asset*> assets;
    void LoadAsset(Asset* asset);
    void LoadAsset(std::string path, AssetType type, std::string name);
    Asset* asset(std::string name);
    bool UnloadAsset(Asset* asset);
    bool UnloadAsset(std::string name);
    void ReloadAsset(Asset* asset);
    void DestroyAsset(Asset* asset);
    Asset* CheckIfLoaded(Asset* asset);
};