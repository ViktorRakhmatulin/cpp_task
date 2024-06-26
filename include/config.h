#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <stdexcept>
#include <fstream>
#include <nlohmann/json.hpp> 

class Config {
public:
    static std::string read_solver_from_config(const std::string& config_file) {
        std::ifstream infile(config_file);
        if (!infile) {
            throw std::runtime_error("Error: Unable to open config file.");
        }
        nlohmann::json config;
        infile >> config;
        return config.at("solver").get<std::string>();
    }
};

#endif 
