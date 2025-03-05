#pragma once
#include <iostream>
enum class AssetType {
    Texture,
};
class Asset {
public:
    AssetType type;
    std::string path;
    std::string name;
    int id = 0;
    Asset(AssetType type, std::string path, std::string name) : type(type), path(path), name(name) {
        static int idCounter = 0;
        id = idCounter++;
    }
    virtual void Load() = 0;
    virtual void Unload() = 0;
    virtual void Reload() = 0;
    virtual void Destroy() = 0;
};