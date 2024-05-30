// User.cpp
#include "User.h"
#include <iostream>

int User::n_user = 0;

User::User(char* nama) : num_of_favourite_music(0) {
    name = new char[strlen(nama) + 1];
    strcpy(name, nama);
    music_list = nullptr;
    n_user++;
}

User::User(const User& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    num_of_favourite_music = other.num_of_favourite_music;
    music_list = new char*[num_of_favourite_music];
    for (int i = 0; i < num_of_favourite_music; ++i) {
        music_list[i] = new char[strlen(other.music_list[i]) + 1];
        strcpy(music_list[i], other.music_list[i]);
    }
    n_user++;
}

User::~User() {
    std::cout << "User " << name << " deleted" << std::endl;
    delete[] name;
    if (music_list != nullptr) {
        for (int i = 0; i < num_of_favourite_music; ++i) {
            delete[] music_list[i];
        }
        delete[] music_list;
    }
    n_user--;
}

void User::addFavouriteMusic(char* judul) {
    char** temp = new char*[num_of_favourite_music + 1];
    for (int i = 0; i < num_of_favourite_music; ++i) {
        temp[i] = new char[strlen(music_list[i]) + 1];
        strcpy(temp[i], music_list[i]);
        delete[] music_list[i];
    }
    temp[num_of_favourite_music] = new char[strlen(judul) + 1];
    strcpy(temp[num_of_favourite_music], judul);
    delete[] music_list;
    music_list = temp;
    num_of_favourite_music++;
}

void User::deleteFavouriteMusic(char* judul) {
    int index = -1;
    for (int i = 0; i < num_of_favourite_music; ++i) {
        if (strcmp(music_list[i], judul) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        char** temp = new char*[num_of_favourite_music - 1];
        for (int i = 0, j = 0; i < num_of_favourite_music; ++i) {
            if (i != index) {
                temp[j] = new char[strlen(music_list[i]) + 1];
                strcpy(temp[j], music_list[i]);
                delete[] music_list[i];
                j++;
            }
        }
        delete[] music_list[index];
        delete[] music_list;
        music_list = temp;
        num_of_favourite_music--;
    }
}

void User::setName(char* nama) {
    delete[] name;
    name = new char[strlen(nama) + 1];
    strcpy(name, nama);
}

char* User::getName() const {
    return name;
}

int User::getNumOfFavouriteMusic() const {
    return num_of_favourite_music;
}

void User::viewMusicList() const {
    if (num_of_favourite_music == 0) {
        std::cout << "No music in your favourite list" << std::endl;
    } else {
        for (int i = 0; i < num_of_favourite_music; ++i) {
            std::cout << i + 1 << ". " << music_list[i] << std::endl;
        }
    }
}

int User::getNumOfUser() {
    return n_user;
}
