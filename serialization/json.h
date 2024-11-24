#pragma once


#ifndef _JSON_H
#define _JSON_H

#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

#include "nlohmann/json.hpp"

#include "owner.h"

namespace seagame
{

class Json : public Owner
{
public:
    Json(const std::string &_filename);
    Json();

    Json(const Json &other);
    Json(Json &&other) noexcept;

    ~Json();

    Json& operator=(const Json &other);
    Json& operator=(Json &&other) noexcept;

    void save(const nlohmann::json &_json);
    nlohmann::json load(void);

private:
    std::fstream _file;
    std::string _filename;

private:
    void __init_file();

};

} // seagame


#endif // _JSON_H

