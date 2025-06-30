#ifndef CROWD_MOMENTUM_SYSTEM_H
#define CROWD_MOMENTUM_SYSTEM_H

#include <string>

// Forward declarations
class Team;
class Stadium;

// ----------------------------
// GameManager
// ----------------------------
class GameManager {
private:
    int currentMomentum;
    std::string currentGameState;
    Team* homeTeam;
    Team* awayTeam;
    Stadium* stadium;

public:
    GameManager();
    void updateMomentum();
    void applyCrowdEffects();
    int getMomentumLevel() const;
};

// ----------------------------
// CrowdManager
// ----------------------------
class CrowdManager {
private:
    float crowdVolume;
    int momentumLevel;
    float rivalryModifier;
    float excitementFactor;

public:
    CrowdManager();
    void calculateVolume();
    void updateCrowdState();
    float getCrowdIntensity() const;
};

// ----------------------------
// PlayerEffectController
// ----------------------------
class PlayerEffectController {
private:
    float qbReadDelay;
    int routeConfusionChance;
    float penaltyChance;

public:
    PlayerEffectController();
    void applyCrowdPenalties();
    void clearEffects();
    void simulateCrowdImpact();
};

// ----------------------------
// Stadium
// ----------------------------
class Stadium {
private:
    std::string name;
    float baseNoiseLevel;
    int maxCapacity;
    float homeFieldBonus;

public:
    Stadium(std::string stadiumName, float noiseLevel, int capacity, float bonus);
    float getNoiseMultiplier() const;
    bool isRivalryGame(const Team& home, const Team& away) const;
};

// ----------------------------
// Team
// ----------------------------
class Team {
private:
    std::string name;
    int fanBaseSize;
    int teamPrestige;

public:
    Team(std::string teamName, int fans, int prestige);
    int getFanSupportLevel() const;
    void getTeamStats() const;
    std::string getTeamName() const;
};

#endif // CROWD_MOMENTUM_SYSTEM_H
