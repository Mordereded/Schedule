#include "File.h"

std::vector<Node> AttractionTableReader::readTable(const std::string& filename) {
    std::vector<Node> attractions;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return attractions;
    }

    std::string line;
    // Пропускаем заголовок
    getline(file, line);
    while (getline(file, line)) {
        Node attraction = parseAttraction(line);
        attractions.push_back(attraction);
    }

    file.close();
    return attractions;
}

Node AttractionTableReader::parseAttraction(const std::string& line) {
    std::stringstream ss(line);
    Node attraction;
    std::string name, visitTimeStr, importanceStr;

    // Извлекаем данные из строки
    getline(ss, name, '\t');
    getline(ss, visitTimeStr, '\t');
    getline(ss, importanceStr, '\t');

    // Преобразуем строки в нужные типы данных
    attraction.name = name;
    attraction.time = stod(visitTimeStr);
    attraction.priorite = stoi(importanceStr);

    return attraction;
}