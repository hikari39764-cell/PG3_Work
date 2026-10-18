#include <cstdio>
#include <cstring>
#include <list>

void PrintStations(int year, const std::list<const char*>& stations) {
    std::printf("%d (%zu stations)\n", year, stations.size());
    int number = 1;
    for (const char* station : stations) {
        std::printf("%2d. %s\n", number, station);
        ++number;
    }
    std::printf("\n");
}

int main() {
    // 1970年の駅一覧。
    std::list<const char*> stations = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
        "Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
        "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
        "Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
        "Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
        "Hamamatsucho", "Shimbashi", "Yurakucho"
    };
    PrintStations(1970, stations);

    // 田端駅の前に西日暮里駅を追加。
    for (auto it = stations.begin(); it != stations.end(); ++it) {
        if (std::strcmp(*it, "Tabata") == 0) {
            stations.insert(it, "Nishi-Nippori");
            break;
        }
    }
    PrintStations(2019, stations);

    // 田町駅の前に高輪ゲートウェイ駅を追加。
    for (auto it = stations.begin(); it != stations.end(); ++it) {
        if (std::strcmp(*it, "Tamachi") == 0) {
            stations.insert(it, "Takanawa Gateway");
            break;
        }
    }
    PrintStations(2022, stations);
    return 0;
}
