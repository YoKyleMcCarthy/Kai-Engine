#include "AssetManager.hpp"

AssetManager* AssetManager::instance = nullptr;

AssetManager::AssetManager() {}

AssetManager* AssetManager::GetInstance() {
    if (instance == nullptr) {
        instance = new AssetManager();
    }
    return instance;
}

// check if asset already exists
Asset* AssetManager::CheckIfLoaded(Asset* asset) {
    for (auto const& [key, val] : assets) {
        if (val->path == asset->path) {
            std::cout << "Asset path already loaded under: " << asset->name << std::endl;
            return val;
        }
        if(val->name == asset->name) {
            std::cout << "Asset name already used modifying name: " << asset->name << std::endl;
            asset->name += std::to_string(asset->id);
        }
        return asset;
    }
    return asset;
}


void AssetManager::LoadAsset(std::string path, AssetType type, std::string name = "") {
    Asset* asset;
    if(name == "") {
        name = std::to_string(asset->id);
    }
    std::cout << "Loading asset: " << name << std::endl;

    asset = CheckIfLoaded(asset);

    switch (type) {
        case AssetType::Texture:
            asset = new Texture(path, name, nullptr);
            break;
    }
    assets[name] = asset;
    asset->Load();
}

Asset* AssetManager::asset(std::string name) {
    if (assets.find(name) == assets.end()) {
        std::cout << "Asset not found: " << name << std::endl;
        return nullptr;
    }
    return assets[name];
}

void AssetManager::UnloadAsset(Asset* asset) {

    if (assets.find(asset->name) == assets.end()) {
        std::cout << "Asset not found: " << asset->name << std::endl;
        return;
    }
    asset->Unload();
}

void AssetManager::ReloadAsset(Asset* asset) {
    if (assets.find(asset->name) == assets.end()) {
        std::cout << "Asset not found: " << asset->name << std::endl;
        return;
    }
    asset->Reload();
}

void AssetManager::DestroyAsset(Asset* asset) {

    if (assets.find(asset->name) == assets.end()) {
        std::cout << "Asset not found: " << asset->name << std::endl;
        return;
    }
    asset->Destroy();
}

