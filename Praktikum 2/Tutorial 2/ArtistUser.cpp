// ArtistUser.cpp
#include "ArtistUser.h"
#include <iostream>

int ArtistUser::num_of_artist = 0;

ArtistUser::ArtistUser(char* nama) : User(nama), num_of_music_uploaded(0) {
    uploaded_music_list = nullptr;
    num_of_artist++;
}

ArtistUser::ArtistUser(const ArtistUser& other) : User(other), num_of_music_uploaded(other.num_of_music_uploaded) {
    uploaded_music_list = new char*[num_of_music_uploaded];
    for (int i = 0; i < num_of_music_uploaded; ++i) {
        uploaded_music_list[i] = new char[strlen(other.uploaded_music_list[i]) + 1];
        strcpy(uploaded_music_list[i], other.uploaded_music_list[i]);
    }
    std::cout << "Artist User Copied" << std::endl;
    num_of_artist++;
}

ArtistUser::~ArtistUser() {
    std::cout << "Artist user " << getName() << " deleted" << std::endl;
    if (uploaded_music_list != nullptr) {
        for (int i = 0; i < num_of_music_uploaded; ++i) {
            delete[] uploaded_music_list[i];
        }
        delete[] uploaded_music_list;
    }
    num_of_artist--;
}

void ArtistUser::uploadMusic(char* judul) {
    char** temp = new char*[num_of_music_uploaded + 1];
    for (int i = 0; i < num_of_music_uploaded; ++i) {
        temp[i] = new char[strlen(uploaded_music_list[i]) + 1];
        strcpy(temp[i], uploaded_music_list[i]);
        delete[] uploaded_music_list[i];
    }
    temp[num_of_music_uploaded] = new char[strlen(judul) + 1];
    strcpy(temp[num_of_music_uploaded], judul);
    delete[] uploaded_music_list;
    uploaded_music_list = temp;
    num_of_music_uploaded++;
}

void ArtistUser::deleteUploadedMusic(char* judul) {
    int index = -1;
    for (int i = 0; i < num_of_music_uploaded; ++i) {
        if (strcmp(uploaded_music_list[i], judul) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        char** temp = new char*[num_of_music_uploaded - 1];
        for (int i = 0, j = 0; i < num_of_music_uploaded; ++i) {
            if (i != index) {
                temp[j] = new char[strlen(uploaded_music_list[i]) + 1];
                strcpy(temp[j], uploaded_music_list[i]);
                delete[] uploaded_music_list[i];
                j++;
            }
        }
        delete[] uploaded_music_list[index];
        delete[] uploaded_music_list;
        uploaded_music_list = temp;
        num_of_music_uploaded--;
    }
}

void ArtistUser::viewUploadedMusicList() const {
    if (num_of_music_uploaded == 0) {
        std::cout << "No music uploaded" << std::endl;
    } else {
        for (int i = 0; i < num_of_music_uploaded; ++i) {
            std::cout << i + 1 << ". " << uploaded_music_list[i] << std::endl;
        }
    }
}

int ArtistUser::getNumOfMusicUploaded() const {
    return num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist() {
    return num_of_artist;
}
