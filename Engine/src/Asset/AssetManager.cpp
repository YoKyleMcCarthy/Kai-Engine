#include "AssetManager.hpp"
#include <string>
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
    std::cout << "Loading asset: " << name << std::endl;

    Asset* asset = nullptr;
    switch (type) {
        case AssetType::Texture:
            asset = new Texture(path, name, nullptr);
            break;
    }
    asset = CheckIfLoaded(asset);
    if(name == "") {
        name = std::to_string(asset->id);
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

bool AssetManager::UnloadAsset(Asset* asset) {
    asset->Unload();
    return true;
}


bool AssetManager::UnloadAsset(std::string name) {
    auto it = assets.find(name);
    if (it == assets.end()) {
        std::cout << "Asset not found: " << name << std::endl;
        return false;
    }

    it->second->Unload();  // Assuming assets[name] is a pointer to an asset
    assets.erase(it);      // Remove from the map if necessary

    return true;
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

