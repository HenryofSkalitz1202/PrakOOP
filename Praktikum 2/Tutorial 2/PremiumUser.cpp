// PremiumUser.cpp
#include "PremiumUser.h"
#include <iostream>

// PremiumUser.cpp
#include "PremiumUser.h"
#include <iostream>

PremiumUser::PremiumUser(char* nama) : User(nama), num_of_music_downloaded(0), active(true) {}

PremiumUser::PremiumUser(const PremiumUser& other) : User(other), num_of_music_downloaded(other.num_of_music_downloaded), active(other.active) {
    std::cout << "Premium User Copied" << std::endl;
}

PremiumUser::~PremiumUser() {
    std::cout << "Premium user " << getName() << " deleted" << std::endl;
}

void PremiumUser::downloadMusic(char* judul) {
    if (!active) {
        std::cout << "Activate premium account to download music" << std::endl;
        return;
    }
    std::cout << "Music Downloaded: " << judul << std::endl;
    num_of_music_downloaded++;
}

void PremiumUser::inactivatePremium() {
    active = false;
}

void PremiumUser::activatePremium() {
    active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const {
    return active;
}

