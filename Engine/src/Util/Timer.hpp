#pragma once
#include <SDL3/SDL.h>

class Timer {
private:
    Uint64 startTime = 0;
    Uint64 pauseTime = 0;
    Uint64 stopTime = 0;
    bool running = false;
    bool paused = false;

public:
    Timer(bool start = true) {
        if (start) {
            Start();
        }
    }

    void Start() {
        if (!running) {
            running = true;
            paused = false;
            startTime = SDL_GetPerformanceCounter();
            pauseTime = 0;
            stopTime = 0;
        }
    }

    void Stop() {
        if (running) {
            running = false;
            stopTime = SDL_GetPerformanceCounter();
        }
    }

    void Pause() {
        if (running && !paused) {
            paused = true;
            pauseTime = SDL_GetPerformanceCounter();
        }
    }

    void Unpause() {
        if (running && paused) {
            startTime += SDL_GetPerformanceCounter() - pauseTime;
            paused = false;
        }
    }

    Uint64 GetTicks() const {
        if (!running) {
            return stopTime - startTime;
        } else if (paused) {
            return pauseTime - startTime;
        } else {
            return SDL_GetPerformanceCounter() - startTime;
        }
    }

    double GetTimeInSeconds() const {
        return static_cast<double>(GetTicks()) / SDL_GetPerformanceFrequency();
    }

    bool IsStarted() const {
        return running;
    }

    bool IsPaused() const {
        return paused;
    }

    void Reset() {
        running = false;
        paused = false;
        startTime = 0;
        pauseTime = 0;
        stopTime = 0;
    }
};
