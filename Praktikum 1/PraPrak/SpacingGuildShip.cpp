#include "SpacingGuildShip.hpp"
#include <cmath>
#include <algorithm> 

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), passengerCount(0), operatingGuildNavigator(3), serialNum(++producedShips), spiceStock(50) {}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), passengerCount(0), operatingGuildNavigator(guildNavigatorCount), serialNum(++producedShips), spiceStock(spiceStock) {}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& other) : maxPassengerCap(other.maxPassengerCap), guildNavigatorCount(other.guildNavigatorCount), passengerCount(other.passengerCount), operatingGuildNavigator(other.operatingGuildNavigator), serialNum(++producedShips), spiceStock(other.spiceStock) {}

SpacingGuildShip::~SpacingGuildShip() {}

int SpacingGuildShip::getShipSerialNum() const {
    return serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
    return passengerCount;
}

void SpacingGuildShip::travel(float distance) {
    if (operatingGuildNavigator > 0) {
        totalGuildTravel += distance / (E * E * operatingGuildNavigator);
        operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers) {
    if (addedPassengers > 0) {
        passengerCount += addedPassengers;
        if (passengerCount > maxPassengerCap) {
            passengerCount = maxPassengerCap;
        }
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers) {
    if (droppedPassengers > 0) {
        passengerCount -= droppedPassengers;
        if (passengerCount < 0) {
            passengerCount = 0;
        }
    }
}

void SpacingGuildShip::refreshNavigator(int n) {
    int refreshCount = std::min(n, guildNavigatorCount - operatingGuildNavigator);
    int spiceRequired = refreshCount * GUILD_NAVIGATOR_SPICE_DOSE;
    if (spiceStock >= spiceRequired) {
        operatingGuildNavigator += refreshCount;
        spiceStock -= spiceRequired;
    } else {
        refreshCount = spiceStock / GUILD_NAVIGATOR_SPICE_DOSE;
        operatingGuildNavigator += refreshCount;
        spiceStock = 0;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    spiceStock += addedSpice;
}
