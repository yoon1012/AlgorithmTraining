#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct Song;

struct Genre
{
    int count = 0;
    vector<Song> songs;
};

struct Song
{
    int id = 0;
    int count = 0;
};

bool songCompare(Song& s1, Song& s2)
{
    if (s1.count == s2.count)
    {
        return s1.id < s2.id;
    }

    return s1.count > s2.count;
}

bool genreCompare(Genre& g1, Genre& g2)
{
    return g1.count > g2.count;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, vector<Song>> genreHash;

    for (int i = 0; i < genres.size(); i++)
    {
        genreHash.insert(make_pair(genres[i], vector<Song>()));
    }

    for (int i = 0; i < plays.size(); i++)
    {
        Song s = { i, plays[i] };
        genreHash[genres[i]].push_back(s);
    }

    // range-based for loop에서 값을 업데이트
    for (auto& genre : genreHash)
    {
        vector<Song>& genreSongs = genre.second;
        sort(genreSongs.begin(), genreSongs.end(), songCompare);
    }

    // 장르별 곡 재생 횟수를 계산한 다음, 상위 2곡을 선정
    vector<Genre> genreList;
    for (auto& genre : genreHash)
    {
        Genre g;

        for (auto song : genre.second)
        {
            g.count += song.count;
        }

        vector<Song>& genreSongs = genre.second;
        sort(genreSongs.begin(), genreSongs.end(), songCompare);

        if (genre.second.size() > 2)
        {
            genreSongs.erase(genreSongs.begin() + 2, genreSongs.end());
        }

        g.songs = genreSongs;
        genreList.push_back(g);
    }

    sort(genreList.begin(), genreList.end(), genreCompare);

    for (auto genre : genreList)
    {
        for (auto song : genre.songs)
        {
            answer.push_back(song.id);
        }
    }

    return answer;
}

#include <iostream>

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    auto answer = solution(genres, plays);

    for (auto a : answer)
    {
        cout << a << " ";
    }
    
    cout << endl;
    return 0;
}
