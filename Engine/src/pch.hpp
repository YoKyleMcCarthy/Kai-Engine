#pragma once

// std libs
#include <iostream>
#include <map>
#include <vector>


// 3rd party libs
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

// Export API

#ifdef KAI_EXPORT
    #ifdef _MSC_VER
        #define KAI_API __declspec(dllexport)
    #else
        #define KAI_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define KAI_API __declspec(dllimport)
    #else
        #define KAI_API
    #endif
#endif

// Loggin System

#if defined(_DEBUG)
    #define KAI_LOG(level, message, ...) \
    fprintf(stderr, "[%s] ", level); \
    fprintf(stderr, message, ##__VA_ARGS__); \
    fprintf(stderr, "\n");

    #define WARNING(message, ...) KAI_LOG("WARNING", message, ##__VA_ARGS__)
    #define ERROR(message, ...) KAI_LOG("ERROR", message, ##__VA_ARGS__)
    #define INFO(message, ...) KAI_LOG("INFO", message, ##__VA_ARGS__)
#else
    #define WARNING
    #define ERROR
    #define INFO
#endif


// Function inlining
#if defined(__clang__) || defined(__gcc__)
    #define KAI_INLINE __attribute__((always_inline)) inline
    #define KAI_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
    #define KAI_INLINE __forceinline
    #define KAI_NOINLINE __declspec(noinline)
#else
    #define KAI_INLINE inline
    #define KAI_NOINLINE
#endif
